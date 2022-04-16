// random
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// headers
#include "../include/game.h"

int main()
{
    srand (time(NULL));
    Game game{600, 600};
    game.renderLoop();
	return 0;
}