#ifndef ERR_H
#define ERR_H

#include <stdio.h>
#include <stdlib.h>

#define ERROR(msg) { printf("Error: %s\n", msg); exit(1); }

#endif