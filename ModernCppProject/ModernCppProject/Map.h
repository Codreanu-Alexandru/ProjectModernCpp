#pragma once
#include <vector>
#include "Region.h"

class Map {
public:
	/*Public Constructor*/
	Map(uint8_t nrPlayers);

	/*Setters*/
	void SetWidth(size_t width);
	void SetHeight(size_t height);

	/*Getters*/

	/*Public Functions*/
	void ShowMap();

private:
	/*Private members*/
	size_t kWidth;
	size_t kHeight;
	std::vector<std::vector<Region>> m_regions;

	/*Private Functions*/
	void GenerateMap();
};