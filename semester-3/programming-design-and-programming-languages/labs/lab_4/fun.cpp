#include <IntArray.h>
#include <fun.h>

int checkNum() {
    int num {0};
    while (true) {
        if (cin >> num) 
            break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            system("clear");
            cout << "Enter THE NUM (￣□￣」): "<<endl;
        }
    }
    return num;
}

void findSeq(IntArray* &mas, const int & size) {

    cout <<"Enter size of your sequence: "<< endl;
    int seq_size {checkNum()}, cntr{0},is_seq{0};
    int* seq = new int [seq_size];

    cout << "Enter nums for your seqence"<<endl;

    for (int i = 0; i < seq_size; i++) {
        seq[i] = checkNum();
    }
    system("clear");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < mas[i].m_length;j++) {
            if ( seq [j] == mas[i][j] )
                cntr++;
            if (cntr == seq_size) {
                cout << "[" << i+1 << "]: " << mas[i]<<endl;
                cntr = 0;
            }
            else is_seq++; 
        }
    }

    if(is_seq == size)
        cout << "Your sequence is not here 0_0" << endl;
}

void printMenu() {
    cout    << "Hello User (＾▽＾)"<< endl
            << "please choose your variant"<< endl
            << "1 - add/create array"<< endl
            << "2 - add element to array" << endl
            << "3 - print all arrays"<< endl
            << "4 - sort arrays"<< endl
            << "5 - find queue" << endl
            << "Oher num - exit"<< endl << endl;
}

void printArr(const IntArray* mas, const int size) {
    system("clear");
    if (!size) {
        cout << "Create at least one array" << endl;
        return; 
    }
    cout << "Your arrray: " <<endl;
    for (int i = 0; i < size ; i++) 
        cout << "[" << i+1 << "]: " << mas[i]<<endl; 
    cout <<"\n";
}

void sortArr(IntArray* & mas,const int & size) {
    system("clear");
    if (!size) {
        cout << "Create at least one array" << endl;
        return; 
    }
    for (int i = 0; i < size; i++) {
        mas[i].sort();
    }
}

void inpt(IntArray* & mas,const int & size) {
    system("clear");
    if (!size) {
        cout << "Create at least one array" << endl;
        return; 
    }
    if (size == 1) 
        mas[0].push();
    else {
        printArr(mas,size);
        cout << "Choose num of array -_-"<<endl;
        while (true) {
            int checker {checkNum()};
            if (checker > 0 && checker <= size) {
                mas[checker-1].push();
                break;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
                system("clear");
                printArr(mas,size);
                cout << "Enter the right num (´• ω •): "<<endl;
            }
        }
    }
}

void add(IntArray* & mas,int & size) {
    if (!size) {
        mas = new IntArray [1];
        ++size;
    }
    else {
        IntArray* temp = new IntArray [++size];
        for (int i = 0; i < size - 1; i++) {
            temp[i] = mas[i];
        }
        delete[] mas;
        mas = new IntArray [size];
        for (int i = 0; i < size; i++) {
            mas[i] = temp[i];
        }
        delete[] temp;
    }
}

void mainMenu() {
    IntArray* arr;
    int size_arr{0};
    printMenu();
    while(1) {
        int chooser {checkNum()};
        switch (chooser) {
        case 1:
            add (arr,size_arr);
            system("clear");
            printMenu();
            break;
        case 2: 
            inpt(arr,size_arr);
            printMenu();
            break;
        case 3:
            printArr(arr,size_arr);
            printMenu();
            break;
        case 4:
            sortArr(arr,size_arr);
            printMenu();
            break;    
        case 5: 
            findSeq(arr,size_arr);
            printMenu();
            break;
        default:
            return;
        }
    }
    delete[] arr;
}