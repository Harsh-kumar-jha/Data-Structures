#include<iostream>
using namespace std;

// Question 5 : Check if a number is prime or not
// i/p : 5
// o/p : yes

//  Naive approach -- O(n)
bool isPrime(int n ){
  if(n == 1) return false;
  for(int i = 2; i<n ;i++){
    if(n%i == 0 ) return false;
  }
  return true;
}

// Efficient approach -- O(sqrt(n))
bool isPrime2(int n){
  if(n == 1) return false;

  for(int i = 2; i*i <= n ; i++){
    if(n%i == 0 ) return false;
  }
  return true;
}

// the above soln work fine for small number but fail in very large number case 
// so we have further more optimize the soln
bool isPrime3(int n){
  if (n == 1 || n == 2 || n == 3) return false;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for(int i = 5 ; i*i <= n ; i = i+6)
    {
      if(n%i == 0 || n % (i+12) == 0){
        return false;
      }
    }
  return true;
 }

int main(){

  if(isPrime(5)){
    cout<<"yes";
  }else cout<<"No";
  
  if(isPrime2(5)){
    cout<<"yes";
  }else cout<<"No";
  
  if(isPrime3(5)){
    cout<<"yes";
  }else cout<<"No";

  return 0;
}