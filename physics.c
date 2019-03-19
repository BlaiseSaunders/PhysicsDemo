#include "physics.h"

void apply_forces(list_node *list)
{
	/* Iterate through all of the entities we've been given */
	list_node *cur = list;
	entity *ent;

	while (cur != NULL)
	{
		ent = cur->ent;

		/*
		 * Apply forces
		 */

		/* Apply gravity */
		ent->ya = 10;

		cur = cur->next;
	}

}


void update_physics(list_node *list)
{
	/* Iterate through all of the entities we've been given */
	list_node *cur = list;
	entity *ent;

	while (cur != NULL)
	{
		ent = cur->ent;

		/*
		 * Apply forces
		 */


		/* Update positions based on velocity */
		ent->x += ent->xv;
		ent->y += ent->yv;

		/* Update velocities based on accelerations */
		ent->xv += ent->xa;
		ent->yv += ent->ya;


		cur = cur->next;
	}

}

void check_collisions(list_node *objects, list_node *statics)
{
	list_node *cur_obj, *cur_static;

	cur_obj = objects;
	while (cur_obj != NULL)
	{
		cur_static = statics;
		while (cur_static != NULL)
		{

			cur_static = cur_static->next;
		}


		cur_obj = cur_obj->next;
	}

}
