#pragma once
#include <crow.h>
#include "User.h"


class DeleteUserHandler
{
public:

	crow::response operator() (const crow::request& req) const;
};

