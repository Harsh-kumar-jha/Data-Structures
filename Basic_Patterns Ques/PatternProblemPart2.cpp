#include <iostream>
using namespace std;

// Q.1 printing full Pyramid
/*
       *
      * *
     * * *
    * * * * 
*/
void fullPyramid(){
  int n;
  cin  >> n;

  for(int i = 0; i<n ; i++){
    for(int j = 0; j < n-i-1 ; j++){
      cout<<" ";
    }
    for(int j = 0; j<i+1; j++){
      cout<<"* ";
    }
    cout<<endl;
  }
}

// Q.2 Printing inverted full Pyramid
/*
   * * * * *
    * * * *
     * * *
      * *
       *
*/
void invertedFullPyramid(){
  int n;
  cin >> n;
  for(int i = 0 ; i<n ; i++){
    for(int j = 0 ; j<i ; j++){
      cout<<" ";
    }
    for(int j = 0 ; j<=n-i-1 ; j++){
      cout<<"* ";
    }
    cout<<endl;
  }
}

// Q.3 Printing Solid Diamond
/*
        *
       * *
      * * *
     * * * *
    * * * * *
    * * * * *
     * * * *
      * * *
       * *
        *

*/
void solidDimond(){
  int n; 
  cin >> n;

  // full Pyramid
  for(int i = 0; i<n ; i++){
    for(int j = 0 ; j<n-i-1 ; j++){
      cout<<" ";
    }
    for(int j = 0 ; j<i+1 ; j++){
      cout<<"* ";
    }
    cout<<endl;
  }
  // inverted full Pyramid
  for(int i = 0 ; i<n ;i++){
    for(int j = 0 ; j<i ; j++){
      cout<<" ";
    }
    for(int j = 0 ; j<n-i ; j++){
      cout<<"* ";
    }
    cout<<endl;
  }
}

// Q.4 Printing Hollow Diamond
/*
     *
    * *
   *   *
  *     *
  *     *
   *   *
    * *
     *
*/
void holloDiamond(){
  int n;
  cin >> n;

  for(int i = 0; i<n ; i++){
    for(int j = 0 ; j < n-i-1; j++){
      cout<<" ";
    }
    for(int j = 0; j<2*i+1 ; j++){
      if(j == 0 ){
        cout<<"*";
      }
      else if (j == 2*i){
        cout<<"* ";
      }
      else {
        cout<<" ";
      }
    }
    cout<<endl;
  }
  for(int i = 0; i<n ; i++){
    for(int j = 0 ; j<i ; j++){
      cout<<" ";
    }
    for(int j = 0 ; j < 2*n-2*i-1 ; j++){
      if(j == 0 ){
        cout<<"*";
      }
      else if(j == 2*n-2*i-2){
        cout<<"* ";
      }
      else{
        cout<<" ";
      }
    }
    cout<<endl;
  }
}

// Q.5 Printing Flipped Solid Diamond
/*
   * * * * * * * *
   * * *     * * *
   * *         * *
   *             *
   *             *
   * *         * *
   * * *     * * *
   * * * * * * * *
*/
void flippedSolidDiamond(){
  int n;
  cin >> n;
  for(int i = 0 ; i<n ; i++){
    for(int j = 0 ; j<n-i; j++){
      cout<<"*";
    }
    for(int j = 0 ; j<2*i+1 ; j++){
      cout<<" ";
    }
    for(int j = 0 ; j<n-i; j++){
      cout<<"*";
    }
    cout<<endl;
  }
  for(int i = 0 ; i<n ; i++){
    for(int j = 0 ; j<i+1 ; j++){
      cout<<"*";
    }
    for(int j = 0 ; j<2*n-2*i-1 ; j++){
      cout<<" ";
    }
    for(int j = 0 ; j<i+1; j++){
      cout<<"*";
    }
    cout<<endl;
  }
}

// Q.6 Fancy Pattern 
/*
   1
   2*2
   3*3*3
   4*4*4*4
   5*5*5*5*5
   5*5*5*5*5
   4*4*4*4
   3*3*3
   2*2
   1
*/
void fancyPattern1(){
  int n;
  cin >> n;
  for(int i = 0; i<n ; i++){
    for(int j = 0; j<i+1; j++){
      cout<<i+1;
      if(j != i){
        cout<<"*";
      }
    }
    cout<<endl;
  }
  for(int i = 0 ; i<n ;i++){
    for(int j = 0 ; j<n-i-1 ; j++){
      cout<<n-i-1;
      if(j != n-i-2){
        cout<<"*";
      }
      
    }
    cout<<endl;
  }
}

// Q.7 Printing Alphabet Palindrome Pyramid
/*
   A
   A B A
   A B C B A
   A B C D C B A
   A B C D E D C B A
*/
void alphabetPalindromePyramid(){
  int n;
  cin >> n;
  for(int i = 0 ; i<n ; i++){
    int j;
    for(j = 0 ; j <i+1 ; j++){
      int ans = j+1;
      char ch = ans + 'A' -1;
      cout<<ch<<" ";
    }
    for(j = i ; j>=1 ; j--){
      int ans = j;
      char ch = ans + 'A' -1;
      cout<<ch << " ";
    }
    cout<<endl;
  }
}

int main() {
  // fullPyramid();
  // invertedFullPyramid();
  // solidDimond();
  // holloDiamond();
  // flippedSolidDiamond();
  // fancyPattern1();
  alphabetPalindromePyramid();
  
  return 0;
}