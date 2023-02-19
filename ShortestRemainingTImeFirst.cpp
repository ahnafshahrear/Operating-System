#include<bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    int burst, burstCopy, arrival;
    int waiting = 0, completion = 0, turnaround = 0;
};

bool compareProcess(process x, process y)
{
    if (x.burst != y.burst) return x.burst < y.burst;
    else return x.arrival < y.arrival;
}

int main()
{
    int size;
    cin >> size;
    vector<process> x(size);
    // Input format: Process-Id Burst-Time Arrival-Time
    for (int i = 0; i < size; i++)
    {
        cin >> x[i].id >> x[i].arrival >> x[i].burst;
        x[i].burstCopy = x[i].burst;
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
    // Output
    string op = "|";
    for (auto v: ans)
    {
        op += "  " + v.first + "  |";
    }
    for (char ch: op) cout << "-";
    cout << "\n" << op << "\n";
    for (char ch: op) cout << "-";
    cout << "\n0";
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
    return 0;
}