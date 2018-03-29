#include <stdio.h>
#include <string.h>
#include "fileoperator.h"

int FileOperator::AddLine(const string& line)
{
	linemap[linemap.size()] = line;
	return linemap.size();
}
int FileOperator::LineCout(void)
{
	return linemap.size();
}
const string& FileOperator::GetLine(int line)
{
	Iterator i = linemap.find(line);
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
			char *p = strchr(buf, '\n');
			if( p )
			{
				*p = 0;
			}
			linemap[i] = buf;
		}
		else
		{
			break;
		}
	}
	fclose(fp);
	return !linemap.empty();
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
	for(Iterator i = begin(); i != end(); i++)
	{
		if( fwrite(i->second.data(), i->second.length(), 1, fp) != 1 )
		{
			return false;
		}
		fwrite("\n", 1, 1, fp);
	}
	fclose(fp);
	return true;
}
