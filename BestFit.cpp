#include <bits/stdc++.h>

using namespace std;

// Dynamic storage allocation problem - Best Fit
// Best Fit algorithm: Allocate the smallest hole that is big enough

int main()
{
    int hole; // Number of free memory holes
    cin >> hole;
    vector<int> holes(hole);
    for (int i = 0; i < hole; i++)
    {
        cin >> holes[i];
    }
    
    int size; // Process size
    cin >> size;

    sort(holes.begin(), holes.end());
    for (int x: holes)
    {
        if (x >= size)
        {
            cout << "The process is allocated into "
                 << x << " mb memory hole.";
            return 0;
        }
    }
    cout << "No suitable hole available!";
}