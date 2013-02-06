#include "GameMidLayer.h"

GameMidLayer::GameMidLayer()
: player(NULL),
  istouching(false),
  isPressed(false),
  UILayer(NULL),
  enemy(NULL)
{
}

GameMidLayer::~GameMidLayer()
{
}

bool GameMidLayer::init()
{
	bool bRet = false;

	do 
	{
		// Super init first
		CC_BREAK_IF(!CCLayer::init());
		// Add layers here
		
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		cache->addSpriteFramesWithFile("grossini-aliases.plist");
		
		CCSpriteBatchNode *spritesheet1 =  CCSpriteBatchNode::create("grossini-aliases.png");
		this->addChild(spritesheet1,1);

		CCArray* animFrames = CCArray::createWithCapacity(15);
    
		for(int i = 1; i < 15; i++)
		{
			CCString* str = CCString::createWithFormat("dance_%02d", i);
			CCSpriteFrame *frame = cache->spriteFrameByName(str->getCString());
			animFrames->addObject(frame);
		}

		CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames, 0.3f);
		CCAction *anim = CCRepeatForever::create(CCAnimate::create(animation));

		player = Player::create("grossini_dance_01.png", spritesheet1, anim);
		player->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		
		enemy = Enemy::create("grossini_dance_03.png", spritesheet1, NULL);
		enemy->setPosition(ccp(size.width + 50.0f, size.height * 0.5f));
		
		///////////////////////////////////////////////////
		
		this->addChild(BulletPool::SharedBulletPool()->getBspritesheet(), 0);

		//this->scheduleUpdate();
			
		bRet = true;
	} while (0);

	return bRet;
}

void GameMidLayer::onEnter()
{
	CCLayer::onEnter();
	// This enable touches
	this->setTouchEnabled(true);
}

void GameMidLayer::update(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	BulletPool::SharedBulletPool()->update(dt);
	this->enemy->update(dt);

	int rany = rand() % (int)(size.height - enemy->getContentSize().height) + (0 + enemy->getContentSize().height);
	CCObject *it = NULL;
	CCARRAY_FOREACH(BulletPool::SharedBulletPool()->getBullets(), it)
	{
		Bullet *bullet = (Bullet*) it;
		if (bullet->isVisible())
		{
			if (enemy->boundingBox().containsPoint(bullet->getPosition()))
			{
				player->addPoints();
				bullet->setPosition(CCPointZero);
				bullet->setVelo(CCPointZero);
				bullet->setVisible(false);
				enemy->stopAllActions();
				enemy->setPosition(ccp(size.width + 50.0f, rany));
				enemy->startaction();
			}
		}
	}

	if (enemy->getPositionX() <= 0)
	{
		enemy->stopAllActions();
		enemy->setPosition(ccp(size.width + 50.0f, rany));
		enemy->startaction();
	}

	if (player->getpoints() >= 5)
	{
		player->setpoints(0);
		GameManager::SharedGameManager().runSceneWithID(SCENE_ID_RESTART, TRANSITION_ID_FADEWHITETRANSITION, TRANSITION_DURATION);
	}
}

void GameMidLayer::onEnterTransitionDidFinish()
{
	CCLayer::onEnterTransitionDidFinish();

	this->scheduleUpdate();
}

void GameMidLayer::onExit()
{
	BulletPool::SharedBulletPool()->destroy();
	player->destroy();
	//enemy->destroy();
	//CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
	this->removeAllChildrenWithCleanup(true);
	CCLayer::onExit();
}

void GameMidLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	CCPoint position = touch->getLocation();
	
	istouching = true;

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	if (UILayer->getBtn()->boundingBox().containsPoint(position))
	{
		istouching = false;
		isPressed = true;
		BulletPool::SharedBulletPool()->shoot(player->getPosition(), ccp(1000,0));
	}
}

void GameMidLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	CCPoint position = touch->getLocation();
	
	if (istouching)
	{
		player->setMove(position);
	}
}

void GameMidLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	CCPoint position = touch->getLocation();

	istouching = false;
	isPressed = false;
}

void GameMidLayer::SetUILayer(GameUILayer *_uilayer)
{
	UILayer = _uilayer;
}


