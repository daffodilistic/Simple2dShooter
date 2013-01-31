#ifndef __GAME_OVER_SCENE_H_
#define __GAME_OVER_SCENE_H_

#include "cocos2d.h"
#include "GameOverBgLayer.h"
#include "GameOverBtnLayer.h"


USING_NS_CC;

class GameOverScene : public CCScene
{
public:
	GameOverScene();
	~GameOverScene();
	bool init();
	CREATE_FUNC(GameOverScene);
	void onExit();
};

#endif