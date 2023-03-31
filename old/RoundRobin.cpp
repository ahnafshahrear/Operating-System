#include<bits/stdc++.h>

using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> burst(size), remaining(size);
    for (int i = 0; i < size; i++)
    {
        cin >> burst[i];
    }
    remaining = burst;
    vector<int> waiting(size), turnaround(size);
    int quantum = 4;
    int timeNow = 0;
    string line1 = "  ", line2 = "0    ";
    for (int i = 0; true; i++)
    {
        i %= size;
        if (!remaining[i])
        {
            continue;
        }
        int time = quantum;
        if (remaining[i] <= quantum)
        {
            time = remaining[i];
            turnaround[i] = timeNow + time;
        }
        remaining[i] -= time;
        timeNow += time;
        line1.push_back('P');
        line1.push_back(i + 1 + '0');
        line1 += "    ";
        line2.push_back(timeNow / 10 + '0');
        line2.push_back(timeNow % 10 + '0');
        line2 += "    ";
        int ok = accumulate(remaining.begin(), remaining.end(), 0);
        if (!ok) break;
    }
    for (int i = 0; i < size; i++)
    {
        waiting[i] = turnaround[i] - burst[i];
    }
    double avgWaiting = accumulate(waiting.begin(), waiting.end(), 0) / (double)size;
    double avgTurnaround = accumulate(turnaround.begin(), turnaround.end(), 0) / (double)size;
    
    cout << "Gantt Chart: \n\n"
         << line1 << "\n" << line2 << "\n\n"
         << "Average waiting time = " << avgWaiting << " ms\n"
         << "Average turnaround time = " << avgTurnaround << " ms\n";
}