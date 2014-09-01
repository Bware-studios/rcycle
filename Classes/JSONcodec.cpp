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

#include <iostream>
#include <fstream>

USING_NS_CC;



bool write_json_file(cocos2d::Value *avalue, std::string filename)
{
    
    
    
}

Value read_json_file(std::string filename)
{
    // stream from filename
    FILE *f=fopen(filename.c_str(),"r");
    rapidjson::FileStream fs(f);

    // parse
    rapidjson::Document jsondoc;
    jsondoc.ParseStream<0>(fs);
    if (jsondoc.HasParseError()) {
        LOG_SCORE("error");
        return Value();
    }
    
    Value result=json_node_to_value(jsondoc);
    return result;
}


std::string value_to_json_str(cocos2d::Value *avalue)
{
    
    
}


cocos2d::Value json_node_to_value(const rapidjson::Value &json_node)
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
        LOG_SCORE("object");
        ValueMap dict;
        rapidjson::Value::ConstMemberIterator i;
        for (i=json_node.MemberonBegin();i!=json_node.MemberonEnd();i++) {
            Value subelement = json_node_to_value(i->value);
            dict[i->name.GetString()]=subelement;
            LOG_SCORE("%s : %d",i->name.GetString(),i->value.GetType());
        }
        return cocos2d::Value(dict);
    } else if (json_node.IsArray()) {
        LOG_SCORE("array");
        ValueVector arr;
        rapidjson::Value::ConstValueIterator i;
        for (i=json_node.onBegin();i!=json_node.onEnd();i++) {
            Value subelement = json_node_to_value(*i);
            arr.push_back(subelement);
            LOG_SCORE("a : %d\n",i->GetType());
        }
        return cocos2d::Value(arr);
    }
    return cocos2d::Value();
}

