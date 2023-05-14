// C++ implementation to find the longest subarray
// with sum divisible by k
 
#include <bits/stdc++.h>
using namespace std;
 
// function to find the longest subarray
// with sum divisible by k
 
int longestSubarrWthSumDivByK(int arr[], int n, int k)
{
    // unordered map 'um' implemented as
    // hash table
    unordered_map<int, int> um;
 
    // 'mod_arr[i]' stores (sum[0..i] % k)
    int mod_arr[n], max_len = 0;
    int curr_sum = 0;
 
    // traverse arr[] and build up the
    // array 'mod_arr[]'
    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];
 
        // as the sum can be negative, taking modulo twice
        mod_arr[i] = ((curr_sum % k) + k) % k;
 
        // if true then sum(0..i) is divisible by k
        if (mod_arr[i] == 0)
            // update 'max'
            max_len = i + 1;
 
        // if value 'mod_arr[i]' not present in 'um'
        // then store it in 'um' with index of its
        // first occurrence
        else if (um.find(mod_arr[i]) == um.end())
            um[mod_arr[i]] = i;
 
        else
            // if true, then update 'max'
            if (max_len < (i - um[mod_arr[i]]))
            max_len = i - um[mod_arr[i]];
    }
 
    // return the required length of longest subarray
    // with sum divisible by 'k'
    return max_len;
}
 
// Driver code
int main()
{
    int arr[] = { 2, 7, 6, 1, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
 
    cout << "Length = "
         << longestSubarrWthSumDivByK(arr, n, k);
 
    return 0;
}