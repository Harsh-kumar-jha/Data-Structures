#include <iostream>

using namespace std;
// Question 1: Write a function which gives prime factor of a number 
// i/p : 12
// o/p : 2,2,3

// helper function 
bool isPrime(int n){
  if(n == 1 ) return false;
  if(n == 2 || n == 3) return true;
  if(n%2 == 0 || n%3 == 0) return false;

  for(int i = 5 ; i<=n ; i = i+6){
    if(n%i == 0 || n%(i+12) == 0) return false;
  }
  return true;
  
}
// Naive approach -- O(n^2log(n))
void PrimeFactor(int n){
  for(int i = 2; i<= n; i++){
    if(isPrime(i)){
      int x = i;
      while(n%x == 0){
        cout<<x << endl;
        x = x*i;
      }
    }
  }
}

// effective approach -- O(sqrt(n) * lon(n))
void printPrimeFactor(int n){
  if(n <= 1) return;
  for(int i = 2; i*i < n ;i++){
    if(isPrime(i)){
      while(n%i == 0){
        cout<<i<<endl;
        n = n/i;
      }
    }
  }
  if(n>1) cout<<n<<endl;
}

// more effective approach  -- O(sqrt(n))
void printPrimeFactor2(int n){
  if(n <= 1 ) return ;
  while(n % 2 == 0){
    cout<<2<<endl;
    n = n/2;
  }
  while(n % 3 == 0){
    cout<<3<<endl;
    n = n/3;
  }
  for(int i = 5; i*i<n ; i = i+6){
    while(n%i == 0){
      cout<<i<<endl;
      n = n/i;
    }
    while(n%(i+2) == 0){
      cout<<i+2<<endl;
      n = n / (i+2);
    }
  }
  if(n>3) cout<<n;
}
int main() {

  // PrimeFactor(12);
  // printPrimeFactor(12);
  printPrimeFactor2(12);
  return 0; 

};
