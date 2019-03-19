#include <math.h>

#include "list.h"

void apply_forces(list_node *list);

void update_physics(list_node *list);

void check_collisions(list_node *objects, list_node *statics);
