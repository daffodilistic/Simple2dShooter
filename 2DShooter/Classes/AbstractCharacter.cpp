#include "AbstractCharacter.h"

AbstractCharacter::AbstractCharacter()
{
}

AbstractCharacter::~AbstractCharacter()
{
}

bool AbstractCharacter::initCharacter(const char* _framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim)
{
	spritesheet = _spritesheet;
	if(!CCSprite::initWithSpriteFrameName(_framename))
	{
		return false;
	}

	this->setAnchorPoint(ccp(0.5f, 0.5f));
	this->setPosition(CCPointZero);
	_spritesheet->addChild(this);
	
	if (_anim)
	{
		this->runAction(_anim);
	}

	return true;
}

CCRect AbstractCharacter::getRect()
{
	return CCRectMake(this->getPositionX(),
					  this->getPositionY(),
					  this->getContentSize().width,
					  this->getContentSize().height);
}

void AbstractCharacter::destroy()
{
	this->stopAllActions();
	spritesheet->removeAllChildren();
}


// Layer->SpriteBatchNode->Sprite