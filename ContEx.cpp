#include "ContEx.h"




ContException::ContException(const string& msg, ErrorID id)
	:Exception(msg, id) {}

ContException::ContException(const char* msg, ErrorID id)
	:Exception(msg, id) {}


