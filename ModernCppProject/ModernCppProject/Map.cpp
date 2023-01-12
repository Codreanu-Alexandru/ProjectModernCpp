#include "Map.h"

Map::Map(uint8_t nrPlayers) {

	switch (nrPlayers) {
	case 2:
	{
		/*setWidth(3);
		setHeight(3);*/
		kWidth = 3;
		kHeight = 3;
		break;
	}
	case 3:
	{
		/*setWidth(5);
		setHeight(3);*/
		kWidth = 5;
		kHeight = 3;
		break;
	}
	case 4:
	{
		/*setWidth(6);
		setHeight(4);*/
		kWidth = 6;
		kHeight = 4;
		break;
	}
	default:
	{
		kWidth = 0;
		kHeight = 0;
		break;
	}
	}

	GenerateMap();
}

void Map::SetWidth(size_t width) {
	kWidth = width;
}

void Map::SetHeight(size_t height) {
	kHeight = height;
}

uint8_t Map::GetHeight()
{
	return kHeight;
}

uint8_t Map::GetWidth()
{
	return kWidth;
}

void Map::GenerateMap()
{
	for (int heightIndex = 0; heightIndex < kHeight; heightIndex++)
	{
		std::vector<Region> regionsRow;
		for (int widthIndex = 0; widthIndex < kWidth; widthIndex++)
		{
			Region region;
			regionsRow.push_back(region);
		}
		m_regions.push_back(regionsRow);
	}
}

void Map::ShowMap()
{
	for (int heightIndex = 0; heightIndex < kHeight; heightIndex++)
	{
		for (int widthIndex = 0; widthIndex < kWidth; widthIndex++)
		{
			std::cout << m_regions[heightIndex][widthIndex].GetScore() << ' ';
		}
		std::cout << '\n';
	}
}
