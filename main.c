#include "main.h"

SDL_Window *screen;
SDL_Renderer *renderer;
TTF_Font *font;

SDL_Event event;


int main(void)
{
	/*
	 * Declarations
	 */
	int w, h;
	unsigned int frame_limit, ticks;

	list_node *entity_list, *static_list, *cur;


	/*
	 * Initialisation
	 */


	/* Setup SDL */
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMECONTROLLER|
	             SDL_INIT_AUDIO) < 0)
	{
		printf("Failed to init SDL: %s\n", SDL_GetError());
		return 1;
	}

	if (TTF_Init() < 0)
		printf("TTF failed to initialise, gomen gomen\n");

	font = TTF_OpenFont("font/DroidSansMono.ttf", 48);
	if (font == NULL)
		printf("Managed to fuck up opening the font: %s\n", TTF_GetError());
	TTF_SetFontHinting(font, TTF_HINTING_MONO);
	TTF_SetFontKerning(font, 0);

	if ((screen = SDL_CreateWindow("Physics Demo",
		                       30,
		                       50,
		                       SCREEN_WIDTH, SCREEN_HEIGHT,
		                       SDL_WINDOW_OPENGL/*|SDL_WINDOW_FULLSCREEN_DESKTOP*/)) == NULL)
	{
		printf("Failed to create SDL window: %s\n", SDL_GetError());
		return 1;
	}
	if ((renderer = SDL_CreateRenderer(screen, -1, 0)) == NULL)
	{
		printf("Failed to create SDL screen: %s\n", SDL_GetError());
		return 1;
	}
	atexit(cleanup);

	/* Init Misc */
	srand(time(NULL));

	/* initialise the object lists */
	if (!init_list_node(&entity_list))
		return EXIT_FAILURE;
	if (!init_list_node(&static_list))
		return EXIT_FAILURE;


	/* x, y, xv, yv, xa, ya, angle, size, colour, name, list */
	if (!create_entity(0, 0, 0, 0, 0, 0, 0, 10, RED, "test", entity_list))
		return EXIT_FAILURE;
	if (!create_entity(100, 100, 20, 30, 0, 0, 0, 10, BLUE, "test", entity_list))
		return EXIT_FAILURE;


	if (!create_entity(100, 100, 20, 30, 0, 0, 0, 10, GREEN, "Floor", static_list))
		return EXIT_FAILURE;

	/*
	 * Main Game Loop
	 */
	frame_limit = SDL_GetTicks() + SLOW;
	while (1)
	{
		/*
		* Check for a change in screen size
		*/
		SDL_GetWindowSize(screen, &w, &h);


		/*
		* Get Input
		*/
		if (!get_input())
		{
			cleanup();
			break;
		}

		/*
		 * Update Physics
		 */
		check_collisions(entity_list, static_list);
		update_physics(entity_list);
		apply_forces(entity_list);


		/*
		* Draw
		*/
		SDL_SetRenderDrawColor(renderer, 23, 24, 26, 255);
		SDL_RenderClear(renderer);

		cur = entity_list;
		while (cur->next != NULL)
		{
			draw_square(renderer, cur->ent);
			cur = cur->next;
		}

		SDL_RenderPresent(renderer);

		/*
		* Sleep
		*/
		if (frame_limit > (ticks = SDL_GetTicks()) + SLOW)
			SDL_Delay(SLOW);
		else if (frame_limit > ticks)
			SDL_Delay(frame_limit - ticks);
		frame_limit = SDL_GetTicks() + SLOW;

	}

	return EXIT_SUCCESS;
}

void cleanup()
{
	SDL_Quit();
}
