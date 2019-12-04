#ifndef JSONP_BUFFER_PARSER_H
#define JSONP_BUFFER_PARSER_H

#include "jsonP_parser.h"
#include "file_chunk_impl.h"

//
//class jsonP_buffer_parser : public jsonP_parser
//{
//private:
//	int buffer_size;
//	char *buffer;
//	bool more_chunks;
//	int read;
//	IChunk_reader *reader = nullptr;
//	
//	//magic numbers
//	int need_more_bytes{300};
//	int min_buffer_size{1024};
//	
//	int read_next_chunk();
//	bool check_buffer();
//	
//	//overrides
////	virtual void eat_whitespace(int idx) override;
//	virtual inline void eat_whitespace() override {
//		check_buffer();
//	
//		try {
//			jsonP_parser::eat_whitespace();
//		} catch (jsonP_exception &ex) {
//			if (index >= json_length) {
//				if (check_buffer())
//					eat_whitespace();
//				else
//					throw ex;
//			} else {
//				throw ex;
//			}
//		}
//		
//		check_buffer();
//	}
//	
////	jsonP_buffer_parser(std::string json) : jsonP_parser(json) {}
//	
//protected:
//	//overrides
//	virtual void parse_key(std::string &) override;
//	virtual void parse_bool(bool &) override;
////	virtual element_type parse_numeric(std::string &) override;
//virtual element_type parse_numeric() override;
////	virtual void parse_object(element_object *&) override;
//	
//public:
//	jsonP_buffer_parser(std::string file_name, int buf_sz = 8192);
//	jsonP_buffer_parser(IChunk_reader *reader, int buf_sz = 8192);
//	~jsonP_buffer_parser();
//
//	jsonP_doc * parse();
//};

#endif // JSONP_BUFFER_PARSER_H
