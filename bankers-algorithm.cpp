#include <bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    vector<int> max_need, allocation, need;
};

bool safetyAlgorithm(vector<int> work, vector<process> x)
{
    string sequence = "";
    int no_of_resource = work.size();
    int no_of_process = x.size();
    vector<bool> finish(no_of_process, false);

    while (true)
    {
        bool found = false;
        for (int i = 0; i < no_of_process; i++)
        {
            if (finish[i])
            {
                continue;
            }
            bool ok = true;
            for (int j = 0; j < no_of_resource; j++)
            {
                if (x[i].need[j] > work[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                found = true;
                finish[i] = true;
                for (int j = 0; j < no_of_resource; j++)
                {
                    work[j] += x[i].allocation[j];
                }
                sequence += x[i].id + " ";
            }
        }
        if (!found) break;
    }
    for (int i = 0; i < no_of_process; i++)
    {
        if (!finish[i])
        {
            return false;
        }
    }
    cout << sequence << "\n";
    return true;
}

int main()
{
    int no_of_process, no_of_resource;
    
    cin >> no_of_resource;
    vector<int> available(no_of_resource);
    for (int &a: available)
    {
        cin >> a;
    }

    cin >> no_of_process;
    vector<process> x(no_of_process);
    for (int i = 0; i < no_of_process; i++)
    {
        x[i].max_need.resize(no_of_resource);
        x[i].allocation = x[i].need = x[i].max_need;
        cin >> x[i].id;
        for (int &a: x[i].allocation)
        {
            cin >> a;
        }
        for (int j = 0; j < no_of_resource; j++)
        {
            cin >> x[i].max_need[j];
            x[i].need[j] = x[i].max_need[j] - x[i].allocation[j];
        }
    }

    if (safetyAlgorithm(available, x))
    {
        cout << "The system is in a safe state";
    }
    else cout << "The system is not in a safe state!";
}

/*
Input:
3
3 3 2
5
T0   0 1 0   7 5 3
T1   2 0 0   3 2 2
T2   3 0 2   9 0 2
T3   2 1 1   2 2 2
T4   0 0 2   4 3 3

Output:
T1 T3 T4 T0 T2 
The system is in a safe state
*/