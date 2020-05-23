#pragma once
#define _TText_h_

#include "TTextLink.h"
#include "TStack.h"
#include <string>

class TText
{
	TTextLink* pFirst;
	TTextLink* pCurr;
	TStack<TTextLink*> stack;

public:

	TText();
	void GoFirstLink();
	void GoDownLink();
	void GoNextLink();
	void GoPrevLink();
	void SetLine(std::string astr);
	std::string GetLine();

	void InsNextLine(std::string astr);
	void InsNextSection(std::string astr);
	void InsDownLine(std::string astr);
	void InsDownSection(std::string astr);
	void DelNext();
	void DelDownLine();

	void Read(std::string fn);
	TTextLink* ReadRec(std::ifstream& ifs);
	void Write(std::string fn);
	void WriteRec(std::ofstream& ofs, TTextLink* pWC);
	void ConsolePrint();
	void ConsolePrintRec(TTextLink* pWC);

	int Reset();
	int IsEnd();
	int GoNext();
};