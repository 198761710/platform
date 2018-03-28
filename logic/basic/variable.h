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
	void SetInit(const bool b);
	void SetManual(const bool b);
	void SetDeath(const double &v);
	void SetRuntime(const double &v);
	void SetIOType(const IOType t);
	void SetABType(const ABType t);
public:
	void SetReal(const double &v);
	void SetValue(const double &v);
public:
	void Define(ABType, IOType);
};

#endif//__VARIABLE_H__
