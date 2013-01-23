#include "GameBGLayer.h"

GameBGLayer::GameBGLayer()
{
}

GameBGLayer::~GameBGLayer()
{
}

bool GameBGLayer::init()
{
	bool bRet = false;

	do 
	{
		// Super init first
		CC_BREAK_IF(!CCLayer::init());
			
		initBG();
		scrolling(bgx1);
		scrolling(bgx2);

		bRet = true;
	} while (0);

	return bRet;
}

void GameBGLayer::initBG()
{
	 CCSize size = CCDirector::sharedDirector()->getWinSize();

	// First background
	bgx1 = CCSprite::create("GameBG.png");
	bgx1->setAnchorPoint(ccp(0.5f, 0.5f));
	bgx1->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));

	// Offsets
	bgoffsetx = (size.width * 1.5f) - 1.0f; 
	bgoffsety = (size.height * 1.5f) - 1.0f;

	// Second background
	bgx2 = CCSprite::createWithTexture(bgx1->getTexture());
	bgx2->setAnchorPoint(ccp(0.5f, 0.5f));
	bgx2->setPosition(ccp(bgoffsetx, size.height * 0.5f)); 

	this->addChild(bgx1, 0);
	this->addChild(bgx2, 0);
}

void GameBGLayer::scrolling(CCObject *_sender)
{
	CCAction *scrollAction = NULL;
	CCNode *node = (CCNode*) _sender;
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	if (node->getPositionX() <= -(size.width * 0.5f) )
	{
		node->setPosition(ccp(bgoffsetx, node->getPositionY()));
	}

	scrollAction = CCSequence::create(CCMoveBy::create(15.0f, ccp(-(size.width * 0.5f), 0)), 
									   CCCallFuncO::create(this, callfuncO_selector(GameBGLayer::scrolling),_sender),
									   NULL);

	if (scrollAction)
	{
		node->runAction(scrollAction);
	}
}