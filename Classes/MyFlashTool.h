#ifndef __NoOneDies_MyFlashTool_H__
#define __NoOneDies_MyFlashTool_H__
#include<iostream>
#include<cocos2d.h>
USING_NS_CC;

class MyFlashTool
{
public:
	static Animate * readJsonSpriteSheet(std::string jsonFile, float delayPerUnit);
	static Animate * readPlistAnimate(std::string jsonFile, float delayPerUnit);

};

#endif // __NoOneDies_MyFlashTool_H__