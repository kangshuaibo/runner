#pragma once
#ifndef _Player_H__
#define _Player_H__
#include"cocos2d.h"
#include"Entity.h"
using namespace cocos2d;
#define JUMP_ACTION_TAG 1
class Player:public Entity
{
public:
	Player();
	~Player();
	CREATE_FUNC(Player);
	virtual bool inti();
 
};


#endif _Player_H_
