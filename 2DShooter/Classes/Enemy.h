#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "cocos2d.h"
#include "AbstractCharacter.h"

USING_NS_CC;

class Enemy : public AbstractCharacter
{
public:
	bool init();
	void changeState(CHAR_STATE _cstate);
	static Enemy* create(const char *_framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim);
	void update(float dt);
private:
	Enemy();
	~Enemy();
};

#endif