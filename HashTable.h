#pragma once
#include"Table.h"

class THashTable :public TTable
{
protected:
	virtual unsigned int HashFunc(const TKey k);
public:
	THashTable() :TTable() {}

};