#include "JSONParser.h"

#include "../../cocos2d/external/json/stringbuffer.h"
#include "../../cocos2d/external/json/writer.h"

using namespace rapidjson;

JSONBase::JSONBase()
{
	_fromString = false;
}

JSONBase::JSONBase(const std::string &data)
{
	_fromString = true;
	_doc.Parse<kParseDefaultFlags>(data.c_str());
}

JSONBase::~JSONBase()
{}

std::string JSONBase::toString()
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	if(_fromString) {
		_doc.Accept(writer);
	} else {
		_val.Accept(writer);
	}

    return buffer.GetString();
}

JSONObject::JSONObject()
{
	_val.SetObject();
}

JSONObject::JSONObject(const std::string &data):JSONBase(data)
{
	assert(_doc.IsObject());
}

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

//JSONObject JSONObject::optJSONObject(const std::string &name)
//{
//    JSONObject obj;
//    return obj;
//}
//
//JSONArray JSONObject::optJSONArray(const std::string &name)
//{
//    JSONArray arr;
//    return arr;
//}

JSONArray::JSONArray()
{
	 _fromString = false;
	 _val.SetArray();
}

JSONArray::JSONArray(const std::string &data) : JSONBase(data)
{
	assert(_doc.IsArray());
}

JSONArray::~JSONArray()
{}
