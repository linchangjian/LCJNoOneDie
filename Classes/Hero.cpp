#include "Hero.h"
#include "MyFlashTool.h"

bool Hero::init()
{
	Sprite::initWithFile("CloseNormal.png");
	Size s = Size(45 ,50);

	//runAction(RepeatForever::create(MyFlashTool::readJsonSpriteSheet("Hero.json", 0.3f)));
	
	setPhysicsBody(PhysicsBody::createBox(s));
	
	setContentSize(s);

	getPhysicsBody()->setRotationEnable(false);
	getPhysicsBody()->setContactTestBitmask(1);
	return true;
}

//getPhysicsBody()->setrotat