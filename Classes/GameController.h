#ifndef __NoOneDies_GameController_H__
#define __NoOneDies_GameController_H__
#include<iostream>
#include<cocos2d.h>
#include"Edge.h"
#include"Hero.h"
#include"Block.h"
USING_NS_CC;

class GameController : public Ref
{
private :
	Layer *_layer;
	float _positionY;
	Size visibleSize;
	int currentFrameIndex;
	int nextFrameCount;
	Edge *edge;
	Hero *hero;
private:
	void resetFrames();
	void addBlock();
public:


	virtual bool init(Layer* layer, float positionY, std::string fileName);
	void onUpdate(float dt);
	bool hitTestPoint(Vec2 point);
	void onUserTouch();
	static GameController* create(Layer* layer, float positionY, std::string fileName);
	//CREATE_FUNC(GameController);
};

#endif // __NoOneDies_GameController_H__	