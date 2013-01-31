#ifndef __GAME_BG_LAYER_H_
#define __GAME_BG_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class GameBGLayer : public CCLayer
{
public:
	/* Constructor
	*/
	GameBGLayer();

	/* Destructor
	*/
	~GameBGLayer();

	/* Initialisation
	*/
	bool init();

	void onExit();

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(GameBGLayer);

private:
	/* First background sprite
	*/
	CC_SYNTHESIZE(CCSprite*, bgx1, Bgx1);

	/* Second background sprite
	*/
	CC_SYNTHESIZE(CCSprite*, bgx2, Bgx2);

	/* Background offset for x
	*/
	CC_SYNTHESIZE(float, bgoffsetx, Bgoffsetx);

	/* Background offset for y
	*/
	CC_SYNTHESIZE(float, bgoffsety, Bgoffsety);

	/* Initialise background
	*/
	void initBG();

	/* Background scrolling
	*/
	void scrolling(CCObject *_sender);
};

#endif;