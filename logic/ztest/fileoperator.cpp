#include <stdio.h>
#include "lineoperator.h"
#include "fileoperator.h"

int main(void)
{
	LineOperator line;
	FileOperator filer;
	FileOperator filew;

	filew.AddLine(line.Make("0,file1.bas"));
	filew.AddLine(line.Make("1,file2.bas"));
	filew.AddLine(line.Make("0,file%d.bas", 3));
	for(FileOperator::Iterator i = filew.begin(); i != filew.end(); i++)
	{
		printf("%s\n", i->second.data()); 
	}
	filew.Store("test.file");

	filer.Load("test.file");
	for(FileOperator::Iterator i = filer.begin(); i != filer.end(); i++)
	{
		line.Set(i->second).Trim();
		line.Set(line.Get()).Trim();
		printf("%s\n", line.Get().data());
	}

	return 0;
}
