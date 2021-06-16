#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"
#include "cocostudio\SimpleAudioEngine.h"
#include "ui\CocosGUI.h"

class Character
{
public:
	Character(cocos2d::Scene* scene);

	cocos2d::Sprite* character;

	cocos2d::Scene* current;


	void controller();
	void characterMove();
	void mainAnimation();
	void mainStopAnimation();

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	bool left, right;

};

#endif 