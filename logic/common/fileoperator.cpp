#include <stdio.h>
#include <stdarg.h>
#include "fileoperator.h"

int FileOperator::AddLine(const string& line)
{
	linemap[linemap.size()] = line;
	return linemap.size();
}
int FileOperator::AddLine(const char* fmt,...)
{
	if( fmt )
	{
		int n = 0;
		va_list ap;
		char buf[4096];

		va_start(ap, fmt);
		n = vsnprintf(buf, sizeof(buf), fmt, ap);
		va_end(ap);
		AddLine(string(buf));
		return n;
	}

	return 0;
}
int FileOperator::LineCout(void)
{
	return linemap.size();
}
const string& FileOperator::GetLine(int line)
{
	iterator i = linemap.find(line);
	if( linemap.end() == i )
	{
		return emptyline;
	}
	return i->second;
}
bool FileOperator::Load(const string& fname)
{
	if( fname.empty() )
	{
		return false;
	}
	FILE *fp = fopen(fname.data(), "r");
	if( NULL == fp )
	{
		return false;
	}
	for(int i = 0; i < 20000; i++)
	{
		char buf[1024] = {0};
		if( fgets(buf, sizeof(buf), fp) )
		{
			linemap[i] = buf;
		}
		else
		{
			return false;
		}
	}
	fclose(fp);
	return true;
}
bool FileOperator::Store(const string& fname)
{
	if( fname.empty() )
	{
		return false;
	}
	FILE *fp = fopen(fname.data(), "w");
	if( NULL == fp )
	{
		return false;
	}
	for(iterator i = linemap.begin(); i != linemap.end(); i++)
	{
		if( fwrite(i->second.data(), i->second.length(), 1, fp) != 1 )
		{
			return false;
		}
	}
	fclose(fp);
	return true;
}
