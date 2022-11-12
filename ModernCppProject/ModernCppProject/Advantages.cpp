#include "Advantages.h"

Advantages::Advantages()
{
	m_fiftyFiftyAvailable = true;
	m_chooseAnswerAvailable = true;
	m_suggestAnswerAvailable = true;
}

void Advantages::applyFiftyFifty()
{
	m_fiftyFiftyAvailable = false;
}

void Advantages::applyChooseAnswer()
{
	m_chooseAnswerAvailable = false;
}

void Advantages::applySuggestAnswer()
{
	m_suggestAnswerAvailable = false;
}
