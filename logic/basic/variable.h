#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include <list>
#include <string>
#include <time.h>
#include "timeoperator.h"
using namespace std;

typedef enum
{
	VarValue,
	VarInput,
	VarOutput,
}VariableType;
typedef enum
{
	Binary,
	Analog,
}ValueType;

class Variable
{
public:
	bool init;
	bool manual;
	bool output;
	double value;
	double outvalue;
	double threshold;
	double runtime;
	ValueType valuetype;
	VariableType vartype;
	TimeOperator ontime;
	TimeOperator offtime;
	TimeOperator outtime;
	list<string> waitqueue;
public:
	Variable(void);
public:
	bool GetInit(void);
	bool GetManual(void);
	bool GetOutput(void);
	double GetValue(void);
	double GetOnTime(void);
	double GetOffTime(void);
	double GetRuntime(void);
	double GetThreshold(void);
	ValueType GetValueType(void);
	VariableType GetVariableType(void);
public:
	void SetInit(const bool b);
	void SetManual(const bool b);
	void SetOutput(const bool b);
	void SetRuntime(const double &v);
	void SetThreshold(const double &v);
	void SetValueType(const ValueType t);
	void SetVariableType(const VariableType t);
public:
	void SoftSetValue(const double &v);
	void HardSetValue(const double &v);
public:
};

#endif//__VARIABLE_H__
