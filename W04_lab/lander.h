/***********************************************************************
 * Header File:
 *    Lander : Represents the lander in the lunar lander game
 * Author:
 *    Garrett Badger/Marquis Jackson
 * Summary:
 *    Contains all attributes of the lander.
 ************************************************************************/
#pragma once
#include "point.h"
#include "thrust.h"
#include "uiDraw.h"
#include "velocity.h"
#include "acceleration.h"

class Lander
{
public:
	Lander() {};
	Lander(const Point& ptUpperRight) { pt.setX(ptUpperRight.getX() - 50), pt.setY(ptUpperRight.getY() - 50); };
	
	void reset()
	{
		pt.setX(400);
		pt.setY(400);
	}
	bool isDead()
	{

	}
	bool isLanded()
	{

	}
	bool isFlying()
	{

	}
	Point getPosition()
	{
		return pt;
	}
	double getFuel()
	{
		return fuel;
	}
	Velocity getVelocity()
	{
		return v;
	}
	void draw(Thrust thrust, ogstream& gout, const Interface *ui)
	{
		gout.drawLander(pt /*position*/, angle /*angle*/);
		gout.drawLanderFlames(pt, angle, /*angle*/
			ui->isUp(), ui->isLeft(), ui->isRight());
	}
	Acceleration input(Thrust thrust) 
	{
		Acceleration a;
		if (fuel = 0)
			return;
		if (thrust.isMain())
		{
			double power = 45000.000 / 15103.000 * clock();
			a.setDDY(cos(angle) * power);
			a.setDDX(-sin(angle) * power);
			fuel = fuel - 10.0;

			
		}
		if (thrust.isClock())
		{
			angle = angle + 0.1;
			fuel = fuel - 1.0;
		}

		if (thrust.isCounter())
		{
			angle = angle - 0.1;
			fuel = fuel - 1;
		}
		if (fuel < 0)
			fuel = 0;
		return a;
	}
	void coast(Acceleration accel)
	{

	}
	void land()
	{

	}
	void crash()
	{

	}
private:
	//Status status;
	Point pt;
	Velocity v;
	double angle;
	double fuel = 2272.0;
};