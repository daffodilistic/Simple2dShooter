#ifndef __GAME_UI_LAYER_H_
#define __GAME_UI_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class GameUILayer : public CCLayer
{
public:
	GameUILayer();
	~GameUILayer();
	bool init();
	CREATE_FUNC(GameUILayer);

	CCSprite *btn;
};

#endif;