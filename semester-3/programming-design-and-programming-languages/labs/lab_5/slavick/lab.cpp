#include <iostream>
using namespace std;
class Human {
   private:
    int height;

   public:
    Human(int x) : height(x) {}
    Human() {}
    void print() { cout << "height is " << height << endl; }
    int getHeight() { return height; }
    ~Human() {}
};
class Worker : public virtual Human {
   private:
    int earn;

   public:
    Worker() {}
    Worker(int dlr, int height) : Human(height), earn(dlr) {}
    void print() {
        // Human::print();
        static_cast<Human &>(*this).print();
        cout << "Earn is " << earn << endl;
    }
    int getEarn() { return earn; }
    ~Worker() {}
};
class Engineer : public Worker {
   private:
    std::string workPlace;

   public:
    Engineer() {}
    Engineer(std::string jbHouse, int earn, unsigned int height)
        : Worker(earn, height), workPlace(jbHouse) {}
    void print() {
        // Worker::print();
        static_cast<Worker &>(*this).print();
        cout << "His workplace is " << workPlace << endl;
    }
    std::string getWorkPlace() { return workPlace; }
    ~Engineer() {}
};
class Parent : public virtual Human {
   private:
    int age;

   public:
    Parent() {}
    Parent(int _age, int height) : Human(height), age(_age) {}
    void print() {
        // Human::print();
        static_cast<Human &>(*this).print();
        cout << "His age is " << age << endl;
    }
    int getAge() { return age; }
    ~Parent() {}
};
class Child : public Parent {
   private:
    int friendsNumber;

   public:
    Child() {}
    Child(int friends, int age, int height)
        : Parent(age, height), friendsNumber(friends) {}

    void print() {
        // Parent::print();
        static_cast<Parent &>(*this).print();
        cout << "He have a " << friendsNumber << " friends\n";
    }
    int getFriends() { return friendsNumber; }
    ~Child() {}
};
class Student : public Child, public Engineer {
   private:
    int course;

   public:
    Student() {}
    Student(int course_, int friendsNumber, int age, int height,
            string workplace, int earn)
        : Child(friendsNumber, age, height),
          Engineer(workplace, earn, height),
          Human(height),
          course(course_) {}
    void print() {
        cout << "(" << course << " course," << getFriends() << " friends,"
             << getAge() << " years," << getHeight() << " sm," << getWorkPlace()
             << " comp.," << getEarn() << "$)\n";
    }
    int getCourse() { return course; }
    static Student create() {
        cout << "Enter a course of student:";
        int course;
        while (true) {
            cin >> course;
            if (course > 0 && course < 7) break;
            cout << "Error,rewrite:";
        }
        cout << "How many friends he have?";
        int friendsNmbr;
        while (true) {
            cin >> friendsNmbr;
            if (friendsNmbr > -1) break;
            cout << "Error,rewrite:";
        }
        cout << "What age?";
        int age;
        while (true) {
            cin >> age;
            if (age > 0) break;
            cout << "Error,rewrite:";
        }
        cout << "What height?";
        int height;
        while (true) {
            cin >> height;
            if (age > 0) break;
            cout << "Error,rewrite:";
        }
        cout << "What company?";
        string work;
        cin.ignore();
        cin >> work;
        cout << "What salary?";
        int salary;
        while (true) {
            cin >> salary;
            if (salary > 0) break;
            cout << "Error,rewrite:";
        }
        system("cls");
        // Student(course,friendsNmbr,friendsNmbr,height,work,salary).print();
        return Student(course, friendsNmbr, friendsNmbr, height, work, salary);
    }
    ~Student() {}
};

int main() {
    cout << "How much student?";
    int count;
    cin >> count;
    Student *arr = new Student[count];
    for (int i = 0; i < count; i++) {
        arr[i] = Student::create();
    }
    for (int i = 0; i < count; i++) {
        arr[i].print();
    }
    cout << "enter a param for sort!\n1-course \n2-friends number \n3-height "
            "\n4-workplace \n5-salary \n6-jears old";
    int choise;
    while (true) {
        cin >> choise;
        if (choise > 0 && choise < 7) break;
        cout << "Error,rewrite!";
    }

    switch (choise) {
        case 1: {
            for (int i = 0; i < count; i++) {
                for (int k = i + 1; i < count; k++) {
                    if (arr[i].getCourse() > arr[k].getCourse())
                        swap(arr[i], arr[k]);
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < count; i++) {
                for (int k = i + 1; k < count; k++) {
                    if (arr[i].getFriends() > arr[k].getFriends())
                        swap(arr[i], arr[k]);
                }
            }
            break;
        }

        case 3: {
            for (int i = 0; i < count; i++) {
                for (int k = i + 1; k < count; k++) {
                    if (arr[i].getHeight() > arr[k].getHeight())
                        swap(arr[i], arr[k]);
                }
            }
            break;
        }
        case 4: {
            for (int i = 0; i < count; i++) {
                for (int k = i + 1; k < count; k++) {
                    if (arr[i].getWorkPlace() > arr[k].getWorkPlace())
                        swap(arr[i], arr[k]);
                }
            }
            break;
        }

        case 5: {
            for (int i = 0; i < count; i++) {
                for (int k = i + 1; k < count; k++) {
                    if (arr[i].getEarn() > arr[k].getEarn())
                        swap(arr[i], arr[k]);
                }
            }
            break;
        }
        case 6: {
            for (int i = 0; i < count; i++) {
                for (int k = i + 1; k < count; k++) {
                    if (arr[i].getAge() > arr[k].getAge()) swap(arr[i], arr[k]);
                }
            }
            break;
        }
    }
    for (int i = 0; i < count; i++) {
        arr[i].print();
    }
}
//все данные для последнего объекта ввод с клаиватруы ,ввод нескольких стуентов
//,сортировка по выбраному парметру