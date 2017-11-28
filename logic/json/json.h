#ifndef __JSON_H__
#define __JSON_H__
#include "xstring.h"
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
using namespace rapidjson;

typedef	Document::MemberIterator JsonIterator;
class Json
{
private:	
	bool parseok;
	Document doc;
	Value nullvalue;
	StringBuffer sb;
	Writer<StringBuffer> writer;
	JsonIterator nomember;

public:
	Json(void);
	Json(const char* s);
	Json(const xstring& s);

public:
	bool Parse(const char* s);
	bool Parse(const xstring& s);
	const bool ParseOk(void)const;
	const Value& NullValue(void)const;
	const JsonIterator& NullNode(void)const;
	Value& operator[](const char* s);
	Value& operator[](const xstring& s);
	Value& operator[](const unsigned int i);
	JsonIterator begin(void);
	JsonIterator end(void);

public:
	void Clear(void);
	bool StartObject(void);
	bool EndObject(void);
	bool StartArray(void);
	bool EndArray(void);
	bool Key(const xstring&	k);
	bool String(const xstring&	s);
	bool Null(void);
	bool Bool(int b);
	bool Int(int i);
	bool Uint(unsigned u);
	bool Int64(int64_t i64);
	bool Uint64(uint64_t u64);
	bool Double(double d);
	const char* GetJsonString(void);
};

#endif//__JSON_H__
