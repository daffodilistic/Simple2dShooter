#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
}

bool Bullet::init()
{
	this->setPosition(CCPointZero);
	this->setVelo(CCPointZero);
	this->setAnchorPoint(ccp(0.5f, 0.5f));

	return true;
}

void Bullet::changeState(CHAR_STATE _cstate)
{

}

Bullet* Bullet:: create(const char *_framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim)
{
	Bullet *bullet = new Bullet();

	if (bullet && bullet->initCharacter(_framename, _spritesheet, _anim))
	{
		bullet->init(); // Initialise
		bullet->autorelease(); // Set to autorelease
        return bullet;
	}

	CC_SAFE_DELETE(bullet);
	return NULL;
}

void Bullet::update(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();


	if ((this->getPositionX() + this->getContentSize().width * 0.5f) > size.width)
	{
		this->setPosition(CCPointZero);
		this->setVelo(CCPointZero);
		this->setVisible(false);
	}
	else
	{
		this->setPosition(ccpAdd(this->getPosition(), ccpMult(this->velo, dt)));
	}
}

