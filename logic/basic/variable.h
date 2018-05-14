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
typedef enum{
	Chg_Chnage,
	Chg_Unchange,
	Chg_Delete,
	Chg_Deleted,
}ChangeType;

class Variable
{
protected:
	bool init;
	bool manual;
	double death;
	double valueI;
	double valueO;
	double runtime;
	unsigned comid;
	unsigned keyid;
	string name;
	ABType abtype;
	IOType iotype;
	ChangeType change;
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
	ChangeType GetChange(void);
	const string& GetName(void);
	const unsigned GetCom(void)const;
	const unsigned GetKey(void)const;
public:
	void SetCom(const unsigned);
	void SetKey(const unsigned);
	void SetName(const string&);
	void SetInit(const bool);
	void SetManual(const bool);
	void SetDeath(const double&);
	void SetRuntime(const double&);
	void SetIOType(const IOType);
	void SetABType(const ABType);
	void SetChange(const ChangeType);
public:
	void SetReal(const double&);
	void SetValue(const double&);
	void SetValueIO(const double&, const double&);
public:
	void Define(ABType, IOType, unsigned, unsigned);
};

#endif//__VARIABLE_H__
