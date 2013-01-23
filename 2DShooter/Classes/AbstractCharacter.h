#ifndef __ABSTRACT_CHARACTER_H_
#define __ABSTRACT_CHARACTER_H_

#include "cocos2d.h"
#include "Constants.h"
#include <string.h>

USING_NS_CC;
using namespace std;

class AbstractCharacter : public CCSprite
{
public:
	/* Constructor
	*/
	AbstractCharacter();

	/* Destructor
	*/
	~AbstractCharacter();
	
	/* Initilise character 
	  @param _framename: starting frame for sprite
	  @param _spritesheet: reference to a texture
	  @param _anim: animate sprite according to the given action (Put NULL if do not have)
	*/
	bool initCharacter(const char* _framename, CCSpriteBatchNode *_spritesheet, CCAction *_anim);
	
	/* Change state of character
		@param _cstate: state of character
	*/
	virtual void changeState(CHAR_STATE _cstate) = 0;
	
	/* Stops all action and cleans up
	*/
	void destroy();

	/* Get sprite collision box
	*/
	CCRect getRect();

protected:
	/* Hit points
	*/
	CC_SYNTHESIZE(int, hp, Hp);

	/* Speed
	*/
	CC_SYNTHESIZE(float, speed, Speed);

	/* State
	*/
	CC_SYNTHESIZE(CHAR_STATE, state, State);

	/* Name of character
	*/
	CC_SYNTHESIZE(const char*, name, Name);

	/* Sprite sheet
	*/
	CC_SYNTHESIZE(CCSpriteBatchNode*, spritesheet, spritesheet);

};

#endif