#ifndef __GAME_OVER_BG_LAYER_H_
#define __GAME_OVER_BG_LAYER_H_

#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

class GameOverBGLayer : public CCLayer
{
public:
	GameOverBGLayer();
	~GameOverBGLayer();
	bool init();
	void onExit();
	CREATE_FUNC(GameOverBGLayer);
private:
	CC_SYNTHESIZE_READONLY(CCSpriteBatchNode*, spritesheet, spritesheet);
};

#endif