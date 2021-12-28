#include <iostream>
using namespace std;
// Менюшка + проверка на имя (без буков и один дефис только) + если есть уже айдишник то перезапись или errorka
// TO DO перегрузка и из-за неё проверка 
class Detail {
    string m_id;
    string m_name;
    double m_mass;
public :
    friend void prntDetail(const Detail& detail);
    Detail (const string id = "", const string name = "", const double mass = 0) {
        m_id = id;
        m_name = name;
        m_mass = mass;
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
    friend class Control;

};
double checkMass() {
    double mass;
    cin >> mass;
    return mass;
}

class Control {
    public :
    void chngWeight(Detail& detail) {
        detail.m_mass = checkMass();
    }
    ~Control(){};
};

void prntDetail (const Detail& detail) {
    cout << "-----------------------------" << endl;
    cout << "Id - "  << detail.m_id   << endl
        << "Name - " << detail.m_name << endl
        << "Mass - " << detail.m_mass << endl;
    cout << "-----------------------------" << endl;
}
int checkNumChoose (Detail* detail, int size) {
    int num;
    while (!(cin >> num) || num - 1 < 0 || num - 1 > size) {
        cout << "Please enter num again" << endl;
    }
    return num;
} 
void menu() {




}

int main () {
    int size = 0;
    cout << "Enter count of details" << endl;
    do {
        rewind(stdin);
        cin >> size;
    } while(!size);
    Detail* details = new Detail[size];
    for (int i = 0; i < size; i++) {
        string id, name;
        cout << "Enter a id" << endl;
        cin >> id;
        details[i].setId(id);
        cout << "Enter a name of detail" << endl;
        cin >> name;
        details[i].setName(name);
        cout << "Enter a mass of detail" << endl;
        details[i].setMass(checkMass());
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "Num - " << i + 1 << endl;
        prntDetail(details[i]);
    }
    cout << endl;
    cout << "Do you want to change your mass of Detail ?" << endl << "1 - yes, 0 - no" << endl;
    
        bool chooser;
        cin >> chooser;
        if (chooser) {
            Control control;
            cout << "Choose num of editable detail" << endl;
            control.chngWeight(details[checkNumChoose(details,size) - 1]);
        }

        cout << "Editable :" << endl;
        for (int i = 0; i < size; i++) {
        cout << "Num - " << i + 1 << endl;
        prntDetail(details[i]);
    }
    delete [] details;
    return 0;
}