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
    
    // 轉為緊湊型JSON，適合傳輸
    std::string toString();
    
    // 轉為格式化JSON，適合閱讀
    std::string toString2();

protected:

    rapidjson::Document _doc;

    bool _fromString;
};

// JSON Object class
class JSONObject : public JSONBase
{
public:

    JSONObject();

    JSONObject(const std::string &data);
    
    ~JSONObject();
    
    /**
     * 寫入name對應int型value，_isNameUnique（默認）為true時
     * 該方法會覆蓋已存在name及其value
     */
    void put(const std::string &name, int value);
    
    /**
     * 寫入name對應bool型value，_isNameUnique（默認）為true時
     * 該方法會覆蓋已存在name及其value
     */
    void put(const std::string &name, bool value);
    
    /**
     * 寫入name對應double型value，_isNameUnique（默認）為true時
     * 該方法會覆蓋已存在name及其value
     */
    void put(const std::string &name, double value);
    
    /**
     * 寫入name對應std::string型value，_isNameUnique（默認）為true時
     * 該方法會覆蓋已存在name及其value
     */
    void put(const std::string &name, const std::string &value);
    
    /**
     * 寫入name對應[字符串字面值]型value，_isNameUnique（默認）為true時
     * 該方法會覆蓋已存在name及其value
     */
    void put(const std::string &name, const char *value);
    
    /**
     * 寫入name對應JSONObject or JSONArray型value，_isNameUnique（默認）為true時
     * 該方法會覆蓋已存在name及其value
     */
    void put(const std::string &name, JSONBase &value);
    
    /**
     * 讀取name對應int型值，當JSONObject中不存在name時，將返回
     * 指定的fallback，fallback默認為0
     */
    int optInt(const std::string &name, int fallback = 0);
    
    /**
     * 讀取name對應bool型值，當JSONObject中不存在name時，將返回
     * 指定的fallback，fallback默認為false
     */
    bool optBool(const std::string &name, bool fallback = false);
    
    /**
     * 讀取name對應double型值，當JSONObject中不存在name時，將返回
     * 指定的fallback，fallback默認為0.0
     */
    double optDouble(const std::string &name, double fallback = 0.0);
    
    /**
     * 讀取name對應std::string型值，當JSONObject中不存在name時，將返回
     * 指定的fallback，fallback默認為""
     */
    std::string optString(const std::string &name, std::string fallback = "");
    
    void optJSONObject(const std::string &name, JSONObject &object);

    void optJSONArray(const std::string &name, JSONArray &array);
    
    /**
     * 判斷JSONObject是否包含name字段
     *
     * name std::string類型
     * remove 是否刪除已存在的字段。true，刪除；false，不刪除。默認false
     */
    bool has(const std::string &name, bool remove = false);
    
private:
    
    bool _isNameUnique;
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
