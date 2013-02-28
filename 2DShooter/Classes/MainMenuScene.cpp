#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

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
		//this->addChild(MainMenuBtnLayer::create(), 1);

		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("PT_335090_lowres.mp3", true);

		bRet = true;
	} while (0);

	return bRet;
}

void MainMenuScene::onExit()
{
	this->removeAllChildrenWithCleanup(true);
}
