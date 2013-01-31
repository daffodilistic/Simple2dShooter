#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

bool Player::init()
{
	state = CHAR_STATE_NONE;
	hp = 5;
	speed = 1000.0f;
	name = NULL;
	moveaction = NULL;
	points = 0;

	return true;
}

void Player::changeState(CHAR_STATE _cstate)
{
	state = _cstate;

	switch (state)
	{
		case CHAR_STATE_NONE:
			break;
		case CHAR_STATE_SPAWN:
			break;
		case CHAR_STATE_SHOOT:
			break;
		case CHAR_STATE_DEAD:
			break;
		default:
			break;
	}

}

Player*  Player::create(const char* _framename, CCSpriteBatchNode *_spritesheet,  CCAction *_anim)
{
	Player *player = new Player();

	if (player && player->initCharacter(_framename, _spritesheet, _anim))
    {
		player->init(); // Initialise
		player->autorelease(); // Set to autorelease
        return player;
    }

    CC_SAFE_DELETE(player);
	return NULL;
}


void Player::addPoints()
{
	points ++;
}

void Player::setMove(CCPoint _pos)
{
	/*
	if(moveaction)
	{
		this->stopAction(moveaction);
	}
	*/

	CCPoint currentpos = this->getPosition();
	CCPoint movediff = ccpSub(currentpos, _pos);
	float finaldest = ccpLength(movediff);
	float moveDuration = finaldest / speed;

	moveaction = CCMoveTo::actionWithDuration(moveDuration, _pos);
	this->runAction(moveaction);

}
