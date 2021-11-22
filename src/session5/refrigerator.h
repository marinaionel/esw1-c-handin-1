//
// Created by Marina Ionel on 21/04/2020.
//

#ifndef HANDIN_REFRIGERATOR_H
#define HANDIN_REFRIGERATOR_H

typedef enum ResultInfo {
    ERROR, OK, INVALID_ARGUMENT
} ResultInfo;

void refrigerator_setInternalTemperature(int temperature);

void refrigerator_turnOn();

#endif //HANDIN_REFRIGERATOR_H
