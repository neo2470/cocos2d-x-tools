#include "JSONParser.h"

#include "cocos2d.h"

#include "../../cocos2d/external/json/stringbuffer.h"
#include "../../cocos2d/external/json/writer.h"
#include "../../cocos2d/external/json/prettywriter.h"

using namespace rapidjson;

// ==================== JSONBase ====================

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

rapidjson::Document& JSONBase::getDocument()
{
    return _doc;
}

std::string JSONBase::toString()
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
    _doc.Accept(writer);

    return buffer.GetString();
}

std::string JSONBase::toString2()
{
    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    _doc.Accept(writer);
    
    return buffer.GetString();
}

// ==================== JSONObject ====================

JSONObject::JSONObject()
{
    _isNameUnique = true;
	_doc.SetObject();
}

JSONObject::JSONObject(const std::string &data):JSONBase(data)
{
	assert(_doc.IsObject());
}

JSONObject::~JSONObject()
{}

void JSONObject::put(const std::string &name, int value)
{
    has(name, _isNameUnique);
    _doc.AddMember(StringRef(name.c_str()), value, _doc.GetAllocator());
}

void JSONObject::put(const std::string &name, bool value)
{
    has(name, _isNameUnique);
    _doc.AddMember(StringRef(name.c_str()), value, _doc.GetAllocator());
}

void JSONObject::put(const std::string &name, double value)
{
    has(name, _isNameUnique);
    _doc.AddMember(StringRef(name.c_str()), value, _doc.GetAllocator());
}

void JSONObject::put(const std::string &name, const std::string &value)
{
    has(name, _isNameUnique);
    rapidjson::Value val(value.c_str(), _doc.GetAllocator());
    _doc.AddMember(StringRef(name.c_str()), val, _doc.GetAllocator());
}

void JSONObject::put(const std::string &name, const char *value)
{
    std::string values(value);
    put(name, values);
}

void JSONObject::put(const std::string &name, JSONBase &value)
{
    has(name, _isNameUnique);
    std::string valueString = value.toString();
    Document tmp(&_doc.GetAllocator());
    tmp.Parse<kParseDefaultFlags>(valueString.c_str());
    _doc.AddMember(StringRef(name.c_str()), tmp, _doc.GetAllocator());
    
    // TODO chek
    // 此處_doc.AddMember()的key，貌似在第一次調用toString()，會出現問題
}

int JSONObject::optInt(const std::string &name, int fallback)
{
    if (has(name)) {
        return _doc[name.c_str()].GetInt();
    }
    return fallback;
}

bool JSONObject::optBool(const std::string &name, bool fallback)
{
    if (has(name)) {
        return _doc[name.c_str()].GetBool();
    }
    return fallback;
}

double JSONObject::optDouble(const std::string &name, double fallback)
{
    if (has(name)) {
        return _doc[name.c_str()].GetDouble();
    }
    return fallback;
}

std::string JSONObject::optString(const std::string &name, std::string fallback)
{
    if (has(name)) {
        return _doc[name.c_str()].GetString();
    }
    return fallback;
}

void JSONObject::optJSONObject(const std::string &name, JSONObject &object)
{
    if (has(name)) {
        const Value& value = _doc[name.c_str()];
        assert(value.IsObject());
        
        // TODO 此處有錯誤
        
        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        value.Accept(writer);
        
        cocos2d::log("JSONObject::optJSONObject tmp string = %s", buffer.GetString());
        
        Document tmp(&object.getDocument().GetAllocator());
        tmp.Parse<kParseDefaultFlags>(buffer.GetString());
        
        object._doc.AddMember(StringRef(name.c_str()), tmp, object._doc.GetAllocator());
    }
}

void JSONObject::optJSONArray(const std::string &name, JSONArray &array)
{}

bool JSONObject::has(const std::string &name, bool remove)
{
    if (_doc.HasMember(name.c_str())) {
        cocos2d::log("JSONObject::has %s is exist", name.c_str());
        if (remove) {
            _doc.RemoveMember(name.c_str());
            cocos2d::log("JSONObject::has %s is exist and removed", name.c_str());
        }
        return true;
    }
    cocos2d::log("JSONObject::has %s is not exist", name.c_str());
    return false;
}

// ==================== JSONArray ====================

JSONArray::JSONArray()
{
	 _doc.SetArray();
}

JSONArray::JSONArray(const std::string &data) : JSONBase(data)
{
	assert(_doc.IsArray());
}

JSONArray::~JSONArray()
{}
