#pragma once
#include"Table.h"
#include"Record.h"

enum PosData { CURRENT_POS };
class TArrayTable : public TTable
{
protected:
	TRecord *MasRec;     
	int TabSize;        
	int pCurr;          //текущая
public:
	TArrayTable(int size = MaxSize)
	{
		MasRec = new TRecord[size];
		TabSize = size;
		DataCount = pCurr = 0;
	}
	~TArrayTable()
	{
		delete[]MasRec;
	}

	

	virtual bool IsFull() const
	{
		return (DataCount >= TabSize);
	}

	virtual int Reset(void);
	virtual int IsTabEnd(void) const;
	virtual int GoNext(void);
	virtual int SetCurr(int pos);   

	int GetTabSize() const { return TabSize; }
	int GetCurr() const { return pCurr; }

	virtual TKey GetKey(void) const
	{
		return GetKey(CURRENT_POS);  
	}

	virtual TValue GetVal(void) const
	{
		return GetVal(CURRENT_POS);
	}
	virtual TKey GetKey(PosData m) const;
	virtual TValue GetVal(PosData m) const;

	friend istream& operator >>(istream& is, TArrayTable &tab)
	{
		TKey k;
		TValue v;
		int data_count;
		cout << "enter DataCount" << endl;
		is >> data_count;
		for (int i = 0; i < data_count; i++)
		{
			is >> k;
			tab.MasRec[i].SetKey(k);
			is >> v;
			tab.MasRec[i].SetVal(v);
			tab.DataCount++;
		}
		return is;
	}

	friend class TSortTable;
	friend class TScanTable;
};
