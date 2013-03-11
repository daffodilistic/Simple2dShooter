#ifndef __MAINMENU_BG_LAYER_H_
#define __MAINMENU_BG_LAYER_H_

#include "cocos2d.h"

#include "GameManager.h"

USING_NS_CC;

class MainMenuBGLayer : public CCLayer
{
public:
	/* Constructor
	*/
	MainMenuBGLayer();

	/* Destructor
	*/
	~MainMenuBGLayer();

	/* Initialise
	*/
	bool init();

	/* When layer is added
	*/
	void onEnter();

	/* On touch begin events
	   @param pTouches: get user touches
	   @param pEvent: get type of event
	*/
	void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);

	/* When exiting layer
	*/
	void onExit();

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(MainMenuBGLayer);
};

#endif