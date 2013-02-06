#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "cocos2d.h"
#include "AbstractCharacter.h"

USING_NS_CC;

class Player : public AbstractCharacter
{
public:
	/* Initialise
	*/
	bool init();

	/* Change state of character
	   @param _cstate: state of character
	*/
	void changeState(CHAR_STATE _cstate);

	/* Static override method
	   @param _framename: starting frame for sprite
	   @param _spritesheet: reference to a texture
	   @param _anim: animate sprite according to the given action (Put NULL if do not have)
	*/
	static Player* create(const char *_framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim);

	/* Set character move to position
	*/
	void setMove(CCPoint _pos);

	/* Adds point
	*/
	void addPoints();

private:
	/* Constructor
	*/
	Player();

	/* Destructor
	*/
	~Player();

	/* Points
	*/
	CC_SYNTHESIZE(int, points, points);

	CCAction *moveaction;

};

#endif