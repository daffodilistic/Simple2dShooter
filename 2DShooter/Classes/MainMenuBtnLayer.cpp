#include "MainMenuBtnLayer.h"

MainMenuBtnLayer::MainMenuBtnLayer()
{
}

MainMenuBtnLayer::~MainMenuBtnLayer()
{
}

bool MainMenuBtnLayer::init()
{
	bool bRet = false;
    do 
	{
		// Super init first
		CC_BREAK_IF(!CCLayer::init());

		CCSize size = CCDirector::sharedDirector()->getWinSize();

		
		CCImage menufile;
		menufile.initWithImageFile("Buttons.png");
		CCTexture2D *menuTexture = new CCTexture2D();
        menuTexture->initWithImage(&menufile);

		CCMenuItemSprite *startgameitem = CCMenuItemSprite::create(CCSprite::createWithTexture(menuTexture, CCRectMake(6, 2, 166, 28)),
																   CCSprite::createWithTexture(menuTexture, CCRectMake(6, 35, 166, 28)),
																   CCSprite::createWithTexture(menuTexture, CCRectMake(6, 70, 166, 28)),
																   this, menu_selector (MainMenuBtnLayer::menucallback));
		startgameitem->setTag(MAINMENU_ID_START);
		CCMenuItemSprite *settings = CCMenuItemSprite::create(CCSprite::createWithTexture(menuTexture, CCRectMake(188, 2, 166, 28)),
																   CCSprite::createWithTexture(menuTexture, CCRectMake(188, 35, 166, 28)),
																   CCSprite::createWithTexture(menuTexture, CCRectMake(188, 70, 166, 28)),
																   this, menu_selector (MainMenuBtnLayer::menucallback));
		settings->setTag(MAINMENU_ID_SETTING);
		CCMenuItemSprite *about = CCMenuItemSprite::create(CCSprite::createWithTexture(menuTexture, CCRectMake(370, 2, 166, 28)),
																   CCSprite::createWithTexture(menuTexture, CCRectMake(370, 35, 166, 28)),
																   CCSprite::createWithTexture(menuTexture, CCRectMake(370, 70, 166, 28)),
																   this, menu_selector (MainMenuBtnLayer::menucallback));
		about->setTag(MAINMENU_ID_ABOUT);
		CCMenuItemSprite *quit = CCMenuItemSprite::create(CCSprite::createWithTexture(menuTexture, CCRectMake(552, 2, 166, 28)),
																   CCSprite::createWithTexture(menuTexture, CCRectMake(552, 35, 166, 28)),
																   CCSprite::createWithTexture(menuTexture, CCRectMake(552, 70, 166, 28)),
																   this, menu_selector (MainMenuBtnLayer::menucallback));
		quit->setTag(MAINMENU_ID_QUIT);
		
		CCMenu *menu = CCMenu::create(startgameitem, settings, about, quit, NULL);
		menu->alignItemsVerticallyWithPadding(10);
		menu->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		this->addChild(menu);
		
		bRet = true;

	} while(0);
	
	return bRet;
}

void MainMenuBtnLayer::menucallback(CCObject *_sender)
{
	CCNode *node = (CCNode*) _sender;
    int tag = node->getTag();
	
	switch (tag)
	{
		case MAINMENU_ID_START: GameManager::SharedGameManager().runSceneWithID(SCENE_ID_PLAY); 
			break;
		case MAINMENU_ID_SETTING: GameManager::SharedGameManager().runSceneWithID(SCENE_ID_SETTINGS); 
			break; 
		case MAINMENU_ID_ABOUT: GameManager::SharedGameManager().runSceneWithID(SCENE_ID_ABOUT); 
			break;
		case MAINMENU_ID_QUIT: GameManager::SharedGameManager().runSceneWithID(SCENE_ID_QUIT); 
			break;
	}
}

