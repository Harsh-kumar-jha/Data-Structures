#include<iostream>
#include<vector>
using namespace std;

// Question 10 : Subset Sum Problem
//i/p : {10,5,2,3,6} ,target =8
// o/p : 3

int countSum(vector<int>arr,int n,int target) //tc = O(2^n) sc = O(2^n)
{
  if(n == 0) {
    return(target == 0) ? 1:0;
  }
  return countSum(arr,n-1,target) + countSum(arr,n-1,target-arr[n-1]);
}
int main(){
  vector<int> arr = {10,5,2,3,6} ;
  cout<<countSum(arr,arr.size()-1,8);
  return 0;
}