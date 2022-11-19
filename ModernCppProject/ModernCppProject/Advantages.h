#pragma once
#include <iostream>
#include "MultipleChoiceQuestion.h"
#include "SingleNumericQuestion.h"

class Advantages
{
public:
	Advantages();
	void applyFiftyFifty();
	void applyChooseAnswer();
	void applySuggestAnswer();
	void displayAdvantages(Question question);


private:
	bool m_fiftyFiftyAvailable;
	bool m_chooseAnswerAvailable;
	bool m_suggestAnswerAvailable;


	
};

