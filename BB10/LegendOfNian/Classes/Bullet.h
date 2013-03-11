#ifndef __BULLET_H_
#define __PLAYER_H_

#include "cocos2d.h"
#include "AbstractCharacter.h"

USING_NS_CC;

class Bullet : public AbstractCharacter
{
public:
	/* Static override method
	   @param _framename: starting frame for sprite
	   @param _spritesheet: reference to a texture
	   @param _anim: animate sprite according to the given action (Put NULL if do not have)
	*/
	static Bullet* create(const char *_framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim);
	
	/* Initialise
	*/
	bool init();

	/* Change state of bullet (temp)
	   @param _cstate: state of bullet 
	*/
	void changeState(CHAR_STATE _cstate);

	/* Updates
	   @param dt: delta time
	*/
	void update(float dt);

private:
	/* Constructor
	*/
	Bullet();

	/* Destructor
	*/
	~Bullet();

	/* Velocity/Speed
	*/
	CC_SYNTHESIZE(CCPoint, velo, Velo); 

};

#endif;