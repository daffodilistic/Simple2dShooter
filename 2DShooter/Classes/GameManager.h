#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_

#include "cocos2d.h"
#include "Constants.h"
#include "MainMenuScene.h"
#include "GameScene.h"

USING_NS_CC;

class GameManager
{
public:
	static GameManager& SharedGameManager();
	void runSceneWithID(SCENE_ID _sceneID);
	CC_SYNTHESIZE_READONLY(SCENE_ID, currentscene, CurrentScene);
private:
	GameManager();
	~GameManager();
	GameManager(GameManager const&);    // Don't Implement
    void operator=(GameManager const&); // Don't implement
	void init();
};

#endif