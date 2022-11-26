#pragma once
#include <cstdint>
#include <iostream>

class Region {
public:
	void setScore(uint16_t score);
	uint16_t getScore();

private:
	uint16_t m_score = 100;
};