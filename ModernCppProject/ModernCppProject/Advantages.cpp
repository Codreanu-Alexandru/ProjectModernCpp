#include "Advantages.h"

Advantages::Advantages()
{
	m_fiftyFiftyAvailable = true;
	m_chooseAnswerAvailable = true;
	m_suggestAnswerAvailable = true;
}

void Advantages::applyFiftyFifty()
{
	if (m_fiftyFiftyAvailable)
	{

		m_fiftyFiftyAvailable = false;
	}
	
}

void Advantages::applyChooseAnswer()
{
	if (m_chooseAnswerAvailable)
	{
		m_chooseAnswerAvailable = false;
	}
	
}

void Advantages::applySuggestAnswer()
{
	if (m_suggestAnswerAvailable)
	{
		m_suggestAnswerAvailable = false;
	}
	
}

void Advantages::displayAdvantages(Question question)
{
	uint8_t option;
	SingleNumericQuestion* a = dynamic_cast<SingleNumericQuestion*>(&question);
	std::cout << "Avantaje disponibile: \n";
	if (a!=nullptr)
	{
		if (m_fiftyFiftyAvailable)
			std::cout << "7: 50/50 - Nu e valabil pentru acest tip de intrebare \n";
		if (m_chooseAnswerAvailable)
			std::cout << "8: Alege intre 4 raspunsuri \n";
		if (m_suggestAnswerAvailable)
			std::cout << "9: Genereaza un raspuns apropiat \n";

		std::cin >> option;
		switch (option)
		{
		case 8:
			applyChooseAnswer();
			break;
		case 9:
			applySuggestAnswer();
			break;
		default:
			break;
		}
	}
	else
	{
		if (m_fiftyFiftyAvailable)
			std::cout << "7: 50/50 \n";
		if (m_chooseAnswerAvailable)
			std::cout << "8: Alege intre 4 raspunsuri - Nu este valabil pentru acest tip de intrebare \n";
		if (m_suggestAnswerAvailable)
			std::cout << "9: Sugereaza raspunsul corect \n";
		std::cin >> option;
		switch (option)
		{
		case 7:
			applyFiftyFifty();
			break;
		case 9:
			applySuggestAnswer();
			break;
		default:
			break;
		}
	}
	

}
