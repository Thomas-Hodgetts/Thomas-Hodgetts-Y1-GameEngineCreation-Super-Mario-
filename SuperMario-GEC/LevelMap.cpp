#include "LevelMap.h"

LevelMap::LevelMap(int map[MAP_HEIGHT][MAP_WIDTH])
{
	m_Map = NULL;
	m_Map = new int* [MAP_HEIGHT];
	for (unsigned int i = 0; i < MAP_HEIGHT; i++)
	{
		m_Map[i] = new int[MAP_WIDTH];
	}
	for (unsigned int i = 0; i < MAP_HEIGHT; i++)
	{
		for (unsigned int j = 0; j < MAP_WIDTH; j++)
		{
			m_Map[i][j] = map[i][j];
		}
	}
}


LevelMap::~LevelMap()
{
	for (unsigned int i = 0; i < MAP_HEIGHT; i++)
	{
		delete[] m_Map[i];
	}
	delete[] m_Map;
}

int LevelMap::GetTileAt(unsigned int h, unsigned int w)
{
	if (h < MAP_HEIGHT && w < MAP_WIDTH)
	{
		return m_Map[h][w];
	}
	return 0;
}

void LevelMap::ChangeTileAt(unsigned int row, unsigned int column, unsigned int newValue)
{
	m_Map[row][column] = newValue;
}