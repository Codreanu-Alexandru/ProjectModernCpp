#pragma once
#include <string>
#include <random>
#include <algorithm>
#include <cmath>
#include <iostream>

class Encoder
{
private:

	std::string m_salt;
	uint16_t m_passwordLenght;

	char GeneratePepper();
	void Lengthen(std::string& stringInput);

public:

	Encoder(const std::string& salt, uint16_t passwordLenght);
	Encoder();

	void SetSalt(const std::string& salt);
	std::string GetSalt();

	std::string Encode(const std::string& userInput, char pepper);

	bool TryToMatch(const std::string& stringToBeChecked, const std::string& password);
};
