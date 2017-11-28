#include "json.h"

Json::Json(void):writer(sb),parseok(false)
{
}
Json::Json(const char* s):writer(sb),parseok(false)
{
	Parse(s);
}
Json::Json(const xstring& s):writer(sb),parseok(false)
{
	Parse(s);
}

bool Json::Parse(const char* s)
{
	if( NULL == s )
	{
		return false;
	}
	doc.Parse(s);
	parseok = (doc.HasParseError() == false);
	return parseok;
}
bool Json::Parse(const xstring& s)
{
	if( s.empty() )
	{
		return false;
	}
	return Parse( (const char*)s.data() );
}
const bool Json::ParseOk(void)const
{
	return parseok;
}
const Value& Json::NullValue(void) const
{
	return nullvalue;
}
JsonIterator Json::begin()
{
	if( true == parseok )
	{
		return doc.MemberBegin();
	}
	return nomember;
}
JsonIterator Json::end()
{
	if( true == parseok )
	{
		return doc.MemberEnd();
	}
	return nomember;
}
Value& Json::operator[](const char* s)
{
	if( NULL == s )
	{
		return nullvalue;
	}
	if( false == parseok )
	{
		return nullvalue;
	}
	if( doc.HasMember(s) )
	{
		return doc[s];
	}
	return nullvalue;
}

Value& Json::operator[](const xstring& s)
{
	if( s.empty() )
	{
		return nullvalue;
	}
	return (*this)[s.data()];
}
Value& Json::operator[](const unsigned int i)
{
	if(doc.MemberCount() < i )
	{
		return nullvalue;
	}
	if( false == parseok )
	{
		return nullvalue;
	}
	return doc[i];
}

void Json::Clear(void)
{
	sb.Clear();
}
bool Json::StartObject(void)
{
	return writer.StartObject();
}
bool Json::EndObject(void)
{
	return writer.EndObject();
}
bool Json::StartArray(void)
{
	return writer.StartArray();
}
bool Json::EndArray(void)
{
	return writer.EndArray();
}
bool Json::Key(const xstring& k)
{
	return writer.Key(k.c_str());
}
bool Json::String(const xstring& s)
{
	return writer.String(s.c_str());
}
bool Json::Null(void)
{
	return writer.Null();
}
bool Json::Bool(int b)
{
	return writer.Bool(b);
}
bool Json::Int(int i)
{
	return writer.Int(i);
}
bool Json::Uint(unsigned u)
{
	return writer.Uint(u);
}
bool Json::Int64(int64_t i64)
{
	return writer.Int64(i64);
}
bool Json::Uint64(uint64_t u64)
{
	return writer.Uint64(u64);
}
bool Json::Double(double d)
{
	return writer.Double(d);
}
const char* Json::GetJsonString(void)
{
	return sb.GetString();
}


//#define JSON_TEST
#ifdef JSON_TEST
int main(void)
{
	Json json;
	StringBuffer s;
	Writer<StringBuffer> writer(s);

	writer.StartObject();
	writer.Key("xx");
	writer.String("yy");
	{
		writer.Key("values");
		writer.StartArray();
		for(int i = 0; i < 10; i++)
		{
			writer.Int(i);
		}
		writer.EndArray();
	}
	writer.EndObject();

	printf("%s\n", s.GetString());
	json.Parse(s.GetString());	
	printf("v.size=%d\n", json["values"].Size());

	return 0;
}
#endif
