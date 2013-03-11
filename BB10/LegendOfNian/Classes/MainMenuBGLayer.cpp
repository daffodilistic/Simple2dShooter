#include "SimpleAudioEngine.h"
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
		CCSprite *bg = CCSprite::create("BG_MainMenu.jpg");
		//bg->setScaleX(size.width / bg->getContentSize().width);
		//bg->setScaleY(size.height/ bg->getContentSize().height);
		bg->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		this->addChild(bg);
		
		/*
		CCSprite *logo = CCSprite::create("Logo.png");
		logo->setAnchorPoint(ccp(0.5f,0.5f));
		logo->setPosition(ccp(size.width * 0.5f,size.height * 0.9f));
		this->addChild(logo);
		*/

		// Preload this so that there's no lag
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("menu_start.wav");
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("WolframTones.mp3");

		//  - See more at: http://www.cocos2d-x.org/boards/6/topics/11382#sthash.Tt1PY4uK.dpuf
		CocosDenshion::SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
		CocosDenshion::SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);

		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("WolframTones.mp3", true);

		bRet = true;
	} while (0);

	return bRet;
}

void MainMenuBGLayer::onEnter()
{
	CCLayer::onEnter();
	// This enable touches
	this->setTouchEnabled(true);
}

void MainMenuBGLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	// Play sound and move to next screen
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("menu_start.wav");
	GameManager::SharedGameManager().runSceneWithID(SCENE_ID_PLAY, TRANSITION_ID_CROSSFADE, TRANSITION_DURATION); 
}

void MainMenuBGLayer::onExit()
{
	this->setTouchEnabled(false);
	this->removeAllChildrenWithCleanup(true);
}

