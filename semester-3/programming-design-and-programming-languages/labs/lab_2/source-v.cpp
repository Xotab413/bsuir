#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;
// Менюшка + проверка на имя (без цифр) + если есть уже айдишник то перезапись // Доп
class Detail {
    string m_id;
    string m_name;
    double m_mass;
public :
    friend void prntDetails(const vector<Detail>& details);
    friend bool findId(const vector<Detail>& details, const string& id);
    friend class Control; 
    Detail (const string id = "", const string name = "", const double mass = 0) 
        : m_id{id}, m_name{name}, m_mass{mass}                
    {
    }
    ~Detail() {
        m_id.clear();
        m_name.clear();
    }
    string getId()   { return m_id;}
    string getName() { return m_name;}
    double getMass() { return m_mass;}
    void setId(string id) { m_id = id;}
    void setName(string name) {m_name = name;}
    void setMass(double mass) {m_mass = mass;}
    

};

double checkMass() {
    double mass {0};
    while (true) {
        if (cin >> mass && mass > 0) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            system("clear");
            cout << "Enter the mass of details: ";
        }
    }
    return mass;
}
int checkChooser() {
    int chooser {0};
    while (true) {
        if (cin >> chooser) {
            break;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            system("clear");
            cout << "Enter the right choose: ";
        }
    }
    return chooser;
}
bool findDigit(const string& str) {
    for(const auto c : str) {
        if (isdigit(c))
            return true;
    }
    return false;
}
string checkName() {
    string name {""};
    while (true) {
        if (cin >> name && !findDigit(name)) {
            break;
        } else {
            cin.clear();
            cin.sync();
            system("clear");
            cout << "Enter the name of detail without digit: ";
        }
    }
    return name;

}
string enterId(const vector<Detail>& details) {
    string id {""};
    while (true) {
        cin >> id;
        if (findId(details,id)) {
            cin.clear();
            cin.sync();
            system("clear");
            prntDetails(details);
            cout << "Enter different id: ";
        }
        else 
            break;
    }
    return id;

}
int chkWeightChs (int size) {
    int num;
    while (!(cin >> num) || num - 1 < 0 || num - 1 >= size) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
        system("clear");
        cout << "Please enter num again: " << endl;
    }
    return num;
} 


class Control {
    public :
    void chngWeight(Detail& detail) {
        cout << "Enter a mass of detail: ";
        detail.m_mass = checkMass();
    }
    ~Control(){};
};

void prntDetails (const vector<Detail>& details) {
    int i {1};
    system("clear");
    if (details.empty()) {
        cout << "Create at least one detail" << endl;
        return; 
    }
    for (auto & detail : details) {
        cout << "Position - " << i++ << endl
            << "--------------------------------" << endl
            << "Id - "  << detail.m_id   << endl
            << "Name - " << detail.m_name << endl
            << "Mass - " << detail.m_mass << endl
            << "--------------------------------" << endl;
    }
}
bool findId(const vector<Detail>& details, const string& id) {
    for(const auto& detail : details) 
        if(detail.m_id == id)
            return true;
    return false;
}
void printMenu() {
    cout    << "Hello User (＾▽＾)"<< endl
            << "please choose your variant"<< endl
            << "1 - add detail"<< endl
            << "2 - print all details"<< endl
            << "3 - edit weight in some detail"<< endl
            << "Oher num - exit"<< endl << endl;
}
Detail enterOneDetail(const vector<Detail>& details) {
    Detail detail;
    cout << "Enter a id: ";
    detail.setId(enterId(details));
    cout << "Enter a name of detail: ";
    detail.setName(checkName());
    cout << "Enter a mass of detail: ";
    detail.setMass(checkMass());
    return detail;

}
void selctMass( vector<Detail>& details) {
    system("clear");
    prntDetails(details);
    if (details.empty()) {
        cout << "Create at least one detail" << endl;
        return; 
    }
    Control control;
    cout << "Choose number of editable detail" << endl;
    control.chngWeight(details[chkWeightChs(details.size()) - 1]);
}


void mainMenu(vector<Detail>& details) {
    printMenu();
    while(1) {
        int chooser {checkChooser()};
        switch (chooser) {
        case 1:
            details.push_back(enterOneDetail(details));
            system("clear");
            printMenu();
            break;
        case 2:
            prntDetails(details);
            printMenu();
            break;
        case 3:
            selctMass(details);
            printMenu();
            break;    
        default:
            return;
        }
    }
}

int main () {
    vector<Detail> details;
    mainMenu(details);
    details.clear();
    return 0;
}