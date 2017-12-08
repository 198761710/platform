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

class Variable
{
public:
	bool inited;
	bool manual;
	bool output;
	double value;
	double outvalue;
	double threshold;
	double runtime;
	VariableType type;
	TimeOperator ontime;
	TimeOperator offtime;
	TimeOperator outtime;
	list<string> waitqueue;
public:
	Variable(void);
public:
	const double Value(void);
	const double OnTime(void);
	const double OffTime(void);
	const double Runtime(void);
	const double GetValue(void);
	void SetRuntime(const double &t);
	void SoftSetValue(const double &v);
	void HardSetValue(const double &v);
public:
};

#endif//__VARIABLE_H__
