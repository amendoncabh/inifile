#include "inifile_err.h"

#include <sstream>

using namespace std;

static inline
string
build_parse_error(const char* src, int lnum, const string& __arg)
{
	stringstream sstr;
	sstr << src << ":" << lnum << ": " << __arg;
	return sstr.str();
}

parse_error::parse_error(const char* src, int lnum, const string& __arg) :
	runtime_error(build_parse_error(src, lnum, __arg))
{}

parse_error::~parse_error() throw() {}

notfound_error::notfound_error(const string& __arg) :
	invalid_argument(__arg)
{}

notfound_error::~notfound_error() throw() {}

duplicate_error::duplicate_error(const string& __type, const string& __arg) :
	invalid_argument("duplicate " + __type + ": " + __arg)
{}

duplicate_error::~duplicate_error() throw() {}

