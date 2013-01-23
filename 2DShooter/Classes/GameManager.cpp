#include "GameManager.h"

//static GameManager *instance = NULL;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::init()
{
	currentscene = SCENE_ID_NONE;
}

GameManager& GameManager::SharedGameManager()
{
	static GameManager instance;

	instance.init();

	return instance;
	
	/*
	if (!instance)
	{
		instance = new GameManager();
		instance->init();
	}

	return instance;
	*/
}

void GameManager::runSceneWithID(SCENE_ID _sceneID)
{
	SCENE_ID oldSceneID = currentscene;
	currentscene = _sceneID;
	
	CCScene *sceneToRun = NULL;

	switch(currentscene)
	{
		case SCENE_ID_MAINMENU: sceneToRun =  MainMenuScene::create(); 
			break;
		case SCENE_ID_PLAY:  sceneToRun = GameScene::create();
			break;
		case SCENE_ID_SETTINGS:
			break;
		case SCENE_ID_ABOUT:
			break;
		case SCENE_ID_RESULTS:
			break;
		case SCENE_ID_QUIT:  CCDirector::sharedDirector()->end();
			break;
		default: CCLOG("Unknown");
			break;
	}

	if (!sceneToRun)
	{
		currentscene = oldSceneID;
		return;
	}

	// Check if it is the first running scene
	if (!CCDirector::sharedDirector()->getRunningScene()) 
	{
        CCDirector::sharedDirector()->runWithScene(sceneToRun);
    }
    else 
	{
        CCDirector::sharedDirector()->replaceScene(sceneToRun);
    }
}