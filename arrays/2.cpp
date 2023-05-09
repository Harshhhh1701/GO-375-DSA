//{ Driver Code Starts
//Initial Template for C++

//You are given a string s. You need to reverse the string.
#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
  //Your code here
  int start=0;
  int j=str.size();
  int end=j-1;
  while(start<=end){
      swap(str[start],str[end]);
      start++;
      end--;
  }
  return str;
}

