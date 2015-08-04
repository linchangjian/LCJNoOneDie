#include "GameController.h"
#include"Edge.h"
#include"Hero.h"
#include"Block.h"
GameController* GameController::create(cocos2d::Layer *layer, float positionY)
{
	auto _ins = new GameController();
	_ins->init(layer,positionY);
	_ins->autorelease();
	return _ins;
}

bool GameController::init(cocos2d::Layer *layer, float positionY)
{
	_layer = layer;
	_positionY = positionY;

	visibleSize = Director::getInstance()->getVisibleSize();


	auto edge = Edge::create();
	edge->setPosition(visibleSize.width / 2, visibleSize.height / 2+positionY);
	layer->addChild(edge);

	auto ground = Sprite::create();
	ground->setTextureRect(Rect(0,0,visibleSize.width,3));
	ground->setPosition(visibleSize.width/2,1.5+positionY);
	layer->addChild(ground);

	auto hero = Hero::create();
	hero->setPosition(50, hero->getContentSize().height/2+positionY);
	layer->addChild(hero);
	resetFrames();
	return true;
}
void GameController::addBlock()
{
	auto b = Block::create();
	_layer->addChild(b);
	b->setPositionY(b->getContentSize().height/2+_positionY);
}
void GameController::onUpdate(float dt)
{
	currentFrameIndex++;
	if (currentFrameIndex>=nextFrameCount)
	{
		resetFrames();
		addBlock();
	}
}
void GameController::resetFrames()
{
	currentFrameIndex = 0;
	nextFrameCount = (rand()%120) + 100;
}