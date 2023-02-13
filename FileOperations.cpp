#include<bits/stdc++.h>

using namespace std;

// File Name Format: "F:\\C++ Codes\\Operating System Lab\\x.txt"

int main()
{
    string operation;
    cin >> operation;
    cin.ignore();
    if (operation == "Create")
    {
        string name;
        getline(cin, name);
        ofstream newFile(name.c_str());
        time_t timeNow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        newFile << "File has created\nTime: " << ctime(&timeNow) << endl;
        newFile.close();
    }
    else if (operation == "Rename")
    {
        string oldname, newname;
        getline(cin, oldname);
        getline(cin, newname);
        int mark = rename(oldname.c_str(), newname.c_str());
        if (mark) 
        {
            cout << "Error renaming file!";
        }
        else cout << "File successfully renamed";
    }
    else if (operation == "Delete")
    {
        string fileName;
        getline(cin, fileName);
        int mark = remove(fileName.c_str());
        if (mark) 
        {
            cout << "Couldn't delete file!";
        }
        else cout << "File successfully deleted";
    }
    else cout << "Invalid operation name!";
}