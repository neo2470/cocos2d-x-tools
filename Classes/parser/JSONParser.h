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

// JSON Base class
class JSONBase
{};

// JSON Object class
class JSONObject
{
public:
    JSONObject();
    ~JSONObject();
};

// JSON Array class
class JSONArray
{
public:
    JSONArray();
    ~JSONArray();
};

#endif // _JSON_PARSER_H_