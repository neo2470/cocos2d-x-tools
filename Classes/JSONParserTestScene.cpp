//
//  JSONParserTestScene.cpp
//  cocos2d-x-tools
//
//  Created by Alex on 20/9/2016.
//
//

#include "ui/UIButton.h"

#include "parser/JSONParser.h"

#include "JSONParserTestScene.h"

USING_NS_CC;
using namespace cocos2d::ui;

JSONParserTest::JSONParserTest()
{}

JSONParserTest::~JSONParserTest()
{}

Scene* JSONParserTest::createScene()
{
    auto scene = Scene::create();
    
    auto layer = JSONParserTest::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool JSONParserTest::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    Button* backBtn = Button::create();
    backBtn->setTag(0);
    backBtn->setTitleFontName(BTN_FONT_NAME);
    backBtn->setTitleFontSize(BTN_FONT_SIZE);
    backBtn->setTitleText("Back");
    backBtn->setAnchorPoint(Vec2(0.0f, 1.0f));
    backBtn->setPosition(Vec2(origin.x, origin.y + visibleSize.height));
    backBtn->addClickEventListener(CC_CALLBACK_1(JSONParserTest::onBtnClicked, this));
    addChild(backBtn);
    
    std::string data = "{ \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4]}";
    JSONObject obj(data);

    std::string data2 = "[2, 3, 4, 5, 6, 7, 8, 9, 10]";
    JSONArray arr(data2);

    log("JSONParserTest::init JSONObject obj.toString() = %s", obj.toString().c_str());
    log("JSONParserTest::init JSONArray arr.toString() = %s", arr.toString().c_str());

    return true;
}

void JSONParserTest::onBtnClicked(Ref* pSender)
{
    Node* node = static_cast<Node*>(pSender);
    switch (node->getTag()) {
        case 0:
            Director::getInstance()->popScene();
            break;
            
        default:
            break;
    }
}
