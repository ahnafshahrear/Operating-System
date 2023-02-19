#include<bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    int burst, backupBurst, arrival;
    int waiting = 0, completion = 0, turnaround = 0;
};

bool compareProcess(process x, process y)
{
    if (x.burst != y.burst) return x.burst < y.burst;
    else return x.arrival < y.arrival;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    vector<process> x(size);

    // Input format: Process-Id Arrival-Time  Burst-Time
    for (int i = 0; i < size; i++)
    {
        cin >> x[i].id >> x[i].arrival >> x[i].burst;
        x[i].backupBurst = x[i].burst;
    }

    // Main calculation
    int now = 0;
    vector<pair<string, int>> ans;
    while (true)
    {
        sort(x.begin(), x.end(), compareProcess);
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            if (x[i].arrival <= now and x[i].burst)
            {
                x[i].burst--;
                if (!x[i].burst)
                {
                    x[i].completion = now;
                    x[i].turnaround = x[i].completion - x[i].arrival;
                    x[i].waiting = x[i].turnaround - x[i].backupBurst;
                }
                if (ans.size() and ans.back().first == x[i].id)
                {
                    ans.back().second = ++now;
                }
                else ans.push_back({x[i].id, ++now});
                flag = true;
                break;
            }
        }
        if (!flag) break;
    }
    // Gantt Chart output
    string op = "|", border = "-";
    for (auto v: ans)
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
            cout << ans[in].second;
            if (ans[in++].second > 9) i++;
        }
        else if (op[i + 1] == '|' and i + 2 == op.size());
        else cout << " ";
    }
    // Average Waiting time, Turnaround time & Completion time output
    // It can be done easily
    return 0;
}