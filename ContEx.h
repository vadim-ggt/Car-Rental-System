#pragma once
#include "CLASS_EXEPTION.h"
class ContException : public Exception
{
public:
	explicit ContException(const string&, ErrorID id);
	explicit ContException(const char* msg, ErrorID id);
};
