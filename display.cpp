#include display.h

void displayOne(Coordinate **map, Coordinate position)
{
	char 	toPrint = ' ';
	Agent * isHere = position.getOccupier();
	if (isHere)
	{
		toPrint = isHere->getId();
	}
	cout << "\033[" << 30+(isHere->getTeam()) << "m" << toPrint;
}

void displayLine(Coordinate **map, int lineNumber, int lineLength)
{
	for (int i = 0; i < lineLength; i++)
	{
		displayOne(map, map[lineNumber][i]);
	}
	cout << endl;
}

void displayAll(Coordinate **map, int lines, int columns)
{
	for (int i = 0, i < lines, i++)
	{
		displayLine(map, i, columns);
	}
}
