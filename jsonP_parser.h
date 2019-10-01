#ifndef _JSONP_PARSER_H_
#define _JSONP_PARSER_H_

#include "element_object.h"
//#include "jsonP_exception.h"

#include <string>


class jsonP_parser
{
private:
	std::string json;
	int index;
	
	void eat_whitespace(int);
	
	void parse_value(element *&);
	void parse_array(element_array *&);
	void parse_object(element_object *&);
	void parse_key(std::string &);
	void parse_bool(bool &);
	void parse_numeric(long &);
	
public:
	jsonP_parser() = default;
	jsonP_parser(std::string json);
	~jsonP_parser() = default;

	jsonP_doc * parse();
	jsonP_doc * parse(std::string & json);
};

#endif // _JSONP_PARSER_H_
