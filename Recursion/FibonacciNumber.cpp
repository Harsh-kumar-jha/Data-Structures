#include<iostream>
using namespace std;

// Question 4 : WAP to find the nth fibonacci number 
// example of fibonacci number : 0,1,1,2,3,5 .. basically it is the sum of last two fibo number n-1 and n-2 
//i/p : n = 3
// o/p : 2

// using recursion 
int fibonacciNumber(int n){ // tc : O(2^n) and sc : O(n)
  if(n == 0 || n == 1) return n; //base case 
  return fibonacciNumber(n-1)+fibonacciNumber(n-2); //function calling it self 
}

// converting recursive code into itrative 
int fibonacciNumber2(int n){
  if(n == 0 || n == 1) return n;

  int prev = 0,curr = 1, next = 0;
  for(int i = 2; i<=n ; i++){
    next = prev+curr;
    prev = curr;
    curr = next;
  }
  return curr;
}

int main(){
   cout << fibonacciNumber(3)<<endl;
   cout << fibonacciNumber2(3);
  return 0;
}