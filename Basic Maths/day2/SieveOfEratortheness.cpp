#include<iostream>
#include <vector>

using namespace std;

//  Question 3 : Write a program to print all prime number upto the given limit
// i/p : n = 10
// o/p : 2 3 5 7

// helper function 
bool isPrime(int n){
  if(n == 1) return false;
  if(n == 2 || n == 3) return true;
  if(n%2 == 0 || n%3 == 0) return false;

  for(int i = 5 ; i*i <= n ; i = i+6){
    if(n % i == 0 || n % (i+12) == 0){
      return false;
    }
  }
  return true;
}

// Naive approach -- O(n * sqrt(n))
void printPrime(int n){
  for(int i = 2; i <= n ; i++){
    if(isPrime(i)) cout<<i<<" ";
  }
}

// effective approach (using Sieve of Eratortheness algo) -- tc = O(nloglogn) and Sc = O(n)
void printPrime2(int n){
  vector<bool> prime(n+1,true);
  
  for(int i = 2 ; i*i <= n; i++){
    if(prime[i]){
      for(int j = 2*i; j<= n; j= j+i){
        prime[j] = false;
      }
    }
  }
   for(int i = 2; i<=n; i++){
      if(prime[i]) cout<< i <<" ";
    }
}



int main(){

  // printPrime(15);
  printPrime2(15);
  return 0;
}