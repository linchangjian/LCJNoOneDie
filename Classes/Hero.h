#ifndef __NoOneDies_Hero_H__
#define __NoOneDies_Hero_H__
#include<iostream>
#include<cocos2d.h>
USING_NS_CC;

class Hero : public Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Hero);
};

#endif // __NoOneDies_Hero_H__