#ifndef __RECORD_H__
#define __RECORD_H__
#include <stdio.h>

#define MIN_RECORD_DATA_LEN	1
#define MAX_RECORD_DATA_LEN	1024
#define MIN_RECORD_BUFF_LEN	(4 + MIN_RECORD_DATA_LEN + 2)
#define MAX_RECORD_BUFF_LEN	(4 + MAX_RECORD_DATA_LEN + 2)

class Record
{
protected:
	int offset;
	unsigned char *buffer;
public:
	Record(void);
	~Record(void);

public:
	const bool Check(void)const;
	const int GetOffset(void)const;
	const int GetDataLength(void)const;
	const int GetBufferLength(void)const;
	const unsigned char* GetBuffer(void)const;
	const unsigned char* GetData(void)const;
	const unsigned short GetCrc(void)const;

public:
	void Show(void);
	bool Malloc(int);
	void SetOffset(int offset);
	void SetData(const unsigned char *p, int len);
};

#endif//__RECORD_H__
