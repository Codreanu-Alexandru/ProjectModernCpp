#pragma once
#include "Player.h"
#include <cstdint>
#include <optional>

class Region {
public:
	/*Public Constructor*/
	Region(uint16_t score, std::optional<Player> owner);
	Region();

	/*Getters*/
	uint16_t GetScore();

	/*Setters*/
	void SetScore(uint16_t score);

private:
	/*Private members*/
	uint16_t m_score;
	std::optional<Player> m_owner;
};