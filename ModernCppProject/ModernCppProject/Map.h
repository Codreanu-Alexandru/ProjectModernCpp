#pragma once
#include <vector>
#include "Region.h"

class Map {

public:
	Map(uint8_t nrPlayers);
	void setWidth(size_t width);
	void setHeight(size_t height);

private:
	size_t kWidth;
	size_t kHeight;
	std::vector<std::vector<Region> > m_regions;
};