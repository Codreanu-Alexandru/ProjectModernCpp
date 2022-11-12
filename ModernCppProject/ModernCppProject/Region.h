#pragma once
#include <cstdint>
#include <iostream>

class Region {
	void setScore(uint16_t score);

private:
	User m_owner;
	uint16_t m_score = 100;
};