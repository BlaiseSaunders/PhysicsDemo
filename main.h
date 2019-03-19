#define _XOPEN_SOURCE 600

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <fcntl.h>

#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h>
#include <errno.h>

#include "shared.h"
#include "list.h"
#include "input.h"
#include "draw.h"
#include "physics.h"

/* Constants for initial screen width and height */
#define SCREEN_WIDTH  1024
#define SCREEN_HEIGHT 512

#define SLOW 256

void cleanup();
