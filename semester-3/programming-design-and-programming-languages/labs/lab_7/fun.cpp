#include "../headers/fun.h"
#include "Set.h"
void strParce() { // sorry for hardcoding ヽ(°□° )ノ
    string mainLine;
	rewind(stdin);
    cout << "PRINT STRING" << endl;
	getline(cin, mainLine);
	Set<string> arrStr;
	Set<int> arrInt;
	Set<double> arrDbl;
	mainLine += ' ';
	string space = " ";
	mainLine.insert(0, space);
	int lineLenght = mainLine.length();
	bool intTrig = false;
	bool strTrig = false;
	bool dblTrig = false;
	string intLine;
	string strLine;
	string dblLine;
	for (int i = 0; i < lineLenght; i++) {
		if (mainLine[i] == '\0') {
			break;
		}

	if ((mainLine[i] == '.') && ((mainLine[i - 1] < '0') || (mainLine[i - 1] > '9'))) {
		mainLine.erase(i, 1);
		i--;
	}
	if (mainLine[i + 1]) {
		if ((mainLine[i] == '.') && ((mainLine[i + 1] < '0') || (mainLine[i + 1] > '9'))) {
			mainLine.erase(i, 1);
			i--;
		}
	}
}
	for (int i = 0; i < lineLenght; i++) {
		if (mainLine[i] == '\0') {
			break;
		}
		if (((mainLine[i] <= 'Z') && (mainLine[i] >= 'A')) || ((mainLine[i] <= 'z') && (mainLine[i] >= 'a'))) {
			strLine += mainLine[i];
		}
		else {
			strLine += ' ';
		}

		if (((mainLine[i] >= '0') && (mainLine[i] <= '9')) || (mainLine[i] == '.')) {
			intLine += mainLine[i];
		}
		else {
			intLine += ' ';
		}
	}
    system("clear");
	cout << "My line is " << mainLine << endl;

	string secStrLine;
	for (int i = 0; i < lineLenght; i++) {
		if (mainLine[i] == '\0') {
			break;
		}
		if (((strLine[i] <= 'Z') && (strLine[i] >= 'A')) || ((strLine[i] <= 'z') && (strLine[i] >= 'a'))) {
			secStrLine += strLine[i];
			strTrig = true;
		}
		else {
			if (strTrig) {
				arrStr.add(secStrLine);
				strTrig = false;
				secStrLine.clear();
			}
			strTrig = false;
		}
	}
	intLine += 'a';
	string secIntLine;
	lineLenght = intLine.length();
	bool dotTrig = false;
	for (int i = 0; i < lineLenght; i++) {
		if (intLine[i] == '\0') {
			break;
		}
		if (((intLine[i] <= '9') && (intLine[i] >= '0')) || (intLine[i] == '.')) {
			if (intLine[i] == '.') {
				dotTrig = true;
			}
			secIntLine += intLine[i];
			intTrig = true;
		}
		else{
			if (intTrig) {
				if (dotTrig) {
					arrDbl.add(stod(secIntLine));
				}
				else {
					arrInt.add(stoi(secIntLine));
				}
				intTrig = false;
				dotTrig = false;
				secIntLine.clear();
			}
			intTrig = false;
		}
	}
    cout << "My parse : " << "\n"
         << arrStr << endl
	     << arrInt << endl
         << arrDbl << endl;

}