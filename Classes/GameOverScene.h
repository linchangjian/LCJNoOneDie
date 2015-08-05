#ifndef __NoOneDies_GameOverScene_H__
#define __NoOneDies_GameOverScene_H__
#include<iostream>
#include<cocos2d.h>
#include"ui\CocosGUI.h"
using namespace ui;
USING_NS_CC;

class GameOverScene : public LayerColor
{
private:
	Size visibleSize;
public:
	virtual bool init()
	{
		LayerColor::initWithColor(Color4B::YELLOW);

		visibleSize = Director::getInstance()->getVisibleSize();

		
		
		auto btn_continue = Button::create("btn-continue.png");

		btn_continue->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 50));

		btn_continue->addTouchEventListener([=](Ref* pSender, Widget::TouchEventType type){

			if (type == Widget::TouchEventType::ENDED){
				auto transition = TransitionSplitRows::create(2.0, HelloWorld::createScene());
				Director::getInstance()->pushScene(transition);
			}

		});

		addChild(btn_continue);
		return true;
	}
	CREATE_FUNC(GameOverScene);

	static Scene* createScene(int Score)
	{
		auto s = Scene::create();
		GameOverScene* layer = GameOverScene::create();
		Size visibleSize = Director::getInstance()->getVisibleSize();
		auto label = Label::create();
		char tmp[30];
		sprintf(tmp, "Game Over \n  Score %d", Score);
		label->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		label->setString(tmp);
		label->setSystemFontSize(40);
		label->setColor(Color3B::BLACK);
		layer->addChild(label);
		s->addChild(layer);
		return s;
	}


};

#endif // __NoOneDies_Base_H__
