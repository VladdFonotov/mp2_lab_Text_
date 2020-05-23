#pragma once
#define _TTextLink_h_
#include <string>

#define TTextLineLength 80
#define MemSize 100

class TText;
class TTextLink;

typedef char TStr[TTextLineLength];

struct TTextMem
{
	TTextLink *pFirst;
	TTextLink *pLast;
	TTextLink *pFree;
	friend class TTextLink;
};

class TTextLink
{
protected:
	TTextLink* pNext, *pDown;
	static TTextMem MemHeader;
	friend class TText;
public:
	TStr str;
	int recD;
	static void InitMemSystem(int size = MemSize);
	static void PrintFreeLink(void);
	void* operator new (size_t size);
	void operator delete (void* pM);
	static void MemCleaner(TText& txt);

	TTextLink(const TStr c = NULL, TTextLink* pn = NULL, TTextLink* pd = NULL) {
		recD = 0;
		pNext = pn;
		pDown = pd;
		if (c == NULL)
			str[0] = '\0';
		else
			strcpy_s(str, c);
	}

	~TTextLink() {}
};
