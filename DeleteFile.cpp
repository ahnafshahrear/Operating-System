#include<bits/stdc++.h>

using namespace std;

int main()
{
    char name[] = "F:\\C++ Codes\\Operating System Lab\\x.txt";
    // Parameter of remove() must be char[]
    int mark = remove(name);
    if (!mark) // If zero, file deleted successfully
    {
        cout << "File removed successfully";
    }
    else cout << "Could no delete file";
    return 0;
}