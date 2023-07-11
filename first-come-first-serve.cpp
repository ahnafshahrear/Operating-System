#include <bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    int burst, waiting, turnaround;
};

int main()
{
    int size;
    cin >> size;
    vector<process> x(size);

    for (int i = 0; i < size; i++)
    {
        cin >> x[i].id >> x[i].burst;
    }
    
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
    cout << "Gantt Chart:\n" << border << "\n" 
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

/*//... Sample Input-Output:
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
5
P1 13
P2 3
P3 17
P4 4
P5 2
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
Gantt Chart:
------------------------------------
|  P1  |  P2  |  P3  |  P4  |  P5  |
------------------------------------
0      13     16     33     37     39 

Average waiting time = 19.8
Average turnaround time = 27.6

Process   |   Waiting Time   |   Turnaround Time
------------------------------------------------
P1              0                    13
P2              13                   16
P3              16                   33
P4              33                   37
P5              37                   39

*///...