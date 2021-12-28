#include "../headers/fun.h"
#include "../headers/FileException.h"
#include "../headers/Plant.h"
#include <cstring>
#include <algorithm>

int checkNum() {
    int num{0};
    while (true) {
        if (cin >> num)
            break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            system("clear");
            cout << "Enter THE NUM (￣□￣」): " << endl;
        }
    }
    return num;
}
void printMenu() {
    cout << endl
         << "1 - Enter Plant" << endl
         << "2 - Print Plants" << endl
         << "3 - Rev print" << endl
         << "4 - Find Plant" << endl
         << "5 - Delete Plant" << endl
         << "6 - Delete Duplicate" << endl
         << "7 - Sort Plants" << endl
         << "8 - Find Diapazone" <<endl
         << "0 - Exit" << endl;
}


void printFileType() {
    cout << "1 - Text file in text mode;" << endl
         << "2 - Text file in binary mode;" << endl
         << "3 - Binary file in binary mode;" << endl
         << "Other num - Exit;" << endl;
}

#pragma region Dop
//-------------------------Dop-----------------------

//-----------------File's funs-----------------------
void SaveBin(vector <Plant> &pl_v,const string path) {
    ofstream fout(path,ios::binary);
    if (!fout) 
        throw FileException(1);
    for (auto& plant : pl_v) {
    char buf[50];
    strcpy(buf,(plant.getName()).c_str());
    fout.write(buf, sizeof(buf));
    int age = plant.getAge();
    fout.write((char *)&(age), sizeof(age));
    double lenght = plant.getLenght();
    fout.write((char *)&lenght, sizeof(lenght));
    }
    system("clear");
    fout.close();    
}
void ReadBin(vector <Plant> &pl_v,const string path) {
    ifstream fin(path,ios::binary);
    if (!fin) 
        throw FileException(1);
    system("clear");
    fin.seekg(0, fin.end);
    long long l = fin.tellg();
    fin.seekg(0, fin.beg);
    while (l) {
        Plant temp;
        char buf[50];
        l -= sizeof(buf) + sizeof(int) + sizeof(double);
        fin.read(buf,sizeof buf);
        string name;
        name = buf;
        temp.setName(name);
        int age {0};
        fin.read((char *)&age, sizeof(age));
        temp.setAge(age);
        double lenght {0};
        fin.read((char *)&lenght, sizeof(lenght));
        temp.setLenght(lenght);
        pl_v.push_back(temp);
    }
    fin.close();
}
void SaveTxT(vector <Plant> &pl_v,const string path) {
    ofstream fout(path);
    if (!fout) 
        throw FileException(1);
    for (auto& plant : pl_v) {
    fout    << plant.getName() << endl
            << plant.getAge() << endl
            << plant.getLenght() << "\n";
    }
    fout.close();
}
void ReadTxT(vector <Plant> &pl_v,const string path) {
    string s;
    ifstream fin(path);
    if (!fin) 
        throw FileException(1);
    system("clear");
    while (!fin.eof()) {
        Plant temp;
        getline(fin, s);
        if (s == "")
            continue; 
        temp.setName(s);
        getline(fin, s);
        if (s == "")
            continue; 
        temp.setAge(atoi(s.c_str()));
        getline(fin, s);
        if (s == "")
            continue; 
        temp.setLenght(atof(s.c_str()));
        pl_v.push_back(temp);
        if (s == "")
            continue;                                  
    }
}

//-----------------Delete Dupl-----------------------
void DeleteDuplAlg(vector <Plant> &pl_v) {
    for (int i = 0; i < pl_v.size(); i ++) 
        for (int j = i+1; j < pl_v.size(); j++)
            if (pl_v[i] == pl_v[j])
                pl_v.erase(pl_v.begin() + i);
}
void DeleteDuplText(string path) {
    ifstream fin(path);
    if (!fin) {
        fin.close();
        return;
    }
    fin.close();
    vector <Plant> pl_v;
    ReadTxT(pl_v,path);
    DeleteDuplAlg(pl_v);
    SaveTxT(pl_v,path);
    pl_v.clear();
}
void DeleteDuplBin(const string path) {
    ifstream fin(path,ios::binary);
    if (!fin) {
        fin.close();
        return;
    }
    fin.close();
    vector <Plant> pl_v;
    ReadBin(pl_v,path);
    DeleteDuplAlg(pl_v);
    SaveBin(pl_v,path);
    pl_v.clear();

}
void DeleteDuplicate() {
    DeleteDuplBin("../out/binary_in_binary.dat");
    DeleteDuplBin("../out/text_in_binary.dat");
    DeleteDuplText("../out/text_in_text.txt");
}

//-------------Finding Range-------------------------
void FindAlg(vector <Plant>& pl_v) {
    //-----------------lab_6 copypaste
    cout << "Enter low&high borders of the range age" << endl;
    int low = checkNum();
    int high = checkNum();
    system("clear");
    int count{0};
    for (auto& plant : pl_v) {
        if (plant.getAge() <= high && plant.getAge() >= low) {
            cout << plant << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your age is not between << " << low << ".." << high << " 0_0"
             << endl;
}
void FindRangeTxT(const string path) {
    ifstream fin(path);
    if (!fin) {
        fin.close();
        return;
    }
    fin.close();
    vector <Plant> pl_v;
    ReadTxT(pl_v,path);
    FindAlg(pl_v);
    pl_v.clear();
}
void FindRangeBin(const string path) {
    ifstream fin(path,ios::binary);
    if (!fin) {
        fin.close();
        return;
    }
    fin.close();
    vector <Plant> pl_v;
    ReadBin(pl_v,path);
    FindAlg(pl_v);
    pl_v.clear();
}

//------------------SORTING OH MY GOSH---------------
//COMPARATOR
bool compAge(Plant left, Plant right) {
    return left.getAge() < right.getAge();
}
bool compLenght(Plant left, Plant right) {
    return left.getLenght() < right.getLenght();
}
bool compName(Plant left, Plant right) {
    return left.getName() < right.getName();
}
bool noTcompAge(Plant left, Plant right) {
    return left.getAge() > right.getAge();
}
bool noTcompLenght(Plant left, Plant right) {
    return left.getLenght() > right.getLenght();
}
bool noTcompName(Plant left, Plant right) {
    return left.getName() > right.getName();
}
//---------------------------------------------------
void descAsc() {
    system("clear");
    cout << "1 - ascednding " << endl << "2 - descending " << endl << endl;
}
void menuSort() {
    system("clear");
    cout << "1 - Age" << endl
         << "2 - Name" << endl
         << "3 - Lenght" << endl
         << "other num - exit" << endl
         << endl;
}
void sortAlg(vector <Plant> &pl_v) {
        system("clear");
    if (pl_v.empty()) {
        cout << "Create at least one Plant" << endl;
        return;
    }
    menuSort();
    switch (checkNum()) {
        case 1:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pl_v.begin(), pl_v.end(), compAge);
                    break;
                case 2:
                    std::sort(pl_v.begin(), pl_v.end(), noTcompAge);
                    break;
            }
            break;
        case 2:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pl_v.begin(), pl_v.end(), compName);
                    break;
                case 2:
                    std::sort(pl_v.begin(), pl_v.end(), noTcompName);
                    break;
            }

            break;
        case 3:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pl_v.begin(), pl_v.end(), compLenght);
                    break;
                case 2:
                    std::sort(pl_v.begin(), pl_v.end(), noTcompLenght);
                    break;
            }
            break;
        default:
            return;
    }
    system("clear");
}
//---------------------------------------------------
void sortBin(const string path) {
    ifstream fin(path,ios::binary);
    if (!fin) {
        fin.close();
        return;
    }
    fin.close();
    vector <Plant> pl_v;
    ReadBin(pl_v,path);
    sortAlg(pl_v);
    SaveBin(pl_v,path);
    pl_v.clear();

}
void sortTxT(const string path) {
        ifstream fin(path);
    if (!fin) {
        fin.close();
        return;
    }
    fin.close();
    vector <Plant> pl_v;
    ReadTxT(pl_v,path);
    sortAlg(pl_v);
    SaveTxT(pl_v,path);
    pl_v.clear();
}
#pragma endregion

//---------------------------------------------------
void mainMenu() {
    Plant some;
    while (1) {
        system("clear");
        printFileType();
        try {
            int chooser{checkNum()};
            switch (chooser) {
                case 1:
                    some.textMode("../out/text_in_text.txt");
                    break;
                case 2:
                    some.binaryMode("../out/text_in_binary.dat");
                    break;
                case 3:
                    some.binaryMode("../out/binary_in_binary.dat");
                    break;
                default:
                    return;
            }
        } catch (FileException &ex) {
            system("clear");
            ex.Nani();
        }
    }
}
