/***********************************************************************
 * Header File:
 *   Game : The main game class
 * Author:
 *    Garrett Badger/Marquis Jackson
 * Summary:
 *    The class that controls the game.
 ************************************************************************/
#pragma once

#include "point.h"
#include "uiInteract.h"
#include "thrust.h"
#include "lander.h"
#include "ground.h"
#include "star.h"
#include "acceleration.h"
#include "uiDraw.h"

class Game 
{
public:
	Game(const Point & ptUpperRight);

	void reset()
	{
		lander.reset();
		stars.reset(400, 400);
		ground.reset();
		
	}
	Thrust input(const Interface * ui)
	{
		thrust.set(ui);
		if (not lander.isFlying())
			reset();
		return thrust;

	}
	void gamePlay(const Thrust thrust)
	{
		if (not lander.isFlying())
		{
			return;
		}
		Acceleration acceleration = lander.input(thrust);
		lander.coast(acceleration);
		if (ground.hitGround(lander.getPosition(), 20))
			lander.crash();
		else if (ground.onPlatform(lander.getPosition(), 20))
			if (lander.getVelocity().getSpeed() > 4)
				lander.crash();
			else
				lander.land();

		
	}
	void display(const Thrust thrust, const Interface * ui)
	{
		ogstream gout;
		ground.draw(gout);
		lander.draw(thrust, gout, ui)
		
		int index;
    	for (index = 0;
        	index < 50;
        	index++)
        	stars[index].draw(gout);
	}
private:
	Thrust thrust;
	Lander lander;
	Point ptUpperRight;
	Ground ground;
	Star stars[50];
};