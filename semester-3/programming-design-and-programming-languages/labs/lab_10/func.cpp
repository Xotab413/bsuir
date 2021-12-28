#include "../headers/func.hpp"

void printList(List<int>& list_int, List<double>& list_double,
               List<string>& list_string) {
    cout << "Int list: " << endl
         << list_int << endl
         << "Double list: " << endl
         << list_double << endl
         << "String list: " << endl
         << list_string << endl;
}

void strParce() {  // sorry for hardcoding ヽ(°□° )ノ (took from lab_7)
    string mainLine;
    rewind(stdin);
    cout << "PRINT STRING" << endl;
    getline(cin, mainLine);
    List<string> arrStr;
    List<int> arrInt;
    List<double> arrDbl;
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

        if ((mainLine[i] == '.') &&
            ((mainLine[i - 1] < '0') || (mainLine[i - 1] > '9'))) {
            mainLine.erase(i, 1);
            i--;
        }
        if (mainLine[i + 1]) {
            if ((mainLine[i] == '.') &&
                ((mainLine[i + 1] < '0') || (mainLine[i + 1] > '9'))) {
                mainLine.erase(i, 1);
                i--;
            }
        }
    }
    for (int i = 0; i < lineLenght; i++) {
        if (mainLine[i] == '\0') {
            break;
        }
        if (((mainLine[i] <= 'Z') && (mainLine[i] >= 'A')) ||
            ((mainLine[i] <= 'z') && (mainLine[i] >= 'a'))) {
            strLine += mainLine[i];
        } else {
            strLine += ' ';
        }

        if (((mainLine[i] >= '0') && (mainLine[i] <= '9')) ||
            (mainLine[i] == '.')) {
            intLine += mainLine[i];
        } else {
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
        if (((strLine[i] <= 'Z') && (strLine[i] >= 'A')) ||
            ((strLine[i] <= 'z') && (strLine[i] >= 'a'))) {
            secStrLine += strLine[i];
            strTrig = true;
        } else {
            if (strTrig) {
                arrStr.push_back(secStrLine);
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
        if (((intLine[i] <= '9') && (intLine[i] >= '0')) ||
            (intLine[i] == '.')) {
            if (intLine[i] == '.') {
                dotTrig = true;
            }
            secIntLine += intLine[i];
            intTrig = true;
        } else {
            if (intTrig) {
                if (dotTrig) {
                    arrDbl.push_back(stod(secIntLine));
                } else {
                    arrInt.push_back(stoi(secIntLine));
                }
                intTrig = false;
                dotTrig = false;
                secIntLine.clear();
            }
            intTrig = false;
        }
    }
    cout << "My parse : "
         << "\n";
    printList(arrInt, arrDbl, arrStr);
    findStr(arrInt, arrDbl, arrStr);
    sortList(arrInt, arrDbl, arrStr);
    printList(arrInt, arrDbl, arrStr);
}

void findStr(List<int>& list_int, List<double>& list_double,
             List<string>& list_string) {
    string mainLine;
    int chooser{1};
    cout << "Enter finding: \n1 - find in int \n2 - in double \n3 - in string" << endl;
    cin >> chooser;
    cout << "Enter a find string" << endl;
    cin.ignore();
    getline(cin, mainLine);
    cout << "------------------------------------------" << endl;
    switch (chooser) {
        case 1: {
            for (int i = 0; i < list_int.GetSize(); i++) {
                if (list_int[i] == atoi(mainLine.c_str()))
                    cout << list_int[i] << endl;
            }
        } break;
        case 2: {
            for (int i = 0; i < list_double.GetSize(); i++) {
                if (list_double[i] == atof(mainLine.c_str()))
                    cout << list_double[i] << endl;
            }

        } break;
        case 3: {
            for (int i = 0; i < list_string.GetSize(); i++) {
                if (list_string[i] == mainLine.c_str())
                    cout << list_string[i] << endl;
            }
        } break;
        default:
            return;
    }
}

void sortList(List<int>& list_int, List<double>& list_double,
              List<string>& list_string) {
    int chooser{1};
    cout << "Enter a num to sort or letter to exit" << endl;
    while (cin >> chooser) {
        system("clear");
        cout << "Enter type sort for int List" <<endl;
        list_int.sortAcrossContent();
        cout << "Enter type sort for string List" <<endl;
        list_string.sortAcrossContent();
        cout << "Enter type sort for double List" <<endl;
        list_double.sortAcrossContent();
        cout << "Enter a num to sort or letter to exit" << endl;
    }
}
void notDop() {
    List<int> list;
    List<double> list_d;
    List<string> list_str;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list_d.push_back(3.2);
    list_d.push_back(2.2);
    list_d.push_back(2.8);

    list_str.push_back("Heelo");
    list_str.push_back("My");
    list_str.push_back("Semyon");

    cout << "Int list: " << endl;
    for (int i = 0; i < list.GetSize(); i++) cout << list[i] << " ";
    cout << endl;
    cout << "Double list: " << endl;
    for (int i = 0; i < list_d.GetSize(); i++) cout << list_d[i] << " ";
    cout << endl;
    cout << "String list: " << endl;
    for (int i = 0; i < list_str.GetSize(); i++) cout << list_str[i] << " ";

    cout << endl;

    cout << "Delete first el-ts" << endl;
    list.pop_front();
    list_str.pop_front();
    list_d.pop_front();
    cout << "Int list: " << endl;
    for (int i = 0; i < list.GetSize(); i++) cout << list[i] << " ";
    cout << endl;
    cout << "Double list: " << endl;
    for (int i = 0; i < list_d.GetSize(); i++) cout << list_d[i] << " ";
    cout << endl;
    cout << "String list: " << endl;
    for (int i = 0; i < list_str.GetSize(); i++) cout << list_str[i] << " ";
    cout << endl;

    //----------Find------------------
    cout << "Find in int array " << endl;
    int find_i;
    cin >> find_i;

    cout << "Int list: " << endl;
    for (int i = 0; i < list.GetSize(); i++)
        if (list[i] == find_i) cout << list[i];
    cout << endl;
    cout << "Find in int double " << endl;
    double find_d;
    cin >> find_d;

    cout << "Double list: " << endl;
    for (int i = 0; i < list_d.GetSize(); i++)
        if (list_d[i] == find_d) cout << list[i];
    cout << endl;
    cout << "Find in string " << endl;
    string find_str;
    cin >> find_str;

    cout << "String list: " << endl;
    for (int i = 0; i < list_str.GetSize(); i++)
        if (list_str[i] == find_str) cout << list_str[i];
    cout << endl;
    list_str.sortAcrossContent();
    for (int i = 0; i < list_str.GetSize(); i++) cout << list_str[i] << " ";
    cout << endl;
}