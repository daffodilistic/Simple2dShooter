#ifndef __BULLET_H_
#define __PLAYER_H_

#include "cocos2d.h"
#include "AbstractCharacter.h"

USING_NS_CC;

class Bullet : public AbstractCharacter
{
public:
	bool init();
	void changeState(CHAR_STATE _cstate);
	static Bullet*  create(const char *_framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim);
	void update(float dt);

private:
	Bullet();
	~Bullet();
	CC_SYNTHESIZE(CCPoint, velo, Velo); 

};

#endif;