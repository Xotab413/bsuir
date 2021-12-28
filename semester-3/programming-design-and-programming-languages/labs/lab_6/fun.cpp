#include "headers/fun.h"

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

GradeStudent enterOneGradeStudent() {
    GradeStudent grdS;
    cout << "Enter a Name: ";
    grdS.setName(enterStr());
    cout << "Enter a Age: ";
    grdS.setAge(checkNum());
    cout << "Enter a Course: ";
    grdS.setCourse(checkNum());
    cout << "Enter a Workplace ";
    grdS.setWorkpl(enterStr());

    return grdS;
}
Student enterOneStudent() {
    Student stdnt;
    cout << "Enter a Name: ";
    stdnt.setName(enterStr());
    cout << "Enter a Age: ";
    stdnt.setAge(checkNum());
    cout << "Enter a Course: ";
    stdnt.setCourse(checkNum());

    return stdnt;
}
SchoolKid enterOneSchoolKid() {
    SchoolKid schk;
    cout << "Enter a Name: ";
    schk.setName(enterStr());
    cout << "Enter a Age: ";
    schk.setAge(checkNum());
    cout << "Enter a Grade: ";
    schk.setGrade(checkNum());

    return schk;
}

void menuCreation() {
    system("clear");
    cout << "Press : " << endl
         << "1 - for Student" << endl
         << "2 - for SchoolKid" << endl
         << "3 - for GradeStudent" << endl
         << "4 - other num exit" << endl
         << endl;
}
void findMenu() {
    system("clear");
    cout << "1 - Age" << endl
         << "2 - Grade" << endl
         << "3 - Course" << endl
         << "4 - Name" << endl
         << "5 - Workplace" << endl
         << "other num - exit" << endl
         << endl;
}

void createPupils(Pupil**& mas, int& size) {
    if (!size) {
        mas = new Pupil*[1];
        ++size;
    } else {
        Pupil** temp = new Pupil*[++size];
        for (int i = 0; i < size - 1; i++) {
            temp[i] = mas[i];
        }
        delete[] mas;
        mas = new Pupil*[size];
        for (int i = 0; i < size; i++) mas[i] = temp[i];
        delete[] temp;
    }
    menuCreation();
    switch (checkNum()) {
        case 1:
            mas[size - 1] = new Student(enterOneStudent());
            break;
        case 2:
            mas[size - 1] = new SchoolKid(enterOneSchoolKid());
            break;
        case 3:
            mas[size - 1] = new GradeStudent(enterOneGradeStudent());
            break;
        default:
            return;
    }
}

//--------------------------------------------------
void findName(Pupil**& mas, const int size) {
    cout << "Enter finding name" << endl;
    string name = enterStr();
    system("clear");
    int count{0};
    for (int i = 0; i < size; i++) {
        if (mas[i]->getName() == name) {
            cout << "Hello user i'm a " << mas[i]->type() << endl
                 << mas[i] << endl;
            count++;
        }
    }
    if (!count) cout << "Your name is not here 0_0" << endl;
}
void findWorkpl(Pupil**& mas, const int size) {
    cout << "Enter finding Workplace" << endl;
    string workpl = enterStr();
    system("clear");
    int count{0};
    for (int i = 0; i < size; i++) {
        if (mas[i]->type() == "GradeStudent")
            if (mas[i]->getWorkpl() == workpl) {
                cout << "Hello user i'm a " << mas[i]->type() << endl
                     << mas[i] << endl;
                count++;
            }
    }
    if (!count) cout << "Your Workplace is not here 0_0" << endl;
}
void findGrade(Pupil**& mas, const int size) {
    cout << "Enter low&high borders of the range grade" << endl;
    int low = checkNum();
    int high = checkNum();
    system("clear");
    int count{0};
    for (int i = 0; i < size; i++) {
        if (mas[i]->getGrade() <= high && mas[i]->getGrade() >= low) {
            cout << "Hello user i'm a " << mas[i]->type() << endl
                 << mas[i] << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your grade is not between << " << low << ".." << high << " 0_0"
             << endl;
}
void findCourse(Pupil**& mas, const int size) {
    cout << "Enter low&high borders of the range Course" << endl;
    int low = checkNum();
    int high = checkNum();
    system("clear");
    int count{0};
    for (int i = 0; i < size; i++) {
        if (mas[i]->getCourse() <= high && mas[i]->getCourse() >= low) {
            cout << "Hello user i'm a " << mas[i]->type() << endl
                 << mas[i] << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your course is not between << " << low << ".." << high
             << " 0_0" << endl;
}
void findAge(Pupil**& mas, const int size) {
    cout << "Enter low&high borders of the range Course" << endl;
    int low = checkNum();
    int high = checkNum();
    system("clear");
    int count{0};
    for (int i = 0; i < size; i++) {
        if (mas[i]->getAge() <= high && mas[i]->getAge() >= low) {
            cout << "Hello user i'm a " << mas[i]->type() << endl
                 << mas[i] << endl;
            count++;
        }
    }
    if (!count)
        cout << "Your age is not between << " << low << ".." << high << " 0_0"
             << endl;
}
void findPupils(Pupil**& mas, const int size) {
    system("clear");
    if (!size) {
        cout << "Create at least one Pupil" << endl;
        return;
    }
    findMenu();
    switch (checkNum()) {
        case 1:
            findAge(mas, size);
            break;
        case 2:
            findGrade(mas, size);
            break;
        case 3:
            findCourse(mas, size);
            break;
        case 4:
            findName(mas, size);
            break;
        case 5:
            findWorkpl(mas, size);
            break;
        default:
            return;
    }
}
//--------------------------------------------------

void deleteOnce(Pupil**& mas, int& size, int del_pos) {
    Pupil** temp = new Pupil*[size - 1];
    for (int i = 0; i < size; i++)
        if (i != del_pos) temp[i] = mas[i];
    delete[] mas;
    mas = new Pupil*[--size];
    for (int i = 0; i < size; i++) mas[i] = temp[i];
    delete[] temp;
}
void deleteDuplicate(Pupil**& mas, int& size) {
    int col = 0;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++) {
            if (mas[i]->getAge() == mas[j]->getAge() &&
                mas[i]->getName() == mas[j]->getName() &&
                mas[i]->getCourse() == mas[j]->getCourse() &&
                mas[i]->getGrade() == mas[j]->getGrade() &&
                mas[i]->getWorkpl() == mas[j]->getWorkpl()) {
                deleteOnce(mas, size, j--);
            }
        }
}

void prntPupils(Pupil** arr, const int size) {
    int i{0};
    system("clear");
    if (!size) {
        cout << "Create at least one Pupil" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "Position - " << i + 1 << endl
             << "--------------------------------" << endl
             << "Hello user i'm a " << arr[i]->type() << endl
             << arr[i] << "--------------------------------" << endl
             << endl;
    }
}
void printMenu() {
    cout << "Hello User (＾▽＾)" << endl
         << "please choose your variant" << endl
         << "1 - add Pupil" << endl
         << "2 - print all Pupils" << endl
         << "3 - find Pupils" << endl
         << "4 - use Template for Pupils" << endl
         << "5 - delete duplicates" << endl
         << "Oher num - exit" << endl
         << endl;
}

void getTempl(Pupil**& mas, int& size) {
    size = 5;
    mas = new Pupil*[size];
    mas[0] = new GradeStudent("Charlie", 24, 4, "BSU"),
    mas[1] = new Student("Josh", 19, 3),
    mas[2] = new SchoolKid("Martin", 12, 5),
    mas[3] = new GradeStudent("Kirill", 24, 5, "Oxford"),
    mas[4] = new SchoolKid("Nil", 14, 8);
}

void mainMenu() {
    Pupil** ppl{nullptr};
    int size{0};
    printMenu();
    while (1) {
        int chooser{checkNum()};
        switch (chooser) {
            case 1:
                createPupils(ppl, size);
                system("clear");
                printMenu();
                break;
            case 2:
                prntPupils(ppl, size);
                printMenu();
                break;
            case 3:
                findPupils(ppl, size);
                printMenu();
                break;
            case 4:
                getTempl(ppl, size);
                system("clear");
                printMenu();
                break;
            case 5:
                deleteDuplicate(ppl, size);
                system("clear");
                printMenu();
                break;
            default:
                delete[] ppl;
                return;
        }
    }
}