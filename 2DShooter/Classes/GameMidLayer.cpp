#include "GameMidLayer.h"

GameMidLayer::GameMidLayer()
: player(NULL),
  istouching(false),
  isPressed(false),
  UILayer(NULL)
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
		
		///////////////////////////////////////////////////
		
		this->addChild(BulletPool::SharedBulletPool()->getBspritesheet(), 0);

		this->scheduleUpdate();

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
}

void GameMidLayer::onExit()
{
	BulletPool::SharedBulletPool()->destroy();
	player->destroy();
	CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
	CCLayer::onExit();
}

void GameMidLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)pTouches->anyObject();
	CCPoint position = touch->getLocation();
	
	istouching = true;
	//player->setMove(position);
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	if (UILayer->btn->boundingBox().containsPoint(position))
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
		//player->setPosition(position);
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


