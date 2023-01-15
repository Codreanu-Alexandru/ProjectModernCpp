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

uint8_t Map::GetHeight() const
{
	return kHeight;
}

uint8_t Map::GetWidth() const
{
	return kWidth;
}

void Map::GenerateMap()
{
	for (size_t heightIndex = 0; heightIndex < kHeight; heightIndex++)
	{
		std::vector<Region> regionsRow;
		for (size_t widthIndex = 0; widthIndex < kWidth; widthIndex++)
		{
			Region region;
			regionsRow.push_back(region);
		}
		m_regions.push_back(regionsRow);
	}
}

bool Map::HasEmptyRegions()
{
	for (auto& row : m_regions)
	{
		for (auto& region : row)
		{
			if (!region.HasOwner())
			{
				return true;
			}
		}
	}
	return false;
}

void Map::ShowMap()
{
	for (size_t heightIndex = 0; heightIndex < kHeight; heightIndex++)
	{
		for (size_t widthIndex = 0; widthIndex < kWidth; widthIndex++)
		{
			std::cout << m_regions.at(heightIndex).at(widthIndex).GetScore() << ' ';
		}
		std::cout << '\n';
	}
}

Region& Map::operator[](const Position& position)
{
	auto [x, y] = position;

	if (x >= kHeight || y >= kWidth)
	{
		std::cerr << "Out of bounds" << std::endl;
		return m_regions[0][0];
	}

	return m_regions[x][y];
}

const Region& Map::operator[](const Position& position) const
{
	auto [x, y] = position;

	if (x >= kHeight || y >= kWidth)
	{
		std::cerr << "Out of bounds" << std::endl;
		return m_regions[0][0];
	}

	return m_regions[x][y];
}
