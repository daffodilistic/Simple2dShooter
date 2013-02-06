#ifndef __GAME_OVER_SCENE_H_
#define __GAME_OVER_SCENE_H_

#include "cocos2d.h"
#include "GameOverBgLayer.h"
#include "GameOverBtnLayer.h"


USING_NS_CC;

class GameOverScene : public CCScene
{
public:
	/* Constructor
	*/
	GameOverScene();

	/* Destructor
	*/
	~GameOverScene();

	/* Initialise
	*/
	bool init();

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(GameOverScene);
	
	/* When exiting layer
	*/
	void onExit();
};

#endif