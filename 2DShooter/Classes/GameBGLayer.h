#ifndef __GAME_BG_LAYER_H_
#define __GAME_BG_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class GameBGLayer : public CCLayer
{
public:
	GameBGLayer();
	~GameBGLayer();
	bool init();
	CREATE_FUNC(GameBGLayer);

private:
	CCSprite *bgx1; 
	CCSprite *bgx2; 
	float bgoffsetx;
	float bgoffsety;
	void initBG();
	void scrolling(CCObject *_sender);
};

#endif;