#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void printArr(vector<int> arr){
  for(auto i : arr){
    cout<< i <<" ";
  }
}

// Searching in An Array 
int Search(vector<int> arr, int key){ // TC : O(n)
  for(int i = 0 ; i<arr.size(); i++){
    if(arr[i] == key){
      return i;
    }
    
  }
  return -1;
}

// insert inside an array  TC : O(n)
void insert(vector<int> &arr, int &size ,int position , int val){
  int i;
  size++;
  arr.resize(size);
  for(i = size-1; i>= position ; i--){
    arr[i] = arr[i-1];
  }

  arr[position - 1] = val;
}

// Delete an element from array 
void deleteEle(vector<int> &arr, int &size,int val){ //TC : O(n)
  int i;
  for(i = 0 ; i<size ; i++){
    if(arr[i] == val )
      break;
  }
  if(i < size){
    for(int j = i ; j < size ; j++){
      arr[j] = arr[j+1];
    }
  }
  size--;
  arr.resize(size);
}

// Finding the max element insize an array 
int findingMx(vector<int> &arr){
  int mx = INT_MIN;
  for(int i = 0; i < arr.size() ; i++){
    if(arr[i] > mx){
      mx = arr[i];
    }
  }
  return mx;
}

// Finding the min element insize an array 
int findingMn(vector<int> &arr){
  int mn = INT_MAX;
  for(int i = 0; i < arr.size() ; i++){
    if(arr[i] < mn){
      mn = arr[i];
    }
  }
  return mn;
}

// Finding Second Largest Element in the array 
int second_largest(vector<int> &arr){ // O(n)
  int res = -1;
  int largest = 0;
  for(int i = 1 ; i<arr.size() ; i++){
    if(arr[i] > arr[largest]){
      res = largest;
      largest = i;
    }
    else if (arr[i] != arr[largest]){
      if(res == -1 || arr[i] > arr[res])
      res = i;
    }
  }
  return arr[res];
}

// Checking if a given array is sorted or not 
bool isSorted(vector<int> &arr){
  for(int i = 0 ; i< arr.size() ; i++){
    if(arr[i] > arr[i+1]){
      return false;
    }
  }
  return true;
}

// counting 0's and 1's inside an array 
void count(vector<int> &arr){
  int zeroCount = 0;
  int oneCount = 0;
  for(int i = 0 ; i<arr.size(); i++){
    if(arr[i] == 0){
        zeroCount++;
    }
    if(arr[i] == 1){
      oneCount++;
    }
  }
  cout << zeroCount << endl;
  cout << oneCount << endl;
  
}

// Printing Extreme element of an array 
void printExt(vector<int> &arr){
  int l = 0;
  int h = arr.size()-1;
  while(l <= h){
    cout << arr[l] <<" "<<arr[h]<<endl;
    l++;
    h--;
  }
  if(l == h ) cout << arr[l]<<endl;
}

// Reversing an array 
void Reverse(vector<int> &arr){
  int l = 0; 
  int h = arr.size()-1;
  while(l <= h ){
    swap(arr[l],arr[h]);
    l++;
    h--;
  }
}

int main() {
  
  int n; 
  cin >> n;
  vector<int>arr(n);
  for(int i = 0; i<n ; i++){
    cin >> arr[i];
  }
  // int key;
  // cin >> key;

  // cout << Search(arr,key) << endl;
  // insert(arr,n,key,1);
  // deleteEle(arr, n, key);
  // cout << findingMx(arr) <<endl;
  // cout << findingMn(arr) <<endl;
  // printArr(arr);
  // cout << second_largest(arr);
  // cout<<isSorted(arr);
     // count(arr);
  // printExt(arr);
  // Reverse(arr);
  // printArr(arr);
  return 0;
}