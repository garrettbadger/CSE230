/*************************************************************
 * 1. Name:
 *      Garrett Badger
 * 2. Assignment Name:
 *      Lab 01: Hello World
 * 3. Assignment Description:
 *      A simple program to display a message on the screen
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was getting used to Visual Studio Community and figuring
 *      out how to get my program to run.
 * 5. How long did it take for you to complete the assignment?
 *      3 hours.
 *****************************************************************/

#include <iostream>
/*
* This is the Main function which outputs Hello World! to the screen.
*/
int main()
{
    // outputs 'Hello World!'
    std::cout << "Hello World!\n";
    std::cout << (1 / 2) << std::endl;
    int x = 1;
    std::cout << (7 + 3 * ++x) << std::endl;
    for (int count = 1; count < 11; count++)
        std::cout << count << std::endl;
    return 0;

}


