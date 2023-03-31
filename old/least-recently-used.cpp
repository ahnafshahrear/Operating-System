#include <bits/stdc++.h>

using namespace std;

void printFrame(vector<int> frames)
{
    for (int x: frames)
    {
        if (x != -1) cout << x <<  " "; 
    }
}

int main()
{
    int size = 3;
    vector<int> frames(size, -1);
    map<int, int> lastUsed;
    int miss = 0;
    vector<int> seq = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    for (int i = 0; i < seq.size(); i++)
    {
        int x = seq[i];
        lastUsed[x] = i;
        cout << x << " -> ";
        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (frames[i] == x)
            {
                found = true;
                break;
            }
            else if (frames[i] == -1)
            {
                found = true;
                frames[i] = x;
                printFrame(frames);
                miss++;
                break;
            }
        }
        if (found)
        {
            cout << "\n";
            continue;
        }
        miss++;
        int out = frames[0];
        for (int o: frames)
        {
            if (lastUsed[o] < lastUsed[out])
            {
                out = o;
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (frames[i] == out)
            {
                frames[i] = x;
                printFrame(frames);
                cout << "\n";
                break;
            }
        }
    }
    cout << "Total page fault = " << miss;
}