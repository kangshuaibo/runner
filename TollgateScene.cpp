#include"TollgateScene.h"
#include"Player.h"
#include"Entity.h"
#include"cocos2d.h"
#include"SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

Scene* TollgateScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = TollgateScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool TollgateScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	/*´´½¨222*/
	m_player = Player::create();
	m_player->bindSprite(Sprite::create("hp.png"));
	m_player->setPosition(Point(200, visibleSize.height / 4));
	this->addChild(m_player, 3);
    this->scheduleUpdate();
	initBG(); 
	loadUI();

	
	return true;
}

void TollgateScene::update(float delta)
{
	int posX1 = m_bgSprite1->getPositionX();
	int posX2 = m_bgSprite2->getPositionX();
	int iSpeed = 1;

	posX1 -= iSpeed;
	posX2 -= iSpeed;

	Size mapSize = m_bgSprite1->getContentSize();

	if (posX1 <= -mapSize.width / 2) {
		posX1 = mapSize.width + mapSize.width / 2;
	}
	if (posX2 <= -mapSize.width / 2) {
		posX2 = mapSize.width + mapSize.width / 2;
	}
    m_bgSprite1->setPositionX(posX1);
	m_bgSprite2->setPositionX(posX2);
}




void TollgateScene::initBG() {
	Size visibleSize = Director::getInstance()->getVisibleSize();

	m_bgSprite1 = Sprite::create("tollgateBG.jpg");
	m_bgSprite1->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(m_bgSprite1, 0);

	m_bgSprite2 = Sprite::create("tollgateBG.jpg");
	m_bgSprite2->setPosition(Point(visibleSize.width+ visibleSize.width / 2, visibleSize.height / 2));
	m_bgSprite2->setFlippedX(true);
	this->addChild(m_bgSprite2, 0);



}

void TollgateScene::loadUI()
{
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("LittleRunnerUi_1.ExportJson");
	this->addChild(UI);
	auto jumpBtn = (Button*)Helper::seekWidgetByName(UI, "JumpBtn");
	jumpBtn->addTouchEventListener(this, toucheventselector(TollgateScene::jumpEvent));
	
}

void TollgateScene::jumpEvent(Ref *, TouchEventType type)
{
	switch (type) { case TouchEventType::TOUCH_EVENT_ENDED:m_player->jump(); 
	break;
	}
}










