#ifndef __MAINMENU_BUTTONS_LAYER_H_
#define __MAINMENU_BUTTONS_LAYER_H_

#include "cocos2d.h"
#include "GameManager.h"
#include "Constants.h"

USING_NS_CC;

class MainMenuBtnLayer : public CCLayer
{
public:

	MainMenuBtnLayer();
	~MainMenuBtnLayer();
	bool init();
	CREATE_FUNC(MainMenuBtnLayer);
private:
	void menucallback(CCObject *_sender);
};

#endif