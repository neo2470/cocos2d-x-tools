#ifndef __MAINLIST_SCENE_H__
#define __MAINLIST_SCENE_H__

#include <string>
#include <vector>

#include "cocos2d.h"
#include "ui/UIListView.h"

class MainList : public cocos2d::Layer
{
public:
    
    MainList();
    ~MainList();
    
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainList);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void onListViewSelectItemEvent(cocos2d::Ref* pSender, cocos2d::ui::ListView::EventType type);
    
private:
    
    void onListViewItemClicked(ssize_t index);
    
    const float FONT_SIZE = 30.0f;
    const std::string FONT_NAME = "fonts/Marker Felt.ttf";
    
    std::vector<std::string> _topics;
    
    cocos2d::ui::ListView* _listView;
};

#endif // __MAINLIST_SCENE_H__
