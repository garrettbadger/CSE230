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
    double dx = 3.1;
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
        return velocity;
    }
    void add(double accel, double time)
    {
        this->velocity = std::sqrt(dx * dx + dy * dy) + accel * time;
       
    }

};