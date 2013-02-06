#ifndef __GAME_OVER_BG_LAYER_H_
#define __GAME_OVER_BG_LAYER_H_

#include "cocos2d.h"
#include "Constants.h"

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