/***********************************************************************
 * Header File:
 *    Acceleration : Represents the acceleration in the lunar lander game
 * Author:
 *    Garrett Badger/Marquis Jackson
 * Summary:
 *    The acceleration of the lander.
 ************************************************************************/
#pragma once

class Acceleration
{
   
private:
    // private attributes
    double ddx = 0.0;
    double ddy = 0.0;

public:
    //constructors
   //default constructor
    Acceleration() {};

    //non-default constructor

    Acceleration(double ddx, double ddy) { this->ddx = ddx, this->ddy = ddy; };

    //public methods
    double getDDX()
    {
        return ddx;
    }
    double getDDY()
    {
        return ddy;
    }
    void setDDX(double ddx)
    {
        this->ddx = ddx;
    }
    void setDDY(double ddy)
    {
        this->ddy = ddy;
    }

};
