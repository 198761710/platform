#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "lineoperator.h"
#include "crc16.h"

LineOperator::LineOperator(void)
{
}
LineOperator::LineOperator(const string& l)
{
	Set(l);
}
const string& LineOperator::Get(void)const
{
	return data;
}
LineOperator& LineOperator::Set(const string& line)
{
	if( line.empty() )
	{
		data = line;
	}
	else
	{
		char buf[LINE_BUF_SIZE];
		sscanf(line.data(), "%s$", buf);
		buf[sizeof(buf)-1] = 0;
		data = buf;
	}
	return *this;
}

LineOperator& LineOperator::Add(const int v)
{
	char buf[32];

	if( data.empty() )
	{
		snprintf(buf, sizeof(buf), "%u", v);
	}
	else
	{
		snprintf(buf, sizeof(buf), ",%u", v);
	}
	data += buf;
	return *this;
}
LineOperator& LineOperator::Add(const double v)
{
	char buf[32];

	if( data.empty() )
	{
		snprintf(buf, sizeof(buf), "%f", v);
	}
	else
	{
		snprintf(buf, sizeof(buf), ",%f", v);
	}
	data += buf;
	return *this;
}
LineOperator& LineOperator::Add(const string& v)
{
	if( data.empty() == false )
	{
		data += ",";
	}
	data += v;
}
const string& LineOperator::Make(void)
{
	if( Check() == false )
	{
		char buf[32];
		unsigned crc = CRC16(data.data(), data.length());
		snprintf(buf, sizeof(buf), "%u,", crc);
		data = buf + data;
	}
	return data;
}
const string& LineOperator::Trim(void)
{
	if( Check() )
	{
		data = strchr(data.data(), ',') + 1;
	}

	return data;
}
const string& LineOperator::Make(const char* fmt,...)
{
	if( fmt )
	{
		va_list ap;
		char buf[LINE_BUF_SIZE];

		va_start(ap, fmt);
		vsnprintf(buf, sizeof(buf), fmt, ap);
		va_end(ap);
		data = buf;
	}
	return Make();
}
const int LineOperator::Scan(const char* fmt,...)
{
	int ret = 0;

	if( fmt && data.empty() == false )
	{
		va_list ap;
		va_start(ap, fmt);
		ret = vsscanf(data.data(), fmt, ap);
		va_end(ap);
	}

	return ret;
}
const bool LineOperator::Check(void)
{
	if( data.empty() )
	{
		return false;
	}
	const char *p = strchr(data.data(), ',');
	if( NULL == p++ )
	{
		return false;
	}
	return atoi(data.data()) == CRC16(p, strlen(p));
}
