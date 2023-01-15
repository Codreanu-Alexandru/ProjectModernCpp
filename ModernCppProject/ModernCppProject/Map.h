#pragma once
#include <vector>
#include <ranges>
#include "Region.h"

using Position = std::pair<size_t, size_t>;

class Map {
public:

	/*Public Constructor*/
	Map(uint8_t nrPlayers);

	/*Setters*/
	void SetWidth(size_t width);
	void SetHeight(size_t height);

	/*Getters*/
	uint8_t GetHeight() const;
	uint8_t GetWidth() const;

	/*Public Functions*/
	bool HasEmptyRegions();
	void ShowMap();

	/*Public Operators*/
	Region& operator[](const Position& position);
	const Region& operator[](const Position& position) const;

private:
	/*Private members*/
	std::vector<std::vector<Region>> m_regions;
	size_t kWidth;
	size_t kHeight;

	/*Private Functions*/
	void GenerateMap();
};