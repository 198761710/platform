#include <stdio.h>
#include "cache.h"
#include "basicservice.h"

extern Cache GlobalVariable;

void BasicService::Run(void)
{
	for(map<string,Basic>::iterator i = basicmap.begin(); i != basicmap.end(); i++)
	{
		if( i->second.GetRun() )
		{
			i->second.Execute();
		}
	}
	DoReceive();
}
bool BasicService::ProcPacket(Packet& packet)
{
	switch( packet.type() )
	{
	case VarGetType:
		return ProcVarGetType(packet);

	case VarSetType:
		return ProcVarSetType(packet);

	case VarGetInit:
		return ProcVarGetInit(packet);

	case VarSetInit:
		return ProcVarSetInit(packet);

	case VarGetValue:
		return ProcVarGetValue(packet);

	case VarSoftValue:
		return ProcVarSoftValue(packet);

	case VarHardValue:
		return ProcVarHardValue(packet);

	case VarGetManual:
		return ProcVarGetManual(packet);

	case VarSetManual:
		return ProcVarSetManual(packet);

	case VarGetRuntime:
		return ProcVarGetRuntime(packet);

	case VarSetRuntime:
		return ProcVarSetRuntime(packet);

	case VarGetThreshold:
		return ProcVarGetThreshold(packet);

	case VarSetThreshold:
		return ProcVarSetThreshold(packet);

	case VarSetListener:
		return ProcVarSetListener(packet);

	case VarGetInputList:
		return ProcVarGetInputList(packet);

	case VarGetOutputList:
		return ProcVarGetOutputList(packet);

	case VarGetValueList:
		return ProcVarGetValueList(packet);

	case BasicAddFile:
		return ProcBasicAddFile(packet);

	case BasicDelFile:
		return ProcBasicDelFile(packet);

	case BasicGetRun:
		return ProcBasicGetRun(packet);

	case BasicSetRun:
		return ProcBasicSetRun(packet);

	case BasicSetDebug:
		return ProcBasicSetDebug(packet);

	case BasicCompile:
		return ProcBasicCompile(packet);
	}
	return false;
}
bool BasicService::ProcVarGetType(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.uvalue( var.GetVariableType() );

	return true;
}
bool BasicService::ProcVarSetType(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetVariableType( (VariableType)packet.uvalue() );

	return true;
}
bool BasicService::ProcVarGetInit(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.uvalue( var.GetInit() );

	return true;
}
bool BasicService::ProcVarSetInit(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetInit( packet.uvalue() != 0 );

	return true;
}
bool BasicService::ProcVarGetValue(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.dvalue( var.GetValue() );

	return true;
}
bool BasicService::ProcVarSoftValue(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SoftSetValue( packet.dvalue() );

	return true;
}
bool BasicService::ProcVarHardValue(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.HardSetValue( packet.dvalue() );

	return true;
}
bool BasicService::ProcVarGetManual(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.uvalue( var.GetManual() );

	return true;
}
bool BasicService::ProcVarSetManual(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetManual( (AutoType)packet.uvalue() );

	return true;
}
bool BasicService::ProcVarGetRuntime(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.uvalue( (unsigned)var.GetRuntime() );

	return true;
}
bool BasicService::ProcVarSetRuntime(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetRuntime( (double)packet.uvalue() );

	return true;
}
bool BasicService::ProcVarGetThreshold(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	packet.dvalue( var.GetThreshold() );

	return true;
}
bool BasicService::ProcVarSetThreshold(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetThreshold( packet.dvalue() );

	return true;
}
bool BasicService::ProcVarSetListener(Packet &packet)
{
	Variable& var = GlobalVariable.GetVariable( packet.name() );

	var.SetListener( packet.svalue() );

	return true;
}
bool BasicService::ProcVarGetInputList(Packet &packet)
{
	map<string,Variable> varmap;

	GlobalVariable.GetInputList(varmap);
	if( varmap.empty() )
	{
		return false;
	}
	return ListAsJson("inputlist.txt", varmap);
	return ListAsHtml("inputlist.html", varmap);
}
bool BasicService::ProcVarGetOutputList(Packet &packet)
{
	map<string,Variable> varmap;

	GlobalVariable.GetOutputList(varmap);
	if( varmap.empty() )
	{
		return false;
	}
	return ListAsJson("outputlist.txt", varmap);
	return ListAsHtml("outputlist.html", varmap);
}
bool BasicService::ProcVarGetValueList(Packet &packet)
{
	map<string,Variable> varmap;

	GlobalVariable.GetValueList(varmap);
	if( varmap.empty() )
	{
		return false;
	}
	return ListAsJson("variablelist.txt", varmap);
	return ListAsHtml("variablelist.html", varmap);
}
bool BasicService::ProcBasicAddFile(Packet &packet)
{
	string name = packet.svalue();
	basicmap[name].SetName(name);
	return true;
}
bool BasicService::ProcBasicDelFile(Packet &packet)
{
	string name = packet.svalue();
	basicmap.erase(name);
	return true;
}
bool BasicService::ProcBasicGetRun(Packet &packet)
{
	Biterator i = basicmap.find( packet.name() );

	if( basicmap.end() == i )
	{
		return false;
	}
	packet.uvalue( i->second.GetRun() );

	return true;
}
bool BasicService::ProcBasicSetRun(Packet &packet)
{
	Biterator i = basicmap.find( packet.name() );

	if( basicmap.end() == i )
	{
		return false;
	}
	i->second.SetRun( packet.uvalue() );

	return true;
}
bool BasicService::ProcBasicSetDebug(Packet &packet)
{
	Biterator i = basicmap.find( packet.name() );

	if( basicmap.end() == i )
	{
		return false;
	}
	i->second.SetDebug( packet.uvalue() );

	return true;
}
bool BasicService::ProcBasicCompile(Packet &packet)
{
	Biterator i = basicmap.find( packet.name() );

	if( basicmap.end() == i )
	{
		return false;
	}
	i->second.SetName( i->first );
	i->second.Compile();

	return true;
}
bool BasicService::ListAsHtml(const string &fname, map<string,Variable> &varmap)
{
	FILE *f = fopen(fname.data(), "w");

	if( NULL == f )
	{
		return false;
	}

	string table;
	table += "<style>th{border:solid 1px;}";
	table += "td{border:solid 1px;}</style>";
	table += "<table><tr>";
	table += "<th>Name</th>";
	table += "<th>Init</th>";
	table += "<th>Manual</th>";
	table += "<th>OnTime</th>";
	table += "<th>OffTime</th>";
	table += "<th>RunTime</th>";
	table += "<th>Threshold</th>";
	table += "<th>Value</th>";
	table += "</tr>";
	fwrite(table.data(), table.length(), 1, f);

	for(map<string,Variable>::iterator i = varmap.begin(); i != varmap.end(); i++)
	{
		string data;
		char buf[128];
		snprintf(buf, sizeof(buf), "<tr><td>%s</tb>", i->first.data());
		data += buf;
		snprintf(buf, sizeof(buf), "<td>%d</tb>", (int)i->second.GetInit());
		data += buf;
		snprintf(buf, sizeof(buf), "<td>%d</tb>", (int)i->second.GetManual());
		data += buf;
		snprintf(buf, sizeof(buf), "<td>%d</tb>", (int)i->second.GetOnTime());
		data += buf;
		snprintf(buf, sizeof(buf), "<td>%d</tb>", (int)i->second.GetOffTime());
		data += buf;
		snprintf(buf, sizeof(buf), "<td>%d</tb>", (int)i->second.GetRuntime());
		data += buf;
		snprintf(buf, sizeof(buf), "<td>%f</tb>", i->second.GetThreshold());
		data += buf;
		snprintf(buf, sizeof(buf), "<td>%.1f</tb></tr>\n ", i->second.GetValue());
		data += buf;
		fwrite(data.data(), data.length(), 1, f);
	}
	table = "</table>";
	fwrite(table.data(), table.length(), 1, f);
	fflush(f);
	fclose(f);

	return true;
}
bool BasicService::ListAsJson(const string &fname, map<string,Variable> &varmap)
{
	FILE *f = fopen(fname.data(), "w");

	if( NULL == f )
	{
		return false;
	}
	for(map<string,Variable>::iterator i = varmap.begin(); i != varmap.end(); i++)
	{
		string data;
		char buf[128];
		snprintf(buf, sizeof(buf), "{\"name\":\"%s\",", i->first.data());
		data += buf;
		snprintf(buf, sizeof(buf), "\"init\":\"%d\",", (int)i->second.GetInit());
		data += buf;
		snprintf(buf, sizeof(buf), "\"manual\":\"%d\",", (int)i->second.GetManual());
		data += buf;
		snprintf(buf, sizeof(buf), "\"ontime\":\"%d\",", (int)i->second.GetOnTime());
		data += buf;
		snprintf(buf, sizeof(buf), "\"offtime\":\"%d\",", (int)i->second.GetOffTime());
		data += buf;
		snprintf(buf, sizeof(buf), "\"runtime\":\"%d\",", (int)i->second.GetRuntime());
		data += buf;
		snprintf(buf, sizeof(buf), "\"threshold\":\"%f\",", i->second.GetThreshold());
		data += buf;
		snprintf(buf, sizeof(buf), "\"value\":\"%.1f\"}\n", i->second.GetValue());
		data += buf;
		fwrite(data.data(), data.length(), 1, f);
	}
	fflush(f);
	fclose(f);

	return true;
}
