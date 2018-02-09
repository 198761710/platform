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
protected:
	bool init;
	bool manual;
	double value;
	double runtime;
	double outvalue;
	double threshold;
	string listener;
	ValueType valuetype;
	VariableType vartype;
	TimeOperator ontime;
	TimeOperator offtime;
	TimeOperator outtime;
public:
	Variable(void);
public:
	bool Output(void);
	bool GetInit(void);
	bool GetManual(void);
	double GetValue(void);
	double GetOnTime(void);
	double GetOffTime(void);
	double GetRuntime(void);
	double GetOutValue(void);
	double GetThreshold(void);
	const string& GetListener(void);
	VariableType GetVariableType(void);
	ValueType GetValueType(void);
public:
	void SetInit(const bool b);
	void SetManual(const bool b);
	void SetRuntime(const double &v);
	void SetThreshold(const double &v);
	void SetListener(const string &ls);
	void SetValueType(const ValueType t);
	void SetVariableType(const VariableType t);
public:
	void SoftSetValue(const double &v);
	void HardSetValue(const double &v);
public:
	void SetDefine(ValueType, VariableType);
};

#endif//__VARIABLE_H__
