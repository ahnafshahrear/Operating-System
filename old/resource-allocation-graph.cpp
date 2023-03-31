#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> graph;
map<string, bool> vis;
string src;
bool deadlock = false;

void dfs(string node)
{
    vis[node] = true;
    for (string n: graph[node])
    {
        if (vis[n])
        {
            if (n == src)
            {
                deadlock = true;
            }
        }
        else dfs(n);
    }
}

int main()
{
    set<string> nodes;
    string n1, n2;
    while (cin >> n1 >> n2)
    {
        graph[n1].insert(n2);
        nodes.insert(n1);
        nodes.insert(n2);
    }
    for (string node: nodes)
    {
        for (string node: nodes)
        {
            vis[node] = false;
        }
        src = node;
        dfs(node);
        if (deadlock)
        {
            cout << "Deadlock";
            return 0;
        }
    }
    cout << "No Deadlock";
}

/*
Input:
T1 R1
R1 T2
T2 R3
R3 T5
T2 R4
R4 T3
T3 R5
T2 R5
R5 T4
T4 R2
R2 T1

Output:
Deadlock
*/

/*Input:
T1 R1
T2 R3
R3 T5
T2 R4
R4 T3
T3 R5
T2 R5
R5 T4
T4 R2
R2 T1

Output:
No Deadlock
*/