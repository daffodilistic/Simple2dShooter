#include "GameOverBtnLayer.h"

GameOverBtnLayer::GameOverBtnLayer()
{
}

GameOverBtnLayer::~GameOverBtnLayer()
{
}

bool GameOverBtnLayer::init()
{
	bool bRet = false;

	do 
	{
		// Super init first
		CC_BREAK_IF(!CCLayer::init());

		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Restart_buttons.plist");
		
		spritesheet = CCSpriteBatchNode::create("Restart_buttons.png");
		this->addChild(spritesheet, -1);

		CCSprite *buttons[2][2];

		buttons[0][0] = CCSprite::createWithSpriteFrameName("Button_Yes_Normal.png");
		buttons[0][1] = CCSprite::createWithSpriteFrameName("Button_Yes_Selected.png");
		buttons[1][0] = CCSprite::createWithSpriteFrameName("Button_No_Normal.png");
		buttons[1][1] = CCSprite::createWithSpriteFrameName("Button_No_Selected.png");

		CCMenuItemSprite *yesoption = CCMenuItemSprite::create(buttons[0][0], buttons[0][1],
															   this, menu_selector(GameOverBtnLayer::menucallback));
		yesoption->setTag(RESTART_ID_YES);

		CCMenuItemSprite *nooption = CCMenuItemSprite::create(buttons[1][0], buttons[1][1],
															  this, menu_selector(GameOverBtnLayer::menucallback));
		nooption->setTag(RESTART_ID_NO);

		CCMenu *options = CCMenu::create(yesoption, nooption, NULL);
		options->alignItemsHorizontallyWithPadding(10);
		options->setPosition(ccp(size.width * 0.5f, size.height * 0.4f));
		this->addChild(options);
	
		bRet = true;

	} while (0);

	return bRet;
}

void GameOverBtnLayer::menucallback(CCObject *_sender)
{
	CCNode *node = (CCNode*) _sender;
	int tag = node->getTag();

	switch (tag)
	{
		case RESTART_ID_YES: GameManager::SharedGameManager().runSceneWithID(SCENE_ID_PLAY, TRANSITION_ID_FADE, TRANSITION_DURATION);
			break;
		case RESTART_ID_NO: GameManager::SharedGameManager().runSceneWithID(SCENE_ID_MAINMENU, TRANSITION_ID_FADEWHITETRANSITION, TRANSITION_DURATION);
			break;
	}
}

void GameOverBtnLayer::onExit()
{
	this->removeAllChildrenWithCleanup(true);
}