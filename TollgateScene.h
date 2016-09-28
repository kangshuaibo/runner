#pragma once
#ifndef __TollgateScene_H__
#define __TollgateScene_H__
#include "cocos2d.h"
#include"editor-support\cocostudio\CCSGUIReader.h"
#include"ui\CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d;
class Player;
class TollgateScene:public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TollgateScene);
	virtual void update(float delta);
private:
	void initBG();
private:
	Sprite*m_bgSprite1;
	Sprite*m_bgSprite2;

	Player* m_player;
	void loadUI();
	void jumpEvent(Ref*, TouchEventType type);
};
#endif // !__TollgateScene_H__
