//bit manipulation divibility problem

#include <bits/stdc++.h>
using namespace std;
 
// index >> 5 corresponds to dividing index by 32
// index & 31 corresponds to modulo operation of
// index by 32
 
// Function to check value of bit position whether
// it is zero or one
bool checkbit(int array[], int index)
{
    return array[index >> 5] & (1 << (index & 31));
}
 
// Sets value of bit for corresponding index
void setbit(int array[], int index)
{
    array[index >> 5] |= (1 << (index & 31));
}
 
/* Driver program to test above functions*/
int main()
{
    int a = 2, b = 10;
    int size = abs(b - a)+1;
 
    // Size that will be used is actual_size/32
    // ceil is used to initialize the array with
    // positive number
    size = ceil((double)size/32);
     
    // Array is dynamically initialized as
    // we are calculating size at run time
    int* array = new int[size];
 
    // Iterate through every index from a to b and
    // call setbit() if it is a multiple of 2 or 5
    for (int i = a; i <= b; i++)
        if (i % 2 == 0 || i % 5 == 0)
            setbit(array, i - a);
 
    cout << "MULTIPLES of 2 and 5:\n";
    for (int i = a; i <= b; i++)
        if (checkbit(array, i - a))
            cout << i << " ";
 
    return 0;
}