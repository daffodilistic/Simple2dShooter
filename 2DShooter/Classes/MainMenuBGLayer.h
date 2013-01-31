#ifndef __MAINMENU_BG_LAYER_H_
#define __MAINMENU_BG_LAYER_H_

#include "cocos2d.h"

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

	void onExit();

	/* Implement the "static node()" method manually
	*/
	CREATE_FUNC(MainMenuBGLayer);
};

#endif