#pragma once
#ifndef __Entity__H_
#define __Entity__H_
#include"cocos2d.h"
USING_NS_CC;
class Entity:public Node 
{
public:
	Entity();
	~Entity();
	Sprite* getSprite();                 //ªÒ»°
	void bindSprite(Sprite* sprite);     //∞Û∂®

private:
	Sprite* m_sprite;

};
#endif
