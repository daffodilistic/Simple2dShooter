#include "MainMenuBGLayer.h"

MainMenuBGLayer::MainMenuBGLayer()
{
}

MainMenuBGLayer::~MainMenuBGLayer()
{
};

bool MainMenuBGLayer::init()
{
    bool bRet = false;
    do 
	{
		// Super init first
		CC_BREAK_IF(!CCLayer::init());

		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// Background image
		CCSprite *bg = CCSprite::create("Background.jpg");
		bg->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		this->addChild(bg);

		CCSprite *logo = CCSprite::create("Logo.png");
		logo->setAnchorPoint(ccp(0.5f,0.5f));
		logo->setPosition(ccp(size.width * 0.5f,size.height * 0.9f));
		this->addChild(logo);

		bRet = true;
	} while (0);

	return bRet;
}

void MainMenuBGLayer::onExit()
{
	this->removeAllChildrenWithCleanup(true);
}

