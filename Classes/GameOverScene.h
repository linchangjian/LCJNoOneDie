#ifndef __NoOneDies_GameOverScene_H__
#define __NoOneDies_GameOverScene_H__
#include<iostream>
#include<cocos2d.h>
USING_NS_CC;

class GameOverScene : public LayerColor
{
private:
	Size visibleSize;
public:
	virtual bool init()
	{
		LayerColor::initWithColor(Color4B::WHITE);

		visibleSize = Director::getInstance()->getVisibleSize();

		auto label = Label::create();
		label->setString("Game Over");
		label->setSystemFontSize(40);
		label->setColor(Color3B::BLACK);
		label->setPosition(visibleSize.width/2,visibleSize.height/2);
		addChild(label);
		return true;
	}
	CREATE_FUNC(GameOverScene);

	static Scene* createScene()
	{
		auto s = Scene::create();

		s->addChild(GameOverScene::create());
		return s;
	}


};

#endif // __NoOneDies_Base_H__