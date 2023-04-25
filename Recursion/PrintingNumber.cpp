#include <iostream>

using namespace std;

// Question 1 : Write a program which print n to 1 using Recursion
// i/p : n = 4
// o/p : 4 3 2 1

void Print(int n){  //time and space complexity = O(n)
  if(n == 0) return; // base case 
  cout<<n<<" ";  // some programing statement
  Print(n-1); // calling itself 
}

// Question 2 : Write a program which Print 1 to n using Recursion 
// i/p : n = 5
// o/p : 1 2 3 4 5

void Print2(int n){  //time and space complexity = O(n)
  if(n == 0) return; //base case
  Print2(n-1); // function call itself again 
  cout<<n<<" "; //some programming statement
}

int main(void) {

  Print(4);
  cout<<endl;
  Print2(5);
  
	return 0;
};
