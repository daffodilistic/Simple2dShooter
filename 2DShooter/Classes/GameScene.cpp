#include "GameScene.h"
#include "SimpleAudioEngine.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

bool GameScene::init()
{
	bool bRet = false;

	do 
	{
		// Super init first
		CC_BREAK_IF(!CCScene::init());
		// Add layers here

		this->addChild(GameBGLayer::create(), 0);
		
		GameMidLayer *midlayer = GameMidLayer::create();
		GameUILayer *uilayer = GameUILayer::create();
		midlayer->SetUILayer(uilayer);

		this->addChild(midlayer, 1);
		this->addChild(uilayer, 2);

		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("PT_333884_lowres.mp3", true);

		bRet = true;
	} while (0);

	return bRet;
}

void GameScene::onExit()
{
	this->removeAllChildrenWithCleanup(true);
}