/*************************************************************
 * 1. Name:
 *      Garrett Badger
 * 2. Assignment Name:
 *      Practice 02: Physics simulator
 * 3. Assignment Description:
 *      Compute how the Apollo lander will move across the screen
 * 4. What was the hardest part? Be as specific as possible.
 *     The hardest part was a bug I got stuck on. I basically had everything
 *     correct but I switched sin and cos on the horizontal and vertical functions.
 * 5. How long did it take for you to complete the assignment?
 *      7 hours
 **************************************************************/

#include <iostream>  // for CIN and COUT
#include <cmath>
using namespace std;

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
 // your function goes here
double computeDistance(double s, double v, double a, double t)
{
    double newS = s + v * t + 0.5 * a * (pow(t, 2));
    return newS;
}
 /**************************************************
  * COMPUTE ACCELERATION
  * Find the acceleration given a thrust and mass.
  * This will be done using Newton's second law of motion:
  *     f = m * a
  * INPUT
  *     f : force, in Newtons (kg * m / s^2)
  *     m : mass, in kilograms
  * OUTPUT
  *     a : acceleration, in meters/second^2
  ***************************************************/
  // your function goes here
double computeAcceleration()
{
    double a = THRUST / WEIGHT;
    return a;
}
  /***********************************************
   * COMPUTE VELOCITY
   * Starting with a given velocity, find the new
   * velocity once acceleration is applied. This is
   * called the Kinematics equation. The
   * equation is:
   *     v = v + a t
   * INPUT
   *     v : velocity, in meters/second
   *     a : acceleration, in meters/second^2
   *     t : time, in seconds
   * OUTPUT
   *     v : new velocity, in meters/second
   ***********************************************/
   // your function goes here
double computeVelocity(double v, double a, double t)
{
    double newV = v + a * t;
    return newV;
}

   /***********************************************
    * COMPUTE VERTICAL COMPONENT
    * Find the vertical component of a velocity or acceleration.
    * The equation is:
    *     cos(a) = y / total
    * This can be expressed graphically:
    *      x
    *    +-----
    *    |   /
    *  y |  / total
    *    |a/
    *    |/
    * INPUT
    *     a : angle, in radians
    *     total : total velocity or acceleration
    * OUTPUT
    *     y : the vertical component of the total
    ***********************************************/
    // your function goes here
double computeVerticalComponent(double a, double total)
{
    double y = cos(a) * total;
    return y;
}
    /***********************************************
     * COMPUTE HORIZONTAL COMPONENT
     * Find the horizontal component of a velocity or acceleration.
     * The equation is:
     *     sin(a) = x / total
     * This can be expressed graphically:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    |a/
     *    |/
     * INPUT
     *     a : angle, in radians
     *     total : total velocity or acceleration
     * OUTPUT
     *     x : the vertical component of the total
     ***********************************************/
     // your function goes here
double computeHorizontalComponent(double a, double total)
{
    double x = sin(a) * total;
    return x;
}
     /************************************************
      * COMPUTE TOTAL COMPONENT
      * Given the horizontal and vertical components of
      * something (velocity or acceleration), determine
      * the total component. To do this, use the Pythagorean Theorem:
      *    x^2 + y^2 = t^2
      * where:
      *      x
      *    +-----
      *    |   /
      *  y |  / total
      *    | /
      *    |/
      * INPUT
      *    x : horizontal component
      *    y : vertical component
      * OUTPUT
      *    total : total component
      ***********************************************/
      // your function goes here
double computeTotalComponent(double x, double y)
{
    double total = sqrt(pow(x, 2) + pow(y, 2));
    return total;
}

      /*************************************************
       * RADIANS FROM DEGEES
       * Convert degrees to radians:
       *     radians / 2pi = degrees / 360
       * INPUT
       *     d : degrees from 0 to 360
       * OUTPUT
       *     r : radians from 0 to 2pi
       **************************************************/
       // your function goes here
double radiansFromDegrees(double d)
{
    double pi = 2 * acos(0.0);
    double r = d * (pi / 180);
    return r;
}
       /**************************************************
        * PROMPT
        * A generic function to prompt the user for a double
        * INPUT
        *      message : the message to display to the user
        * OUTPUT
        *      response : the user's response
        ***************************************************/
        // your function goes here
double prompt(string message)
{
    cout << message;
    double output;
    cin >> output ;
    return output;
}
        /****************************************************************
         * MAIN
         * Prompt for input, compute new position, and display output
         ****************************************************************/
int main()
{
    // Prompt for input and variables to be computed
    double dx = prompt("What is your horizontal velocity (m/s)? ");
    double dy = prompt("What is your vertical velocity (m/s)? ");
    double y = prompt("What is your altitude (m)? ");
    double x = prompt("What is your position (m)? ");
    double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    double t = prompt("What is the time interval (s)? ");
    double aRadians;            // Angle in radians
    double accelerationThrust;  // Acceleration due to thrust 
    double ddxThrust;           // Horizontal acceleration due to thrust
    double ddyThrust;           // Vertical acceleration due to thrust
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
    double v;                   // Total velocity

    // Go through the simulator five times
      // your code goes here
    aRadians = radiansFromDegrees(aDegrees);
    accelerationThrust = computeAcceleration();
    for (int i = 0; i < 5; i++)
    {
        
        ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);
        ddyThrust = computeVerticalComponent(aRadians, accelerationThrust) + GRAVITY;
        dx = computeVelocity(dx, ddxThrust, t);
        dy = computeVelocity(dy, ddyThrust, t);
        
        v = computeTotalComponent(dx, dy);
        x = computeDistance(x, dx, ddxThrust, t);
        y = computeDistance(y, dy, ddyThrust, t);

        // Output
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);
        cout << "\tNew position:   (" << x << ", " << y << ")m\n";
        cout << "\tNew velocity:   (" << dx << ", " << dy << ")m/s\n";
        cout << "\tTotal velocity:  " << v << "m/s\n\n";

    }
    return 0;
}
