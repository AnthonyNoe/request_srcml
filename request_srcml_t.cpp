/*
  @file request_srcml_t.cpp

  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>

int main() {

	  std::string filename;
  std::string local_filename;
  std::string optional_filename;
  std::string enrty_filename;
  std::string optional_language;

    {
        srcml_request request = { "local_filename", "entry_filename", "optional_filename",\
 "optional_language"};
        assert(request_filename(request) == "");
        assert(request_language(request, "") == "");
    }

    filename = request_filename(request);
    assert(request_filename(request) == "local_filename");

	return 0;
	
}
