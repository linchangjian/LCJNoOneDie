#ifndef __NoOneDies_Block_H__
#define __NoOneDies_Block_H__
#include<iostream>
#include<cocos2d.h>
USING_NS_CC;

class Block :public Sprite
{
public:
	virtual bool init();
	virtual void update(float delta);
	CREATE_FUNC(Block);
};

#endif // __NoOneDies_Block_H__