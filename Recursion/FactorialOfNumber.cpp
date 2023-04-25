#include <iostream> 
using namespace std;

// Question 3 : WAP to find factorial of a number
// i/p : 4
// o/p : 24 (4*3*2*1);

// using Recursion 
int factorial(int n){  // time and space complexity is O(n)
  if(n == 0 || n == 1) return 1; //base case 
  
  return n*factorial(n-1); //faction calling itself
}

// converting Recursive function into itrative function 
int factorial2(int n){ // tc - O(n) and sc - O(1)
  int res = 1;
  for(int i = 1; i<=n; i++){
    res = res * i;
  }
  return res;
}

int main(){
  cout << factorial(4) << endl;
  cout << factorial2(4) << endl;
  return 0;
}