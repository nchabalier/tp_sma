#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include "map.h"

using namespace std;

void displayOne(Coordinate **map, Coordinate position);
void displayLine(Coordinate **map, int lineNumber, int lineLength);
void displayAll(Coordinate **map, int lines, int columns);

#endif
