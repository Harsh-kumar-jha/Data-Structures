#include <iostream>
using namespace std;

//  Question 1 
// Finding Trailing zeros
// I/p : 5
// O/p : 1 (1*2*3*4*5 = 120)

// first we will see Naive approach :- time complexity - O(n)
int countTailingZero(int n ){
  int fact = 1;
  for(int i = 2; i <= n; i++){
    fact = fact * i;
  }
  int res = 0;
  while(fact % 10 == 0){
    res++;
    fact = fact/10;
  }
  return res;
}
// Now Effective Approach -- time complexity O(log n)
int countTailingZero2(int n ){
  int res = 0;
  for(int i = 5; n/i>=1;i = i*5 ){
    res = res+n/i;
  }
  return res;
}



int main() {
  cout<<countTailingZero(20); // problem with this approach is it wont work with larger number 
  cout<<endl << countTailingZero2(20);

}