#include "Region.h"

Region::Region(uint16_t score, std::optional<Player> owner)
	:m_score(score), m_owner(owner)
{
}

Region::Region()
{
	m_score = 100;
}

void Region::SetScore(uint16_t score) {
	m_score = score;
}

uint16_t Region::GetScore() {
	return m_score;
}
