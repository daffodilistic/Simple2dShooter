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
		cache->addSpriteFramesWithFile("SPR_Nian.plist");
		cache->addSpriteFramesWithFile("grossini-aliases.plist");

		CCSpriteBatchNode *spritesheet1 =  CCSpriteBatchNode::create("grossini-aliases.png");
		CCSpriteBatchNode *spr_NianMonster =  CCSpriteBatchNode::create("SPR_Nian.png");
		this->addChild(spritesheet1,1);
		this->addChild(spr_NianMonster,1);

		CCArray* animFrames = CCArray::createWithCapacity(15);
    
		CCArray* animFrames_NianMonster = CCArray::createWithCapacity(2);
    
		CCLog("%s => SpriteBatchNode children count: %i", __FUNCTION__, spr_NianMonster->getChildrenCount());

		for(int i = 0; i < 1; i++)
		{
			// Use exact name as in PLIST file if alias does not exist
			CCString* str = CCString::createWithFormat("Nian%02d.png", i);
			CCSpriteFrame *frame = cache->spriteFrameByName(str->getCString());
			animFrames_NianMonster->addObject(frame);
		}

		CCAnimation *animation_NianMonster = CCAnimation::createWithSpriteFrames(animFrames_NianMonster, 0.3f);
		CCAction *anim2 = CCRepeatForever::create(CCAnimate::create(animation_NianMonster));

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
		
		enemy = Enemy::create("Nian00.png", spr_NianMonster, NULL);
		enemy->setPosition(ccp(size.width + 50.0f, enemy->getHeight()));
		enemy->setFlipX(true);

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
	BulletPool::SharedBulletPool()->update(dt);
	this->enemy->update(dt);
	
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
				this->spawnNewEnemy();
			}
		}
	}

	// If enemy goes off screen, spawn a new one.
	if (enemy->getPositionX() <= 0)
	{
		this->spawnNewEnemy();
	}

	if (player->getpoints() >= 5)
	{
		player->setpoints(0);
		GameManager::SharedGameManager().runSceneWithID(SCENE_ID_RESTART, TRANSITION_ID_FADEWHITETRANSITION, TRANSITION_DURATION);
	}
}

void GameMidLayer::spawnNewEnemy()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// TODO: Read http://c-faq.com/lib/randrange.html for a fix. Perhaps use a Mersenne-Twister lib?
	//int enemyHeight  = rand() % (int) (enemy->getHeight());
	
	//CCLog("enemy height is %f", enemy->getHeight());

	int rany = rand() % ((int) (enemy->getHeight()));

	// __func__ is supposed to be C99 Standard, but as usual, Micro$oft "Changes Everything"
	CCLog("%s => new random position: %i", __FUNCTION__, rany);

	enemy->stopAllActions();
	enemy->setPosition(ccp(size.width + 50.0f, rany));
	enemy->startaction();
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


