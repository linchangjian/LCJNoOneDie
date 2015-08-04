#include "Hero.h"
#include "MyFlashTool.h"

bool Hero::init()
{
	Sprite::init();
	Size s = Size(45 ,50);
	//Sprite::createWithSpriteFrameName("farmers_default.png");
	//runAction(RepeatForever::create(MyFlashTool::readJsonSpriteSheet("Hero.json", 0.3f)));
	runAction(RepeatForever::create(MyFlashTool::readPlistAnimate("Ino",0.05f)));
	setPhysicsBody(PhysicsBody::createBox(s));
	
	setContentSize(s);

	getPhysicsBody()->setRotationEnable(false);
	getPhysicsBody()->setContactTestBitmask(1);
	return true;
}
void Hero::setHeroSkin(std::string fileName)
{
	runAction(RepeatForever::create(MyFlashTool::readPlistAnimate(fileName, 0.05f)));
	
}
//getPhysicsBody()->setrotat