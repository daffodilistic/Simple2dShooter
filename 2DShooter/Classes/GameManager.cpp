#include "GameManager.h"

//static GameManager *instance = NULL;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::init()
{
	currentscene = SCENE_ID_NONE;
}

GameManager& GameManager::SharedGameManager()
{
	static GameManager instance;

	instance.init();

	return instance;
	
	/*
	if (!instance)
	{
		instance = new GameManager();
		instance->init();
	}

	return instance;
	*/
}

void GameManager::runSceneWithID(SCENE_ID _sceneID)
{
	SCENE_ID oldSceneID = currentscene;
	currentscene = _sceneID;
	
	CCScene *sceneToRun = NULL;

	switch(currentscene)
	{
		case SCENE_ID_MAINMENU: sceneToRun =  MainMenuScene::create(); 
			break;
		case SCENE_ID_PLAY:  sceneToRun = GameScene::create();
			break;
		case SCENE_ID_SETTINGS:
			break;
		case SCENE_ID_ABOUT:
			break;
		case SCENE_ID_RESULTS:
			break;
		case SCENE_ID_RESTART: sceneToRun = GameOverScene::create();
			break;
		case SCENE_ID_QUIT: CCDirector::sharedDirector()->end();
			break;
		default: CCLOG("Unknown");
			break;
	}

	if (!sceneToRun)
	{
		currentscene = oldSceneID;
		return;
	}

	// Check if it is the first running scene
	if (!CCDirector::sharedDirector()->getRunningScene()) 
	{
        CCDirector::sharedDirector()->runWithScene(sceneToRun);
    }
    else 
	{
        CCDirector::sharedDirector()->replaceScene(sceneToRun);
    }
}

void GameManager::runSceneWithID(SCENE_ID _sceneID, TRANSITION_ID _tranID, int _time)
{
	SCENE_ID oldSceneID = currentscene;
	currentscene = _sceneID;
	
	CCScene *sceneToRun = NULL;
	CCScene *sceneToRunwt = NULL;

	switch(currentscene)
	{
		case SCENE_ID_MAINMENU: sceneToRun =  MainMenuScene::create(); 
			break;
		case SCENE_ID_PLAY:  sceneToRun = GameScene::create();
			break;
		case SCENE_ID_SETTINGS:
			break;
		case SCENE_ID_ABOUT:
			break;
		case SCENE_ID_RESULTS:
			break;
		case SCENE_ID_RESTART: sceneToRun = GameOverScene::create();
			break;
		case SCENE_ID_QUIT: CCSpriteFrameCache::sharedSpriteFrameCache()->purgeSharedSpriteFrameCache();
							CCDirector::sharedDirector()->end(); 	
			break;
		default: CCLOG("Unknown");
			break;
	}
	
	if (!sceneToRun)
	{
		currentscene = oldSceneID;
		return;
	}
	else
	{
		sceneToRunwt = GameManager::createTransition(_tranID, _time, sceneToRun);
	}

	// Check if it is the first running scene
	if (!CCDirector::sharedDirector()->getRunningScene()) 
	{
        CCDirector::sharedDirector()->runWithScene(sceneToRunwt);
    }
	else
	{
		CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
        CCDirector::sharedDirector()->replaceScene(sceneToRunwt);
    }
}

class FadeWhiteTransition : public CCTransitionFade 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionFade::create(t, s, ccWHITE); 
    }
};

class FlipXLeftOver : public CCTransitionFlipX 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionFlipX::create(t, s, kCCTransitionOrientationLeftOver);
    }
};

class FlipXRightOver : public CCTransitionFlipX 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionFlipX::create(t, s, kCCTransitionOrientationRightOver);
    }
};

class FlipYUpOver : public CCTransitionFlipY 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionFlipY::create(t, s, kCCTransitionOrientationUpOver); 
    }
};

class FlipYDownOver : public CCTransitionFlipY 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionFlipY::create(t, s, kCCTransitionOrientationDownOver); 
    }
};

class FlipAngularLeftOver : public CCTransitionFlipAngular 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionFlipAngular::create(t, s, kCCTransitionOrientationLeftOver); 
    }
};

class FlipAngularRightOver : public CCTransitionFlipAngular 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionFlipAngular::create(t, s, kCCTransitionOrientationRightOver);
    }
};

class ZoomFlipXLeftOver : public CCTransitionZoomFlipX 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionZoomFlipX::create(t, s, kCCTransitionOrientationLeftOver); 
    }
};

class ZoomFlipXRightOver : public CCTransitionZoomFlipX 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionZoomFlipX::create(t, s, kCCTransitionOrientationRightOver);
    }
};

class ZoomFlipYUpOver : public CCTransitionZoomFlipY 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionZoomFlipY::create(t, s, kCCTransitionOrientationUpOver); 

    }
};

class ZoomFlipYDownOver : public CCTransitionZoomFlipY 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionZoomFlipY::create(t, s, kCCTransitionOrientationDownOver); 
    }
};

class ZoomFlipAngularLeftOver : public CCTransitionZoomFlipAngular 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionZoomFlipAngular::create(t, s, kCCTransitionOrientationLeftOver); 
    }
};

class ZoomFlipAngularRightOver : public CCTransitionZoomFlipAngular 
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        return CCTransitionZoomFlipAngular::create(t, s, kCCTransitionOrientationRightOver);
    }
};

class PageTransitionForward : public CCTransitionPageTurn
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        CCDirector::sharedDirector()->setDepthTest(true);
        return CCTransitionPageTurn::create(t, s, false);
    }
};

class PageTransitionBackward : public CCTransitionPageTurn
{
public:
    static CCTransitionScene* create(float t, CCScene* s)
    {
        CCDirector::sharedDirector()->setDepthTest(true);
        return CCTransitionPageTurn::create(t, s, true);
    }
};


CCTransitionScene* GameManager::createTransition(TRANSITION_ID _tranID, int _time, CCScene *_scene)
{
	 CCDirector::sharedDirector()->setDepthTest(false);

	 switch (_tranID)
	 {
		case TRANSITION_ID_JUMPZOOM: return CCTransitionJumpZoom::create(_time, _scene); 
			 break;
		case TRANSITION_ID_PROGRESSRADIALCCW: return CCTransitionProgressRadialCCW::create(_time, _scene);
			 break;
		case TRANSITION_ID_PROGRESSRADIALCW: return CCTransitionProgressRadialCW::create(_time, _scene);
			break;
		case TRANSITION_ID_HORIZONTAL: return CCTransitionProgressHorizontal::create(_time, _scene);
			break;
		case TRANSITION_ID_VERTICAL: return CCTransitionProgressVertical::create(_time, _scene);
			break;
		case TRANSITION_ID_INOUT: return CCTransitionProgressInOut::create(_time, _scene);
			break;
		case TRANSITION_ID_OUTIN: return CCTransitionProgressOutIn::create(_time, _scene);
			break;
		case TRANSITION_ID_CROSSFADE: return CCTransitionCrossFade::create(_time, _scene);
			break;
		case TRANSITION_ID_PAGETRANSITIONFORWARD: return PageTransitionForward::create(_time, _scene);
			break;
		case TRANSITION_ID_PAGETRANSITIONBACKWARD:  return PageTransitionBackward::create(_time, _scene);
			break;
		case TRANSITION_ID_FADETR: return CCTransitionFadeTR::create(_time, _scene);
			break;
		case TRANSITION_ID_FADEBL: return CCTransitionFadeBL::create(_time, _scene);
			break;
		case TRANSITION_ID_FADEUP: return CCTransitionFadeUp::create(_time, _scene);
			break;
		case TRANSITION_ID_FADEDOWN: return CCTransitionFadeDown::create(_time, _scene);
			break;
		case TRANSITION_ID_TURNOFFTILES: return CCTransitionTurnOffTiles::create(_time, _scene);
			break;
		case TRANSITION_ID_SPLITROWS: return CCTransitionSplitRows::create(_time, _scene);
			break;
		case TRANSITION_ID_SPLITCOLS: return CCTransitionSplitCols::create(_time, _scene);
			break;
		case TRANSITION_ID_FADE: return CCTransitionFade::create(_time, _scene);
			break;
		case TRANSITION_ID_FADEWHITETRANSITION: return FadeWhiteTransition::create(_time, _scene);
			break;
		case TRANSITION_ID_FLIPXLEFTOVER: return FlipXLeftOver::create(_time, _scene);
			break;	
		case TRANSITION_ID_FLIPXRIGHTOVER: return FlipXRightOver::create(_time, _scene);
			break;	 
		case TRANSITION_ID_FLIPYUPOVER: return FlipYUpOver::create(_time, _scene);
			break;	 
		case TRANSITION_ID_FLIPYDOWNOVER: return FlipYDownOver::create(_time, _scene);
			break;	 
		case TRANSITION_ID_FLIPANGULARLEFTOVER: return FlipAngularLeftOver::create(_time, _scene); 
			break; 
		case TRANSITION_ID_FLIPANGULARRIGHTOVER: FlipAngularRightOver::create(_time, _scene);
			break;	 
		case TRANSITION_ID_ZOOMFLIPXLEFTOVER: return ZoomFlipXLeftOver::create(_time, _scene);
			break;	 
		case TRANSITION_ID_ZOOMFLIPXRIGHTOVER: return ZoomFlipXRightOver::create(_time, _scene);
			break;
		case TRANSITION_ID_ZOOMFLIPYUPOVER: return ZoomFlipYUpOver::create(_time, _scene);
			break;
		case TRANSITION_ID_ZOOMFLIPYDOWNOVER: return ZoomFlipYDownOver::create(_time, _scene);
			break;
		case TRANSITION_ID_ZOOMFLIPANGULARLEFTOVER: return ZoomFlipAngularLeftOver::create(_time, _scene);
			break;
		case TRANSITION_ID_ZOOMFLIPANGULARRIGHTOVER: return ZoomFlipAngularRightOver::create(_time, _scene);
			break;
		case TRANSITION_ID_SHRINKGROW: return CCTransitionShrinkGrow::create(_time, _scene);
			break;
		case TRANSITION_ID_ROTOZOOM: return CCTransitionRotoZoom::create(_time, _scene);
			break;
		case TRANSITION_ID_MOVEINL: return CCTransitionMoveInL::create(_time, _scene);
			break;
		case TRANSITION_ID_MOVEINR: return CCTransitionMoveInR::create(_time, _scene);
			break;
		case TRANSITION_ID_MOVEINT: return CCTransitionMoveInT::create(_time, _scene);
			break;
		case TRANSITION_ID_MOVEINB: return CCTransitionMoveInB::create(_time, _scene);
			break;
		case TRANSITION_ID_SLIDEINL: return CCTransitionSlideInL::create(_time, _scene);
			break;
		case TRANSITION_ID_SLIDEINR: return CCTransitionSlideInR::create(_time, _scene);
			break;
		case TRANSITION_ID_SLIDEINT: return CCTransitionSlideInT::create(_time, _scene);
			break;
		case TRANSITION_ID_SLIDEINB: return CCTransitionSlideInB::create(_time, _scene);
			break;
	 }
}