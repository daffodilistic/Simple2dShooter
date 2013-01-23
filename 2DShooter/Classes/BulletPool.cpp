#include "BulletPool.h"


static BulletPool* instance = NULL;

BulletPool::BulletPool()
	:bspritesheet(NULL),
	next(0),
	bullets(NULL)
{
}

BulletPool::~BulletPool()
{
}

bool BulletPool::init()
{
	bool bRet = false;
    
    do {
		bullets = CCArray::createWithCapacity(MAX_SIZE);
		bullets->retain();
		CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		cache->addSpriteFramesWithFile("bullet.plist");

		bspritesheet =  CCSpriteBatchNode::create("bullet.png");

		for (int i = 0; i < MAX_SIZE; i ++)
		{
			Bullet *bullet = Bullet::create("W1.png", bspritesheet, NULL);
			bullet->setVisible(false);
			bullet->setRotation(90.0f);
			bullets->addObject(bullet);
		}

		next = 0;

		bRet = true;
	} while (0);
	
	return bRet;

}

BulletPool* BulletPool::SharedBulletPool()
{
	if (!instance)
	{
		instance = new BulletPool();
		if (!instance->init())
		{
			CCAssert(0, "Failed");
		}
	}

	return instance;
}

void BulletPool::destroy()
{
	bullets->release();
	instance = NULL;
	delete instance;
}

void BulletPool::shoot(CCPoint _pos, CCPoint _velo, int _life)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	/*
	CCArray *bullets = bspritesheet->getChildren();
    CCObject *object = bullets->objectAtIndex(next);
    Bullet *bullet = (Bullet*) object;

	bullet->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
	bullet->setVelo(_velo);
	bullet->setVisible(true);

	CCLog("posx: %f , posy: %f", _pos.x, _pos.y);
	CCLog("next: %i", next);
	CCLog("count: %i", bspritesheet->getChildrenCount());

	++ next;

	if (next >= bspritesheet->getChildrenCount())
	{
        next = 0;
    }
	*/
}

void BulletPool::shoot(CCPoint _pos, CCPoint _velo)
{
	Bullet *bullet = (Bullet*) bullets->objectAtIndex(next);

	bullet->setPosition(_pos);
	bullet->setVelo(_velo);
	bullet->setVisible(true);

	++ next;

	if (next >= MAX_SIZE)
	{
		next = 0;
	}
}

void BulletPool::update(float dt)
{
    CCObject *object = NULL;
    
    CCARRAY_FOREACH(bullets, object)
    {
        Bullet *bullet = (Bullet*) object;
        bullet->update(dt);
    }
}

