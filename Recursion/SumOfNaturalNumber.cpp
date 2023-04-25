#include<iostream>
using namespace std;

// Quesiont 5 : WAP to Print sum of n natural numbers
// i/p : n = 5 
// o/p : 15 (1+2+3+4+5);

// using recursion 
int sumOfN(int n){  // tc and sc = O(n)
  if(n == 1) return 1; //base case 

  return n+sumOfN(n-1); // function calling it self 
}

//converting recursive code into itrative one 
int sumOfN2(int n){
  int sum = 0;
  for(int i = 1; i<=n;i++){
    sum +=i;
  }
  return sum;
}

int main (){
  cout<<sumOfN(5)<<endl;
  cout<<sumOfN2(5);
  return 0;
}