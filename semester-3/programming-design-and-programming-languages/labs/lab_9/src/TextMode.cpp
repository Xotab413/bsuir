#include "../headers/FileException.h"
#include "../headers/Plant.h"
#include "../headers/fun.h"

void Plant::textMode(const string path) {  
    system("clear");
    bool f = true;
    string s;
    while (1) {
        printMenu();
        switch (checkNum()) {
            case 1: {
                ofstream fout(path, ios::app);
                if (!fout) {
                    f = false;
                    throw FileException(1);
                }
                cout << "Enter a name of Plant: ";
                cin.ignore();
                cin >> m_name;
                cout << "Enter a age of Plant: ";
                cin >> m_age;
                cout << "Enter a lenght of Plant: ";
                cin >> m_lenght;
                fout << this->m_name << endl
                     << m_age << endl
                     << m_lenght << "\n";
                system("clear");
                break;
            }
            case 2: {
                ifstream fin(path);
                if (!fin) {
                    f = false;
                    throw FileException(1);
                }
                system("clear");
                while (!fin.eof()) {
                    getline(fin, s); 
                    if (s == "")
                        continue;
                    cout << s << endl;                                       
                }
                break;
            }
            case 3: {
                ifstream fin(path);
                char c;
                if (!fin) {
                    f = false;
                    throw FileException(1);
                }
                system("clear");
                fin.seekg(0, fin.end);
                long long len = fin.tellg();
                len--;

                while (len--) {
                    fin.seekg(len, fin.beg);
                    fin.get(c);
                    if (c != '\n' && len != 0) continue;
                    if (len == 0) {
                        fin.seekg(len, fin.beg);
                        getline(fin, s);
                        if (s == "") break;
                        cout << s << endl;
                        break;
                    } else {
                        fin.seekg(len + 1, fin.beg);
                        getline(fin, s);
                        if (s == "") continue;
                        cout << s << endl;
                    }
                }
                break;
            }
            case 4: {
                int pos{1};
                ifstream fin(path);
                if (!fin) {
                    f = false;
                    throw FileException(1);
                }
                system("clear");
                int l = 0;
                string find, cheak;
                cout << "Enter the name for search: ";
                cin.ignore();
                getline(cin, find);
                while (!fin.eof()) {
                    getline(fin, cheak);
                    if (cheak == find) {
                        l++;
                        cout << "Position - " << pos << endl << cheak << endl;
                        getline(fin, cheak);
                        cout << cheak << endl;
                        getline(fin, cheak);
                        cout << cheak << endl;
                    }
                }
                    if (l == 0) {
                        system("clear");
                        cout << "Not found!" << endl;
                    }
                break;
            }
            case 5: {
                ifstream fin(path);
                if (!fin) {
                    f = false;
                    throw FileException(1);
                }
                system("clear");
                string find, buf;
                vector<string> arr;
                cout << "What Plant must be deleted?: ";
                cin.ignore();
                getline(cin, find);
                while (!fin.eof()) {
                    buf = "";
                    getline(fin, buf);
                    if (buf == find) {
                        getline(fin, buf);
                        getline(fin, buf);
                        continue;
                    }
                    arr.push_back(buf);
                }
                fin.close();
                ofstream fout(path);
                for (string check : arr) fout << check << endl;
                fout.close();
                break;
            }
            case 6: 
                DeleteDuplicate();
                break;
            case 7:
                sortTxT(path);
                break;
            case 8:
                FindRangeTxT(path);
                break;
            case 0:
                return;
            default:
                throw FileException(2);
                break;
        }
    }
}
