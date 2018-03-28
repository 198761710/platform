#include <stdio.h>
#include "fileoperator.h"

int main(void)
{
	FileOperator file;
	FileOperator filer;

	file.AddLine("test line one\n");
	file.AddLine("test line tow\n");
	file.AddLine("test line %d\n", 3);
	for(int i = 0; i < file.LineCout(); i++)
	{
		printf("%d:%s", i, file.GetLine(i).data());
	}
	file.Store("test.file");

	filer.Load("test.file");
	for(int i = 0; i < filer.LineCout(); i++)
	{
		printf("%d:%s", i, filer.GetLine(i).data());
	}

	return 0;
}
