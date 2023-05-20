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
#include <windows.h>

class Lander
{
public:
	Lander() {};
	Lander(const Point& ptUpperRight) { pt.setX(ptUpperRight.getX() -20 ), pt.setY(ptUpperRight.getY() -20), this->ptUpperRight = ptUpperRight; };
	
	void reset()
	{
		angle = 0;
		fuel = 2272.0;
		pt.setX(400);
		pt.setY(400);
	}
	bool isDead()
	{
		return false;
	}
	bool isLanded()
	{
		return false;
	}
	bool isFlying()
	{
		return true;
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
			return a;
		if (thrust.isMain())
		{
			double power = 45000.000 / 15103.000;
			a.setDDY((cos(angle) * power) + -1.625);
			a.setDDX(-sin(angle) * power);
			fuel = fuel - 10.0;


		}
		else
			a.setDDY(-1.625);
		if (thrust.isClock())
		{
			angle = angle - 0.1;
			fuel = fuel - 1.0;
		}

		if (thrust.isCounter())
		{
			angle = angle + 0.1;
			fuel = fuel - 1.0;
		}
		if (fuel < 0)
			fuel = 0;
		return a;
	}
	void coast(Acceleration accel, const Interface * ui)
	{
		v.add(accel.getDDY(), accel.getDDX(), 0.1);

		pt.add(accel, v);
		
	}
	void land()
	{

	}
	void crash()
	{
		ogstream gout;
		angle = 10;
		gout.setPosition(Point(100, 300));
		gout << "Houston we have a problem!";
		Sleep(2000);
		reset();
	}
private:
	//Status status;
	Point ptUpperRight;
	Point pt;
	Velocity v;
	double angle = 0.0;
	double fuel = 2272.0;
};