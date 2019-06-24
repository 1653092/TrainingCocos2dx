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
	menuSprite->setScale(0.3);
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
	menuSprite->stopAllActions();
	auto touchLocation = touch->getLocation();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (touchLocation.x < menuSprite->getBoundingBox().size.width / 2)
	{
		touchLocation.x = menuSprite->getBoundingBox().size.width / 2;
	}
	if (touchLocation.y < menuSprite->getBoundingBox().size.height / 2)
	{
		touchLocation.y = menuSprite->getBoundingBox().size.height / 2;
	}
	if (touchLocation.x > visibleSize.width - menuSprite->getBoundingBox().size.width / 2)
	{
		touchLocation.x = visibleSize.width - menuSprite->getBoundingBox().size.width / 2;
	}
	if (touchLocation.y > menuSprite->getBoundingBox().size.height / 2)
	{
		touchLocation.y = menuSprite->getBoundingBox().size.height / 2;
	}
	auto actionMove = MoveTo::create(0.2, Point(touchLocation));
	menuSprite->runAction(actionMove);
	return true;
}

void play::onTouchMove(Touch* touch, Event *event)
{
	menuSprite->stopAllActions();

	auto touchLocation = touch->getLocation();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	if (touchLocation.x < menuSprite->getBoundingBox().size.width / 2	)
	{
		touchLocation.x = menuSprite->getBoundingBox().size.width / 2;
	}
	if (touchLocation.y < menuSprite->getBoundingBox().size.height / 2)
	{
		touchLocation.y = menuSprite->getBoundingBox().size.height / 2;
	}
	if (touchLocation.x > visibleSize.width - menuSprite->getBoundingBox().size.width / 2)
	{
		touchLocation.x = visibleSize.width - menuSprite->getBoundingBox().size.width / 2;
	}
	if (touchLocation.y > menuSprite->getBoundingBox().size.height/2)
	{
		touchLocation.y = menuSprite->getBoundingBox().size.height/2;
	}
	if (touchLocation.x < 0)
	{
		touchLocation.x = 0;
	}
	if (touchLocation.x > visibleSize.width)
	{
		touchLocation.x = visibleSize.width;
	}

	auto speed = 100.0f;
	auto difference = touchLocation - menuSprite->getPosition();
	auto change = difference.getNormalized()* speed * 0.3;
	if (difference.length() > change.length())
	{
		menuSprite->setPosition(menuSprite->getPosition() + change);
	}
	else {
		menuSprite->setPosition(touchLocation);
	}

	auto actionMove = MoveTo::create(0.2, Point(touchLocation));
	menuSprite->runAction(actionMove);
}
//void play::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//}
