#include "GameOverBGLayer.h"

GameOverBGLayer::GameOverBGLayer()
{
}

GameOverBGLayer::~GameOverBGLayer()
{
}

bool GameOverBGLayer::init()
{
	bool bRet = false;

	do
	{
		// Super init first
		CC_BREAK_IF(!CCLayer::init());

		CCSize size = CCDirector::sharedDirector()->getWinSize();
		
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GameOverSheet.plist");

		spritesheet = CCSpriteBatchNode::create("GameOverSheet.png");
		this->addChild(spritesheet, -1);

		CCSprite *bg = CCSprite::createWithSpriteFrameName("GameOver.png");
		bg->setAnchorPoint(ccp(0.5f, 0.5f));
		bg->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		spritesheet->addChild(bg);

		CCSprite *title = CCSprite::createWithSpriteFrameName("Title.png");
		title->setAnchorPoint(ccp(0.5f, 0.5f));
		title->setPosition(ccp(size.width * 0.5f, size.height * 0.9f));
		spritesheet->addChild(title);

		CCLabelTTF *replay = CCLabelTTF::create("Do you want to restart?", "Arial", 32.0f, CCSizeMake(350,32), CCTextAlignment::kCCTextAlignmentCenter);
		replay->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		this->addChild(replay);

		bRet = true;

	} while (0);

	return bRet;
}

void GameOverBGLayer::onExit()
{
	this->removeAllChildrenWithCleanup(true);
}