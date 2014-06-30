#include <stdio.h>
#include "Simulation.h"
#include "Timer.h"
#include "Constants.h"

int main( int argc, char* args[] )
{
	Simulation simulation(1024, 720);
	Timer capTimer;
	Timer fpsTimer;
	fpsTimer.start();
	SDL_Event evt;
	while(simulation.isRunning)
	{
		capTimer.start();
		while( SDL_PollEvent(&evt) )
		{
			switch(evt.type)
			{
			case SDL_QUIT:  simulation.isRunning = false;   break;
			/* process other events you want to handle here */
			}
		}
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