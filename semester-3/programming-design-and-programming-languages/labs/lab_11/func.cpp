
#include "func.hpp"

string enterStr() {
    string some{};
    cin >> some;
    return some;
}
int checkNum() {
    int num{0};
    while (true) {
        if (cin >> num)
            break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("clear");
            cout << "Enter THE NUM (￣□￣」): " << endl;
        }
    }
    return num;
}
float checkDbl() {
    float num;
    while (true) {
        if (cin >> num)
            break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("clear");
            cout << "Enter THE NUM (￣□￣」): " << endl;
        }
    }
    return num;
}

Memorial enterOneMemorial() {
    Memorial memr;
    string firstTemp, secondTemp;
    cout << "Enter a author name" << endl;
    cin >> firstTemp;
    cout << "Enter a author surname" << endl;
    cin >> secondTemp;
    Author* author = new Author(firstTemp, secondTemp);
    cout << "Enter  coordinate" << endl;
    float latitude = checkDbl();
    float longtitude = checkDbl();
    cout << "Enter title material" << endl;
    cin.ignore();
    firstTemp.clear();
    getline(cin,firstTemp);
    cout << "Enter price material" << endl;
    Material* material = new Material(firstTemp, checkNum());
    cout << "Enter a whom is the menorial" << endl;
    cin >> firstTemp;
    cout << "Enter a in honor of what" << endl;
    cin >> secondTemp;
    cout << "Enter a height and square" << endl;
    memr.SetInformation(material, new Coordinate(latitude, longtitude), author,
                        checkDbl(), checkDbl(), firstTemp, secondTemp);
    return memr;
}

void descAsc() {
    system("clear");
    cout << "1 - ascednding " << endl << "2 - descending " << endl << endl;
}
void menuSort() {
    system("clear");
    cout << "1 - Author Name" << endl
         << "2 - Author Surname" << endl
         << "3 - Coordinate (longtitude)" << endl
         << "4 - Title material" << endl
         << "5 - Price material" << endl
         << "6 - A whom is the memorial" << endl
         << "7 - Honor of what" << endl
         << "8 - Height" << endl
         << "9 - Square" << endl
         << "other num - exit" << endl
         << endl;
}

// COMPARATORS
bool compName(Memorial left, Memorial right) {
    return left.authorObg->GetName() < right.authorObg->GetName();
}
bool compSurname(Memorial left, Memorial right) {
    return left.authorObg->GetSurname() < right.authorObg->GetSurname();
}
bool compCoordinate(Memorial left, Memorial right) {  // i use longtittude
    return left.coorObg->GetLongitude() < right.coorObg->GetLongitude();
}
bool compPriceMaterial(Memorial left, Memorial right) {
    return left.matObj->GetPrice() < right.matObj->GetPrice();
}
bool compTitleMaterial(Memorial left, Memorial right) {
    return left.matObj->GetNameOfMaterial() < right.matObj->GetNameOfMaterial();
}
bool compWhom(Memorial left, Memorial right) {
    return left.GetWhomIsTheMemorial() < right.GetWhomIsTheMemorial();
}
bool compHonor(Memorial left, Memorial right) {
    return left.GetInHonorOfWhat() < right.GetInHonorOfWhat();
}
bool compHeight(Memorial left, Memorial right) {
    return left.archObj->GetHeight() < right.archObj->GetHeight();
}
bool compSquare(Memorial left, Memorial right) {
    return left.archObj->GetSquare() < right.archObj->GetSquare();
}

// NOT COMPARATORS
bool noTcompName(Memorial left, Memorial right) {
    return left.authorObg->GetName() > right.authorObg->GetName();
}
bool noTcompSurname(Memorial left, Memorial right) {
    return left.authorObg->GetSurname() > right.authorObg->GetSurname();
}
bool noTcompCoordinate(Memorial left, Memorial right) {  // i use longtittude
    return left.coorObg->GetLongitude() > right.coorObg->GetLongitude();
}
bool noTcompPriceMaterial(Memorial left, Memorial right) {
    return left.matObj->GetPrice() > right.matObj->GetPrice();
}
bool noTcompTitleMaterial(Memorial left, Memorial right) {
    return left.matObj->GetNameOfMaterial() > right.matObj->GetNameOfMaterial();
}
bool noTcompWhom(Memorial left, Memorial right) {
    return left.GetWhomIsTheMemorial() > right.GetWhomIsTheMemorial();
}
bool noTcompHonor(Memorial left, Memorial right) {
    return left.GetInHonorOfWhat() > right.GetInHonorOfWhat();
}
bool noTcompHeight(Memorial left, Memorial right) {
    return left.archObj->GetHeight() > right.archObj->GetHeight();
}
bool noTcompSquare(Memorial left, Memorial right) {
    return left.archObj->GetSquare() > right.archObj->GetSquare();
}
//--------------------------------------------------
void findMemorial( const vector<Memorial>& memr_v) {
    system("clear");
    if (memr_v.empty()) {
        cout << "Create at least one Professor" << endl;
        return;
    }
    menuSort();
    switch (checkNum()) {
        case 1:
            findName(memr_v);
            break;
        case 2:
            findSurname(memr_v);
            break;
        case 3:
            findCoordinate(memr_v);
            break;
        case 4:
            findTitleMaterial(memr_v);
            break;
        case 5:
            findPriceMaterial(memr_v);
            break;
        case 6:
            findWhom(memr_v);
            break;
        case 7:
            findHonor(memr_v);
            break;
        case 8:
            findHeight(memr_v);
            break;
        case 9:
            findSquare(memr_v);
            break;
        default:
            return;
    }
}

// FINDING
void findName( const vector<Memorial>& memr_v) {
    cout << "Enter finding name" << endl;
    string name = enterStr();
    system("clear");
    int count{0};
    for (auto& Memr : memr_v) {
        if (Memr.authorObg->GetName() == name) {
            cout << Memr << endl;
            count++;
        }
    }
    if (!count) cout << "Your name is not here 0_0" << endl;
}
void findSurname( const vector<Memorial>& memr_v) {
    cout << "Enter finding Book" << endl;
    string surname = enterStr();
    system("clear");
    int count{0};
    for (auto& Memr : memr_v) {
        if (Memr.authorObg->GetSurname() == surname) {
            cout << Memr << endl;
            count++;
        }
    }
    if (!count) cout << "Your surname is not here 0_0" << endl;
}
void findCoordinate( const vector<Memorial>& memr_v) {
    cout << "Enter low&high borders of the range grade" << endl;
    float low = checkDbl();
    float high = checkDbl();
    system("clear");
    int count{0};
    for (auto& Memr : memr_v) {
        if (Memr.coorObg->GetLongitude() <= high &&
            Memr.coorObg->GetLongitude() >= low) {
            cout << Memr << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your Longtitude is not between << " << low << ".." << high
             << " 0_0" << endl;
}
void findPriceMaterial( const vector<Memorial>& memr_v) {
    cout << "Enter low&high borders of the range grade" << endl;
    int low = checkNum();
    int high = checkNum();
    system("clear");
    int count{0};
    for (auto& Memr : memr_v) {
        if (Memr.matObj->GetPrice() <= high && Memr.matObj->GetPrice() >= low) {
            cout << Memr << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your Price is not between << " << low << ".." << high << " 0_0"
             << endl;
}
void findTitleMaterial( const vector<Memorial>& memr_v) {
    cout << "Enter finding Title of Material" << endl;
    string material = enterStr();
    system("clear");
    int count{0};
    for (auto& Memr : memr_v) {
        if (Memr.matObj->GetNameOfMaterial() == material) {
            cout << Memr << endl;
            count++;
        }
    }
    if (!count) cout << "Your Material is not here 0_0" << endl;
}
void findWhom( const vector<Memorial>& memr_v) {
    cout << "Enter finding Title of Material" << endl;
    string whom = enterStr();
    system("clear");
    int count{0};
    for (auto& Memr : memr_v) {
        if (Memr.whomIsTheMemorial == whom) {
            cout << Memr << endl;
            count++;
        }
    }
    if (!count) cout << "Your Whom message is not here 0_0" << endl;
}
void findHonor( const vector<Memorial>& memr_v) {
    cout << "Enter finding the Honor of What memorial built" << endl;
    string honor = enterStr();
    system("clear");
    int count{0};
    for (auto& Memr : memr_v) {
        if (Memr.inHonorOfWhat == honor) {
            cout << Memr << endl;
            count++;
        }
    }
    if (!count) cout << "Your Honor is not here 0_0" << endl;
}
void findHeight( const vector<Memorial>& memr_v) {
    cout << "Enter low&high borders of the range grade" << endl;
    float low = checkDbl();
    float high = checkDbl();
    system("clear");
    int count{0};
    for (auto& Memr : memr_v) {
        if (Memr.archObj->GetHeight() <= high && Memr.archObj->GetHeight() >= low) {
            cout << Memr << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your Height is not between << " << low << ".." << high
             << " 0_0" << endl;
}
void findSquare( const vector<Memorial>& memr_v) {
    cout << "Enter low&high borders of the range grade" << endl;
    float low = checkDbl();
    float high = checkDbl();
    system("clear");
    int count{0};
    for (auto& Memr : memr_v) {
        if (Memr.archObj->GetSquare() <= high && Memr.archObj->GetSquare() >= low) {
            cout << Memr << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your Square is not between << " << low << ".." << high
             << " 0_0" << endl;
}
//--------------------------------------------------

void sortMemorial(vector<Memorial>& memr_v) {
    system("clear");
    if (memr_v.empty()) {
        cout << "Create at least one Memorial" << endl;
        return;
    }
    menuSort();
    switch (checkNum()) {
        case 1:
            descAsc();
            switch (checkNum()) {
                case 1:
                    sort(memr_v.begin(), memr_v.end(), compName);
                    break;
                case 2:
                    sort(memr_v.begin(), memr_v.end(), noTcompName);
                    break;
            }
            break;
        case 2:
            descAsc();
            switch (checkNum()) {
                case 1:
                    sort(memr_v.begin(), memr_v.end(), compSurname);
                    break;
                case 2:
                    sort(memr_v.begin(), memr_v.end(), noTcompSurname);
                    break;
            }

            break;
        case 3:
            descAsc();
            switch (checkNum()) {
                case 1:
                    sort(memr_v.begin(), memr_v.end(), compCoordinate);
                    break;
                case 2:
                    sort(memr_v.begin(), memr_v.end(), noTcompCoordinate);
                    break;
            }
            break;
        case 4:
            descAsc();
            switch (checkNum()) {
                case 1:
                    sort(memr_v.begin(), memr_v.end(), compTitleMaterial);
                    break;
                case 2:
                    sort(memr_v.begin(), memr_v.end(), noTcompTitleMaterial);
                    break;
            }
            break;
        case 5:
            descAsc();
            switch (checkNum()) {
                case 1:
                    sort(memr_v.begin(), memr_v.end(), compPriceMaterial);
                    break;
                case 2:
                    sort(memr_v.begin(), memr_v.end(), noTcompPriceMaterial);
                    break;
            }
            break;
        case 6:
            descAsc();
            switch (checkNum()) {
                case 1:
                    sort(memr_v.begin(), memr_v.end(), compWhom);
                    break;
                case 2:
                    sort(memr_v.begin(), memr_v.end(), noTcompWhom);
                    break;
            }
            break;
        case 7:
            descAsc();
            switch (checkNum()) {
                case 1:
                    sort(memr_v.begin(), memr_v.end(), compHonor);
                    break;
                case 2:
                    sort(memr_v.begin(), memr_v.end(), noTcompHonor);
                    break;
            }
            break;
        case 8:
            descAsc();
            switch (checkNum()) {
                case 1:
                    sort(memr_v.begin(), memr_v.end(), compHeight);
                    break;
                case 2:
                    sort(memr_v.begin(), memr_v.end(), noTcompHeight);
                    break;
            }
            break;
        case 9:
            descAsc();
            switch (checkNum()) {
                case 1:
                    sort(memr_v.begin(), memr_v.end(), compSquare);
                    break;
                case 2:
                    sort(memr_v.begin(), memr_v.end(), noTcompSquare);
                    break;
            }
            break;
        default:
            return;
    }
    system("clear");
}

void printMemorial( const vector<Memorial>& memr_v) {
    int i{1};
    system("clear");
    if (memr_v.empty()) {
        cout << "Create at least one Memorial" << endl;
        return;
    }
    for (auto& st : memr_v) {
        cout << "Position - " << i++ << endl
             << "--------------------------------" << endl
             << st << endl
             << "--------------------------------" << endl;
    }
}
//--------------------------------------------------
void deleteMemorial(vector<Memorial>& memr_v) {
    system("clear");
    printMemorial(memr_v);
    int indx{0};
    cout << "Input num of set which you want to delete \n" << endl;
    cin >> indx;
    indx--;
    memr_v.erase(memr_v.begin() + indx);
}
void deleteDupl(vector<Memorial>& memr_v) {
    for (int i = 0; i < memr_v.size(); i++)
        for (int j = i + 1; j < memr_v.size(); j++)
            if (memr_v[i] == memr_v[j]) memr_v.erase(memr_v.begin() + i);
}
void CopyToPosition(vector<Memorial>& memr_v) {
    system("clear");
    printMemorial(memr_v);
    int pos{0}, indx{0};
    cout << "Please enter num of copy set and in what position would you "
            "insert it\n";
    cin >> pos >> indx;
    pos--;
    indx--;
    Memorial cpy = memr_v[pos];
    memr_v.insert(memr_v.begin() + indx, cpy);
}
//--------------------------------------------------

inline void printMenu() {
    cout << "Hello User (＾▽＾)" << endl
         << "please choose your variant" << endl
         << "1 - create Memorial" << endl
         << "2 - print Memorial" << endl
         << "3 - Delete Memorial " << endl
         << "4 - use Template for Menorials" << endl
         << "5 - sort Memorials" << endl
         << "6 - Delete duplicates" << endl
         << "7 - Copy to posistion" << endl
         << "8 - Find Memorial" << endl
         << "Oher num - exit" << endl
         << endl;
}
void mainMenu() {
    vector<memorial::Memorial> memr_v{};
    printMenu();
    while (1) {
        int chooser{checkNum()};
        switch (chooser) {
            case 1:

                memr_v.push_back(enterOneMemorial());
                system("clear");
                printMenu();
                break;
            case 2:
                printMemorial(memr_v);
                printMenu();
                break;
            case 3:
                deleteMemorial(memr_v);
                system("clear");
                printMenu();
                break;
            case 5:
                sortMemorial(memr_v);
                printMenu();
                break;
            case 6:
                deleteDupl(memr_v);
                system("clear");
                printMenu();
                break;
            case 7:
                CopyToPosition(memr_v);
                printMenu();
                break;
            case 8:
                findMemorial(memr_v);
                printMenu();
                break;
            default:
                return;
        }
    }
}
