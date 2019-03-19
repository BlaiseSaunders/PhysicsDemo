#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "shared.h"

#ifndef LIST_H
#define LIST_H

#define NAME_BUFSIZE 1024

typedef enum
{
	RED,
	GREEN,
	BLUE
} col;

typedef struct
{
	int x, y;
	int size;
	col colour;
	float xv, yv;
	float xa, ya;
	float angle;
	char *name;

} entity;

typedef struct l_n
{
	entity *ent;
	struct l_n *next;

} list_node;


bool create_entity(int x, int y, float xv, float yv, float xa, float ya,
                   float angle, int size, col colour, char *name, list_node *list);

bool init_list_node(list_node **node);

#endif
