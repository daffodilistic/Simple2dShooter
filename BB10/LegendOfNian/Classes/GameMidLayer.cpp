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
		cache->addSpriteFramesWithFile("Dragon.plist");

		CCSpriteBatchNode *spritesheet1 =  CCSpriteBatchNode::create("Dragon.png");
		CCSpriteBatchNode *spr_NianMonster =  CCSpriteBatchNode::create("SPR_Nian.png");
		this->addChild(spritesheet1,1);
		this->addChild(spr_NianMonster,1);

		CCArray* animFrames = CCArray::createWithCapacity(15);
    
		CCArray* animFrames_NianMonster = CCArray::createWithCapacity(2);
    
		CCLog("%s => SpriteBatchNode children count: %i", __FUNCTION__, spr_NianMonster->getChildrenCount());

		for(int i = 0; i < 1; i++)
		{
			// Use exact name as in PLIST file if alias does not exist
			//CCString* str = CCString::createWithFormat("Nian%02d.png", i);
			CCString* str = CCString::createWithFormat("nian.png", i);
			CCSpriteFrame *frame = cache->spriteFrameByName(str->getCString());
			animFrames_NianMonster->addObject(frame);
		}

		CCAnimation *animation_NianMonster = CCAnimation::createWithSpriteFrames(animFrames_NianMonster, 0.3f);
		CCAction *anim2 = CCRepeatForever::create(CCAnimate::create(animation_NianMonster));

		for(int i = 1; i < 15; i++)
		{
			CCString* str = CCString::createWithFormat("Dragon.png", i);
			CCSpriteFrame *frame = cache->spriteFrameByName(str->getCString());
			animFrames->addObject(frame);
		}

		CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames, 0.3f);
		CCAction *anim = CCRepeatForever::create(CCAnimate::create(animation));

		player = Player::create("Dragon.png", spritesheet1, anim);
		player->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
		
		//enemy = Enemy::create("Nian00.png", spr_NianMonster, NULL);
		enemy = Enemy::create("nian.png", spr_NianMonster, NULL);
		this->spawnNewEnemy();
		enemy->setFlipX(true);

		///////////////////////////////////////////////////
		
		this->addChild(BulletPool::SharedBulletPool()->getBspritesheet(), 0);

		//this->scheduleUpdate();
			
		// Init physics

		this->createSpace();

		bRet = true;
	} while (0);

	return bRet;
}

void GameMidLayer::createSpace()
{
/*
	m_pSpace = cpSpaceNew();
	m_pSpace->gravity = cpv(0, -100);

	m_debugNode = CCPhysicsDebugNode::create(m_pSpace);
*/
}

void GameMidLayer::onEnter()
{
	CCLayer::onEnter();
	// This enable touches
	this->setTouchEnabled(true);
}

void GameMidLayer::update(float dt)
{
	// Mechanics update
	BulletPool::SharedBulletPool()->update(dt);
	this->enemy->update(dt);

	// check for last known touch position
	//CCLog("Last known position: %i, %f,%f",istouching, m_lastTouchPosition.x,m_lastTouchPosition.y);
	//CCLog("Player rect
	/*
	if (istouching && player->getRect().containsPoint(m_lastTouchPosition))
	{
		CCLog("%s => should stop");
		player->stopActionByTag(TAGS_ACTION::ACTION_MOVE);
		//player->setV
		
	}
	*/

	// win condition
	if (player->getpoints() >= 10)
	{
		player->setpoints(0);
		GameManager::SharedGameManager().runSceneWithID(SCENE_ID_RESTART, TRANSITION_ID_FADEWHITETRANSITION, TRANSITION_DURATION);
	}
	else
	{
		CCObject *it = NULL;
		CCARRAY_FOREACH(BulletPool::SharedBulletPool()->getBullets(), it)
		{
			Bullet *bullet = (Bullet*) it;
			if (bullet->isVisible())
			{
				// if bullet collides with enemy, add points
				if (enemy->boundingBox().containsPoint(bullet->getPosition()))
				{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Hit.wav");
					player->addPoints();
					// update UI
					UILayer->updatePoints(player->getpoints());
					bullet->setPosition(CCPointZero);
					bullet->setVelo(CCPointZero);
					bullet->setVisible(false);
					if (player->getpoints() < 10)
					{
						this->spawnNewEnemy();
					}
				}
			}
		}

		// If enemy goes off screen, spawn a new one.
		if (enemy->getPositionX() <= 0)
		{
			this->spawnNewEnemy();
		}
	}
}

void GameMidLayer::spawnNewEnemy()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// TODO: Read http://c-faq.com/lib/randrange.html for a fix. Perhaps use a Mersenne-Twister lib?
	//int enemyHeight  = rand() % (int) (enemy->getHeight());
	
	//CCLog("enemy height is %f", enemy->getHeight());

	//int rany = rand() % ((int) (enemy->getHeight()));

	int randX = rand() % 250;

	// __func__ is supposed to be C99 Standard, but as usual, Micro$oft "Changes Everything"
	//CCLog("%s => new random position: %i", __FUNCTION__, rany);

	enemy->stopAllActions();
	enemy->setPosition(ccp(size.width + 150.0f + randX, enemy->getHeight() - enemy->getHeight() / 2));
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
	if (enemy)
	{
		enemy->destroy();
	}
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
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Shoot.wav");
		//Adjust for player mouth position
		CCPoint firePoint = player->getPosition();
		firePoint.x += 55.0f;
		firePoint.y += 65.0f;
		BulletPool::SharedBulletPool()->shoot(firePoint, ccp(1000,0));
	}
	
}

void GameMidLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	//m_lastTouchPosition = touch->getLocation();
	
	if (istouching)
	{
		// basic movement
		
		CCPoint translate = ccpSub(touch->getLocation(),touch->getPreviousLocation());
		CCPoint newPos = ccpAdd(player->getPosition(),translate);
		player->setPosition(newPos);
		
		/*
		//CCRect * touchArea = &CCRectMake(player->boundingBox.getPositionX(), player->boundingBox.getPositionY(), player->getContentSize().width, player->getContentSize().height);
		if (player->getRect().containsPoint(touch->getLocation()) == false)
		{
			CCLog("not inside");
			//player->setMove(touch->getLocation());
		}
		else
		{
			CCLog("inside");
		}
		*/
	}
}

void GameMidLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	CCPoint position = touch->getLocation();

	istouching = false;
	isPressed = false;

	//player->stopActionByTag(TAGS_ACTION::ACTION_MOVE);
}

void GameMidLayer::SetUILayer(GameUILayer *_uilayer)
{
	UILayer = _uilayer;
}


