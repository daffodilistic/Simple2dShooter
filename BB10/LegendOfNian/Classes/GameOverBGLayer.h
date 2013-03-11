#ifndef __GAME_OVER_BG_LAYER_H_
#define __GAME_OVER_BG_LAYER_H_

#include "cocos2d.h"
#include "Constants.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;

class GameOverBGLayer : public CCLayer
{
public:
	/* Constructor
	*/
	GameOverBGLayer();
	
	/* Destructor
	*/
	~GameOverBGLayer();

	/* Initialise
	*/
	bool init();

	/* When layer is added
	*/
	void onEnter();

	/* On touch end events
	   @param pTouches: get user touches
	   @param pEvent: get type of event
	*/
	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	/* When exiting layer
	*/ 
	void onExit();

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(GameOverBGLayer);

private:

	CC_SYNTHESIZE_READONLY(CCSpriteBatchNode*, spritesheet, spritesheet);
};

#endif