/***********************************************************************
 * Header File:
 *    Star : Represents a star in the lunar lander game
 * Author:
 *    Garrett Badger/Marquis Jackson
 * Summary:
 *    The attributes and properties of a star.
 ************************************************************************/
#pragma once

#include "point.h"
#include "uiDraw.h"

class Star
{
public:
	Star() {};
	Star(int x, int y, char phase) { pt.setX(x), pt.setY(y), phase = phase; }
	void reset(int width, int height)
	{

	}
	void draw(ogstream& gout)
	{
				
		gout.drawStar(pt, phase++);
	}
private:
	char phase;
	Point pt;
	
	
};