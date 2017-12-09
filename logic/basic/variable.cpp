#include <math.h>
#include <stdlib.h>
#include "variable.h"


Variable::Variable(void)
{
	init = true;
	manual = false;
	output = false;
	value  = 0.000;
	outvalue = 0.000;
	runtime = 0.0000;
	threshold = 0.0001;
	vartype = VarValue;
	valuetype = Analog;
}
bool Variable::GetInit(void)
{
	return init;
}
bool Variable::GetManual(void)
{
	return manual;
}
bool Variable::GetOutput(void)
{
	return output;
}
double Variable::GetValue(void)
{
	return value;
}
double Variable::GetThreshold(void)
{
	return threshold;
}
double Variable::GetOnTime(void)
{
	if( fabs(value) >= 0.9999 )
	{
		return (double)ontime.sdiff();
	}
	return double(0.0000);
}
double Variable::GetOffTime(void)
{
	if( fabs(value) < 0.9999 )
	{
		return (double)offtime.sdiff();
	}
	return double(0.0000);
}
double Variable::GetRuntime(void)
{
	return runtime + GetOnTime();
}

void Variable::SetInit(const bool b)
{
	init = b;
}
void Variable::SetManual(const bool b)
{
	manual = b;
}
void Variable::SetOutput(const bool b)
{
	output = b;
}
void Variable::SetRuntime(const double &v)
{
	runtime = v;
}
void Variable::SetThreshold(const double &v)
{
	threshold = v;
}
void Variable::SetValueType(const ValueType t)
{
	valuetype = t;
}
void Variable::SetVariableType(const VariableType t)
{
	vartype = t;
}

void Variable::SoftSetValue(const double &v)
{
	if( manual )
	{
		return;
	}
	HardSetValue(v);
}
void Variable::HardSetValue(const double &v)
{
	if( fabs(v - value) < threshold )
	{
		return;
	}
	if( fabs(value) >= 0.9999 && fabs(v) < 0.9999 )
	{
		offtime.init();
		runtime += (double)ontime.sdiff();
	}
	else if( fabs(value) < 0.9999 && fabs(v) >= 0.9999 )
	{
		ontime.init();
	}
	value = v;
}
