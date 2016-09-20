#include "JSONParser.h"

//JSONBase::JSONBase(const std::string &data)
//{}
//
//JSONBase::~JSONBase()
//{}

std::string JSONBase::toString()
{
    return "";
}

JSONObject::JSONObject(const std::string &data)
{}

JSONObject::~JSONObject()
{}

void JSONObject::put(const std::string &name, int value)
{}

void JSONObject::put(const std::string &name, bool value)
{}

void JSONObject::put(const std::string &name, double value)
{}

void JSONObject::put(const std::string &name, const std::string &value)
{}

void JSONObject::put(const std::string &name, JSONObject &value)
{}

void JSONObject::put(const std::string &name, JSONArray &value)
{}

int JSONObject::optInt(const std::string &name, int fallback)
{
    return fallback;
}

bool JSONObject::optBool(const std::string &name, bool fallback)
{
    return fallback;
}

double JSONObject::optDouble(const std::string &name, double fallback)
{
    return fallback;
}

std::string JSONObject::optString(const std::string &name, std::string fallback)
{
    return fallback;
}

JSONObject JSONObject::optJSONObject(const std::string &name)
{
    JSONObject obj("");
    return obj;
}

JSONArray JSONObject::optJSONArray(const std::string &name)
{
    JSONArray arr;
    return arr;
}
