#include "playScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


auto *menuSprite = Sprite::create("xepso.png");

Scene* play::createScene()
{
    return play::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in playScene.cpp\n");
}

bool play::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	menuSprite = Sprite::create("xepso.png");
	menuSprite->setScale(0.1);
	menuSprite->setPosition(Vec2(visibleSize.width / 2, 0+menuSprite->getBoundingBox().size.height/2));
	this->addChild(menuSprite);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(play::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(play::onTouchMove, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

bool play::onTouchBegan(Touch* touch, Event *event)
{
	return true;
}
void play::onTouchMove(Touch* touch, Event *event)
{
	auto touchLocation = touch->getLocation();
	auto speed = 100.0f;
	auto difference = touchLocation - menuSprite->getPosition();
	auto change = difference.getNormalized()* speed * 0.2;
	if (difference.length() > change.length())
	{
		menuSprite->setPosition(menuSprite->getPosition() + change);
	}
	else {
		menuSprite->setPosition(touchLocation);
	}

}
//void play::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//}
