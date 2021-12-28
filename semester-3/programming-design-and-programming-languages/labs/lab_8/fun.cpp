#include "headers/fun.h"
#include "../headers/SetException.h"

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
Set enterOneSet() {
    Set s;
    int num {0};
    while (1) {
        system("clear");
        cout << "Enter a Num: ";
        cin >> num;
        if (num < 0)
            throw SetException(2);
        if (num == 228)
            break;
        s.add(num);
    }
    return s;
}
void printSets(const vector<Set>& set_v) {
        int i{1};
        system("clear");
        if (set_v.empty()) {
            cout << "Create at least one Professor" << endl;
            return;
        }
        for (auto& st : set_v) {
            cout << "Position - " << i++ << endl
                << "--------------------------------" << endl
                << st << endl
                << "--------------------------------" << endl;
        }
    }

//--------------------------------------------------
void findSeq(const vector<Set>& set_v) {
    cout <<"Enter size of your sequence: "<< endl;
    int seq_size {checkNum()}, cntr{0},is_seq{0};
    if (seq_size < 0)
        throw SetException(3);
    int* seq = new int [seq_size];

    cout << "Enter nums for your seqence"<<endl;

    for (int i = 0; i < seq_size; i++) {
        seq[i] = checkNum();
    }
    system("clear");
    int num = 0;
    for (auto& st : set_v) {
        num++;
        for(int j = 0; j < st.m_size;j++) {
            if ( seq [j] == st.m_data[j] )
                cntr++;
            if (cntr == seq_size) {
                cout << "[" << num << "]: " << st<<endl;
                cntr = 0;
            }
            else is_seq++; 
        }
    }
    if(is_seq == set_v.size())
        cout << "Your sequence is not here 0_0." << endl;
}
void deleteSet(vector<Set>& set_v) {
    system("clear");
    printSets(set_v);
    int indx {0};
    cout << "Input num of set which you want to delete \n" << endl;
    cin >> indx;
    indx--;
    if (!(indx >= 0 && indx < set_v.size()))
        throw SetException(1);
    set_v.erase(set_v.begin() + indx);
}
void deleteDupl(vector<Set>& set_v) {
    for (int i = 0; i < set_v.size(); i ++) 
        for (int j = i+1; j < set_v.size(); j++)
            if (set_v[i] == set_v[j])
                set_v.erase(set_v.begin() + i);
}
void unificationSets(vector<Set>& set_v) {
    system("clear");
    printSets(set_v);
    cout << "Enter nums of 1-nd and 2-nd sets \n";
    int f_set {0}, s_set{0};
    cin >> f_set >> s_set;
    --f_set; --s_set;
    if (!(f_set >= 0 && f_set < set_v.size() && s_set >= 0 && s_set < set_v.size()))
        throw SetException(1);
    Set result = set_v[f_set] + set_v[s_set];
    system("clear");
    cout << set_v[f_set] << " U " << set_v[s_set] << ":\n"
         << result << endl;
}
void intersectionSets(vector<Set>& set_v) {
    system("clear");
    printSets(set_v);
    cout << "Enter nums of 1-nd and 2-nd sets \n";
    int f_set {0}, s_set{0};
    cin >> f_set >> s_set;
    --f_set; --s_set;
    if (!(f_set >= 0 && f_set < set_v.size() && s_set >= 0 && s_set < set_v.size()))
        throw SetException(1);
    Set result = set_v[f_set] & set_v[s_set];
    system("clear");
    cout << set_v[f_set] << " ∩ " << set_v[s_set] << ":\n";
        if(!result.m_size)
            cout <<"∅" << endl;
        else 
            cout << result << endl;
}
void CopyToPosition(vector <Set>& set_v) {
    system("clear");
    printSets(set_v);
    int pos{0}, indx{0};
    cout << "Please enter num of copy set and in what position would you insert it\n";
    cin >> pos >> indx;
    pos--;
    indx--;
    if (!(pos >= 0 && pos < set_v.size() && indx >= 0 && indx < set_v.size()))
        throw SetException(1);
    Set cpy = set_v[pos];
    set_v.insert(set_v.begin() + indx,cpy);
}
//--------------------------------------------------

inline void printMenu() {
    cout << "Hello User (＾▽＾)" << endl
         << "please choose your variant" << endl
         << "1 - add Set" << endl
         << "2 - print all Sets" << endl
         << "3 - unification of Sets U" << endl
         << "4 - intersection of Sets ∩" << endl
         << "5 - use Template for Sets" << endl
         << "6 - delete Sets" << endl
         << "7 - Delete duplicates" << endl
         << "8 - Copy to posistion" << endl
         << "9 - Find set" << endl
         << "228 - Just exception" << endl
         << "Oher num - exit" << endl
         << endl;
}
vector<Set> getTempl() {
    int set_1[] {1,2,3,4,5};
    int set_2[] {34,563,42,1,3};
    int set_3[] {2,52,6,42,0};
    int set_4[] {90,80,20,30,40};
    int set_5[] {30,60,10,228,993};
    vector<Set> tmpl{
        Set(set_1,5),
        Set(set_2,5),
        Set(set_3,5),
        Set(set_4,5),
        Set(set_5,5)};
    return tmpl;
}
void mainMenu() {
    vector<Set> set_v;
    printMenu();
    while (1) {
        try {
        int chooser{checkNum()};
        switch (chooser) {
            case 1:
                set_v.push_back(enterOneSet());
                system("clear");
                printMenu();
                break;
            case 2:
                printSets(set_v);
                printMenu();
                break;
            case 3:
                unificationSets(set_v);
                printMenu();
                break;
            case 4:
                intersectionSets(set_v);
                printMenu();
                break;
            case 5:
                set_v.clear();
                set_v = getTempl();
                system("clear");
                printMenu();
                break;
            case 6:
                deleteSet(set_v);
                system("clear");
                printMenu();
                break;
            case 7:
                deleteDupl(set_v);
                system("clear");
                printMenu();
                break;
            case 8:
                CopyToPosition(set_v);
                printMenu();
                break;
            case 9:
                findSeq(set_v);
                printMenu();
                break;
            case 228:
                throw SetException(228);
            default:
                return;
        }
        }
        catch (SetException& ex) {
            system ("clear");
            ex.Nani();
            exit (228);
        }
    }
    for (auto seT : set_v)
        seT.erase();
}
