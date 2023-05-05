#include <iostream>

using namespace std;

// Q.1 Printing Solid Retanngle
// o/p :-
/*
 * * * * *
 * * * * *
 * * * * *
*/
void solidRectangle(){
  int n,m;
  cin >> n >> m;

  if (n == m ){
    cout << "for Rectangle no of rows and no of col can not be equal";
    return;
  }
  else {
  for(int row = 0; row<n ; row++){
    for(int col = 0; col<m; col++){
      cout<<"* ";
    }
    cout<<endl; 
  }
  }
}

// Q.2 Printing Solid Square 
// o/p :-
/*
   * * * * *
   * * * * *
   * * * * *
   * * * * *
   * * * * *
*/
void solidSquare(){
  int n;
  cin >> n;
  for(int row = 0 ; row<n ; row++){
    for(int col = 0 ; col<n ; col++){
      cout<<"* ";
    }
    cout<<endl;
  }
}

// Q.3 Printing Hollow Rectangle
// o/p :- 
/*
  * * * * *
  *       *
  * * * * * 
*/
void hollowRectangle(){
  int rowCount , colCount;
  cin>>rowCount >> colCount;
  for(int row = 0 ; row < rowCount ; row++){
    if(row == 0 || row == rowCount-1){
      for(int col = 0 ; col < colCount ; col++){
        cout<<"* ";
      }
    }
    else {
      cout<<"* ";
      for(int i = 0 ; i<colCount-2 ; i++){
        cout<<"  ";
      }
      cout<<"* ";
    }
    cout<<endl;
  }
}

// Q.4 Printing Half Pyramid 
// o/p :-
/*
  *
  * *
  * * *
  * * * *
  * * * * *
*/
void halfPyramid(){
  int n;
  cin>>n;

  for(int row = 0 ; row<n; row++){
    for(int col = 0; col < row+1; col++){
      cout<<"* ";
    }
    cout<<endl;
  }
}

//Q.5 Printing inverted pyramid
//o/p :-
/*
    * * * *
    * * *
    * *
    *
*/
void invertedPyramid(){
  int n;
  cin >> n;

  for(int row = 0; row<n ; row++){
    for(int col = 0 ; col < n-row ; col++){
      cout<<"* ";
    }
    cout<<endl;
  }
}

// Q.6 Printing Numberic Half Pyramid
/*
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
*/
void numbericHalfPyramid(){
  int n;
  cin >> n;

  for(int row = 0 ; row<n ; row++){
    for(int col = 0 ; col < row+1 ; col++){
      cout<<col+1 << " ";
    }
    cout<<endl;
  }
}

// Q.7 Printing inverted numberic Half Pyramid
/*
  1 2 3 4 5
  1 2 3 4
  1 2 3 
  1 2
  1
*/
void invertedNumbericHalfPyramid(){
  int n;
  cin >> n;

  for(int row = 0 ; row < n ; row++){
    for(int col = 0 ; col < n-row ; col++){
      cout<<col+1<<" ";
    }
    cout<<endl;
  }
}

int main(void) {
	// solidRectangle();
  // solidSquare();
  // hollowRectangle();
  // halfPyramid();
  // invertedPyramid();
  // numbericHalfPyramid();
  // invertedNumbericHalfPyramid();
};
