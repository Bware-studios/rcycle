//
//  JSONcodec.h
//  rcycle
//
//  Created by Mikel on 01/09/14.
//
//

#include "Common.h"


#include "json/document.h"

bool write_json_file(cocos2d::Value *avalue, std::string filename);
std::string write_json_str(cocos2d::Value *avalue);
rapidjson::Value *value_to_json_node(cocos2d::Value *avalue,rapidjson::Value &json_node);
void add_value_to_json_node(const char *name, cocos2d::Value *avalue,rapidjson::Value &json_node);


std::string value_to_json_str(cocos2d::Value *avalue);

cocos2d::Value read_json_file(std::string filename);
cocos2d::Value json_node_to_value(const rapidjson::Value &json_node);

