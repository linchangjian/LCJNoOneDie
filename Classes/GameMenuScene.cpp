﻿#include "GameMenuScene.h"
#include"ui\CocosGUI.h"
#include"HelloWorldScene.h"
USING_NS_CC;
using namespace ui;
Scene* GameMenuScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameMenuScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameMenuScene::init()
{
	if (!Layer::init()){ return false; }

	Size visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// 添加一个关闭菜单，点击可以退出程序
	// 创建一个关闭图标（MenuItemImage），该对象会自动管理内存的释放
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameMenuScene::menuCloseCallback, this));
	// 设置关闭图标在屏幕的位置
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));


	auto bg_1 = Sprite::create("bg.jpg");

	bg_1->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
	this->addChild(bg_1,0);

	auto menu = Menu::create(closeItem , NULL);

	menu->setPosition(Vec2::ZERO);

	this->addChild(menu ,1);


	auto start_button = Button::create("btn-start.png");

	start_button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height/2));

	start_button->addTouchEventListener([=](Ref* pSender, Widget::TouchEventType type){
	
		if (type == Widget::TouchEventType::ENDED){
			auto transition = TransitionSplitRows::create(2.0 , HelloWorld::createScene());
			Director::getInstance()->pushScene(transition);
		}
	
	});

	this->addChild(start_button  ,1);

	auto select_button = Button::create("btn-select.png");

	select_button->setPosition(Vec2(visibleSize.width / 2 , visibleSize.height /2 - 75));
	
	select_button->addTouchEventListener([=](Ref* pSender, Widget::TouchEventType type){
		if (type == Widget::TouchEventType::ENDED){
		}
	});

	this->addChild(select_button ,1);

	return true;

}

void GameMenuScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	// 程序执行结束,释放运行场景。
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
 