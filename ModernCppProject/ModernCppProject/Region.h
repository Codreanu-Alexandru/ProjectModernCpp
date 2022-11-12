#pragma once
#include <cstdint>
#include <iostream>

class Region {
	void setScore(uint16_t score);

private:
	uint16_t m_score = 100;
};