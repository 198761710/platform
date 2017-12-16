#ifndef __BASIC_SERVICE_H__
#define __BASIC_SERVICE_H__
#include "service.h"

class BasicService : public Service
{
protected:
	map<string,Basic> basicmap;
	typedef map<string,Basic>::iterator Biterator;

public:
	void Run(void);
	bool ProcPacket(Packet& packet);

public:
	bool ProcVarGetType(Packet &packet);
	bool ProcVarSetType(Packet &packet);
	bool ProcVarGetInit(Packet &packet);
	bool ProcVarSetInit(Packet &packet);
	bool ProcVarGetValue(Packet &packet);
	bool ProcVarSoftValue(Packet &packet);
	bool ProcVarHardValue(Packet &packet);
	bool ProcVarGetManual(Packet &packet);
	bool ProcVarSetManual(Packet &packet);
	bool ProcVarGetRuntime(Packet &packet);
	bool ProcVarSetRuntime(Packet &packet);
	bool ProcVarGetThreshold(Packet &packet);
	bool ProcVarSetThreshold(Packet &packet);
	bool ProcVarSetListener(Packet &packet);
	bool ProcVarGetInputList(Packet &packet);
	bool ProcVarGetOutputList(Packet &packet);
	bool ProcVarGetValueList(Packet &packet);
	bool ProcBasicAddFile(Packet &packet);
	bool ProcBasicDelFile(Packet &packet);
	bool ProcBasicGetRun(Packet &packet);
	bool ProcBasicSetRun(Packet &packet);
	bool ProcBasicSetDebug(Packet &packet);
	bool ProcBasicCompile(Packet &packet);

public:
	bool ListAsHtml(const string& fname, map<string,Variable>&);
	bool ListAsJson(const string& fname, map<string,Variable>&);
};

#endif//__BASIC_SERVICE_H__
