#include<iostream>
using namespace std;

// Question 2 : Write a program to print all the divisors of a number
// i/p : n = 15
// o/p : 1 3 5 15

// Naive approach -- O(n)
void printDivisor(int n){
  for(int i = 1; i<=n ;i++){
    if(n%i == 0) cout<<i<<endl;
  }
}

// Effective approach -- O(sqrt(n))
void printDivisor2(int n){
  for(int i = 1; i*i <= n; i++){
    if(n%i == 0){
      cout<<i<<" ";
      if(i!=n/i) cout<<n/i<<" ";
    }
  }
}
// since above code doesn't give the divisor in assending order
// here an other approach with same time complexity -- O(sqrt(n));
void printDivisor3(int n){
  int i;
  for(i = 1 ; i*i<=n; i++){
    if(n%i == 0) cout<<i<<" "; 
  }
  for(;i>=1;i--){
    if(n%i == 0) cout<<n/i<<" ";
  }
}

int main(){

  // printDivisor(15);
  // printDivisor2(15);
  printDivisor3(15);
  return 0;
}