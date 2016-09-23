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
    
    // JSONParser test
    JSONParserTest2();
    
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

void JSONParserTest::JSONParserTest2()
{
    // 生成JSON Object
    JSONObject obj1;
    obj1.put("int", 123);
    obj1.put("bool", true);
    obj1.put("double", 14354353.120215);
    
    std::string str("字符串變量");
    obj1.put("string1", str);
    
    obj1.put("string2", "字符串字面值");
    
    JSONObject obj;
    obj.put("key", "由JSONObject手動put而來");
    obj1.put("objFromPut", obj);
    
    JSONObject objs("{\"key\": \"由std::string解析而來\"}");
    obj1.put("objFromParse", objs);
    
    JSONArray arr;
    obj1.put("objFromPut2", arr);
    
    log("JSONParserTest::JSONParserTest2 JSONObject obj1.toString() = %s", obj1.toString().c_str());
    
    // 生成JSON Array
    
    // ====================
    
    // 解析JSON Object
    std::string objStr = "{ \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4], \"obj\":{\"name\":\"alex\"}}";
    JSONObject obj2(objStr);
    log("JSONParserTest::JSONParserTest2 JSONObject parse objStr = %s", objStr.c_str());
    
    std::string hello = obj2.optString("hello");
    log("JSONParserTest::JSONParserTest2 JSONObject parser hello = %s", hello.c_str());
    
    bool t = obj2.optBool("t");
    log("JSONParserTest::JSONParserTest2 JSONObject parser t = %d", t);
    
    bool f = obj2.optBool("f");
    log("JSONParserTest::JSONParserTest2 JSONObject parser f = %d", f);
    
    int i = obj2.optInt("i");
    log("JSONParserTest::JSONParserTest2 JSONObject parser i = %d", i);
    
    double pi = obj2.optDouble("pi");
    log("JSONParserTest::JSONParserTest2 JSONObject parser pi = %f", pi);
    

    // 解析JSON Array
    std::string arrStr = "[2, 3, 4, 5, 6, 7, 8, 9, 10]";
    JSONArray arr1(arrStr);
    
//    log("JSONParserTest::JSONParserTest2 JSONObject obj2.toString() = %s", obj2.toString().c_str());
//    log("JSONParserTest::JSONParserTest2 JSONArray arr1.toString() = %s", arr1.toString().c_str());
}
