#include<iostream>
using namespace std;

// Question 7 : WAP to find sum of digit 
//i/p : n = 253
//o/p : 10 (2+5+3)

// using recursion 
int getSum(int n){
  if(n == 0) return 0; //base case 

  return getSum(n/10)+n%10; //calling itself
}

// converting the recursive code into itrative 
int getSum2(int n){
  int sum = 0;

  while(n > 0){
    sum += n % 10;
    n = n/10;
  }
  return sum;
}

int main(){

  cout<<getSum(253)<<endl;
  cout<<getSum2(253)<<endl;
  return 0;
}