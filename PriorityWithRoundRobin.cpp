#include<bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    int burst, backup, priority;
    int waiting = 0, completion = 0, turnaround = 0;
};

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    vector<process> x(size);
    set<int> priorities;

    // Input format: Process-Id Burst-Time Priority
    for (int i = 0; i < size; i++)
    {
        cin >> x[i].id >> x[i].burst >> x[i].priority;
        priorities.insert(x[i].priority);
    }
    priorities.insert(1e5);

    // Main calculation
    int time = 0;
    int priorityNow = 1;
    int quantum = 2;
    vector<pair<string, int>> timeline;
    while (true)
    {
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            if (x[i].priority == priorityNow and x[i].burst)
            {
                int T = min(x[i].burst, quantum);
                time += T;
                x[i].burst -= T;
                if (!x[i].burst)
                {
                    x[i].completion = time;
                    x[i].turnaround = x[i].completion;
                    x[i].waiting = x[i].turnaround - x[i].backup;
                }
                if (timeline.size() and timeline.back().first == x[i].id)
                {
                    timeline.back().second = time;
                }
                else timeline.push_back({x[i].id, time});
                flag = true;
            }
        }
        if (!flag)
        {
            for (int v: priorities)
            {
                if (v > priorityNow)
                {
                    priorityNow = v;
                    break;
                }
            }
        }
        if (priorityNow == 1e5) break;
    }
    // Gantt Chart output
    string op = "|", border = "-";
    for (auto v: timeline)
    {
        op += "  " + v.first + "  |";
        border += "-------";
    }
    cout << border << "\n"
         << op << "\n"
         << border << "\n0";
    
    // Time output
    int in = 0;
    for (int i = 1; op[i]; i++)
    {
        if (op[i] == '|') 
        {
            cout << timeline[in].second;
            if (timeline[in++].second > 9) i++;
        }
        else if (op[i + 1] == '|' and i + 2 == op.size());
        else cout << " ";
    }
    // Average Waiting time, Turnaround time & Completion time output
    // It can be done easily
    return 0;
}

/*
    Input from Slide:
    -----------------
    5
    P1 4 3 
    P2 5 2
    P3 8 2
    P4 7 1
    P5 3 3

    Output from Slide:
    ------------------------------------------------------------------------------
    |  P4  |  P2  |  P3  |  P2  |  P3  |  P2  |  P3  |  P1  |  P5  |  P1  |  P5  |
    ------------------------------------------------------------------------------
*/