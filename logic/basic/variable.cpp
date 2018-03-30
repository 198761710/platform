#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "variable.h"


Variable::Variable(void)
{
	init = false;
	manual = false;
	death  = 0.0001;
	valueI = 0.000;
	valueO = 0.000;
	runtime = 0.0000;
	abtype = AB_Analog;
	iotype = IO_Holding;
	change = Chg_Unchange;
}
const string& Variable::GetName(void)
{
	return name;
}
ChangeType Variable::GetChange(void)
{
	return change;
}
bool Variable::GetInit(void)
{
	return init;
}
bool Variable::GetManual(void)
{
	return manual;
}
bool Variable::Output(void)
{
	if( IO_Output != iotype )
	{
		return false;
	}
	if( fabs(valueI - valueO) < death )
	{
		return false;
	}
	if( outtime.mdiff() < 1000 )
	{
		return false;
	}
	outtime.init();
	return true;
}
double Variable::GetValueI(void)
{
	return valueI;
}
double Variable::GetValueO(void)
{
	return valueO;
}
double Variable::GetDeath(void)
{
	return death;
}
double Variable::GetOnTime(void)
{
	if( false == init )
	{
		return double(0.0000);
	}
	if( fabs(valueI) >= 0.9999 )
	{
		return (double)ontime.sdiff();
	}
	return double(0.0000);
}
double Variable::GetOffTime(void)
{
	if( false == init )
	{
		return double(0.0000);
	}
	if( fabs(valueI) < 0.9999 )
	{
		return (double)offtime.sdiff();
	}
	return double(0.0000);
}
double Variable::GetRuntime(void)
{
	return runtime + GetOnTime();
}
IOType Variable::GetIOType(void)
{
	return iotype;
}
ABType Variable::GetABType(void)
{
	return abtype;
}
void Variable::SetName(const string& n)
{
	name = n;
}
void Variable::SetInit(const bool b)
{
	init = b;
}
void Variable::SetManual(const bool b)
{
	manual = b;
	if( manual )
	{
		init = true;
	}
}
void Variable::SetChange(const ChangeType c)
{
	change = c;
}
void Variable::SetRuntime(const double &v)
{
	runtime = v;
}
void Variable::SetDeath(const double &v)
{
	death = v;
}
void Variable::SetIOType(const IOType t)
{
	iotype = t;
}
void Variable::SetABType(const ABType t)
{
	abtype = t;
}
void Variable::Define(ABType ab, IOType io)
{
	abtype = ab;
	iotype = io;
	switch(iotype)
	{
		case IO_Input:
		case IO_Output:
			break;
		case IO_Holding:
			init = true;
			break;
	}
	printf("%s,%d,%d\n", __func__, abtype, iotype);
}
void Variable::SetReal(const double &v)
{
	init = true;
	if( fabs(v - valueI) < death )
	{
		return;
	}
	if( fabs(valueI) >= 0.9999 && fabs(v) < 0.9999 )
	{
		offtime.init();
		runtime += (double)ontime.sdiff();
	}
	else if( fabs(valueI) < 0.9999 && fabs(v) >= 0.9999 )
	{
		ontime.init();
	}
	valueI = v;
	//if( AB_Binary == abtype )
	{
		if( Chg_Unchange == change )
		{
			change = Chg_Chnage;
		}
	}
}
void Variable::SetValue(const double &v)
{
	if( manual )
	{
		return;
	}
	switch( iotype )
	{
		case IO_Holding:
		case IO_Input:
			SetReal(v);
			break;
		case IO_Output:
			valueO = v;
			break;
	}
}
void Variable::SetValueIO(const double& I, const double& O)
{
	switch( iotype )
	{
		case IO_Holding:
		case IO_Input:
			SetReal(I);
			break;
		case IO_Output:
			valueO = O;
			break;
	}
}
