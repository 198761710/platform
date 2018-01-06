#ifndef __FILE_OPERATOR_H__
#define __FILE_OPERATOR_H__
#include <stdio.h>
#include <string>
#include "record.h"
using namespace std;

class FileOperator
{
protected:
	FILE *fp;

public:
	FileOperator(void);
	~FileOperator(void);

public:
	bool Close(void);
	bool Open(const string&);
	bool ReadRecord(Record&);
	bool WriteRecord(const Record&);
	bool Seek(int);
	int Size();
};

#endif//__FILE_OPERATOR_H__
