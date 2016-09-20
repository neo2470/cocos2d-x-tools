//
//  JSONParserTestScene.h
//  cocos2d-x-tools
//
//  Created by Alex on 20/9/2016.
//
//

#ifndef _JSON_PARSER_TEST_SCENE_H_
#define _JSON_PARSER_TEST_SCENE_H_

#include "cocos2d.h"

class JSONParserTest : public cocos2d::Layer
{
public:
    
    JSONParserTest();
    ~JSONParserTest();
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(JSONParserTest);
    
    void onBtnClicked(cocos2d::Ref* pSender);
    
private :
    
    const float BTN_FONT_SIZE = 30.0f;
    const std::string BTN_FONT_NAME = "fonts/Marker Felt.ttf";
};


#endif // _JSON_PARSER_TEST_SCENE_H_
