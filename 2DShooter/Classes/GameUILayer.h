#ifndef __GAME_UI_LAYER_H_
#define __GAME_UI_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class GameUILayer : public CCLayer
{
public:
	/* Constructor
	*/
	GameUILayer();

	/* Destructor
	*/
	~GameUILayer();

	/* Initialise
	*/
	bool init();

	void onExit();

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(GameUILayer);

	/* Sprite for button (temp)
	*/
	CC_SYNTHESIZE(CCSprite*, btn, Btn);
};

#endif