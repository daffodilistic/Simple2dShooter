#ifndef __GAME_OVER_BTN_LAYER_H_
#define __GAME_OVER_BTN_LAYER_H_

#include "cocos2d.h"
#include "Constants.h"
#include "GameManager.h"

USING_NS_CC;

#define TRANSITION_DURATION 1.2f

class GameOverBtnLayer : public CCLayer
{
public:
	/* Constructor
	*/
	GameOverBtnLayer();

	/* Destructor
	*/ 
	~GameOverBtnLayer();

	/* Initialise
	*/
	bool init();

	/* When exiting layer
	*/
	void onExit();

	/* A selector callback
	   @param _sender: Any object that is selected
	*/
	void menucallback(CCObject *_object);

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(GameOverBtnLayer);
private:
	/*
	*/
	CC_SYNTHESIZE_READONLY(CCSpriteBatchNode*, spritesheet, spritesheet);
};

#endif