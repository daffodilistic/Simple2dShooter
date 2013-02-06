#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include "AbstractCharacter.h"

USING_NS_CC;

class Enemy : public AbstractCharacter
{
public:
	/* Static override method
	   @param _framename: starting frame for sprite
	   @param _spritesheet: reference to a texture
	   @param _anim: animate sprite according to the given action (Put NULL if do not have)
	*/
	static Enemy* create(const char *_framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim);

	/* Initialise
	*/
	bool init();

	/* Run jump action
	*/
	void startaction();

	/* Change state of enemy (temp)
	   @param _cstate: state of enemy 
	*/
	void changeState(CHAR_STATE _cstate);

	/* Updates
	   @param dt: delta time
	*/
	void update(float dt);
private:
	/* Constructor
	*/
	Enemy();

	/* Destructor
	*/
	~Enemy();
};

#endif