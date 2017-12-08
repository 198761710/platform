#include <math.h>
#include <stdlib.h>
#include "variable.h"


Variable::Variable(void)
{
	//inited = false;
	inited = true;
	manual = false;
	output = false;
	value  = 0.000;
	outvalue = 0.000;
	runtime = 0.0000;
	threshold = 0.0001;
	type = VarValue;
}
const double Variable::Value(void)
{
	return value;
}
const double Variable::GetValue(void)
{
	if( inited )
	{
		return value;
	}
	return double(0.0000);
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
const double Variable::OnTime(void)
{
	if( fabs(value) >= 0.9999 )
	{
		return (double)ontime.sdiff();
	}
	return double(0.0000);
}
const double Variable::OffTime(void)
{
	if( fabs(value) < 0.9999 )
	{
		return (double)offtime.sdiff();
	}
	return double(0.0000);
}
const double Variable::Runtime(void)
{
	return runtime + OnTime();
}
void Variable::SetRuntime(const double &t)
{
	runtime = t;
}
