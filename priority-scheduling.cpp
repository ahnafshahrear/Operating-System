#include <bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    int burst, priority, waiting, turnaround;
};

bool compareProcess(process x, process y)
{
    return x.priority < y.priority;
}

int main()
{
    int size;
    cin >> size;
    vector<process> x(size);

    for (int i = 0; i < size; i++)
    {
        cin >> x[i].id >> x[i].burst >> x[i].priority;
    }
    sort(x.begin(), x.end(), compareProcess);

    int time_now = 0;
    double avg_waiting = 0, avg_turnaround = 0;
    vector<pair<string, int>> timeline;

    for (int i = 0; i < size; i++)
    {
        time_now += x[i].burst;
        timeline.push_back({x[i].id, time_now});
        x[i].turnaround = time_now;
        x[i].waiting = x[i].turnaround - x[i].burst;
        avg_waiting += x[i].waiting;
        avg_turnaround += x[i].turnaround;
    }

    string gantt_chart = "|", border = "-";
    for (auto z: timeline)
    {
        gantt_chart += "  " + z.first + "  |";
        border += "-------";
    }
    cout << border << "\n" 
         << gantt_chart << "\n"
         << border << "\n"
         << "0";

    int index = 0;
    for (int i = 1; gantt_chart[i]; i++)
    {
        if (gantt_chart[i] == '|')
        {
            cout << timeline[index].second;
            if (timeline[index++].second >= 10) 
            {
                i++;
            }
        }
        else cout << " ";
    }

    cout << "\n\n"
         << "Average waiting time = " << avg_waiting / size << "\n"
         << "Average turnaround time = " << avg_turnaround / size << "\n\n"
         << "Process   |   Waiting Time   |   Turnaround Time\n"
         << "------------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << x[i].id << "              "
             << x[i].waiting << "                   "
             << x[i].turnaround << "\n";
    }
}

/*
5
P1 10 3
P2 1 1
P3 2 4
P4 1 5
P5 5 2

Output:
------------------------------------
|  P2  |  P5  |  P1  |  P3  |  P4  |
------------------------------------
0      1      6      16     18     19 

Average waiting time = 8.2
Average turnaround time = 12

Process   |   Waiting Time   |   Turnaround Time
------------------------------------------------
P2              0                   1
P5              1                   6
P1              6                   16
P3              16                  18
P4              18                  19
*/