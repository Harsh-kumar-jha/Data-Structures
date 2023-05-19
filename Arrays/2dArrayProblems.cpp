#include <iostream>
#include <vector>

using namespace std;

// How To print 2D array
void printArr(vector<vector<int>> &arr){
  for(int i = 0 ; i<arr.size() ; i++){
    for(int j = 0 ; j<arr[i].size() ; j++){
      cout << arr[i][j] << " ";
    }
  } 
  cout << endl; 
}
// How To input 2D array
void inputArr(vector<vector<int>> &arr){
  for(int i = 0 ; i<arr.size() ; i++){
    for(int j = 0 ; j<arr[i].size() ; j++){
      cin >>  arr[i][j] ;
    }
  }
}

// How to print 2D array Row wise 
void printRowWise(vector<vector<int>> &arr){
  for(int row = 0 ; row < arr.size(); row++){
    for(int col = 0 ; col < arr[row].size() ; col++){
      cout << arr[row][col] << " ";
    }
    cout << endl;
  }
   cout << endl;

}
// How to print 2D array Column wise 
void printColWise(vector<vector<int>> &arr){
  for(int row = 0 ; row < arr.size(); row++){
    for(int col = 0 ; col < arr[row].size() ; col++){
      cout << arr[col][row] << " ";
    }
    cout << endl;
  }
   cout << endl;
}

// Printing A 2D array in Sanke pattern 
void printSnakePattern(vector<vector<int>> &arr){
  for(int i = 0; i<arr.size() ; i++){
    if(i % 2 == 0){
      for(int j = 0 ; j<arr[i].size(); j++){
        cout << arr[i][j] << " ";
      }
      cout<<endl;
    }
    else {
      for(int j = arr[i].size()-1 ; j>= 0 ; j--){
        cout << arr[i][j] <<" ";
      }
      cout << endl;
    }
  }
}

// Printing Border element in 2D array 
void printBorderEle(vector<vector<int>> &arr){
  int row = arr.size();
  int col = arr[0].size();

  for(int i = 0; i<col-1 ; i++){
    cout << arr[0][i] <<" ";
  }
  for(int i = 0; i < row-1 ; i++){
    cout << arr[i][col-1] << " ";
  }

  for(int i = col-1 ; i>=0 ; i--){
    cout << arr[row-1][i] << " ";
  }
  for(int i = row-2; i>0 ; i--){
    cout << arr[i][0] << " ";
  }
}

// Printing Transpose  of 2d
void printTranspose(vector<vector<int>> &matrix){
  int rows = matrix.size();
    int cols = matrix[0].size();

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Q. Rotate A matrix by 90 degree
// i/p : 1 2 3
//       4 5 6
//       7 8 9

// o/p : 3 6 9
//       8 7 4
//       1 2 5

// Naive Approach -- Tc : O(n*m) & Sc : O(n*m)
void RotateBy90(vector<vector<int>> &arr){
  int n = arr.size();

    vector<vector<int>> temp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[n-j-1][i] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = temp[i][j];
        }
    }

  printArr(arr);
}

// Efficient Approach 
void RotateBy90App2(vector<vector<int>> &arr){
  int n = arr.size();
  for(int i = 0 ; i<n ; i++){
    for(int j = i+1 ; j<n ; j++){
      swap(arr[i][j],arr[j][i]);
    }
  }
  for(int i = 0 ; i < n ; i++){
    int l = 0, h = n-1;
    while(l<h){
      swap(arr[i][l],arr[i][h]);
      l++;
      h--;
    }
  }

 for(auto x : arr){
   for(auto y : x){
     cout << y << " ";
   }
   cout << endl;
 }
}

// Q.Spiral Traversal of Matrix
void printSpiral(vector<vector<int>> &arr){
  int row = arr.size(),col = arr[0].size();
  int top = 0 , bottom = row-1;
  int left = 0, right = col-1;

  while(top <= bottom && left<=right){
    for(int i = left ; i<=right ; i++){
      cout << arr[top][i] << " ";
    }
    top++;
    for(int i = top ; i <= bottom ; i++){
      cout << arr[i][right]  << " ";
    }
    right--;

    if(top<=bottom){
      for(int i = right ; i>=left ; i--){
        cout << arr[bottom][i] << " ";
      }
      bottom--;
    }
    if(left<=right){
      for(int i = bottom ; i >= top ; i--){
          cout << arr[i][left] << " ";
      }
      left++;
    }
  }

}

// Q. Search in a Row-wise and column-wise sorted matrix

void Search(vector<vector<int>> &arr , int x){
  int row = arr.size();
  int col = arr[0].size();

  int i = 0, j = col-1;
  while(i<row && j>=0){
    if(arr[i][j] == x){
      cout << i << " " << j << endl;
      return;
    }
    else if (arr[i][j] > x){
      j--;
    }else {
      i++;
    }
  }
}


int main() {
  
  // How to Create 2d Array
  int n,m;
  cin >> n >> m;

  vector<vector<int>> arr(n,vector<int>(m));
  inputArr(arr);
  // printArr(arr);

  // printRowWise(arr);
  // printColWise(arr);
  // printSnakePattern(arr);
  // cout << endl;
  // printBorderEle(arr);
  // printTranspose(arr);

  // RotateBy90(arr);
  // RotateBy90App2(arr);

  // printSpiral(arr);

  Search(arr,5);


}