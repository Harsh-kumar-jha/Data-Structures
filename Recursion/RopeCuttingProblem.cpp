#include<iostream>
using namespace std;

// question 7 : Rope cutting problem 
// i/p : n = 5 , a = 2 , b = 5 , c  = 1
// o/p : 5 // we make 5 piece of length 1 each 

// using recursion
int maxPiece(int n, int a , int b , int c){ // tc = O(3^n)  sc = O(n)
  if(n == 0 )return 0;
  else if (n < 0) return -1;

  int res = max(max(maxPiece(n-a, a, b, c), maxPiece(n-b, a, b, c)), maxPiece(n-c, a, b, c));

  if(res == -1) return -1;

  return res+1;
}


int main(){

  cout<<maxPiece(5,2,5,1);
  return 0;
}