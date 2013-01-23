#ifndef __GAME_MID_LAYER_H_
#define __GAME_MID_LAYER_H_

#include "cocos2d.h"
#include "Player.h"
#include "GameUILayer.h"
#include "BulletPool.h"

USING_NS_CC;

class GameMidLayer : public CCLayer
{
public:
	GameMidLayer();
	~GameMidLayer();
	bool init();
	void onEnter();
	void update(float dt);
	void onExit();
	void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	void SetUILayer(GameUILayer *_uilayer);

	CREATE_FUNC(GameMidLayer);

private:
	CC_SYNTHESIZE (Player*, player, player);
	CC_SYNTHESIZE(bool, istouching, istouching);
	CC_SYNTHESIZE(GameUILayer*, UILayer, UILayer);
	CC_SYNTHESIZE(bool, isPressed, isPressed);
};	

#endif;