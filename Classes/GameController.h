#ifndef __NoOneDies_GameController_H__
#define __NoOneDies_GameController_H__
#include<iostream>
#include<cocos2d.h>
USING_NS_CC;

class GameController : public Ref
{
private :
	Layer *_layer;
	float _positionY;
	Size visibleSize;
	int currentFrameIndex;
	int nextFrameCount;
private:
	void resetFrames();
	void addBlock();
public:


	virtual bool init(Layer* layer , float positionY);
	void onUpdate(float dt);
	static GameController* create(Layer* layer, float positionY);
	//CREATE_FUNC(GameController);
};

#endif // __NoOneDies_GameController_H__