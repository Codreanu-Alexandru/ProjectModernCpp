#pragma once
#include<iostream>
#include<vector>
#include<stdio.h>
#include "Region.h"
#include"Advantages.h"
#include "User.h"

class Player
{
private:
	std::string m_name;
	Region m_base;
	std::vector<Region> m_territory;
	uint16_t m_score;
	Advantages m_advantages;
	//User m_user;

public:
	//Player(User user);

};

