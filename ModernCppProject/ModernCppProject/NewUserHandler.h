#pragma once
#include <crow.h>
#include "User.h"

class NewUserHandler
{
public:
	/*Operator overload*/
	crow::response operator() (const crow::request& req) const;
};

