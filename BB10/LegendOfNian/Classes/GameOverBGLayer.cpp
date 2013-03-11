#include "GameOverBGLayer.h"

GameOverBGLayer::GameOverBGLayer()
{
}

GameOverBGLayer::~GameOverBGLayer()
{
}

void GameOverBGLayer::onEnter()
{
	CCLayer::onEnter();
	// This enable touches
	this->setTouchEnabled(true);
}

bool GameOverBGLayer::init()
{
	bool bRet = false;

	do
	{
		// Super init first
		CC_BREAK_IF(!CCLayer::init());

		CCSize size = CCDirector::sharedDirector()->getWinSize();
		/*
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("GameOverSheet.plist");

		spritesheet = CCSpriteBatchNode::create("GameOverSheet.png");
		this->addChild(spritesheet, -1);
		*/
		CCSprite *bg = CCSprite::create("background.jpg");
		bg->setAnchorPoint(ccp(0.5f, 0.5f));
		bg->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		this->addChild(bg);

		CCSprite *msg= CCSprite::create("GameOver.png");
		msg->setAnchorPoint(ccp(0.5f, 0.5f));
		msg->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		this->addChild(msg);

		CCSprite *title = CCSprite::create("Title.png");
		title->setAnchorPoint(ccp(0.5f, 0.5f));
		title->setPosition(ccp(size.width * 0.5f, size.height * 0.8f));
		this->addChild(title);
		/*
		CCLabelTTF *replay = CCLabelTTF::create("Do you want to restart?", "Arial", 32.0f, CCSizeMake(350,32), CCTextAlignment::kCCTextAlignmentCenter);
		replay->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		this->addChild(replay);
		*/

		bRet = true;

	} while (0);

	return bRet;
}

void GameOverBGLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	// Play sound and move to next screen
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("menu_start.wav");
	GameManager::SharedGameManager().runSceneWithID(SCENE_ID_MAINMENU, TRANSITION_ID_CROSSFADE, TRANSITION_DURATION); 
}

void GameOverBGLayer::onExit()
{
	this->setTouchEnabled(false);
	this->removeAllChildrenWithCleanup(true);
}