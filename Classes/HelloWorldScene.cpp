#include "HelloWorldScene.h"
#include"GameOverScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	scene->getPhysicsWorld()->setGravity(Vec2(0,-1000));
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(0,0,0,0)))
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    _labelSorce = Label::createWithTTF("Sorce 0", "arial.ttf", 30);
	this->addChild(_labelSorce);
	_labelSorce->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - _labelSorce->getContentSize().height));

	this->schedule(CC_CALLBACK_1(HelloWorld::timeScore, this), 1.0f, "test_key");

	gcs.insert(0, GameController::create(this, 0,"Sakura"));
	gcs.insert(0, GameController::create(this, 200,"Ino"));
	gcs.insert(0, GameController::create(this, 400,"Karin"));
	//gcs.insert(0, GameController::create(this, 450));

	//gcs.pushBack(GameController::create(this, 180));

	scheduleUpdate();

	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact & contact)
	{
		this->unscheduleUpdate();
		this->unschedule("test_key");
		Director::getInstance()->replaceScene(GameOverScene::createScene(scoreCount));
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this](Touch *touch , Event *event)
	{
		for (auto it = gcs.begin(); it != gcs.end();it++)
		{
			if ((*it)->hitTestPoint(touch->getLocation()))
			{
				(*it)->onUserTouch();
				break;
			}
		}
		return false;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,this);
    return true;
}

void HelloWorld::update(float dt)
{
	for (auto it = gcs.begin(); it != gcs.end();it++)
	{
		(*it)->onUpdate(dt);
	}
}
void HelloWorld::timeScore(float dt)
{
	scoreCount++;
	char tmp[10];
	sprintf(tmp, "Score %d", scoreCount);
	_labelSorce->setString(tmp);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
