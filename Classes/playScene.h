
#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
using namespace cocos2d;
using namespace ui;

class play : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
	bool onTouchBegan(Touch* touch, Event *event);
	void onTouchMove(Touch* touch, Event *event);
    // implement the "static create()" method manually
    CREATE_FUNC(play);
};

#endif // __HELLOWORLD_SCENE_H__
