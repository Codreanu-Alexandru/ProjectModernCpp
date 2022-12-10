#pragma once
#include <string>
#include <random>
#include <algorithm>
#include <cmath>
#include <iostream>

#ifdef PASSWORDENCODER_EXPORTS
#define PASSWORDENCODER_API __declspec(dllexport)
#else
#define PASSWORDENCODER_API __declspec(dllimport)
#endif

class PASSWORDENCODER_API Encoder
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

	std::string& Encode(std::string& userInput, char pepper);

	bool TryToMatch(std::string& stringToBeChecked, std::string& password);
};