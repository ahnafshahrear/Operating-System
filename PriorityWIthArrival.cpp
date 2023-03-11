#include<bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    int burst, backup, arrival, priority;
    int waiting = 0, completion = 0, turnaround = 0;
};

bool compareProcess(process x, process y)
{
    if (x.priority != y.priority) return x.priority < y.priority;
    else return x.arrival < y.arrival;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    vector<process> x(size);

    for (int i = 0; i < size; i++)
    {
        cin >> x[i].id >> x[i].arrival >> x[i].priority >> x[i].burst;
        x[i].backup = x[i].burst;
    }

    int time = 0;
    vector<pair<string, int>> timeline;
    double avgW = 0, avgT = 0;
    while (true)
    {
        sort(x.begin(), x.end(), compareProcess);
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            if (x[i].arrival <= time and x[i].burst)
            {
                x[i].burst--;
                time++;
                if (!x[i].burst)
                {
                    x[i].completion = time;
                    x[i].turnaround = x[i].completion - x[i].arrival;
                    x[i].waiting = x[i].turnaround - x[i].backup;
                    avgW += (double)x[i].waiting;
                    avgT += (double)x[i].turnaround;
                }
                if (timeline.size() and timeline.back().first == x[i].id)
                {
                    timeline.back().second = time;
                }
                else timeline.push_back({x[i].id, time});
                flag = true;
                break;
            }
        }
        if (!flag) break;
    }

    string op = "|", border = "-";
    for (auto v: timeline)
    {
        op += "  " + v.first + "  |";
        border += "-------";
    }
    cout << border << "\n"
         << op << "\n"
         << border << "\n0";
    
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

    cout << "\n\nAverage Waiting Time = " << avgW / size << "\n"
         << "Average Turnaround Time = " << avgT / size << "\n";
     
    cout << "\nProcess | Waiting Time | Completion Time | Turnaround Time\n";
    cout << "----------------------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << x[i].id << "        " << x[i].waiting << "             ";
        if (x[i].waiting < 10) cout << " ";
        cout << x[i].completion << "                 ";
        if (x[i].completion < 10) cout << " "; 
        cout << x[i].turnaround << "\n";
    }
    return 0;
}