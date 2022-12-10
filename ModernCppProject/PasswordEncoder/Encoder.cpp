#include "Encoder.h"

Encoder::Encoder(const std::string& salt, uint16_t passwordLenght)
	:m_salt(salt), m_passwordLenght(passwordLenght)
{}

Encoder::Encoder()
{
	m_salt = "a2S(2#<q3d$f%:?_=%b$H3JyuF3-1";
	m_passwordLenght = 32;
}

char Encoder::GeneratePepper()
{
	std::random_device generator;
	std::uniform_int_distribution<int> distribution('a', 'z');
	return distribution(generator);
}

void Encoder::Lengthen(std::string& stringInput)
{
	if (stringInput.empty())
	{
		return;
	}

	std::string originalString = stringInput;

	while (stringInput.size() < m_passwordLenght - m_salt.size())
	{
		std::reverse(originalString.begin(), originalString.end());
		stringInput += originalString;
	}

	if (stringInput.size() > m_passwordLenght - m_salt.size())
	{
		stringInput.resize(m_passwordLenght - m_salt.size() - 1);
		stringInput.shrink_to_fit();
	}
}

void Encoder::SetSalt(const std::string& salt)
{
	m_salt = salt;
}

std::string Encoder::GetSalt()
{
	return m_salt;
}

std::string& Encoder::Encode(std::string& userInput, char pepper)
{
	std::cout << userInput << " <- this " << std::endl;
	if (userInput.empty())
	{
		return userInput;
	}
	std::string newPassword = userInput;
	char utilCharacter = ' ';

	if (pepper == '\0')
	{
		pepper = GeneratePepper();
	}

	Lengthen(newPassword);
	newPassword += m_salt;
	newPassword += pepper;

	for (int i = 0; i < m_passwordLenght; i++)
	{
		for (int j = i + 1; j < m_passwordLenght; j++)
		{
			utilCharacter = (newPassword[j] + utilCharacter) / 2;
		}
		newPassword[i] = (newPassword[i] + utilCharacter + newPassword[m_passwordLenght - i - 1]) / 3;
	}
	const int PRIME = 31;
	unsigned long long hash = 0;

	for (int i = 0; i < m_passwordLenght; i++)
	{
		hash += newPassword[i] * pow(PRIME, i);
	}

	std::default_random_engine generator(hash);
	std::mt19937 distribution(generator);

	std::shuffle(newPassword.begin(), newPassword.end(), distribution);

	return newPassword;
}


bool Encoder::TryToMatch(std::string& stringToBeChecked,std::string& password)
{
	for (char i = 'a'; i < 'z'; i++)
	{
		if (password == Encode(stringToBeChecked, i))
		{
			return true;
		}
	}

	return false;
}