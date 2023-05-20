#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "star.h"
#include "velocity.h"
#include "lander.h"
#include "game.h"
using namespace std;



void callBack(const Interface* pUI, void* p)
{
	Game* game = (Game*)p;

	Thrust thrust = game->input(pUI);
    game->gamePlay(thrust, pUI);
    game->display(thrust, pUI);
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
    // Initialize OpenGL
    Point ptUpperRight(400.0, 400.0);
    Interface ui(0, NULL,
        "Open GL Demo",
        ptUpperRight);
    Star stars[50];
    int index;
    for (index = 0;
        index < 50;
        index++)
    {

        unsigned char phase = random(0, 255);
        Star star(random(0, 400), random(0, 400), phase);
        stars[index] = star;
    }
    

    // Initialize the game class
    Game game(ptUpperRight, stars);
    

    // set everything into action
    ui.run(callBack, &game);

    return 0;
}