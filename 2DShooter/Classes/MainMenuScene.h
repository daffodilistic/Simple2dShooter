#ifndef __MAINMENU_SCENE_H_
#define __MAINMENU_SCENE_H_

#include "cocos2d.h"
#include "MainMenuBGLayer.h"
#include "MainMenuBtnLayer.h"

USING_NS_CC;

class MainMenuScene : public CCScene
{
public:
	/* Constructor
	*/
	MainMenuScene();

	/* Destructor
	*/
	~MainMenuScene();

	/* Initialise
	*/
	bool init();

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(MainMenuScene);
};

#endif