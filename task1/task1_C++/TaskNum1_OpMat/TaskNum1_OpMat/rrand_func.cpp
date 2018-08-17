#include "rrand_func.h"
#include <math.h>
#include <cstdlib>
#include <time.h>
int rrand(int range_min, int range_max) {
	return rand() % (range_max - range_min + 1) + range_min;
}