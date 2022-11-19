#include "Game.h"
#include "Map.h"
#include "../TriviadorLogger/TriviadorLogger.h"


int main()
{
	//Testing question
	Game g;
	std::cout << g.m_questions.size() << std::endl;
	for (int i = 0; i < g.m_questions.size(); i++)
	{
		if (!g.m_questions[i]->GetIsNumericQuestionBoolean())
		{
			MultipleChoiceQuestion* mcq = dynamic_cast<MultipleChoiceQuestion*>(g.m_questions[i]);
			std::cout << mcq->GetQuestion() << std::endl;
			std::cout << mcq->GetAnswer() << std::endl;
			std::vector<std::string> wrong = mcq->GetChoices();
			for (int i = 0; i < wrong.size(); i++)
			{
				std::cout << wrong[i] << std::endl;
			}
			std::cout << std::endl;
		}
		else
		{
			SingleNumericQuestion* snq = dynamic_cast<SingleNumericQuestion*>(g.m_questions[i]);
			std::cout << snq->GetQuestion() << std::endl;
			std::cout << snq->GetAnswer() << std::endl;
			std::cout << std::endl;
		}
	}
}