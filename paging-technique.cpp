#include <bits/stdc++.h>

using namespace std;

//... Implemented for one process

int main()
{
    int memory_size = 512, page_size = 16;
    int no_of_frames = memory_size / page_size;
    int process_size;
    cin >> process_size;
    int frames_needed = ceil(process_size / (double)page_size);
    vector<int> page_table(no_of_frames);
    cout << "\n" << frames_needed << " pages will be allocated to this page."
         << "Enter the frame numbers(zero index based): \n";
    for (int i = 0; i < frames_needed; i++)
    {
        cin >> page_table[i];
        if (page_table[i] >= no_of_frames)
        {
            cout << "Frame limit exceeded!";
            return 0;
        }
    }
    cout << "Give a logical address to see physical address:\n"
         << "Enter page number & offset: ";
    int page_no, offset;
    cin >> page_no >> offset;     
    int physical_address = page_size * (page_table[page_no] - 1) + offset;
    cout << "Physical address = " << physical_address;
}

/*//... Sample Input-Output:
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
45
3 pages will be allocated to this page.Enter the frame numbers(zero index based):
1 0 2
Give a logical address to see physical address:
Enter page number & offset: 0 4
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
Physical address = 19

*///...