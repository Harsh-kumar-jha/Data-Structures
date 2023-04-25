#include<iostream>
using namespace std;

// Question 9 : WAP To generate all the possible subsets of a string
// i/p : s = "AB"
// o/p : " ", "A", "B" , "AB"
void subSets(string &s, string curr = " ",int i = 0){
  if(i == s.length()){
    cout<<curr<<endl;
    return;
  }
  subSets(s,curr,i+1);
  subSets(s,curr+s[i],i+1);
}

int main(){
  string s = "ab";
   subSets(s);
  return 0;
}