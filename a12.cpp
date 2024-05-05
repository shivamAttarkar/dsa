/*
Company maintains employee information as employee ID, name,
designation and salary. Allow user to add, delete information of
employee. Display information of particular employee. If employee
does not exist an appropriate message is displayed. If it is, then the
system displays the employee details. Use index sequential file to
maintain the data
*/

#include <iostream>
#include <fstream>
using namespace std;

struct IndexRecord
{
    int empId;
    int pos;
};

struct EmpRecord
{
    int empId;
    char name[20];
};

class File
{
    string indexFileName, dataFileName;

public:
    File(string indexFileName = "index.dat", string dataFileName = "emp.dat")
    {
        this->indexFileName = indexFileName;
        this->dataFileName = dataFileName;
    }

    void insertRecord()
    {
        IndexRecord i;
        EmpRecord e;
        ofstream indexFile(indexFileName, ios::app | ios::binary);
        ofstream dataFile(dataFileName, ios::app | ios::binary);
        if (indexFile.is_open() && dataFile.is_open())
        {
            cout << "Enter Employee Id: ";
            cin >> e.empId;
            i.empId = e.empId;
            cout << "Enter Employee Name: ";
            cin >> e.name;
            dataFile.seekp(0, ios::end);
            int offset = dataFile.tellp();
            i.pos = offset / sizeof(EmpRecord);

            indexFile.write((char *)&i, sizeof(IndexRecord));
            dataFile.write((char *)&e, sizeof(EmpRecord));

            cout << "Record Inserted Successfully." << endl;
        }
    }

    int search()
    {
        IndexRecord i;
        int empId;
        cout << "Enter Employee ID: ";
        cin >> empId;
        ifstream indexFile(indexFileName, ios::in | ios::binary);
        if (indexFile.is_open())
        {
            while (indexFile.read((char *)&i, sizeof(IndexRecord)))
            {
                if (i.empId == empId)
                {
                    EmpRecord e;
                    ifstream dataFile(dataFileName, ios::in | ios::binary);
                    if (dataFile.is_open())
                    {
                        dataFile.seekg(i.pos * sizeof(EmpRecord), ios::beg);
                        dataFile.read((char *)&e, sizeof(EmpRecord));
                        cout << e.name << endl;
                    }
                    return i.pos;
                }
            }
        }
        return 0;
    }

    void display()
    {
        EmpRecord e;
        ifstream file(dataFileName, ios::in | ios::binary);
        if (file.is_open())
        {
            while (file.read((char *)&e, sizeof(EmpRecord)))
            {
                cout << e.name << endl;
            }
        }
    }

    void displayIndexFile()
    {
        IndexRecord i;
        ifstream file(indexFileName, ios::in | ios::binary);
        if (file.is_open())
        {
            while (file.read((char *)&i, sizeof(IndexRecord)))
            {
                cout << i.empId << ":" << i.pos << endl;
            }
        }
    }
};

int main()
{
    File f;
    f.displayIndexFile();
    f.search();
    /*
    f.insertRecord();
    f.insertRecord();
    f.display();*/
    return 0;
}