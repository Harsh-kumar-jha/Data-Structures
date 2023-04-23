#include<iostream>
using namespace std;

// Question 2 : Find Factorial of a given number 
// I/p : 4
// o/p : 24

// First we will see recursive approach time and space complexity is O(n)
int fact(int n){
  if(n == 0) return 1;
  return n*fact(n-1);
}

// now itrative approach  --time complexity is O(n) and space complexity is O(1)
int fact2(int n){
  int res = 1;
  for(int i = 2; i<=n; i++){
    res = res*i;
  }
  return res;
}


int main(){
  cout<<fact(4);
  cout<<fact2(4);
  
  return 0;
}