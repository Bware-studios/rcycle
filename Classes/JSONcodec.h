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

// interna
void _fill_value_to_json_node(cocos2d::Value *avalue,rapidjson::Value &json_node, rapidjson::Value::AllocatorType &allocator);




cocos2d::Value read_json_file(std::string filename);

// interna
cocos2d::Value _json_node_to_value(const rapidjson::Value &json_node);

