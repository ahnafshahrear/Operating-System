#include <bits/stdc++.h>

using namespace std;

void printState(vector<int> frames)
{
    for (int x: frames)
    {
        if (x != -1) cout << " " << x; 
        else cout << " -";
    }
    cout << "\n";
}

int main()
{
    int size; //... Total number of frames
    cin >> size;
    vector<int> frames(size, -1);
    map<int, int> reference; //... Page's reference bit
    int miss = 0, page;

    int index = 0;
    while (cin >> page)
    {
        bool found = false;
        for (int x: frames)
        {
            if (x == page)
            {
                reference[page] = 1;
                found = true;
                break;
            }
        } 
        if (found)
        {
            cout << page << " ->\n";
            continue;
        }
        miss++;
        while (true)
        {
            if (frames[index] == -1)
            {
                frames[index] = page;
            }
            else if (reference[frames[index]] == 0)
            {
                frames[index] = page;
                index = (index + 1) % size;
                break;
            }
            else reference[frames[index]] = 0;
            index = (index + 1) % size;
        }
        cout << page << " ->";
        printState(frames);
    }
    cout << "Total page fault = " << miss;
}