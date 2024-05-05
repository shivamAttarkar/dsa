#include <iostream>
#include <fstream>

using namespace std;

struct Record
{
    char name[10];
    int rollNo;
};

class File
{
public:
    string filename;

    File(string filename = "stud.dat")
    {
        this->filename = filename;
    }

    void writeRecord()
    {
        Record r;
        cout << "Enter Name: ";
        cin >> r.name;
        cout << "Enter Roll No: ";
        cin >> r.rollNo;
        ofstream file(filename, ios::app | ios::binary);
        while (file.is_open())
        {
            file.write((char *)&r, sizeof(Record));
            file.close();
        }
    }

    void readRecord()
    {
        Record r;
        ifstream file(filename, ios::in | ios::binary);
        if (file.is_open())
        {
            while (file.read((char *)&r, sizeof(Record)))
            {
                if (r.rollNo != -1)
                {
                    cout << r.name << ":" << r.rollNo << endl;
                }
            }
        }
    }

    int search(int rollNo)
    {
        int i = 0;
        Record r;
        ifstream file(filename, ios::in | ios::binary);
        if (file.is_open())
        {
            while (file.read((char *)&r, sizeof(Record)))
            {
                if (r.rollNo == rollNo)
                {
                    return i;
                }
                i++;
            }
            file.close();
        }
        return 0;
    }

    void deleteRecord()
    {
        Record r;
        fstream file(filename, ios::in | ios::out | ios::binary);
        file.seekg(0, ios::beg);
        int rollNo;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        int i = search(rollNo);
        int pos = i * sizeof(Record);
        file.seekp(pos);
        r.rollNo = -1;
        if (file.is_open())
        {
            file.write((char *)&r, sizeof(Record));
            file.close();
        }
    }
};

int main()
{
    File f;
    f.writeRecord();
    f.writeRecord();
    f.readRecord();
    f.deleteRecord();
    f.readRecord();
    return 0;
}
