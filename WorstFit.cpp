#include <bits/stdc++.h>

using namespace std;

// Dynamic storage allocation problem - Worst Fit
// Worst Fit algorithm: Allocate the largest hole that is big enough

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
    if (holes.back() >= size)
    {
        cout << "The process is allocated into "
             << holes.back() 
             << " mb memory hole.";
    }
    else cout << "No suitable hole available!";
}