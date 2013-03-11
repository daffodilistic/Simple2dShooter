#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_

#include "cocos2d.h"
#include "Constants.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "GameOverScene.h"

USING_NS_CC;

class GameManager
{
public:
	/* Singleton
	*/
	static GameManager& SharedGameManager();

	/* Run specific scene using ID
	  @param _sceneID: scene ID of current scene
	*/
	void runSceneWithID(SCENE_ID _sceneID);

	void runSceneWithID(SCENE_ID _sceneID, TRANSITION_ID _tranID, int _time);

	CCTransitionScene* createTransition(TRANSITION_ID _tranID, int _time, CCScene *_scene);

	/* Current scene ID
	*/
	CC_SYNTHESIZE_READONLY(SCENE_ID, currentscene, CurrentScene);
private:
	/* Constructor
	*/
	GameManager();
	
	/* Destructor
	*/
	~GameManager();
	
	/* Make sure they are unaccessable otherwise may accidentally
	   get copies of the singleton appearing
	*/
	GameManager(GameManager const&);    // Don't Implement
    void operator=(GameManager const&); // Don't implement

	/* Initialise game manager
	*/
	void init();
};

#endif