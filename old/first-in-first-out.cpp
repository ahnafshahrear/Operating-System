#include <bits/stdc++.h>

using namespace std;

void printFrame(vector<int> frames)
{
    for (int x: frames)
    {
        if (x != -1) cout << x <<  " "; 
        else cout << "- ";
    }
    cout << "\n";
}

int main()
{
    int size = 3;
    vector<int> frames(size, -1);
    queue<int> q;
    int miss = 0;
    vector<int> seq = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    for (int x: seq)
    {
        cout << x << " -> ";
        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (frames[i] == x)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "\n";
            continue;
        }
        miss++;
        int out = -1;
        if (q.size() >= 3) 
        {
            out = q.front();
            q.pop();
        }
        q.push(x);
        for (int i = 0; i < size; i++)
        {
            if (frames[i] == out)
            {
                frames[i] = x;
                printFrame(frames);
                break;
            }
        }
    }
    cout << "Total page fault = " << miss;
}