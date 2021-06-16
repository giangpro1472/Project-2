#include "HelloWorldScene.h"


USING_NS_CC;
using namespace ui;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}


bool HelloWorld::init()
{
  
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("villaStanzaBussolaBg.png");
    background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    background->setScale(visibleSize.width / background->getContentSize().width);
    this->addChild(background, 0);

    main = new Character(this);
    initEvent();

    return true;
}

void HelloWorld::initEvent()
{
    this->scheduleUpdate();
}

void HelloWorld::update(float dt)
{
    main->characterMove();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
