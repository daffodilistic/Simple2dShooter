#ifndef __GAME_MID_LAYER_H_
#define __GAME_MID_LAYER_H_

#include "cocos2d.h"
#include "Player.h"
#include "GameUILayer.h"
#include "BulletPool.h"
#include "Enemy.h"

USING_NS_CC;

class GameMidLayer : public CCLayer
{
public:
	/* Constructor
	*/
	GameMidLayer();

	/* Destructor
	*/
	~GameMidLayer();

	/* Initialise layer
	*/
	bool init();

	/* When layer is added
	*/
	void onEnter();

	/* Updates
	   @param dt: delta time
	*/
	void update(float dt);

	/* When layer is removed
	*/
	void onExit();

	/* On touch begin events
	   @param pTouches: get user touches
	   @param pEvent: get type of event
	*/
	void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	/* On touch moved events
	   @param pTouches: get user touches
	   @param pEvent: get type of event
	*/
	void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	/* On touch end events
	   @param pTouches: get user touches
	   @param pEvent: get type of event
	*/
	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	
	/* Set local uilayer to global uilayer
	   @param _uilayer: assigns local to global uilayer
	*/
	void SetUILayer(GameUILayer *_uilayer);

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(GameMidLayer);

private:
	/* Player (user)
	*/
	CC_SYNTHESIZE (Player*, player, player);

	/* Boolean to check if button is pressed
	*/
	CC_SYNTHESIZE(bool, istouching, istouching);
	
	/* Boolean to check if button is pressed
	*/
	CC_SYNTHESIZE(bool, isPressed, isPressed);

	/* Single enemy (for now)
	*/
	CC_SYNTHESIZE(Enemy*, enemy, enemy);

	/* Local uilayer
	*/
	CC_SYNTHESIZE(GameUILayer*, UILayer, UILayer);

};	

#endif;