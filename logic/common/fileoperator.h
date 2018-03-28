#ifndef __FILE_OPERATOR_H__
#define __FILE_OPERATOR_H__
#include <map>
#include <string>
using namespace std;

class FileOperator
{
protected:
	string emptyline;
	map<int,string>	 linemap;
public:
	typedef map<int,string>::iterator iterator;
public:
	int LineCout(void);
	const string& GetLine(int);
	int AddLine(const string&);
	int AddLine(const char*,...);
public:
	bool Load(const string&);
	bool Store(const string&);
};

#endif//__FILE_OPERATOR_H__
