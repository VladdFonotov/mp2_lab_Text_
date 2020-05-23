#include <iostream>
#include <conio.h>
#include <string>
#include <clocale>
#include"TText.h"


using namespace std;

TTextMem TTextLink::MemHeader;

void TextMenu(TText &txt) {
	string st;
	string com;
	do {
		cout << "Enter 'help' to see a list of commands" << endl;
		cin >> com;

		if (com == "print")
		{
			txt.ConsolePrint();
		}
		if (com == "printit")
		{
			cout << endl << "printing iterator" << endl;
			for (txt.Reset(); !txt.IsEnd(); txt.GoNext()) {
				cout << txt.GetLine() << endl;
			}
		}
		if (com == "first")
		{
			txt.GoFirstLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "down")
		{
			txt.GoDownLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "next")
		{
			txt.GoNextLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "prev")
		{
			txt.GoPrevLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "deleted")
		{
			txt.DelDownLine();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "deleten")
		{
			txt.DelNext();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (com == "insertdl")
		{
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownLine(st);
		}
		if (com == "insertds")
		{
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsDownSection(st);
		}
		if (com == "insertnl")
		{
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextLine(st);
		}
		if (com == "insertns")
		{
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextSection(st);
		}
		if (com == "free") {
			TTextLink::PrintFreeLink();
		}
		if (com == "help")
		{
			cout << "print - printing text with indentations" << endl;
			cout << "printit - printing text with iterator" << endl;
			cout << "first - go to beginning of text" << endl;
			cout << "next - go to the next link" << endl;
			cout << "down - go to the down link" << endl;
			cout << "prev - go to previous link" << endl;
			cout << "deleted - delete the down link" << endl;
			cout << "deleten - delete  the next link" << endl;
			cout << "insertdl - adding the down line" << endl;
			cout << "insertds - adding the down sectoin" << endl;
			cout << "insertnl - adding the next line" << endl;
			cout << "insertns - adding the next sectoin" << endl;
			cout << "free - show free memory" << endl;
			cout << "exit - exit" << endl;
		}
	} while (com != "exit");
}

int main() {
	TTextLink::InitMemSystem(100);
	TText t;
	t.Read("../textin.txt");
	TextMenu(t);
	t.Write("../textout.txt");
	TTextLink::MemCleaner(t);
	TTextLink::PrintFreeLink();
}