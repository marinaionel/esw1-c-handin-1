#include <time.h>
#include <stddef.h>
#include <stdlib.h>

#include "humidityDriver.h"

void humidityDriver_initDriver(uint8_t portNo) {
	srand(time(NULL));
}

uint8_t humidityDriver_getHumidity() {
	return (rand() % (85 - 35 + 1)) + 35;
}