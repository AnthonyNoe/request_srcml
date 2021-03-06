/*
  @file request_srcml.cpp

  Implementation of request_srcml()
*/

#include "request_srcml.hpp"
#include "get_language_from_filename.hpp"

// extracts the filename to use from the request
std::string request_filename(const srcml_request& request) {

    // TODO: determine the proper filename from the request
    std::string filename;
	
	filename = request.local_filename;
    if(request.optional_filename != "") 
    {
	return request.optional_filename;    
    }

    if(request.entry_filename == "data")
    {
	filename = request.local_filename;    
    
    } else if(request.entry_filename != "data")
    {
	filename = request.entry_filename;    
    }
	
    if(request.local_filename == "-")
    {
	if(request.entry_filename != "data")
		filename = request.entry_filename;
	
	if(request.entry_filename == "data")
		filename = request.optional_filename;
	   
	if(request.optional_filename == "")
		filename = "";
    }
	
    return filename;
}

// extracts the language to use from the request, and the filename
std::string request_language(const srcml_request& request, const std::string& filename) {

    // TODO: determine the proper filename from the request
    std::string language;
	
	if(request.optional_language != "")
	{
		return request.optional_language;	
	}
	
	if(request.entry_filename == "data")
	{
		language = "C++";
		return language;
	} else {
		
		language = get_language_from_filename(filename);
	}

    return language;
}

// generates srcML based on the request
void generate_srcml(const srcml_request& request) {

	std::string filename = request_filename(request);

	std::string language = request_language(request, filename);

	// srcML generation code that is not available yet
	
	if(language == "")
	{
		std::cerr << "Extension not supported";
		return false;
	}
	if(request.local_filename == "-")
		if(language == "")
		{
			std::cerr << "Using std::cin requires a dedicated language";
			return false;
		}
	
}
