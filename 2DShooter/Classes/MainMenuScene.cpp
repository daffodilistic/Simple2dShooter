#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
}

MainMenuScene::~MainMenuScene()
{
}

bool MainMenuScene::init()
{
	bool bRet = false;

	do 
	{
		// Super init first
		CC_BREAK_IF(!CCScene::init());
		// Add layers here
		this->addChild(MainMenuBGLayer::create(), 0);
		this->addChild(MainMenuBtnLayer::create(), 1);
		bRet = true;
	} while (0);

	return bRet;
}
