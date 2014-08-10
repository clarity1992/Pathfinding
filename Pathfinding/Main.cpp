#include <stdio.h>
#include "Simulation.h"
#include "Timer.h"
#include "Constants.h"

int main( int argc, char* args[] )
{
	Simulation simulation(SCREEN_WIDTH, SCREEN_HEIGHT);
	Timer capTimer;
	Timer fpsTimer;
	fpsTimer.start();
	SDL_Event evt;
	while(simulation.isRunning)
	{
		capTimer.start();		
		simulation.input();
		simulation.update();
		simulation.render();

		//If frame finished early
        int frameTicks = capTimer.getTicks();
        if( frameTicks < SCREEN_TICKS_PER_FRAME )
        {
            //Wait remaining time
            SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
        }
	}

    return 0;
}