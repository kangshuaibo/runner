#include "Player.h"

Player::Player()
{
	m_isJumping = false;
}

Player::~Player()
{
}


bool Player::init()
{
	return true;
}

void Player::jump() {
	if (getSprite() == NULL) { return; }
	if (m_isJumping)
	{
		return;
	}
	m_isJumping = true;
	auto jump = JumpBy::create(2.0f, Point(0, 0), 150, 1);
	auto callFunc = CallFunc::create([&]() {m_isJumping = false; });
	auto jumpActions = Sequence::create(jump, callFunc, NULL);
	this->runAction(jumpActions);
}