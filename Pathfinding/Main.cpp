#include <stdio.h>
#include "Simulation.h"


int main( int argc, char* args[] )
{
	Simulation simulation(1024, 720);

	while(simulation.isRunning)
	{
		simulation.update();
		simulation.render();
	}

    return 0;
}