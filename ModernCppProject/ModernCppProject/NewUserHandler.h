#pragma once
#include <crow.h>
#include "User.h"

class NewUserHandler
{
public:
	crow::response operator() (const crow::request& req) const;
};

