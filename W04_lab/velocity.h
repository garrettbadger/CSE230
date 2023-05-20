/***********************************************************************
 * Header File:
 *    Velcotiy : Represents the velocity in the lunar lander game
 * Author:
 *    Garrett Badger/Marquis Jackson
 * Summary:
 *    The velocity of the lander.
 ************************************************************************/
#pragma once
#include <cmath>
class Velocity
{
   
private:
    // private attributes
    double dx = 0.0;
    double dy = 0.0;
    double velocity;

public:
    //constructors
   //default constructor
    Velocity() {};

    //non-default constructor

    Velocity(double dx, double dy) { this->dx = dx, this->dy = dy; };

    //public methods
    double getDX()
    {
        return dx;
    }
    double getDY()
    {
        return dy;
    }
    void setDX(double dx)
    {
        this->dx = dx;
    }
    void setDY(double dy)
    {
        this->dy = dy;
    }
    double getSpeed()
    {
        return std::sqrt(dx * dx + dy * dy);
    }
    void add(double ddy, double ddx, double time)
    {
        this->dy = dy + ddy * time;
        this->dx = dx + ddx * time;
        
       
    }

};