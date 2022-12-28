#pragma once
#include <cstdint>
#include "Advantages.h"


class Player
{
public:
	/*Public Constructor*/
	Player(const std::string& username);

	/*Getter*/
	std::string GetName();

	/*Setter*/
	void SetName(const std::string& username);

private:
	/*Private members*/
	bool m_isActivPlayer;
	uint16_t m_score;
	std::string m_name;
	Advantages m_advantages;
};

