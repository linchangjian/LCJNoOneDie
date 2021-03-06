﻿#ifndef __GAMEMENU_SCENE_H__
#define __GAMEMENU_SCENE_H__
#include"cocos2d.h"
#include"audio/include/SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
// 游戏的精灵表单、背景音乐和音效
class GameMenuScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	void menuCloseCallback(Ref* pSender);
	CREATE_FUNC(GameMenuScene);
};
#endif
//#ifndef __GAMEMENU_SCENE_H__
//#define __GAMEMENU_SCENE_H__
//#include"cocos2d.h"
//#include"GameScene.h"
//#include"audio/include/SimpleAudioEngine.h"
//
//using namespace CocosDenshion;
//
//// 游戏的精灵表单、背景音乐和音效
//#define RESOURCESPLIST "resources.plist"
//#define MUSIC_FILE        "background.mp3"
//#define EFFECT_FILE1        "Fat141.mp3"
//#define EFFECT_FILE2       "Land232.mp3"
//
//class GameMenuScene : public cocos2d::Layer
//{
//public:
//
//	static Scene* createScene();
//	virtual bool init();
//
//	void menuCloseCallback(Ref* pSender);
//
//	CREATE_FUNC(GameMenuScene);
//
//
//};
//#endif // __GAMEMENU_SCENE_H__
//
// 