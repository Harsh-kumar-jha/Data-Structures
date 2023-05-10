#include <iostream>
using namespace std;

// Q.1 Printing Hollow inverted half Pyramid
/*
  * * * * *
  *      *
  *    *
  *  *
  * *
  *
*/
void hollowInvertedHalfPyramid(){
  int n;
  cin >> n;

  for(int i = 0 ;i<n ;i++){
    for(int j = 0; j<n ; j++){
      if(i == 0 || j == 0 || j == n-i-1){
        cout<<"*";
      }
      else {
        cout<<" ";
      }
    }
    cout<<endl;
  }
}

// Q.2 Printing Hollow Pyramid
/*      
        *
       * *
      *   *
     *     *
    *       *
   * * * * * *
*/
void hollowPyramid(){
  int n;
  cin >> n;
  for(int i = 0; i<n ; i++){
    int k = 0;
    for(int j = 0; j<((2*n)-1); j++){
      if(j<n-i-1) {
        cout<<" ";
      }
      else if (k < 2*i+1){
        if(k == 0 || k == 2*i || i == n-1){
          cout<<"*";
        }
        else {
          cout<<" ";
        }
        k++;
      }
      else {
        cout<<" ";
      }
    }
    cout<<endl;
  }
}

// Printing Numeric Full Pyramid 
/*
      1
    2 3 2
  3 4 5 4 3
4 5 6 7 6 5 4
*/
void numbericFullPyramid(){
  int n;
  cin >> n;

  for(int i = 0 ; i<n ;i++){
    for(int j = 0; j < n-i-1; j++){
      cout<<" ";
    }
    for(int j = 0 ; j<i+1; j++){
      cout << i +j +1;
    }
    int s = 2*i;
    for(int j = 0 ; j<i ; j++){
      cout<<s;
      s--;
    }
    cout<<endl;
  }
}

// Q.4 Printing numeric hollow Pyramid
/*
      1
     1 2
    1   3
   1     4
  1       5
 1 2 3 4 5 6
*/
void numericHollowPyramid(){
  int n; 
  cin >> n;
  for(int i = 0; i< n ; i++){
    for(int j = 0; j<n-i-1;j++){
      cout<<" ";
    }
    int s = 1;
    for(int j = 0 ; j<2*i+1;j++){
      if(i == 0 || i == n-1 ){
        if(j%2 == 0){
          cout<<s;
          s++;
        }else {
          cout<<" ";
        }
      }
      else {
        if(j == 0){
          cout<<"1";
        }
        else if(j == 2*i){
          cout<<i+1;
        }else{
          cout<<" ";
        }
      }
    }
    cout<<endl;
  }
}

// Q.5 Printing Numeric hollow half pyramid 
/*
    1
    1 2
    1   3
    1     4
    1 2 3 4 5
*/
void printingNumHollowHalfPyramid(){
  int n;
  cin >> n;
  for(int i = 0; i<n ; i++){
    for(int j = 0; j<=i ; j++){
      if(j == 0 || j == i || i == n-1){
        cout<<j+1;
      }else {
        cout<<" ";
      }
    }
    cout<<endl;
  }
}

// Q.6 Printing inverted half hollw pyramid
/*
   1 2 3 4 5
   2     5
   3   5
   4 5
   5
*/
void printingNumInvHollowPyramid(){
    int n;
    cin >> n;
    for(int i = 0 ; i<n ; i++){
      for(int j = i+1 ; j <= n  ; j++){
        if(j == i+1 || j == n   || i == 0){
          cout<<j;
        }
        else cout <<" ";
      }
      cout<<endl;
    }
}

// Q.7 Printing palindromic Equilateral Pyramid 
/*
         1
        121
       12321
      1234321
     123454321
*/
void equilateralPyramid(){
  int n;
  cin >> n;
   int k = n;
  for(int i = 0; i<n ; i++){
   
    int c = 1;
    for(int j = 0 ; j < k; j++){
      if(j < n - i - 1){
        cout << " ";
      }
      else if (j <= n-1){
        cout << c;
        c++;
      }
      else if(j == n){
        c = c-2;
        cout<<c;
        c--;
      }
      else {
        cout << c;
        c--;
      }
    }
    cout<<endl;
    k++;
  }
}
// Q.8 Printing fancy pattern 
/*
     ********1********
     *******2*2*******
     ******3*3*3******
     *****4*4*4*4*****
     ****5*5*5*5*5****
*/
void fancyPattern(){
  int n;
  for(int i = 0 ; i<n ; i++){
    int startingIndex = 8 - i;
    int num = i + 1;
    int countNum = num;
    for(int j = 0 ; j<17 ; j++){
      if(j == startingIndex && countNum > 0){
        cout << num;
        startingIndex +=2;
        countNum--;
      }
      else {
        cout<<"*";
      }
    }
    cout<<endl;
  }
}
int main(){
     // hollowInvertedHalfPyramid();
   // hollowPyramid();
  // numbericFullPyramid();
  // numericHollowPyramid();
  // printingNumHollowHalfPyramid();
  // printingNumInvHollowPyramid();
  // equilateralPyramid();
  fancyPattern();
  return 0;
}