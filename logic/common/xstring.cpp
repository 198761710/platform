#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <strings.h>
#include "xstring.h"

xstring::xstring(void)
{
}
xstring::xstring(const string& s)
{
    (*(string*)this) = s;
}
xstring::xstring(const xstring& x)
{
    (*(string*)this) = x;
}
xstring::xstring(const char* fmt,...)
{
    int len = -1;

    if( fmt )
    {
        va_list ap;
        char buf[BUFFER_SIZE];

        va_start(ap, fmt);
        len = vsnprintf(buf, sizeof(buf), fmt, ap);
        if( len > 0 )
        {
            if( len >= sizeof(buf) )
            {
                len = sizeof(buf) - 1;
            }
            buf[len] = 0;
            (*(string*)this) = buf;
        }
		else
		{
			printf("xstring %s(%d)\n", __func__, len);
		}
        va_end(ap);
    }
}
const char* xstring::trim(void)const
{
	if( empty() )
	{
		return NULL;
	}
	const char	*p = data();
	while(p && *p)
	{
		switch(*p)
		{
			case ' ':
			case '\a':
			case '\b':
			case '\f':
			case '\v':
			case '\t':
			case '\n':
			case '\r':
				p++;
				break;
			default:
				return p;
		}
	}
	return p;
}
const int xstring::toint(void) const
{
	const char *p = trim();
	if( NULL == p || 0 == *p )
	{
		return int(0);
	}
	if( strncasecmp("0x", p, 2) == 0 )
	{
		return strtol(p, 0, 16);
	}
    return atoi(p);
}
const bool xstring::tobool(void) const
{
	const char *p = trim();

    return p ? !strncasecmp("true", p, 4) : 0;
}
const float xstring::tofloat(void) const
{
	const char *p = trim();
    return p ? strtof(p, NULL) : 0.0;
}
const double xstring::todouble (void) const
{
	const char *p = trim();
    return p ? strtod(p, NULL) : 0.0;
}
const time_t xstring::totime(const char *fmt) const
{
	const char *p = trim();
    if( p && fmt )
    {
        struct tm t = {0};
        if( !strptime(p, fmt, &t) )
        {
            return time_t(0);
        }
        return mktime(&t);
    }
    return time_t(0);
}
const xstring& xstring::tformat(const char *fmt, const time_t t)
{
    if( fmt )
    {
        struct tm dtime = {0};
        if( localtime_r(&t, &dtime) )
        {
            char buf[64] = {0};
            strftime(buf, sizeof(buf), fmt, &dtime);
            (*this) = buf;
        }
    }
    return (*this);
}
const xstring& xstring::format(const char* fmt,...)
{
    int len = -1;

    if( fmt )
    {
        va_list ap;
        char buf[BUFFER_SIZE];

        va_start(ap, fmt);
        len = vsnprintf(buf, sizeof(buf), fmt, ap);
        if( len > 0 )
        {
            if( len >= sizeof(buf) )
            {
                len = sizeof(buf) - 1;
            }
            buf[len] = 0;
            (*(string*)this) = buf;
        }
		else
		{
			printf("xstring %s(%d)\n", __func__, len);
		}
        va_end(ap);
    }
	return *this;
}
const int xstring::scanf(const char* fmt, ...)
{
	int ret = 0;

	if( empty() == false )
	{
		va_list ap;

		va_start(ap, fmt);
		ret = vsscanf(data(), fmt, ap);
		va_end(ap);
	}

	return ret;
}
xstring& xstring::operator=(const xstring& x)
{
    (*(string*)this) = x.data();
    return *this;
}
string& xstring::operator()(void)
{
    return (*(string*)this);
}

#ifdef TEST_XSTRING
int main(void)
{
	xstring a = " \n0x33";
	xstring b = "	33";

	printf("%s=%d\n", a.data(), a.toint());
	printf("%s=%d\n", b.data(), b.toint());

	return 0;
}
#endif//TEST_XSTRING
