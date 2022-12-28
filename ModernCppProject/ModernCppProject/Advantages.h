#pragma once
#include <iostream>
#include "MultipleChoiceQuestion.h"
#include "SingleNumericQuestion.h"

class Advantages
{
public:
	/*Public Constructor*/
	Advantages();

	/*Public Functions*/
	void ApplyFiftyFifty();
	void ApplyChooseAnswer();
	void ApplySuggestAnswer();
	void DisplayAdvantages(Question question);

private:
	/*Private members*/
	bool m_fiftyFiftyAvailable;
	bool m_chooseAnswerAvailable;
	bool m_suggestAnswerAvailable;


	
};

