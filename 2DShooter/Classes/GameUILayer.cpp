#include "GameUILayer.h"

GameUILayer::GameUILayer()
	:btn(NULL)
{
}

GameUILayer::~GameUILayer()
{
}

bool GameUILayer::init()
{
	bool bRet = false;

	do 
	{
		// Super init first
		CC_BREAK_IF(!CCLayer::init());
		
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		//UI button for shooting
		btn = CCSprite::create("UIButton.png");
		btn->setPosition(ccp(size.width*0.9f, size.height*0.1f));
		this->addChild(btn);

		bRet = true;
	} while (0);

	return bRet;
}

void GameUILayer::onExit()
{
	this->removeAllChildrenWithCleanup(true);
}