#include<iostream>
using namespace std;

// Question 4 : Write a program to print power of a given number 
// i/p : n = 2 , m = 3
// o/p : 8 (2*2*2 or 2^3)

// Naive approach -- O(n)
int computePow(int n, int m){
  int res = 1;
  for(int i = 0; i < m ; i++){
    res = res*n;
  }
  return res;
}

// effective approach -- O(log m) coz loop is depend on m and space complexity - O(log m)

int computePower(int n, int m){
  if(m == 0) return 1;
  int temp = computePower(n, m/2);
  temp = temp * temp;
  if(m % 2 == 0)
    return temp;
  return temp*n;
}

// iterative approach  -- O(log n)
int computePower2(int n, int m){
  int res = 1;
  while (m > 0){
    if(m % 2 != 0){
      res = res * n;
    }
    n = n*n;
    m = m/2;
  }
  return res;
}


int main(){

  // cout<<computePow(2, 3);
  // cout<<computePower(2, 3);
  cout<<computePower2(2, 3);
  return 0;
}