#include "OpeningScene.h"


USING_NS_CC;
using namespace ui;

Scene* OpeningScene::createScene()
{
    return OpeningScene::create();
}


bool OpeningScene::init()
{

    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->playBackgroundMusic("menu.mp3", true);

    auto bg = Sprite::create("opbg.png");
    bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    bg->setScale(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
    this->addChild(bg, 0);

    auto title = Sprite::create("title.png");
    title->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 1.3));
    title->setScale(0.8);
    this->addChild(title, 2);

    auto blood = Sprite::create("blood.png");
    blood->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 1.32));
    blood->setScale(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
    blood->setOpacity(120);
    this->addChild(blood, 1);

    auto moveBy = MoveBy::create(25.0, Vec2(0, - (visibleSize.height / 1.22)));
    auto delay = DelayTime::create(10.0);
    auto seq = Sequence::create(delay, moveBy, nullptr);

    blood->runAction(seq);
    
    auto label1 = Label::createWithTTF("New Game", "fonts/andyb.ttf", 45);
    auto label2 = Label::createWithTTF("Settings", "fonts/andyb.ttf", 45);

    label1->setColor(Color3B::RED);
    label2->setColor(Color3B::RED);

    label1->enableOutline(Color4B::BLACK, 2);
    label2->enableOutline(Color4B::BLACK, 2);

    auto menu_item_1 = MenuItemLabel::create(label1, CC_CALLBACK_1(OpeningScene::NewGame, this));
    auto menu_item_2 = MenuItemLabel::create(label2, CC_CALLBACK_1(OpeningScene::Settings, this));

    menu_item_1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 1.6 ));
    menu_item_2->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2.1));
    
    auto* menu = Menu::create(menu_item_1, menu_item_2, NULL);
    menu->setPosition(Point(0, 0));
    this->addChild(menu, 2);
    return true;
}

void OpeningScene::NewGame(cocos2d::Ref* pSender)
{
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->stopBackgroundMusic();
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
}

void OpeningScene::Settings(cocos2d::Ref* pSender)
{

}


void OpeningScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
