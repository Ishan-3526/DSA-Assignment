#include <iostream>
#include <cstring>

using namespace std;
// Deaclred Struct
struct student {
    int roll;
    char name[10];
    float sgpa;
};
//Display All Data Called each time
void display(student myarr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Roll: " << myarr[i].roll << endl;
        cout << "Name: " << myarr[i].name << endl;
        cout << "SGPA: " << myarr[i].sgpa << endl << endl;
    }
}
//To sort data using roll_no
void bubblesort(student myarr[], int size) {
    bool swapped;
    int j;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (j = 0; j < size - i - 1; ++j) {
            if (myarr[j].roll > myarr[j + 1].roll) {
                student temp = myarr[j];
                myarr[j] = myarr[j + 1];
                myarr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
//To find pivot element in quick sort
int partition(student myarr[], int low, int high) {
    float pivot = myarr[high].sgpa;
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (myarr[j].sgpa > pivot) {
            ++i;
            student temp = myarr[i];
            myarr[i] = myarr[j];
            myarr[j] = temp;
        }
    }
    student temp = myarr[i + 1];
    myarr[i + 1] = myarr[high];
    myarr[high] = temp;
   
    return (i + 1);
}
//Mian function to sort toppes by sgpa
void toppersort(student myarr[], int low, int high) {
    if (low < high) {
        int pi = partition(myarr, low, high);
        toppersort(myarr, low, pi - 1);
        toppersort(myarr, pi + 1, high);
    }
}
//Sort data using there name
void alphasort(student myarr[], int size) {
    for (int i = 1; i < size; ++i) {
        student key = myarr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(myarr[j].name, key.name) > 0) {
            myarr[j + 1] = myarr[j];
            j = j - 1;
        }
        myarr[j + 1] = key;
    }
}
//search student with greater than SGPA
void searchgpa(student myarr[] ,int size,int limit)
{
    int j;
    for (int i = 0; i < size - 1; ++i) {
            if (myarr[i].sgpa>= limit) {
                student temp = myarr[j];
                cout<<"Name = "<<myarr[i].name<<endl;
                cout<<"Roll No = "<<myarr[i].roll<<endl;
                cout<<"SGPAv = "<<myarr[i].sgpa<<endl<<endl<<endl;
        }
    }
}
//To search student using name
void namesearch(student myarr[], int size, const char* name) {
    int low = 0;
    int high = size - 1;
   
    while (low <= high) {
        int mid = low + (high - low) / 2;
       
        int cmp = strcmp(myarr[mid].name, name);
        if (cmp == 0) {
            cout << "Student found:" << endl;
            cout << "Roll No = " << myarr[mid].roll << endl;
            cout << "Name = " << myarr[mid].name << endl;
            cout << "SGPA = " << myarr[mid].sgpa << endl << endl;
            return;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }

    }

                cout << "Student not found." << endl;

}
int main() {
    int limit , size = 12, low= 0;
    student myarr[size];

    myarr[0].roll = 11;
    strcpy(myarr[0].name, "Ajay");
    myarr[0].sgpa = 8.9;

    myarr[1].roll = 2;
    strcpy(myarr[1].name, "Vijay");
    myarr[1].sgpa = 9.9;

    myarr[2].roll = 10;
    strcpy(myarr[2].name, "Jay");
    myarr[2].sgpa = 7.9;

    myarr[3].roll = 7;
    strcpy(myarr[3].name, "Abrar");
    myarr[3].sgpa = 9.23;

    myarr[4].roll = 5;
    strcpy(myarr[4].name, "Jay");
    myarr[4].sgpa = 7.9;

    myarr[5].roll = 8;
    strcpy(myarr[5].name, "Ranchi");
    myarr[5].sgpa = 7.9;

    myarr[6].roll = 4;
    strcpy(myarr[6].name, "Suchi");
    myarr[6].sgpa = 7.9;

    myarr[7].roll = 6;
    strcpy(myarr[7].name, "Nihal");
    myarr[7].sgpa = 7.9;

    myarr[8].roll = 9;
    strcpy(myarr[8].name, "Suraj");
    myarr[8].sgpa = 7.9;

    myarr[9].roll = 3;
    strcpy(myarr[9].name, "Aditya");
    myarr[9].sgpa = 7.9;

    myarr[10].roll = 1;
    strcpy(myarr[10].name, "Sarthk");
    myarr[10].sgpa = 4.3;

    myarr[11].roll = 12;
    strcpy(myarr[11].name, "Akshay");
    myarr[11].sgpa = 4.9;


cout<<"Array After Sorting Roll_No."<<endl<<endl;
    bubblesort(myarr, size);
    display(myarr, size);
cout<<endl<<endl;    

cout<<"Array After Sorting Alphabetically"<<endl<<endl;
alphasort(myarr,size);
display(myarr,size);

cout<<"Array After Sorting Toppers."<<endl<<endl;
toppersort(myarr,low , size);
display(myarr,size);

cout<<"Search Student Using SGPA"<<endl<<endl;
cout<<"Enter SGPA Limit :- "<<endl;
cin>>limit;
searchgpa(myarr , size , limit);

    char sname[10];
    cout << "Enter the name of the student to search: "<<endl<<endl;
    cin >> sname;
    namesearch(myarr, size, sname);

    return 0;
}
