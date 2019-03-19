#include "list.h"

bool init_entity(entity **ent)
{
	if ((*ent = malloc(sizeof (entity))) == NULL)
	{
		perror("Error");
		return false;
	}
	if (((*ent)->name = malloc(NAME_BUFSIZE)) == NULL)
	{
		perror("Error");
		return false;
	}

	return true;
}

bool init_list_node(list_node **node)
{
	if ((*node = malloc(sizeof (list_node))) == NULL)
	{
		perror("Error");
		return false;
	}

	if (!init_entity(&((*node)->ent)))
		return false;

	(*node)->next = NULL;

	return true;
}



bool create_entity(int x, int y, float xv, float yv, float xa, float ya,
                   float angle, int size, col colour, char *name, list_node *list)
{
	list_node *new_node = list;

	printf("Creating entity.\n");

	/* make our way to the latest empty node */
	while (new_node->next != NULL)
	{
		printf("Moving ahead.\n");
		new_node = new_node->next;
	}


	new_node->ent->x      = x;
	new_node->ent->y      = y;
	new_node->ent->xv     = xv;
	new_node->ent->yv     = yv;
	new_node->ent->xa     = xa;
	new_node->ent->ya     = ya;
	new_node->ent->angle  = angle;
	new_node->ent->size   = size;
	new_node->ent->colour = colour;
	strcpy(new_node->ent->name, name);

	if (!init_list_node(&(new_node->next)))
		return false;

	return true;
}
