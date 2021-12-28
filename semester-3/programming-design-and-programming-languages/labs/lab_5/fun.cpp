#include "../headers/fun.h"


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
string enterStr() {
    string some{};
    cin >> some;
    return some;
}
Professor enterOneProfesor() {
    Professor prf;
    cout << "Enter a Name: ";
    prf.setName(enterStr());
    cout << "Enter a Age: ";
    prf.setAge(checkNum());
    cout << "Enter a Grade ";
    prf.setGrade(checkNum());
    cout << "Enter a Course ";
    prf.setCourse(checkNum());
    cout << "Enter a Favorite book ";
    prf.setBook(enterStr());
    cout << "Enter a Workplace ";
    prf.setWorkpl(enterStr());
    cout << "Enter a Salary ";
    prf.setSalary(checkNum());

    return prf;
}



void descAsc() {
    system("clear");
    cout << "1 - ascednding " << endl << "2 - descending " << endl << endl;
}
void menuSort() {
    system("clear");
    cout << "1 - Age" << endl
         << "2 - Salary" << endl
         << "3 - Grade" << endl
         << "4 - Course" << endl
         << "5 - Name" << endl
         << "6 - Workplace" << endl
         << "7 - Books" << endl
         << "other num - exit" << endl
         << endl;
}

// COMPARATORS
bool compAge(Professor left, Professor right) {
    return left.getAge() < right.getAge();
}
bool compSalary(Professor left, Professor right) {
    return left.getSalary() < right.getSalary();
}
bool compGrade(Professor left, Professor right) {
    return left.getGrade() < right.getGrade();
}
bool compCourse(Professor left, Professor right) {
    return left.getCourse() < right.getCourse();
}
bool compName(Professor left, Professor right) {
    return left.getName() < right.getName();
}
bool compWorkpl(Professor left, Professor right) {
    return left.getWorkpl() < right.getWorkpl();
}
bool compBooks(Professor left, Professor right) {
    return left.getBook() < right.getBook();
}

bool noTcompSalary(Professor left, Professor right) {
    return !(left.getSalary() < right.getSalary());
}
bool noTcompGrade(Professor left, Professor right) {
    return !(left.getGrade() < right.getGrade());
}
bool noTcompCourse(Professor left, Professor right) {
    return !(left.getCourse() < right.getCourse());
}
bool noTcompName(Professor left, Professor right) {
    return !(left.getName() < right.getName());
}
bool noTcompWorkpl(Professor left, Professor right) {
    return !(left.getWorkpl() < right.getWorkpl());
}
bool noTcompBooks(Professor left, Professor right) {
    return !(left.getBook() < right.getBook());
}
bool noTcompAge(Professor left, Professor right) {
    return !(left.getAge() < right.getAge());
}

//--------------------------------------------------
void findName(const std::vector<Professor>& pr_v) {
    cout << "Enter finding name" << endl;
    string name = enterStr();
    system("clear");
    int count{0};
    for (auto prf : pr_v) {
        if (prf.getName() == name) {
            cout << prf << endl;
            count++;
        }
    }
    if (!count) cout << "Your name is not here 0_0" << endl;
}
void findBook(const std::vector<Professor>& pr_v) {
    cout << "Enter finding Book" << endl;
    string book = enterStr();
    system("clear");
    int count{0};
    for (auto prf : pr_v) {
        if (prf.getBook() == book) {
            cout << prf << endl;
            count++;
        }
    }
    if (!count) cout << "Your book is not here 0_0" << endl;
}
void findWorkpl(const std::vector<Professor>& pr_v) {
    cout << "Enter finding Workplace" << endl;
    string workpl = enterStr();
    system("clear");
    int count{0};
    for (auto prf : pr_v) {
        if (prf.getWorkpl() == workpl) {
            cout << prf << endl;
            count++;
        }
    }
    if (!count) cout << "Your Workplace is not here 0_0" << endl;
}
void findGrade(const std::vector<Professor>& pr_v) {
    cout << "Enter low&high borders of the range grade" << endl;
    int low = checkNum();
    int high = checkNum();
    system("clear");
    int count{0};
    for (auto prf : pr_v) {
        if (prf.getGrade() <= high && prf.getGrade() >= low) {
            cout << prf << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your grade is not between << " << low << ".." << high << " 0_0"
             << endl;
}
void findCourse(const std::vector<Professor>& pr_v) {
    cout << "Enter low&high borders of the range Course" << endl;
    int low = checkNum();
    int high = checkNum();
    system("clear");
    int count{0};
    for (auto prf : pr_v) {
        if (prf.getCourse() <= high && prf.getCourse() >= low) {
            cout << prf << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your course is not between << " << low << ".." << high << " 0_0"
             << endl;
}
void findSalary(const std::vector<Professor>& pr_v) {
    cout << "Enter low&high borders of the range Course" << endl;
    int low = checkNum();
    int high = checkNum();
    system("clear");
    int count{0};
    for (auto prf : pr_v) {
        if (prf.getSalary() <= high && prf.getSalary() >= low) {
            cout << prf << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your salary is not between << " << low << ".." << high << " 0_0"
             << endl;
}
void findAge(const std::vector<Professor>& pr_v) {
    cout << "Enter low&high borders of the range Course" << endl;
    int low = checkNum();
    int high = checkNum();
    system("clear");
    int count{0};
    for (auto prf : pr_v) {
        if (prf.getAge() <= high && prf.getAge() >= low) {
            cout << prf << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your age is not between << " << low << ".." << high << " 0_0"
             << endl;
}

//--------------------------------------------------

void sortProfrs(vector<Professor>& pr_v) {
    system("clear");
    if (pr_v.empty()) {
        cout << "Create at least one Professor" << endl;
        return;
    }
    menuSort();
    switch (checkNum()) {
        case 1:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pr_v.begin(), pr_v.end(), compAge);
                    break;
                case 2:
                    std::sort(pr_v.begin(), pr_v.end(), noTcompAge);
                    break;
            }
            break;
        case 2:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pr_v.begin(), pr_v.end(), compSalary);
                    break;
                case 2:
                    std::sort(pr_v.begin(), pr_v.end(), noTcompSalary);
                    break;
            }

            break;
        case 3:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pr_v.begin(), pr_v.end(), compGrade);
                    break;
                case 2:
                    std::sort(pr_v.begin(), pr_v.end(), noTcompGrade);
                    break;
            }
            break;
        case 4:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pr_v.begin(), pr_v.end(), compCourse);
                    break;
                case 2:
                    std::sort(pr_v.begin(), pr_v.end(), noTcompCourse);
                    break;
            }
            break;
        case 5:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pr_v.begin(), pr_v.end(), compName);
                    break;
                case 2:
                    std::sort(pr_v.begin(), pr_v.end(), noTcompName);
                    break;
            }
            break;
        case 6:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pr_v.begin(), pr_v.end(), compWorkpl);
                    break;
                case 2:
                    std::sort(pr_v.begin(), pr_v.end(), noTcompWorkpl);
                    break;
            }
            break;
        case 7:
            descAsc();
            switch (checkNum()) {
                case 1:
                    std::sort(pr_v.begin(), pr_v.end(), compBooks);
                    break;
                case 2:
                    std::sort(pr_v.begin(), pr_v.end(), noTcompBooks);
                    break;
            }
            break;
        default:
            return;
    }
    system("clear");
}
void prntProfesr(const vector<Professor>& professors) {
    int i{1};
    system("clear");
    if (professors.empty()) {
        cout << "Create at least one Professor" << endl;
        return;
    }
    for (auto& profesor : professors) {
        cout << "Position - " << i++ << endl
             << "--------------------------------" << endl
             << profesor << endl
             << "--------------------------------" << endl;
    }
}
void findProfrs(const std::vector<Professor>& pr_v) {
    system("clear");
    if (pr_v.empty()) {
        cout << "Create at least one Professor" << endl;
        return;
    }
    menuSort();
    switch (checkNum()) {
        case 1:
            findAge(pr_v);
            break;
        case 2:
            findSalary(pr_v);
            break;
        case 3:
            findGrade(pr_v);
            break;
        case 4:
            findCourse(pr_v);
            break;
        case 5:
            findName(pr_v);
            break;
        case 6:
            findWorkpl(pr_v);
            break;
        case 7:
            findBook(pr_v);
            break;
        default:
            return;
    }
}

void printMenu() {
    cout << "Hello User (＾▽＾)" << endl
         << "please choose your variant" << endl
         << "1 - add professor" << endl
         << "2 - print all professors" << endl
         << "3 - print other classes" << endl
         << "4 - sort proffesors" << endl
         << "5 - use Template for Professor" << endl
         << "6 - find professors" << endl
         << "Oher num - exit" << endl
         << endl;
}
void prntOther() {
    system("clear");
    GoodSchoolKid gSchKid;
    GradeStudent grS;
    Pupil pupil;
    SchoolKid schoolKid;
    Student student;

    cout << "Hi i'm Pupil " << endl
         << pupil << endl
         << "Hi i'm GoodSchoolKid " << endl
         << gSchKid << endl
         << "Hi i'm GradeStudent " << endl
         << grS << endl
         << "HI i'm just schoolKid " << endl
         << schoolKid << endl
         << "Hi dude i'm StuDent " << endl
         << student << endl;
}
vector<Professor> getTempl() {
    vector<Professor> tmpl{
        Professor("Charlie", 54, 10, "Tim&Taller", 3, "BSU", 500),
        Professor("Josh", 36, 9, "The Great Gatsby", 2, "Oxford", 3400),
        Professor("Martin", 84, 11, "Moby Dick", 1, "BSUIR", 1000),
        Professor("Kirill", 45, 9, "Hamlet", 5, "Oxford", 2000),
        Professor("Nil", 66, 8, "The Trial", 4, "Yale", 3450)};
    return tmpl;
}
void mainMenu() {
    vector<Professor> prf_v;
    printMenu();
    while (1) {
        int chooser{checkNum()};
        switch (chooser) {
            case 1:
                prf_v.push_back(enterOneProfesor());
                system("clear");
                printMenu();
                break;
            case 2:
                prntProfesr(prf_v);
                printMenu();
                break;
            case 3:
                prntOther();
                printMenu();
                break;
            case 4:
                sortProfrs(prf_v);
                printMenu();
                break;
            case 5:
                prf_v.clear();
                prf_v = getTempl();
                system("clear");
                printMenu();
                break;
            case 6:
                findProfrs(prf_v);
                printMenu();
                break;
            default:
                return;
        }
    }
}


