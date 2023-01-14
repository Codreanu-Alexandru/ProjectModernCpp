#pragma once
#include "Player.h"
#include <cstdint>
#include <optional>

class Region {
public:
	/*Public Constructor*/
	Region(uint16_t score);
	Region();

	/*Getters*/
	uint16_t GetScore();
	std::optional<Player>& GetOwner();

	/*Setters*/
	void SetScore(uint16_t score);
	void SetOwner(std::optional<Player>& player);

	/*Public Functions*/
	bool HasOwner();
	void GiveOwnershipTo(const Player& player);
	void UpdatedScore(uint16_t newScore);
	void IncreaseScoreBy(uint16_t inscreaser);
	void DecreaseScoreBy(uint16_t descreaser);

private:
	/*Private members*/
	uint16_t m_score;
	std::optional<Player> m_owner;
};