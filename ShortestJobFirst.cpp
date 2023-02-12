#include<bits/stdc++.h>

using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> waiting(size), turnaround(size);
    vector<pair<int, int>> burst(size);
    for (int i = 0; i < size; i++)
    {
        cin >> burst[i].first;
        burst[i].second = i + 1;
    }
    sort(burst.begin(), burst.end());
    waiting[0] = 0;
    for (int i = 0; i < size; i++)
    {
        if (i)
        {
            waiting[i] = waiting[i - 1] + burst[i - 1].first;
        }
        turnaround[i] = burst[i].first + waiting[i];
    }
    double avgWaiting = accumulate(waiting.begin(), waiting.end(), 0) / (double)size;
    double avgTurnaround = accumulate(turnaround.begin(), turnaround.end(), 0) / (double)size;
    
    // Output Gantt Chart
    string line1 = "  ";
    for (int i = 0; i < size; i++)
    {
        line1.push_back('P');
        line1.push_back(burst[i].second + '0');
        line1 += "    ";
    }
    string line2 = "0    ";
    for (int i = 0; i < size; i++)
    {
        line2.push_back(turnaround[i] / 10 + '0');
        line2.push_back(turnaround[i] % 10 + '0');
        line2 += "    ";
    }
    cout << "Gantt Chart: \n\n"
         << line1 << "\n" << line2 << "\n\n"
         << "Average waiting time = " << avgWaiting << " ms\n"
         << "Average turnaround time = " << avgTurnaround << " ms\n";

    return 0;
}