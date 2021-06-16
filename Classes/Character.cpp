#include "Character.h"

USING_NS_CC;
using namespace ui;
Character::Character(cocos2d::Scene* scene)
{
    current = scene;

    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    character = Sprite::create("main1.png");
    character->setPosition(Vec2(visibleSize.width / 2 + origin.x - 530, visibleSize.height / 2 + origin.y - 50));
    character->setScaleX(-1);
    character->setTag(0);
    
    current ->addChild(character, 1);

    left = false;
    right = false;

    mainStopAnimation();
    controller();

}

void Character::characterMove()
{
    
    if (left)
    {
        character->setScaleX(1);
        character->setPosition(character->getPosition() + Vec2(-5, 0));
    }
    else if (right)
    {
        character->setScaleX(-1);
        character->setPosition(character->getPosition() + Vec2(5, 0));
    }
}

void Character::controller()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    

    auto arrowLeft = Button::create("arrow.png", "arrowPressed.png", "arrowPressed.png");
    arrowLeft->setPosition(Vec2(origin.x + visibleSize.width / 2 - 480, origin.y + visibleSize.height / 2 - 200));
    arrowLeft->setRotation(90);
    current->addChild(arrowLeft);

    arrowLeft->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                
                mainAnimation();
                left = true;
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                mainStopAnimation();
                left = false;
                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });

    auto arrowRight = Button::create("arrow.png", "arrowPressed.png", "arrowPressed.png");
    arrowRight->setPosition(Vec2(origin.x + visibleSize.width / 2 + 480, origin.y + visibleSize.height / 2 - 200));
    arrowRight->setRotation(-90);
    current->addChild(arrowRight);

    arrowRight->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
                mainAnimation();
                right = true;
                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:
                mainStopAnimation();
                right = false;
                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });

    auto inventarioButton = Button::create("inventarioButton.png", "inventarioButtonPressed.png", "inventarioButtonPressed.png");
    inventarioButton->setPosition(Vec2(origin.x + visibleSize.width / 2 - 80, origin.y + visibleSize.height / 2 - 200));
    current->addChild(inventarioButton);

    inventarioButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:

                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:

                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });

    auto exit = Button::create("exit.png", "exitPressed.png", "exitPressed.png");
    exit->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - 200));
    current->addChild(exit);

    exit->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:

                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:

                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });

    auto alertButton = Button::create("alertButton.png", "alertButtonPressed.png", "alertButtonPressed.png");
    alertButton->setPosition(Vec2(origin.x + visibleSize.width / 2 + 80, origin.y + visibleSize.height / 2 - 200));
    current->addChild(alertButton);

    alertButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:

                break;
            case cocos2d::ui::Widget::TouchEventType::MOVED:
                break;
            case cocos2d::ui::Widget::TouchEventType::ENDED:

                break;
            case cocos2d::ui::Widget::TouchEventType::CANCELED:
                break;
            default:
                break;
            }
        });


}

void Character::mainAnimation()
{
    auto decade = current->getChildByTag(0);
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spritesheet.plist", "spritesheet.png");
    const int numberSprite = 2;

    Vector<SpriteFrame*> animFrames;
    animFrames.reserve(numberSprite);
    animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("main2.png"));
    animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("main3.png"));
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.2f);
    Animate* animate = Animate::create(animation);
    decade->runAction(RepeatForever::create(animate));

    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->playEffect("runningSilently.mp3", true);

}

void Character::mainStopAnimation()
{
    auto decade = current->getChildByTag(0);
    decade->stopAllActions();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("stopanimation.plist", "stopanimation.png");
    const int numberSprite = 2;
    Vector<SpriteFrame*> animFrames;
    animFrames.reserve(numberSprite);
    animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("main.png"));
    animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("main1.png"));

    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.99f);
    Animate* animate = Animate::create(animation);
    decade->runAction(RepeatForever::create(animate));

    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->stopAllEffects();

}


