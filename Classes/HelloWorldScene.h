
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "Character.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    Character *main;

    virtual bool init();

    void update(float dt);
    void initEvent();

    void menuCloseCallback(cocos2d::Ref* pSender);


    CREATE_FUNC(HelloWorld);
};

#endif
