#ifndef __BULLET_POOL_H_
#define __BULLET_POOL_H_

#include "cocos2d.h"
#include "Bullet.h"

USING_NS_CC;

#define MAX_SIZE 25

class BulletPool
{
public:
	static BulletPool* SharedBulletPool();
	bool init();
	void shoot(CCPoint _pos, CCPoint _velo, int _life);
	void shoot(CCPoint _pos, CCPoint _velo);
	void update(float dt);
	void destroy();
private:
	BulletPool();
	~BulletPool();
	BulletPool(BulletPool const&);    // Don't Implement
    void operator=(BulletPool const&); // Don't implement
	int next;
	CC_SYNTHESIZE(CCSpriteBatchNode*, bspritesheet, Bspritesheet);
	CC_SYNTHESIZE(CCArray*, bullets, Bullets);
};



#endif