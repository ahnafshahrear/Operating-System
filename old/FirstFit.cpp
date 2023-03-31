#include <bits/stdc++.h>

using namespace std;

// Dynamic storage allocation problem - First Fit
// First Fit algorithm: Allocate the first hole that is big enough

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

/*
Input:
7
12 3 5 32 43 9 7
27

Output: 
The process is allocated into 32 mb memory hole.
*/