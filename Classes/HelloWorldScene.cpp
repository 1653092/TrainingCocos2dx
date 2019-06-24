#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "playScene.h"

USING_NS_CC;



Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Button *startItem = Button::create("start.png", "start.png");
	startItem->setPosition(Vec2(visibleSize.width / 2-2, visibleSize.height / 2 +80));
	startItem->setScale(0.5);
	this->addChild(startItem, 1);
	startItem->addTouchEventListener(CC_CALLBACK_2(HelloWorld::newScene, this));

    auto sprite = Sprite::create("1545300109_game-lien-quan.png");
    if (sprite == nullptr)
    {
        problemLoading("'1545300109_game-lien-quan.png'");
    }
    else
    {
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
		sprite->setScale(1.5);
        this->addChild(sprite, 0);
    }
    return true;
}

void HelloWorld::newScene(Ref* Sender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
	{
		auto playscene = play::createScene();
		Director::getInstance()->replaceScene(playscene);
	}
		break;
	}
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
