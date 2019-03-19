#include "draw.h"

void set_colour(SDL_Renderer *renderer, col colour)
{
	switch (colour)
	{
		default:
		case RED:
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			break;
		case GREEN:
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			break;
		case BLUE:
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			break;
	}

}


void draw_square(SDL_Renderer *renderer, entity *ent)
{
	int x = ent->x, y = ent->y, size = ent->size, colour = ent->colour;
	SDL_Rect rect;


	rect.x = x;
	rect.y = y;
	rect.w = size;
	rect.h = size;

	set_colour(renderer, colour);
	SDL_RenderFillRect(renderer, &rect);
	printf("Drew: %d, %d, %d, %d;\n", x, y, colour, size);
}
