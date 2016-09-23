/**
 * LanguageHelper.h
 *
 * Support multiple languages
 *
 * cocos2d-x-tools
 *
 * Created by Alex on 23/9/2016.
 */

#ifndef _LANGUAGE_HELPER_H_
#define _LANGUAGE_HELPER_H_

#include <string>

#include "cocos2d.h"

#include "../../cocos2d/external/json/document.h"

class LanguageHelper
{
    
public:
    
    static LanguageHelper* getInstance();
    
    void setCurrentLanguage(cocos2d::LanguageType type);
    
    std::string getString(const std::string &key);
    
private:
    
    LanguageHelper();
    ~LanguageHelper();
    
    static LanguageHelper* _language;
    
    rapidjson::Document _doc;
};

#endif /* _LANGUAGE_HELPER_H_ */
