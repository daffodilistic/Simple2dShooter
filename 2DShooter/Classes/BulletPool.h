#ifndef __BULLET_POOL_H_
#define __BULLET_POOL_H_

#include "cocos2d.h"
#include "Bullet.h"

USING_NS_CC;

#define MAX_SIZE 25

class BulletPool
{
public:
	/* Singleton
	*/
	static BulletPool* SharedBulletPool();

	/* Initialise
	*/
	bool init();

	/* Create bullet at a given point
	   @param _pos: starting position of bullet
	   @param _velo: velocity of bullet
	*/
	void shoot(CCPoint _pos, CCPoint _velo);

	/* Updates
	   @param dt: delta time
	*/
	void update(float dt);

	/* Destroy and clean up
	*/
	void destroy();

private:
	/* Constructor
	*/
	BulletPool();

	/* Destructor
	*/
	~BulletPool();

	/* Make sure they are unaccessable otherwise may accidentally
	   get copies of the singleton appearing
	*/
	BulletPool(BulletPool const&);    // Don't Implement
    void operator=(BulletPool const&); // Don't implement
	
	/* Track usable bullet in pool
	*/ 
	CC_SYNTHESIZE(int, next, Next);

	/* Sprite batch node to store sprites
	*/
	CC_SYNTHESIZE(CCSpriteBatchNode*, bspritesheet, Bspritesheet);
	
	/* Array of bullets
	*/
	CC_SYNTHESIZE(CCArray*, bullets, Bullets);
};



#endif