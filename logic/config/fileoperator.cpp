#include <stdlib.h>
#include <string.h>
#include "fileoperator.h"

FileOperator::FileOperator(void)
{
	fp = 0;
}
FileOperator::~FileOperator(void)
{
	Close();
}
bool FileOperator::Open(const string& path)
{
	fp = fopen(path.data(), "r+");
	if( NULL == fp )
	{
		fp = fopen(path.data(), "w+");
	}
	return (NULL != fp);
}
bool FileOperator::ReadRecord(Record& rc)
{
	int len = 0;
	int offs = -1;
	unsigned char buf[sizeof(int)];

	offs = ftell(fp);
	if( -1 == offs )
	{
		return false;
	}
	if( fread(buf, sizeof(buf), 1, fp) != 1 )
	{
		return false;//feof(fp);
	}
	len  = 4;
	len += (buf[0] << 24);
	len += (buf[1] << 16);
	len += (buf[2] <<  8);
	len += (buf[3] <<  0);
	len += 2;
	if( len < MIN_RECORD_BUFF_LEN )
	{
		return false;
	}
	if( len > MAX_RECORD_BUFF_LEN )
	{
		return false;
	}
	if( rc.Malloc(len) == false )
	{
		return false;
	}
	if( fread((char*)rc.GetBuffer()+4, len-4, 1, fp) != 1 )
	{
		return false;
	}
	memcpy((void*)rc.GetBuffer(), (void*)buf, sizeof(buf));
	rc.SetOffset( offs );

	return true;
}
bool FileOperator::WriteRecord(const Record& rc)
{
	int ret = 0;

	if( rc.GetBuffer() == NULL )
	{
		return false;
	}
	if( rc.GetBufferLength() < MIN_RECORD_BUFF_LEN )
	{
		return false;
	}
	if( rc.GetBufferLength() > MAX_RECORD_BUFF_LEN )
	{
		return false;
	}
	if( rc.GetOffset() == -1 )
	{
		ret = fseek(fp, 0, SEEK_END);
	}
	else
	{
		ret = fseek(fp, rc.GetOffset(), SEEK_SET);
	}
	if( -1 == ret )
	{
		printf("%s.%d\n", __func__, __LINE__);
		return false;
	}
	if( fwrite(rc.GetBuffer(), rc.GetBufferLength(), 1, fp) != 1 )
	{
		printf("%s.%d\n", __func__, __LINE__);
		return false;
	}
	fflush(fp);
	return true;
}
bool FileOperator::Close(void)
{
	return (fclose(fp) == 0);
}
bool FileOperator::Seek(int offset)
{
	if( offset < 0 )
	{
		return (fseek(fp, 0, SEEK_END) == 0);
	}
	return (fseek(fp, offset, SEEK_SET) == 0);
}
int FileOperator::Size()
{
	int offset = ftell(fp);
	if( -1 == offset )
	{
		return offset;
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, offset, SEEK_SET);
	return size;
}

#ifdef TEST_FILEOPERATOR
void Write(FileOperator& file)
{	
	for(int i = 0; i < 32; i++)
	{
		Record rc;
		float d = i;

		rc.SetData((unsigned char*)&d, sizeof(d));
		rc.SetOffset(i * rc.GetBufferLength());
		file.WriteRecord(rc);
	}
}
void Read(FileOperator& file)
{
	file.Seek(0);
	while(1)
	{
		Record rc;

		if( file.ReadRecord(rc) )
		{
			rc.Show();
			float d = (*(float*)rc.GetData()) * 1.1234;
			rc.SetData((unsigned char*)&d, sizeof(d));
			file.WriteRecord(rc);
			continue;
		}
		break;
	}
}
int main(void)
{
	FileOperator file;

	file.Open("test.db");

	Write(file);
	printf("file.size(%d)\n", file.Size());
	for(int i = 0; i < 100; i++)
	{
		Read(file);
		getchar();
	}

	return 0;
}
#endif//TEST_FILEOPERATOR
