#pragma once
#include<iostream>
#include<vector>
#include<stdio.h>
#include "Region.h"
#include"Advantages.h"

class Player
{
public:
	Player(std::string name);
private:
	std::string m_name;
	Region m_base;
	std::vector<Region> m_territory;
	uint16_t m_score;
	Advantages m_advantages;

};

