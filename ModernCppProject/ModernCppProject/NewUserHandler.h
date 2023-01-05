#pragma once
#include <crow.h>
#include "User.h"
#include "../Encoder/Encoder.h"

class NewUserHandler
{
public:
	/*Operator overload*/
	crow::response operator() (const crow::request& req) const;
};

