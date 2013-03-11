#ifndef __GAME_MID_LAYER_H_
#define __GAME_MID_LAYER_H_

//#include "chipmunk.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

#include "GameManager.h"
#include "GameUILayer.h"
#include "Player.h"
#include "BulletPool.h"
#include "Enemy.h"


USING_NS_CC_EXT;

#define TRANSITION_DURATION 1.2f 

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

	/* Init chipmunk world space
	*/
	void createSpace();

	/* When layer is added
	*/
	void onEnter();

	/* Updates
	   @param dt: delta time
	*/
	void update(float dt);

	void onEnterTransitionDidFinish();

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

	/* Spawns a new enemy
	*/
	void spawnNewEnemy();

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(GameMidLayer);

private:
	/* Player (user)
	*/
	CC_SYNTHESIZE(Player*, player, player);

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

	/* Chipmunk stuff
	
	CC_SYNTHESIZE(cpSpace*, m_pSpace, m_pSpace);
	CC_SYNTHESIZE(CCPhysicsDebugNode*, m_debugNode, m_debugNode);
	//CCPhysicsDebugNode* m_debugNode;

	//CC_SYNTHESIZE(CCPoint, m_lastTouchPosition, m_lastTouchPosition);
	*/
};	

#endif;