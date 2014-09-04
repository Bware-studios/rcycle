//
//  JSONcodec.cpp
//  rcycle
//
//  Created by Mikel on 01/09/14.
//
//


#include "JSONcodec.h"

#include <stdio.h>

#include "json/document.h"
#include "json/filestream.h"
#include "json/stringbuffer.h"
#include "json/writer.h"

#include <iostream>
#include <fstream>

USING_NS_CC;



bool write_json_file(cocos2d::Value *avalue, std::string filename)
{
    FILE *f=fopen(filename.c_str(),"w");
    if (!f) return false;
    fprintf(f,"%s",write_json_str(avalue).c_str());
    fclose(f);
    return true;
}

std::string write_json_str(cocos2d::Value *avalue)
{
    char cbuf[2024];
    rapidjson::MemoryPoolAllocator<> allocator (cbuf, sizeof cbuf);
    rapidjson::Document jsondoc (&allocator, 256);
    //rapidjson::Document jsondoc;
    
    _fill_value_to_json_node(avalue, jsondoc, allocator);
    
    // prepare writer
    typedef rapidjson::GenericStringBuffer<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<>> StringBuffer;
//    StringBuffer buf (&allocator);
    StringBuffer buf;
//    rapidjson::Writer<StringBuffer> writer (buf, &allocator);
    rapidjson::Writer<StringBuffer> writer (buf);
    jsondoc.Accept(writer);

    std::string json (buf.GetString(), buf.Size());

    // dump json to stream
    std::ostringstream out_str ;
    out_str << json;
    return out_str.str();
}


void _fill_value_to_json_node(cocos2d::Value *avalue,rapidjson::Value &json_node, rapidjson::Value::AllocatorType &allocator)
{
    Value::Type type=avalue->getType();
    if (type==Value::Type::NONE) {
        json_node.SetNull();
    } else if (type==Value::Type::BYTE) {
        json_node.SetInt(avalue->asByte());
    } else if (type==Value::Type::INTEGER) {
        json_node.SetInt(avalue->asInt());
    } else if (type==Value::Type::FLOAT) {
        json_node.SetDouble(avalue->asFloat());
    } else if (type==Value::Type::DOUBLE) {
        json_node.SetDouble(avalue->asDouble());
    } else if (type==Value::Type::BOOLEAN) {
        json_node.SetBool(avalue->asBool());
    } else if (type==Value::Type::STRING) {
        json_node.SetString(avalue->asString().c_str(),allocator);
    } else if (type==Value::Type::MAP) {
        json_node.SetObject();
        ValueMap &amap=avalue->asValueMap();
        ValueMap::iterator i;
        //char cbuf[1024]; rapidjson::MemoryPoolAllocator<> allocator (cbuf, sizeof cbuf);

        for (i=amap.begin();i!=amap.end();i++) {
            rapidjson::Value v;
            _fill_value_to_json_node(&(i->second), v, allocator);
            json_node.AddMember(i->first.c_str(),v,allocator);
        }
    } else if (type==Value::Type::INT_KEY_MAP) {
        json_node.SetObject();
        ValueMapIntKey &amap=avalue->asIntKeyMap();
        ValueMapIntKey::iterator i;
      //  char cbuf[1024]; rapidjson::MemoryPoolAllocator<> allocator (cbuf, sizeof cbuf);
        std::string *sname;
        for (i=amap.begin();i!=amap.end();i++) {
            rapidjson::Value v;
            _fill_value_to_json_node(&(i->second), v, allocator);
          //  char xname[50];
          //  name<<i->first;
            std::stringstream name;
            name<<i->first;
            //sprintf(xname, "%d",i->first);
            //printf("[%s]",xname);
            sname=new std::string(name.str());
          //  LOG_SCORE("%s %s",name.str().c_str(),i->second.getType());
            json_node.AddMember(sname->c_str(),v,allocator);
        }
    } else if (type==Value::Type::VECTOR) {
        json_node.SetArray();
        ValueVector &amap=avalue->asValueVector();
        ValueVector::iterator i;
      //  char cbuf[1024]; rapidjson::MemoryPoolAllocator<> allocator (cbuf, sizeof cbuf);
        for (i=amap.begin();i!=amap.end();i++) {
            rapidjson::Value v;
            _fill_value_to_json_node(&(*i), v, allocator);
            json_node.PushBack(v,allocator);
        }

    }

}



Value read_json_file(std::string filename)
{
    // stream from filename
    FILE *f=fopen(filename.c_str(),"r");
    if (!f) return *new Value;
    rapidjson::FileStream fs(f);

    // parse
    rapidjson::Document jsondoc;
    jsondoc.ParseStream<0>(fs);
    if (jsondoc.HasParseError()) {
        LOG_SCORE("error");
        LOG_SCORE("%d %s",jsondoc.GetErrorOffset(),jsondoc.GetParseError());
        return Value();
    }
    
    Value result=_json_node_to_value(jsondoc);
    return result;
}


cocos2d::Value _json_node_to_value(const rapidjson::Value &json_node)
{
    if (json_node.IsNull()) {
        return cocos2d::Value();
    } else if (json_node.IsNumber()) {
        if (json_node.IsInt())
            return cocos2d::Value(json_node.GetInt());
        else if (json_node.IsUint())
            return cocos2d::Value((int)json_node.GetUint());
        else if (json_node.IsInt64())
            return cocos2d::Value((int)json_node.GetInt64());
        else if (json_node.IsUint64())
            return cocos2d::Value((int)json_node.GetUint64());
        else if (json_node.IsDouble())
            return cocos2d::Value(json_node.GetDouble());
    } else if (json_node.IsBool()) {
        if (json_node.IsFalse()) return cocos2d::Value(false);
        if (json_node.IsTrue()) return cocos2d::Value(true);
    } else if (json_node.IsString()) {
        return cocos2d::Value(json_node.GetString());
    } else if (json_node.IsObject()) {
        ValueMap dict;
        rapidjson::Value::ConstMemberIterator i;
        for (i=json_node.MemberonBegin();i!=json_node.MemberonEnd();i++) {
            Value subelement = _json_node_to_value(i->value);
            dict[i->name.GetString()]=subelement;
        }
        return cocos2d::Value(dict);
    } else if (json_node.IsArray()) {
        ValueVector arr;
        rapidjson::Value::ConstValueIterator i;
        for (i=json_node.onBegin();i!=json_node.onEnd();i++) {
            Value subelement = _json_node_to_value(*i);
            arr.push_back(subelement);
        }
        return cocos2d::Value(arr);
    }
    return cocos2d::Value();
}

