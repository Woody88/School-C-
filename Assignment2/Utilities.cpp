#include <iostream>
#include <functional>
#include <algorithm>
#include <cctype>
#include "Utilities.h"

char Utilities::delimiter = 0;

Utilities::Utilities(size_t minimum_field_width) { field_width = minimum_field_width; }
void Utilities::setFieldWidth(size_t fw) { field_width = fw; }
size_t Utilities::getFieldWidth() const { return field_width; }

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) { 
	std::string token = str;
	size_t pos = str.find(delimiter, next_pos+1);
	
	// If it doesnt find delimiter more is set to false
	if (pos == std::string::npos) {
		pos = str.length();
		more = false;
	}
	// If found a delimiter push posing of plus 1 to avoid including delimiter in parsing
	if(pos != std::string::npos){
		if (next_pos > 0)
			next_pos++;
		token = str.substr(next_pos, pos-next_pos);
	}


	// If delimiter starts at begining of the string, read string from the next position 
	// until next delimiter without including none of the delimiters
	if (str.at(0) == delimiter){
		//token = str.substr(1, pos-2);
		more = false;
		return "";
		
	}

	// Trim right side of token
	token.erase(token.begin(), std::find_if( token.begin(), token.end(), std::not1( std::ptr_fun<int, int>( std::isspace ) ) ) );
	token.erase(std::find_if( token.rbegin(), token.rend(), std::not1( std::ptr_fun<int, int>( std::isspace ) ) ).base(), token.end() );
	next_pos = pos;

	if (token.size() > field_width)
		field_width = token.size();

	//beg = token.find_first_not_of(" ");
	//if(beg == std::string::npos){
	// 	more = false;
	// 	return "";
	// }

	return token;
}
void Utilities::setDelimiter(const char c) { delimiter = c; }
const char Utilities::getDelimiter() { return delimiter; }