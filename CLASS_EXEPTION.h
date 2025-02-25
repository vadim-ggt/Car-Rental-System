#pragma once

#include <iostream>
#include <string> 

using namespace std;

enum class ErrorID
{
	INVALID_INPUT = 1,
	INVALID_FORMAT,
	OUT_OF_RANGE,
	EMPTY_CONTAINER
};

class Exception
{
protected:
	std::string errorMsg;
	ErrorID errorID;
public:
	virtual void ErrorOut() const;
	ErrorID GetErrorID() const;

	Exception() noexcept;
	Exception(const string&, ErrorID) noexcept;
	Exception(const Exception&) noexcept;
	virtual ~Exception();

	Exception& operator=(const Exception&) noexcept;
};