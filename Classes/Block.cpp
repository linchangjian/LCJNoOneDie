#include "Block.h"
bool Block::init()
{
	Sprite::init();
	Size s = Size((rand() % 20) + 5, (rand() % 30 )+ 10);
	Size visibleSize = Director::getInstance()->getVisibleSize();

	setPhysicsBody(PhysicsBody::createBox(s));
	setTextureRect(Rect(0,0,s.width,s.height));
	setColor(Color3B(255,255,255));
	setContentSize(s);

	setPositionX(visibleSize.width);
	scheduleUpdate();	 
	getPhysicsBody()->setDynamic(false);

	getPhysicsBody()->setContactTestBitmask(1);
	return true;

}

void Block::update(float delta)
{
	this->setPositionX(getPositionX()-5);

	if (getPositionX() < 0)
	{
		log("<<<<<");
		unscheduleUpdate();
		removeFromParent();
	}
}
