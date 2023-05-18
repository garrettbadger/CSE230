/***********************************************************************
 * Header File:
 *    Thrust : Represents the thrust in the lunar lander game
 * Author:
 *    Garrett Badger/Marquis Jackson
 * Summary:
 *    The thrust of the lander.
 ************************************************************************/
#pragma once

class Thrust {



private:
    // private attributes
    bool mainEngine = false;
    bool clockwise = false;
    bool counterClockwise= false;

public:
    //default constructor
    Thrust() {};
    // public methods
    void Rotation()
    {

    }
    void mainEngineThrust()
    {

    }
    bool isMain()
    {
        return mainEngine;
    }
    bool isClock()
    {
        return clockwise;
    }
    bool isCounter()
    {
        return counterClockwise;
    }
    void set(const Interface *ui)
    {
        if (ui->isRight())
            clockwise = true;
        else
            clockwise = false;
        if (ui->isLeft())
            counterClockwise = true;
        else
            counterClockwise = false;
        if (ui->isUp())
            mainEngine = true;
        else
            mainEngine = false;
    }

};