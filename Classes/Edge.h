#ifndef __NoOneDies_Edge_H__
#define __NoOneDies_Edge_H__
#include<iostream>
#include"cocos2d.h"

USING_NS_CC;

class Edge :public Node
{
public:

	virtual bool init();
	CREATE_FUNC(Edge);
};


#endif // __NoOneDies_Edge_H__