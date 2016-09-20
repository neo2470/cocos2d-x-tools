/**
 * JSONParser.h
 * 
 * A JSON parser based on RAPIDJSON
 *
 * cocos2d-x-tools
 * 
 * Created by Alex on 20/9/2016.
 *
 */

#ifndef _JSON_PARSER_H_
#define _JSON_PARSER_H_

#include <string>

class JSONArray;

// JSON Base class
class JSONBase
{
public:
    
    // 根據string生成JSON
//    JSONBase(const std::string &data){};
//    
//    ~JSONBase();
    
    std::string toString();
};

// JSON Object class
class JSONObject : public JSONBase
{
public:
    
    JSONObject(const std::string &data);
    
    ~JSONObject();
    
    void put(const std::string &name, int value);
    
    void put(const std::string &name, bool value);
    
    void put(const std::string &name, double value);
    
    void put(const std::string &name, const std::string &value);
    
    void put(const std::string &name, JSONObject &value);
    
    void put(const std::string &name, JSONArray &value);
    
    int optInt(const std::string &name, int fallback = 0);
    
    bool optBool(const std::string &name, bool fallback = false);
    
    double optDouble(const std::string &name, double fallback = 0.0);
    
    std::string optString(const std::string &name, std::string fallback = "");
    
    JSONObject optJSONObject(const std::string &name);
    
    JSONArray optJSONArray(const std::string &name);
};

// JSON Array class
class JSONArray : public JSONBase
{
public:
    JSONArray();
    ~JSONArray();
};

#endif // _JSON_PARSER_H_