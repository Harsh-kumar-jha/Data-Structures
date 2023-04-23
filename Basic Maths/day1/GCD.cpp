#include<iostream>
using namespace std;

// Question 3 : find Greates Comman Divisor of Two Number 
// i/p: a = 4 and b =6
// o/p : 2

// first we will see Naive approach -- O(mai(a,b))
int gcp(int a, int b){
  int res = min(a,b);
  while(res>0){
    if(a%res == 0 && b%res == 0){
      break;
    }
    res--;
  }
  return res;
}

// Now we will see Effective approach (Euclidean Algorithm) -- tc - O(max(a,b))
int gcd(int a, int b){
  while(a!=b){
    if(a>b) a = a-b;
    else b = b-a;
  }
  return a;   // or we can return b coz a and b are equal
}

// recursive approach -- tc and Sc -- O(log(max(a,b)))
int gcd2(int a, int b){
  if(b == 0 ) return a;
  return gcd2(b,a%b);
}


int main(){

  cout<<gcp(4,6);
  cout<<endl<<gcd(13,11);
  cout<<endl<<gcd2(13,11);
  return 0;
}

