#pragma once
#include <vector>
#include <ranges>
#include "Region.h"

class Map {
public:

	using Position = std::pair<size_t, size_t>;

	/*Public Constructor*/
	Map(uint8_t nrPlayers);

	/*Setters*/
	void SetWidth(size_t width);
	void SetHeight(size_t height);

	/*Getters*/
	uint8_t GetHeight();
	uint8_t GetWidth();

	/*Public Functions*/
	bool HasEmptyRegions();
	void ShowMap();

	/*Public Operators*/
	Region& operator[](const Position& position);
	const Region& operator[](const Position& position) const;

private:
	/*Private members*/
	size_t kWidth;
	size_t kHeight;
	std::vector<std::vector<Region>> m_regions;

	/*Private Functions*/
	void GenerateMap();
};