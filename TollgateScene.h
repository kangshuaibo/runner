#pragma once
#ifndef __TollgateScene_H__
#define __TollgateScene_H__
#include "cocos2d.h"
using namespace cocos2d;
class Player;
class TollgateScene:public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TollgateScene);
private:
	void initBG();
private:
	Sprite*m_bgSpritel1;
	Sprite*m_bgSpritel2;

	Player* m_player;
};
#endif // !__TollgateScene_H__
