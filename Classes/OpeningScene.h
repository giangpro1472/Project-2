#pragma once

#ifndef __OPENING_SCENE_H__
#define __OPENING_SCENE_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "HelloWorldScene.h"
#include "cocostudio\SimpleAudioEngine.h"

class OpeningScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

  

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);

    void NewGame(cocos2d::Ref* pSender);
    void Settings(cocos2d::Ref* pSender);

    CREATE_FUNC(OpeningScene);
};

#endif
