#include "GameUILayer.h"

GameUILayer::GameUILayer()
	:btn(NULL)
{
}

GameUILayer::~GameUILayer()
{
}

bool GameUILayer::init()
{
	bool bRet = false;

	do 
	{
		// Super init first
		CC_BREAK_IF(!CCLayer::init());
		
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// Gold
		CCSprite *m_UILife = CCSprite::create("gold.png");
		//m_UILife->setScaleX(size.width / m_UILife->getContentSize().width);
		//m_UILife->setScaleY(size.height / m_UILife->getContentSize().height);
		m_UILife->setPosition(ccp(size.width*0.1f, size.height* 0.9f));
		this->addChild(m_UILife);

		CCLabelTTF *m_UIGoldCounter = CCLabelTTF::create("m_UIGoldCounter", "Arial", 32.0f, CCSizeMake(350,32), CCTextAlignment::kCCTextAlignmentLeft);
		m_UIGoldCounter->setColor(ccc3(0,0,0));
		m_UIGoldCounter->setString("888");
		m_UIGoldCounter->setPosition(ccp(size.width * 0.22f, size.height * 0.87f));
		this->addChild(m_UIGoldCounter);

		// Firecracker
		/*
		CCSprite *m_UIFirecracker = CCSprite::create("firecracker_small.png");
		//m_UILife->setScaleX(size.width / m_UILife->getContentSize().width);
		//m_UILife->setScaleY(size.height / m_UILife->getContentSize().height);
		m_UIFirecracker->setPosition(ccp(size.width * 0.1f, size.height* 0.7f));
		this->addChild(m_UIFirecracker);
		*/
		/*
		CCLabelTTF *m_UIFirecrackerCounter = CCLabelTTF::create("m_UIFirecrackerCounter", "Arial", 32.0f, CCSizeMake(350,32), CCTextAlignment::kCCTextAlignmentLeft);
		m_UIFirecrackerCounter->setColor(ccc3(1,0,0));
		m_UIFirecrackerCounter->setString("x 888");
		m_UIFirecrackerCounter->setPosition(ccp(size.width * 0.2f, size.height * 0.895f));
		this->addChild(m_UIFirecrackerCounter);
		*/

		//UI button for shooting
		btn = CCSprite::create("firecracker_main.png");
		btn->setPosition(ccp(size.width*0.9f, size.height*0.1f));
		this->addChild(btn);

		bRet = true;
	} while (0);

	return bRet;
}

void GameUILayer::onExit()
{
	this->removeAllChildrenWithCleanup(true);
}