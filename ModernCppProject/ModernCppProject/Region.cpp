#include "Region.h"

Region::Region(uint16_t score)
	:m_score(score)
{
	m_owner = std::nullopt;
}

Region::Region()
{
	m_score = 100;
	m_owner = std::nullopt;
}

void Region::SetScore(uint16_t score) {
	m_score = score;
}

void Region::SetOwner(std::optional<Player>& player)
{
	m_owner = player;
}

bool Region::HasOwner()
{
	return m_owner.has_value();
}

void Region::GiveOwnershipTo(const Player& player)
{
	m_owner = player;
}

void Region::UpdatedScore(uint16_t newScore)
{
	m_score = newScore;
}

void Region::IncreaseScoreBy(uint16_t inscreaser)
{
	m_score += inscreaser;
}

void Region::DecreaseScoreBy(uint16_t decreaser)
{
	m_score -= decreaser;
}

uint16_t Region::GetScore() {
	return m_score;
}

std::optional<Player>& Region::GetOwner()
{
	return m_owner;
}
