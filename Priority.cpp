#include <bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    int burst, priority, arrival;
    int waiting, turnaround;
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
        cin >> x[i].id >> x[i].priority >> x[i].burst;
    }
    sort(x.begin(), x.end(), compareProcess);

    int priorityNow = 1;
    int time = 0;
    vector<pair<string, int>> timeline;

    double avgW = 0, avgT = 0;
    for (int i = 0; i < size; i++)
    {
        time += x[i].burst;
        timeline.push_back({x[i].id, time});
        x[i].turnaround = time;
        x[i].waiting = time - x[i].burst;
        avgW += (double)x[i].waiting;
        avgT += (double)x[i].turnaround;
    }

    string op = "|", border = "-";
    for (auto z: timeline)
    {
        op += "  " + z.first + "  |";
        border += "-------";
    }
    cout << border << "\n" << op << "\n" << border << "\n0";
    int in = 0;
    for (int i = 1; op[i]; i++)
    {
        if (op[i] == '|')
        {
            cout << timeline[in].second;
            if (timeline[in++].second > 9) i++;
        }
        else cout << " ";
    }
    cout << "\n\nAverage Waiting Time = " << avgW / size << "\n"
         << "Average Turnaround Time = " << avgT / size << "\n";

    cout << "\nProcess   |   Waiting Time   |   Turnaround Time\n"
         << "------------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << x[i].id << "              "
             << x[i].waiting << "                   "
             << x[i].turnaround << "\n";
    }
}