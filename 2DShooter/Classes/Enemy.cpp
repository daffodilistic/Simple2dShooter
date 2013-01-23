#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

bool Enemy::init()
{
	this->setPosition(CCPointZero);
	this->setAnchorPoint(ccp(0.5f,0.5f));

	return true;
}

void Enemy::changeState(CHAR_STATE _cstate)
{
}

Enemy *Enemy::create(const char *_framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim)
{
	Enemy *enemy = new Enemy();

	if (enemy && enemy->initCharacter(_framename, _spritesheet, _anim))
	{
		enemy->init();
		enemy->autorelease();
		return enemy;
	}

	CC_SAFE_DELETE(enemy);
	return NULL;
}

void Enemy::update(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	this->setPosition(ccpAdd(this->getPosition(), ccpMult(ccp(-100,0), dt)));
}
