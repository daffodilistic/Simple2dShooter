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
	GameOverBtnLayer();
	~GameOverBtnLayer();
	bool init();
	void onExit();
	void menucallback(CCObject *_object);
	CREATE_FUNC(GameOverBtnLayer);
private:
	CC_SYNTHESIZE_READONLY(CCSpriteBatchNode*, spritesheet, spritesheet);
};

#endif