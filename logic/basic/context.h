#ifndef __CONTEXT_H__
#define __CONTEXT_H__
#include <map>
#include <string>
#include "cache.h"
#include "statement.h"
using namespace std;

class Context
{
protected:
	Cache cache;
	int statement_count;
	Token synbelnotfound;
	map<string,int> labelmap;
	map<int,class Statement> context;
	map<int,class Statement>::iterator index;
	typedef map<int,class Statement>::iterator Iterator;
public:
	Context(void);
public:
	void SymbelNotFound(Token&);
	Token& SymbelNotFound(void);
public:
	class Cache& GetCache(void);
	void AddStatement(class Statement& statement);
	void AddLabel(const string& label);
	void GotoLabel(const string& label);
	int GetErrorLine(void);
	void Execute(void);
	void Clear(void);
	bool Check(void);
};
#endif//__CONTEXT_H__
