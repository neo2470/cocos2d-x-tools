
#include "ui/UIText.h"

#include "MainListScene.h"
#include "JSONParserTestScene.h"

USING_NS_CC;
using namespace cocos2d::ui;

MainList::MainList()
{
    _topics = {
        "1 : JSON Parser based on rapidjson",
        "2 : other"
    };
}

MainList::~MainList()
{}

Scene* MainList::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainList::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainList::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MainList::menuCloseCallback, this));
    closeItem->setAnchorPoint(Vec2(1.0f, 1.0f));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height));
    closeItem->setScale(1.5f);

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
    
    _listView = ListView::create();
    _listView->setDirection(ScrollView::Direction::VERTICAL);
    _listView->setItemsMargin(5);
    _listView->setTouchEnabled(true);
    _listView->setBounceEnabled(true);
    _listView->setScrollBarEnabled(false);
    _listView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    _listView->setContentSize(Size(visibleSize.width * 0.8f, visibleSize.height * 0.9f));
    _listView->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    _listView->addEventListener((ListView::ccListViewCallback) CC_CALLBACK_2(MainList::onListViewSelectItemEvent, this));
    _listView->setGravity(ListView::Gravity::CENTER_HORIZONTAL);
    addChild(_listView);
    
    for (unsigned int i = 0; i < _topics.size(); ++i) {
        Text* item = Text::create();
        item->setFontName(FONT_NAME);
        item->setTouchEnabled(true);
        item->setFontSize(FONT_SIZE);
        item->setTag(i);
        item->setString(_topics[i]);
        _listView->pushBackCustomItem(item);
    }
    
    return true;
}


void MainList::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}

void MainList::onListViewSelectItemEvent(Ref* pSender, ListView::EventType type)
{
    switch (type) {
        case ListView::EventType::ON_SELECTED_ITEM_START:
            log("MainList::onListViewSelectItemEvent start");
            break;
        case ListView::EventType::ON_SELECTED_ITEM_END: {
            log("MainList::onListViewSelectItemEvent end");
            ListView* listView = static_cast<ListView*>(pSender);
            onListViewItemClicked(listView->getCurSelectedIndex());
            break;
        }
        default:
            break;
    }
}

void MainList::onListViewItemClicked(ssize_t index)
{
    log("MainList::onListViewItemClicked start index = %zd", index);
    
    Scene* scene = nullptr;
    switch (index) {
        case 0:
            scene = JSONParserTest::createScene();
            break;
            
        default:
            break;
    }
    
    if (nullptr != scene) {
        Director::getInstance()->pushScene(scene);
    } else {
        log("MainList::onListViewItemClicked no scene is created!");
    }
}
