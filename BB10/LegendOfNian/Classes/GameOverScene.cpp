#include "GameOverScene.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

bool GameOverScene::init()
{
	bool bRet = false;

	do
	{
		// Super init first
		CC_BREAK_IF(!CCScene::init());
		// Add layers here
		this->addChild(GameOverBGLayer::create(), 0);
		//this->addChild(GameOverBtnLayer::create(), 1);

		bRet = true;
	} while (0);

	return bRet;
}

void GameOverScene::onExit()
{
	this->removeAllChildrenWithCleanup(true);
}