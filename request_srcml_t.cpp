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
	
    // A test case to assure that if entry_filename contains
    //the string "data" that the local_filename is not empty
    
if(request.entry_filename == "data")
      {
        assert(request.local_filename != "");
      }

    // A test case to determine make sure the entry_filename
    // is used if the file is std::cin and not a source code archive
    // if the file does contain source-code archive then the test
    // makes sure that the optional_filename is not empty
    if(request.local_filename == "-")
      {
        if(request.entry_filename != "data")
          assert(request.entry_filename != "");

        if(request.entry_filename == "data")
          assert(request.optional_filename != "");
      }

    // Testing to make sure there is a local filename if no
    // optional_filename is given
    if(request.optional_filename == "")
      {
        assert(request.local_filename != "");
      }
	
    // A test case to make sure entry_filename is not empty
    // if no optional language is given
    if(request.optional_language == "")
      {
        assert(request.local_filename != "");
      }

    If(request.optional_language != "")
    {
	assert(request_language(request) == request.optional_language);    
    }
	return 0;
	
}
