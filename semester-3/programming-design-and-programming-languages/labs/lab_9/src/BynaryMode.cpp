#include "../headers/FileException.h"
#include "../headers/Plant.h"
#include "../headers/fun.h"
#include <cstring>

// WHY i use fcking bufer in write&read ?
// because read  https://stackoverflow.com/questions/10873382/write-and-read-string-to-binary-file-c 
// i have this problem on my Linux (Parrot OS) with g++ 10 version https://yadi.sk/i/aIS_TEZezxyr8A
// Maybe Windows skip this problem but, it's bad ...

void Plant::binaryMode(const string path) {
    system("clear");
    bool f = true;
    string s;
    while (1) {
        printMenu();
        switch (checkNum()) {
        case 1: {
            ofstream fout(path,ios::app | ios::binary);
            if (!fout) {
                f = false;
                throw FileException(1);
            }
            cout << "Enter a name of Plant: ";
            cin >> m_name;
            cout << "Enter a age of Plant: ";
            cin >> m_age;
            cout << "Enter a average lenght  of Plant: ";
            cin >> m_lenght;
            char buf[50];
            strcpy(buf,(m_name).c_str());
            fout.write(buf, sizeof(buf));
            fout.write((char *)&m_age, sizeof(m_age));
            fout.write((char *)&m_lenght, sizeof(m_lenght));
            system("clear");
            fout.close();
            break;
        }
            
        case 2: {
            ifstream fin(path,ios::binary);
            if (!fin) {
                f = false;
                throw FileException(1);
            }
            system("clear");
            fin.seekg(0, fin.end);
            long long l = fin.tellg();
            fin.seekg(0, fin.beg);
            while (l) {
                char buf[50];
                l -= sizeof(buf) + sizeof(m_age) + sizeof(m_lenght);
                fin.read(buf,sizeof buf);
                m_name = buf;
                fin.read((char *)&m_age, sizeof(m_age));
                fin.read((char *)&m_lenght, sizeof(m_lenght));
                cout << m_name << endl << m_age << endl << m_lenght << endl << "------------------------------" << endl;
            }
            fin.close();
            break;
        }
            
        case 3: {
            ifstream fin(path, ios::binary);
            char c;
            if (!fin) {
                f = false;
                throw FileException(1);
            }
            system("cls");
            fin.seekg(0, fin.end);
            long long len = fin.tellg(), k = 0;
            int a;

            while (len) {
                char buf[50];
                len -= sizeof(buf) + sizeof(m_age) + sizeof(m_lenght);

                if (k == 0) { a = 0 - sizeof(m_lenght); fin.seekg(a, fin.cur); }
                else { a = 0 - (sizeof(m_lenght) + sizeof(buf)); fin.seekg(a, fin.cur); }
                fin.read((char*)&m_lenght, sizeof(m_lenght));

                a = 0 - (sizeof(m_age) + sizeof(m_lenght));
                fin.seekg(a, fin.cur);
                fin.read((char*)&m_age, sizeof(m_age));

                a = 0 - (sizeof(buf) + sizeof(m_age));
                fin.seekg(a, fin.cur);
                fin.read(buf, sizeof(buf));
                m_name = buf;

                cout « m_lenght « endl « m_age « endl « m_name « endl « "------------------------------" « endl;
                k++;
            }
            break;
            fin.close();
        }

            
        case 4: {
            ifstream fin(path, ios::binary);
            if (!fin) {
                f = false;
                throw FileException(1);
            }
            system("clear");
            int l = 0;
            string find;
            cout << "Enter the name of Plant: ";
            cin.ignore();
            getline(cin, find);
            fin.seekg(0, fin.end);
            long long h = fin.tellg();
            fin.seekg(0, fin.beg);
            while (h) {
                char buf[50];
                h -= sizeof(buf) + sizeof(m_age) + sizeof(m_lenght);
                fin.read(buf, sizeof(buf));
                m_name = buf;
                if (this->m_name == find) {
                    l++;
                    cout << this->m_name << endl;
                    fin.read((char *)&m_age, sizeof(m_age));
                    cout << m_age << endl;
                    fin.read((char *)&m_lenght, sizeof(m_lenght));
                    cout << m_lenght << endl;
                } else
                    fin.seekg((sizeof(m_age) + sizeof(m_lenght)), fin.cur);
            }
            if (l == 0) {
                system("clear");
                cout << "Not found!" << endl;
            }
        }
            break;
        case 5: {
            ifstream fin(path, ios::binary);
            if (!fin) {
                f = false;
                throw FileException(1);
            }

            system("clear");
            int l = 3, ll = 0;
            string *mass, *mass1;
            string find, cheak;
            cout << "What Plant must be deleted: ";
            cin.ignore();
            getline(cin, find);
            fin.seekg(0, fin.end);
            long long h = fin.tellg();
            fin.seekg(0, fin.beg);

            while (h) {
                char buf[50];
                h -= sizeof(buf) + sizeof(m_age) + sizeof(m_lenght);
                fin.read(buf,sizeof (buf));
                m_name = buf;
                fin.read((char *)&m_age, sizeof(m_age));
                fin.read((char *)&m_lenght, sizeof(m_lenght));

                mass = new string[l];

                for (int i = 0; i < ll; i++) mass[i] = mass1[i];

                mass[l - 3] = m_name;
                mass[l - 2] = to_string(m_age);
                mass[l - 1] = to_string(m_lenght);

                mass1 = new string[l];

                for (int i = 0; i < l; i++) mass1[i] = mass[i];

                ll = l;
                l += 3;
            }
            for (int i = 0; i < l; i += 3) {
                if (find == mass[i]) {
                    cout << mass[i] << endl
                         << mass[i + 1] << endl
                         << mass[i + 2] << endl;
                    mass[i] = mass[i + 1] = mass[i + 2] = "";
                    ll -= 3;
                }
            }
            fin.close();
            ofstream fout(path, ios::binary);
            if (!fout) {
                f = false;
                throw FileException(1);
            }
            fout.close();
            if (ll == 0) {
                break;
            } else {
                ofstream fout(path, ios::app | ios::binary);
                for (int i = 0; i < ll+3; i += 3) {
                    if (mass[i] == "") continue;
                    try {
                        m_name = mass[i];
                        m_age = stoi(mass[i + 1]);
                        m_lenght = stod(mass[i + 2]);
                        char buf[50];
                        strcpy(buf,(m_name).c_str());
                        fout.write(buf,sizeof(buf));
                        fout.write((char *)&m_age, sizeof(m_age));
                        fout.write((char *)&m_lenght, sizeof(m_lenght));
                    } catch (...) {
                        fout.close();
                    }
                }
            }

        }
            break;
        case 6:
            DeleteDuplicate();
            break;
        case 7:
            sortBin(path);
            break;
        case 8:
            FindRangeBin(path);
            break;
        case 0: {
            f = false;
            return;
        }
        default:
            throw FileException(2);
            break;
        }
    }
}
