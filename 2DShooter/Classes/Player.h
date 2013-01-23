#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "cocos2d.h"
#include "AbstractCharacter.h"

USING_NS_CC;

class Player : public AbstractCharacter
{
public:
	bool init();
	void changeState(CHAR_STATE _cstate);
	static Player* create(const char *_framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim);
	void setMove(CCPoint _pos);

private:
	Player();
	~Player();
	CCAction *moveaction;

};

#endif