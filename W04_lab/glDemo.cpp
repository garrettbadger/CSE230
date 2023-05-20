/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "star.h"
#include "velocity.h"
//#include "lander.h"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
    Demo(const Point& ptUpperRight) :
        angle(0.0),
        ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
        ptLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
        ground(ptUpperRight)
        
        

   { 
      
      // create stars array
        int index;
        for (index = 0;
            index < 50;
            index++)
        {
            Star star(random(0, 380), random(0, 255));
            stars[index] = star;
            
        }
      
   }

   // this is just for test purposes.  Don't make member variables public!
   Point ptLM;           // location of the LM on the screen
   Point ptUpperRight;   // size of the screen
   double angle;         // angle the LM is pointing
   unsigned char phase;  // phase of the star's blinking
   Ground ground;
   Point ptStar;
   Velocity velocity;
   Star stars[50];
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo * pDemo = (Demo *)p;  

   // move the ship around
   if (pUI->isRight())
   {
      pDemo->angle -= 0.1;
      pDemo->ptLM.addX(1.0);
   }
   if (pUI->isLeft())
   {
      pDemo->angle += 0.1;
      pDemo->ptLM.addX(-1.0);
   }
   if (pUI->isUp())
      pDemo->ptLM.addY(1.0);
   if (pUI->isDown())
      pDemo->ptLM.addY(-1.0);

   // draw our little star
   int index;
    for (index = 0;
        index < 50;
        index++)
        pDemo->stars[index].draw(gout);
   //Lander lander;

   gout.setPosition(Point(10.0, 350.0));
   //gout << "Fuel: " << lander.getFuel() <<"lbs" << "\n";
   gout.setPosition(Point(10.0, 330.0));
   gout << "Altitude: " <<(int)pDemo->ptLM.getY()<< "meters" << "\n";
   gout.setPosition(Point(10.0, 310.0));
   gout << "Speed: 12.91 m/s" << "\n";

   
   // draw the ground
   pDemo->ground.draw(gout);
   //velocity
   double ogX = pDemo->ptLM.getX();
   double ogY = pDemo->ptLM.getY();
   double vX = pDemo->velocity.getDX();
   double vY = pDemo->velocity.getDY();
   pDemo->ptLM.addX(vX);
   pDemo->ptLM.addY(vY);
   pDemo->velocity.setDX((ogX - pDemo->ptLM.getX()));
   pDemo->velocity.setDY(ogY - pDemo->ptLM.getY());
   // draw the lander and its flames
   gout.drawLander(pDemo->ptLM /*position*/, pDemo->angle /*angle*/);
   gout.drawLanderFlames(pDemo->ptLM, pDemo->angle, /*angle*/
                    pUI->isUp(), pUI->isLeft(), pUI->isRight());

   // put some text on the screen
   gout.setPosition(Point(30.0, 30.0));
   gout << "Demo (" << (int)pDemo->ptLM.getX() << ", " << (int)pDemo->ptLM.getY() << ")" << "\n";

   
   gout.drawStar(pDemo->ptStar, pDemo->phase++);
}

