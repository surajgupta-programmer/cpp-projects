#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
using namespace std;

struct student
{
    int id;
    char name[20];
    char course[20];
};

int main(int argc, char const *argv[])
{
    vector<student> students;
    student s;
    int option = 0;
    // -----------------------------------------------------------------------------------------------------------------------------------------------
    cout << "1. Add Student\n2. Display all students\n3. Search student\n4. Delete student\n5. Exit\nEnter the number : ";
    cin >> option;
    // -----------------------------------------------------------------------------------------------------------------------------------------------

    // -----------------------------------------------------------------------------------------------------------------------------------------------
    switch (option)
    {
        // -----------------------------------------------------------------------------------------------------------------------------------------------
    case 1:
    {
        fstream file("data.dat", ios::binary | ios::app);
        if (!file)
        {
            cout << "file is not available!";
        }
        int r = 1;
        while (r == 1)
        {
            cout << "Enter your id : ";
            cin >> s.id;
            cout << "Enter your name : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(s.name, 20);
            cout << "Enter your course : ";
            cin.getline(s.course, 20);

            file.write((char *)&s, sizeof(s));
            cout << "Enter :\n1 - add more student\n2 - exit" << endl;
            cin >> r;
        }

        file.close();
        break;
    }
        // -----------------------------------------------------------------------------------------------------------------------------------------------
    case 2:
    {
        fstream file2("data.dat", ios::in | ios::binary);

        while (file2.read((char *)&s, sizeof(s)))
        {
            cout << s.id << "," << s.name << "," << s.course << endl;
        }
        file2.close();

        break;
    }
        // -----------------------------------------------------------------------------------------------------------------------------------------------
    case 3:
    {
        fstream file3("data.dat", ios::in | ios::binary);

        int target;
        cout << "Enter your Id : ";
        cin >> target;
        bool check=false;
        while (file3.read((char *)&s, sizeof(s)))
        {
            if (target == s.id)
            {
                cout << s.id << "," << s.name << "," << s.course << endl;
                check=true;
                break;
            }
            if (check==false)
            {
                cout<<"Student's record does not exist"<<endl;
            }
            
        }
        file3.close();
        break;
    }
        // -----------------------------------------------------------------------------------------------------------------------------------------------
    case 4:
    {
        int del;
        cout << "Enter the Id to Delete student : ";
        cin >> del;
        ifstream infile("data.dat", ios::binary);
        ofstream outfile("temp.dat", ios::binary);

        while (infile.read((char *)&s, sizeof(s)))
        {
            if (s.id != del)
            {
                outfile.write((char *)&s, sizeof(s));
            }
        }
        infile.close();
        outfile.close();

        remove("data.dat");
        rename("temp.dat", "data.dat");

        cout << "Deleted successfully!" << endl;
        break;
    }
    }
    return 0;
}