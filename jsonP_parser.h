#ifndef _JSONP_PARSER_H_
#define _JSONP_PARSER_H_

#include "element_object.h"
//#include "jsonP_exception.h"
#include "jsonP_json.h"

#include <string>

//#define get_element_type(buf,indx)		*(element_type*)&(buf)[ (indx) ]
//#define get_key_location(buf,indx)		*(unsigned int*)&(buf)[ (indx) ]
//#define get_key_count(buf,indx)		*(unsigned int*)&(buf)[ (indx) ]
//#define increase_stack_buffer()			((stack_buf_sz) - (stack_i)) < 50
//#define increase_data_buffer(needed)	((data_sz) - (data_i)) < needed


//typedef char byte;

const int ltr_b = (int)'b';
const int space = (int)' ';
const int tab = (int)'\t';
const int new_line = (int)'\n';
const int car_return = (int)'\r';
const int quote_int = (int)'"';
const int bk_slsh = (int)'\\';
const int fwd_slsh = (int)'/';
const int comma_int = (int)',';
const int lft_curly = (int)'{';
const int rt_curly = (int)'}';
const int lft_brac = (int)'[';
const int rt_brac = (int)']';
const int colon = (int)':';
const int ltr_f = (int)'f';
const int ltr_r = (int)'r';
const int ltr_n = (int)'n';
const int ltr_t = (int)'t';
const int ltr_u = (int)'u';
const int ltr_e = (int)'e';
const int ltr_E = (int)'E';
const int ltr_T = (int)'T';
const int ltr_F = (int)'F';
const int zero = (int)'0';
const int nine = (int)'9';
const int plus = (int)'+';
const int minus = (int)'-';
const int period = (int)'.';


//static size_t obj_member_sz = sizeof(element_type) + sizeof(unsigned int);
//static size_t obj_root_sz = sizeof(unsigned int);
//static size_t arry_member_sz = obj_member_sz;
//static size_t arry_root_sz = obj_root_sz;
//static size_t obj_member_key_offx = sizeof(element_type);
//static size_t arry_member_val_offx = sizeof(element_type);


// used to partition each element used during sorting
struct obj_member
{
	//byte b[obj_member_sz];      // <-- hardcode for now, see if I can change this with define if else ???
	byte b[5];
};


struct parse_stats
{
	unsigned short stack_buf_increases = 0;
	unsigned short data_increases = 0;
};
	
	
/*
 * borrowed from Chad Austin, sajson; who borrowed it from Rich Geldreich's Purple JSON parser
 */
const uint8_t parse_flags[256] = {
//  0    1    2    3    4    5    6    7      8    9    A    B    C    D    E    F
	0,   0,   0,   0,   0,   0,   0,   0,     0,   2,   2,   0,   0,   2,   0,   0, // 0
	0,   0,   0,   0,   0,   0,   0,   0,     0,   0,   0,   0,   0,   0,   0,   0, // 1
	3,   1,   0,   1,   1,   1,   1,   1,     1,   1,   1,   1,   1,   1,   0x11,1, // 2
	0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,  0x11,0x11,1,   1,   1,   1,   1,   1, // 3
	1,   1,   1,   1,   1,   0x11,1,   1,     1,   1,   1,   1,   1,   1,   1,   1, // 4
	1,   1,   1,   1,   1,   1,   1,   1,     1,   1,   1,   1,   0,   1,   1,   1, // 5
	1,   1,   1,   1,   1,   0x11,1,   1,     1,   1,   1,   1,   1,   1,   1,   1, // 6
	1,   1,   1,   1,   1,   1,   1,   1,     1,   1,   1,   1,   1,   1,   1,   1, // 7

// 128-255
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0
};



class jsonP_parser
{
protected:
//	std::string json;
	std::string json_str;
	char * json = nullptr;
	unsigned long json_length;
	unsigned int index;
	bool look_for_key;
	unsigned int value_start;
	
// STUFF for new modle to rid std::map and std::new for each element
byte * stack_buf;
unsigned int stack_buf_sz;
unsigned int stack_i;

//change to array later so it can be blocks for now large buffer to see if i can get this to work
byte * data;
unsigned long data_sz;
unsigned long data_i;

bool use_json;
bool shrink_buffers;

parse_stats stats;
// END STUFF for new modle to rid std::map and std::new for each element


	//error stuff
	std::string error_string;
	int error_index;
	std::string error_json_snip;
	
	//virtual parse commands
//	virtual void eat_whitespace(int);
	virtual inline __attribute__((always_inline)) void eat_whitespace() {
//		while ((json[index] == space || json[index] == tab || json[index] == new_line || 
//			json[index] == car_return))// && json_length > index) 
//			index++;
		while (parse_flags[json[index]] & 2)
			index++;
	}
	
//	virtual void parse_key(std::string &);
//	virtual void parse_bool(bool &);
//////	virtual element_type parse_numeric(std::string &);
////	virtual element_type parse_numeric();
//	virtual unsigned int parse_array(element_array *&);
//	virtual unsigned int parse_object(element_object *&);
//	virtual void parse_value(element *&);

	virtual void parse_key();
	virtual void parse_bool();
	virtual element_type parse_numeric();
	virtual unsigned int parse_array();
	virtual unsigned int parse_object();
	virtual void parse_value();
	

//	virtual inline element_string * create_string_element(std::string &str) { return new element_string{str}; }
//	virtual inline element_boolean * create_boolean_element(bool b) { return new element_boolean{b}; }
//	virtual inline element_numeric * create_int_element(char *ptr) { return new element_numeric{ptr, numeric_int}; }
//	virtual inline element_numeric * create_long_element(char *ptr) { return new element_numeric{ptr, numeric_long}; }
//	virtual inline element_numeric * create_float_element(char *ptr) { return new element_numeric{ptr, numeric_double}; }
//
//	virtual inline element_null * create_null_element() { return new element_null{}; }
//	
//	virtual inline element_array * create_element_array(element_type t) { return new element_array{t}; }
//	virtual inline void add_array_element(element_array *a, element *e) { a->add_element(e); }
//	
//	virtual inline element_object * create_element_object() { return new element_object{}; }
//	virtual inline void add_object_element(element_object *o, element *e, std::string &k) { o->add_element(k, e); }
	
	void set_error(std::string error);

void test_parse_object(unsigned int);
void test_parse_array(unsigned int);



public:
	jsonP_parser() = default;
	jsonP_parser(std::string & json, short options = 0);
	jsonP_parser(char * json, unsigned long, short options = 0);
	
	~jsonP_parser();

	jsonP_json * parse();
	jsonP_json * parse(std::string & json);
	jsonP_json * parse(char * json, unsigned long);

	std::string get_error_string() { return error_string; }
	int get_error_index() { return error_index; }
	std::string get_error_snip(int chars_before, int chars_after);
	
	parse_stats get_parse_stats() { return stats; }
};

#endif // _JSONP_PARSER_H_
