#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include <list>
#include <string>
#include <time.h>
#include "timeoperator.h"
using namespace std;

typedef enum
{
	IO_Holding,
	IO_Input,
	IO_Output,
}IOType;
typedef enum
{
	AB_Analog,
	AB_Binary,
}ABType;

class Variable
{
protected:
	bool init;
	bool manual;
	char change;
	double death;
	double valueI;
	double valueO;
	double runtime;
	string name;
	ABType abtype;
	IOType iotype;
	TimeOperator ontime;
	TimeOperator offtime;
	TimeOperator outtime;
public:
	Variable(void);
public:
	bool Output(void);
	bool GetInit(void);
	bool GetManual(void);
	char GetChange(void);
	double GetDeath(void);
	double GetValueI(void);
	double GetValueO(void);
	double GetOnTime(void);
	double GetOffTime(void);
	double GetRuntime(void);
	ABType GetABType(void);
	IOType GetIOType(void);
	const string& GetName(void);
public:
	void SetName(const string&);
	void SetInit(const bool);
	void SetChange(const char);
	void SetManual(const bool);
	void SetDeath(const double&);
	void SetRuntime(const double&);
	void SetIOType(const IOType);
	void SetABType(const ABType);
public:
	void SetReal(const double&);
	void SetValue(const double&);
public:
	void Define(ABType, IOType);
};

#endif//__VARIABLE_H__
