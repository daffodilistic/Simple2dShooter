#ifndef __MAINMENU_BG_LAYER_H_
#define __MAINMENU_BG_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class MainMenuBGLayer : public CCLayer
{
public:
	MainMenuBGLayer();
	~MainMenuBGLayer();
	bool init();
	CREATE_FUNC(MainMenuBGLayer);
};

#endif