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

#include "../../cocos2d/external/json/document.h"

class JSONArray;

// JSON Base class
class JSONBase
{
public:
    
	JSONBase();

    JSONBase(const std::string &data);

    ~JSONBase();
    
    std::string toString();

protected:

    rapidjson::Document _doc;

    rapidjson::Value _val;

    bool _fromString;
};

// JSON Object class
class JSONObject : public JSONBase
{
public:

    JSONObject();

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
    
//    JSONObject optJSONObject(const std::string &name);
//
//    JSONArray optJSONArray(const std::string &name);
};

// JSON Array class
class JSONArray : public JSONBase
{
public:

    JSONArray();

    JSONArray(const std::string &data);

    ~JSONArray();
};

#endif // _JSON_PARSER_H_
