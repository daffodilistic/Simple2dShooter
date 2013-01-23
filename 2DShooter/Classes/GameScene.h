#ifndef __GAME_SCENE_H_
#define __GAME_SCENE_H_

#include "cocos2d.h"
#include "GameBGLayer.h"
#include "GameUILayer.h"
#include "GameMidLayer.h"

USING_NS_CC;

class GameScene : public CCScene
{
public:
	GameScene();
	~GameScene();
	bool init();
	CREATE_FUNC(GameScene);
};

#endif;