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
	Game(const Point& ptUpperRight, Star stars[]) :ground(ptUpperRight), lander(ptUpperRight)
	{ 
		this->ptUpperRight = ptUpperRight;
		for (int i = 0; i < 50; i++)
		{
		this->stars[i] = stars[i];
		}; 
	};

	void reset()
	{
		lander.reset();
		Star stars; 
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
	void gamePlay(const Thrust thrust, const Interface * ui)
	{
		if (not lander.isFlying())
		{
			return;
		}
		Acceleration acceleration = lander.input(thrust);
		lander.coast(acceleration, ui);
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
		int index;

		for (index = 0;
			index < 50;
			index++)
		{
			
			stars[index].draw(gout);
		}
		ground.draw(gout);
		lander.draw(thrust, gout, ui);
		
		
			

	}
private:
	Thrust thrust;
	Point ptUpperRight;
	Lander lander;
	Ground ground;
	Star stars[50];
};