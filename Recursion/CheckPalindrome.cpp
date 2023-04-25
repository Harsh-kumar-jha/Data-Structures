 #include<iostream>
using namespace std;

// Question 6 : WAP to check if the given string is palindrome or not
// i/p : abba
// o/p : yes

// using recursion
bool isPalindrome(string &s,int start, int end){ //tc and sc = O(n)
  if(start >= end) return true; //base case 

  return (s[start] == s[end]) && isPalindrome(s, start+1, end-1); //condition if true then it is calling itself
}

// converting recursive code into itrative code 
bool isPalindrome2(string &s){
  int start = 0;
  int end = s.size()-1;

  while(start <= end){
    if(s[start] != s[end]) return false;

    start++;
    end--;
  }
  return true;
}

int main(){
  string s = "abba";
  if(isPalindrome(s,0,3)){
    cout<<"Yes";
  }
  else {
    cout<<"No";
  }
  cout<<endl;
  if(isPalindrome2(s)){
    cout<<"Yes";
  }
  else {
    cout<<"No";
  }
  return 0;
}