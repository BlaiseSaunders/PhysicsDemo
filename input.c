#include "input.h"

extern SDL_Window *screen;

bool get_input()
{
	extern SDL_Event event;
	/*
	* Get Input
	*/
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return false;

		}
	}

	return true;
}


