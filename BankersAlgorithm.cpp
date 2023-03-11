#include <bits/stdc++.h>

using namespace std;

int R, P;
vector<int> available(100);
vector<int> maxNeed[100], allocation[100], need[100];

bool safetyAlgorithm()
{
    vector<int> work = available;
    vector<int> finish(P, 1);
    string serial = "";
    while (true)
    {
        // for (int i = 0; i < 3; i++)
        // {
        //     cout << work[i] << " ";
        // }
        // cout << "\n";
        bool found = false;
        for (int i = 0; i < P; i++)
        {
            if (!finish[i]) continue;   
            bool ok = true;
            for (int k = 0; k < R; k++)
            {
                if (need[i][k] > work[k])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                for (int k = 0; k < R; k++)
                {
                    work[k] += allocation[i][k];
                }
                found = true;
                finish[i] = 0;
                found = true;
                serial.push_back(i + '0');
                serial.push_back(' ');
                break;
            }
        }
        if (!found) break;
    }
    int ok = accumulate(finish.begin(), finish.end(), 0);
    if (!ok) cout << serial << "\n";
    else cout << "Unsafe State\n";
    return ok == 0;
}

int main()
{
    cin >> R;
    for (int i = 0; i < R; i++)
    {
        cin >> available[i];
    }
    cin >> P;
    for (int i = 0; i < P; i++)
    {
        for (int k = 0; k < R; k++)
        {
            int alc, mx;
            cin >> alc >> mx;
            allocation[i].push_back(alc);
            maxNeed[i].push_back(mx);
            need[i].push_back(maxNeed[i][k] - allocation[i][k]);
        }
    }
    // for (int i = 0; i < P; i++)
    // {
    //     for (int k = 0; k < R; k++)
    //     {
    //         cout << need[i][k] << " ";
    //     }
    //     cout << "\n";
    // }
    safetyAlgorithm();
    int no;
    vector<int> req(R);
    cin >> no;
    for (int i = 0; i < R; i++)
    {
        cin >> req[i];
    }
    for (int i = 0; i < R; i++)
    {
        available[i] -= req[i];
        allocation[no][i] += req[i];
        need[no][i] -= req[i];
    }
    if (safetyAlgorithm())
    {
        cout << "Possible";
    }
    else
    {
        for (int i = 0; i < R; i++)
        {
            available[i] += req[i];
            allocation[no][i] -= req[i];
            need[no][i] += req[i];
        }
        cout << "Not Possible";
    } 
}