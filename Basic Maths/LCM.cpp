#include<iostream>
using namespace std;

// Question 4 : Find LCM of Two numbers
// i/p : a = 4 and b = 5
// o/p : 12

// First we will see Navice Approach -- O(a*b)
int lcm(int a, int b){
  int res = max(a,b);
  while(1){
    if(res%a == 0 && res%b == 0) return res;
    res++;
  }
  return res;
}
// Now Effective approach -- O(log(min(a,b)))
int gcd (int a, int b){
  if(b == 0) return a;
  return gcd(b,a%b);
}
int lcm2(int a, int b){
  return (a*b)/gcd(a,b);
  // a * b = gcd(a,b) * lcm(a,b)
}

int main(){
  cout<<lcm(4,6);
  cout<<endl<<lcm2(4,6);
  return 0;
}