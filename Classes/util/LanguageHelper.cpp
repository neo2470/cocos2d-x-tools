//
//  LanguageHelper.cpp
//  cocos2d-x-tools
//
//  Created by Alex on 23/9/2016.
//
//

#include "LanguageHelper.h"

LanguageHelper* LanguageHelper::_language = nullptr;

LanguageHelper* LanguageHelper::getInstance()
{
    if (nullptr == _language) {
        _language = new LanguageHelper;
    }
    
    return _language;
}

void LanguageHelper::setCurrentLanguage(cocos2d::LanguageType type)
{
    std::string file;
    switch (type) {
        case cocos2d::LanguageType::CHINESE:
            file = "cn.json";
            break;
        default:
            file = "en.json";
            break;
    }
    
    std::string content = cocos2d::FileUtils::getInstance()->getStringFromFile(file);
    
    _doc.Parse<rapidjson::kParseDefaultFlags>(content.c_str());
    if (_doc.HasParseError()) {
        cocos2d::log("LanguageHelper::setCurrentLanguage Language file parsing error!");
    }
}

std::string LanguageHelper::getString(const std::string &key)
{
    return _doc[key.c_str()].GetString();
}

LanguageHelper::LanguageHelper()
{
    setCurrentLanguage(cocos2d::Application::getInstance()->getCurrentLanguage());
}

LanguageHelper::~LanguageHelper()
{}
