#include <iostream>
#include <vector>

using namespace std;
void printArr(vector<int> &arr){
  for(auto i : arr){
    cout << i << " ";
  }
}

// Q.1 Removing All the duplicate element from an  array (the array is sorted in ascending  order)
// i/p : arr = {10,20,20,30,30,30}
// o/p : arr = {10,20,30}

// Naive Approach  tc and Sc = O(n)
int remDup(vector<int> &arr , int n){
  if(n == 0) return 0;

  vector<int> temp;
  temp.push_back(arr[0]);

  for(int i = 1 ; i<n ;i++){
    if(temp.back() != arr[i]){
      temp.push_back(arr[i]);
    }
  }
  for(int i = 0; i<temp.size(); i++){
    arr[i] = temp[i];
  }
  arr.resize(temp.size());
  return temp.size();
}

// effective approach -- tc = O(n) and Sc = O(1)
int remDup2(vector<int> &arr, int n){
  if(n == 0) return 0;
  int j = 0;
  for(int i = 1; i<n ; i++){
    if(arr[i] != arr[j]){
      j++;
      arr[j] = arr[i];
    }
  }
  arr.resize(j+1);
  return j+1;
}

// Q.2 Move all the zero to the end
// i/p : arr = {8,5,0,10,0,20}
// o/p : arr = {8,5,10,20,0,0}

// Naive Approach -- TC : O(n^2) and sc = O(1)
void moveZeroToEnd(vector<int> &arr){
  int n = arr.size();
  for(int i = 0; i<n ; i++){
    if(arr[i] == 0 ){
      for(int j = i+1 ; j<n ; j++){
        if(arr[j] != 0){
          swap(arr[i],arr[j]);
          break;
        }
      }
    }
  }
}

// Effecient Approach -- tc : O(n) 
void moveZeroToEnd2(vector<int> &arr){
  int count = 0;
  for(int i = 1; i<arr.size(); i++){
    if(arr[i] != 0){
      swap(arr[i],arr[count++]);
    }
  }
}

// Q.3 Left Rotate an Array By 1 
// i/p : arr = {1,2,3,4,5}
// o/p : arr = {2,3,4,5,1}

void LRotateArrayByOne(vector<int> &arr){ //tc : O(n)
  int temp = arr[0];
  for(int i = 1; i<arr.size() ; i++){
    arr[i-1] = arr[i];
  }
  arr[arr.size()-1] = temp;
}

// Q.4 Right Rotate An Array By One 
// i/p : {1,2,3,4,5}
// o/p : {5,1,2,3,4}

void RRotateArrayByOne(vector<int> &arr){ // tc : O(n)
  int n = arr.size();
  int last = arr[n-1];
  for(int i = n-2; i >= 0 ; i--){
    arr[i+1] = arr[i];
  }
  arr[0] = last;
}

// Q.5 Left Rotate an Array By d
// i/p : [1,2,3,4,5] , d = 2
// o/p : [3,4,5,1,2]
// We may assume d <= no of element in the array

// Naive Approach  --- Tc : O(n*d)
void leftRotate (vector<int> &arr, int d){
  for(int i = 0 ; i<d ; i++){
    LRotateArrayByOne(arr);
  }
}

// Better Approach -- Tc : O(n) and Sc : O(d)
void leftRotate2(vector<int> &arr, int n, int d){
  vector<int>temp;
  for(int i = 0 ; i<d ; i++){
    temp.push_back(arr[i]);
  }
  for(int i = d ; i<n ;i++){
    arr[i-d] = arr[i];
  }
  for(int i = 0 ; i<d ; i++){
    arr[n-d+i] = temp[i];
  }
}

// Efficient Approach -- TC : O(n) and SC : O(1)
void reverse(vector<int> &arr, int low , int high){
  while(low <= high) {
    swap(arr[low],arr[high]);
    low++;
    high--;
  }
}

void leftRotate3(vector<int> &arr,int n,int d){
  reverse(arr,0,d-1);
  reverse(arr,d,n-1);
  reverse(arr,0,n-1);
}

// Q.6 Right Rotate by D 
// i/p : [1,2,3,4,5] , d = 2
// o/p : [4,5,1,2,3]
// We may assume d <= no of element in the array


// Naive Approach -- Tc : O(n*d)
void rightRotate(vector<int> &arr ,int d){
  for(int i = 0 ; i< d; i++){
    RRotateArrayByOne(arr);
  }
}

// better Approach  -- Tc : O(n) and Sc : O(d)
void rightRotate2(vector<int> &arr, int n, int d){
  vector<int> temp(d);
for(int i = n-d ; i < n; i++){
  temp[i-n+d] = arr[i];
}
  for(int i = n-1 ; i>=d ; i-- ){
    arr[i] = arr[i-d];
  }
  for(int i = 0 ;i < d; i++){
    arr[i] = temp[i];
  }
}

// Efficient Approach -- Tc O(n)
void rightRotate3(vector<int> &arr, int n ,int d)
{
  reverse(arr,0,n-1);
  reverse(arr,0,d-1);
  reverse(arr,d,n-1);
}

// Q.7 Leaders in an Arrays 
// An element is a leader if it is greater than all the elements to its right side. And the rightmost element is always a leader
// i/p : [7,10,4,3,6,5,2]
// o/p : 10,6,5,2

// Naive Approach --- tc : O(n^2) 
void leaders(vector<int> &arr)
{
  for(int i = 0 ; i< arr.size(); i++){
    bool flag = false ;
    for(int j = i+1; j < arr.size(); j++){
      if(arr[i] <= arr[j]){
        flag = true;
        break;
      }
    }
    if(flag == false ){
      cout << arr[i] <<" ";
    }
  }
}

// efficitive approach -- tc : O(n)
void leaders2(vector<int> &arr, int n){
  int currLtr = arr[n-1];
  cout << currLtr << " ";
  for(int i = n-2 ; i>=0 ; i--){
    if(arr[i] > currLtr){
      currLtr = arr[i];
      cout << currLtr << " ";
    }
  }
}

// Q.8 Maximum Difference
// Maximum value of arr[j] - arr[i] such that j > i
//i/p : [2 , 3, 10 , 6 ,4 ,8 , 1]
//o/p : 8

// Naive Approach  --  tc : O(n^2)
int maxdiff(vector<int> &arr , int n){
  int res = arr[1] - arr[0];
  for(int i = 0; i<n-1; i++){
    for(int j = i+1 ; j < n ; j++){
      res = max(res,arr[j]-arr[i]);
    }
  }
  return res;
}

// efficient approach  tc : O(n)
int maxdiff2(vector<int> &arr, int n){
  int res = arr[1] - arr[0];
  int minVal = arr[0];

  for(int i = 1 ; i<n ; i++){
    res = max(res, arr[i] - minVal);
    minVal = min(minVal,arr[i]);
  }
  return res;
}

// Q.9 Frequency in a sorted array 
// i/p : [10 , 10 ,10, 25 , 30 ,30,30]
// o/p : 10 - 3
// 25 - 1
// 30 - 3

void printFreq(vector<int> &arr, int n){ // tc : O(n)
  int i = 1;
  int freq = 1;
  while(i < n){
    while(i<n && arr[i] == arr[i-1]){
      freq++;
      i++;
    }
    cout<<arr[i-1] << " " << freq << endl;
    i++;
    freq = 1;
  }
  if(n == 1 || arr[n-1] != arr[n-2]){
    cout<<arr[n-1] << " "<< 1<<endl; 
  }
}

// Q.10 Stock buy and sell
// i/p : [1,5,3,8,12]
//o/p : 13

// Naive Approach O(n^2)
int maxProfit(vector<int> &price, int start, int end){
  if(end <= start) return 0;
  int profit = 0;
  for(int i = start ; i < end ; i++){
    for(int j = i+1; j<=end ; j++){
      if(price[j] > price[i]){
        int currProf = price[j]-price[i]+maxProfit(price, start, i+1)+maxProfit(price, j+1, end);
        profit = max(profit,currProf);
      }
    }
  }
  return profit;
}

//efficient approach 
int maxProfit2(vector<int> &arr , int n){
  int profit = 0;
  for(int i = 1 ; i<n ; i++){
    if(arr[i] > arr[i-1]){
      profit += (arr[i] - arr[i-1]);
    }
  }
  return profit;
}

// Some basic level questions
// 1. find unique Element 
int uniqueEle(vector<int>&arr){
  int res = 0;
  for(int i = 0; i<arr.size(); i++){
    res ^= arr[i];
  }
  return res;
}
// 2.union of two array (no duplicates ) sc:O(n)
vector<int>unionArr(vector<int>a,vector<int>b){
  vector<int>unionArr;

  for(int i = 0; i<a.size(); i++){
    unionArr.push_back(a[i]);
  }
  for(int i = 0 ; i<b.size();i++){
    unionArr.push_back(b[i]);
  }
  return unionArr;
}

// 3.intersection of 2 Array
vector<int>intersection(vector<int>a,vector<int>b){
  vector<int>inter;
  for(int i = 0; i<a.size(); i++){
    for(int j = 0; j<b.size(); j++){
      if(a[i] == b[j]){
        inter.push_back(a[i]);
        b[i] = -1;
      }
    }
  }
  return inter;
}

// 4.Sort 0s and 1s
void SortZerosAndOnes(vector<int> &arr){
  int s = 0;
  int e = arr.size()-1;
  int i = 0;
  while(i != e){
    if(arr[i] == 0){
      swap(arr[i++],arr[s++]);
    }
    if(arr[i] == 1){
      swap(arr[i],arr[e++]);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0 ; i<n ; i++){
    cin >> arr[i];
  }
  // cout << remDup(arr,n) << endl; 
  // cout << remDup2(arr,n) << endl; 
  // moveZeroToEnd(arr);
  // moveZeroToEnd2(arr);
  // LRotateArrayByOne(arr);
  // RRotateArrayByOne(arr);
  // leftRotate(arr, 2);
  // leftRotate2(arr,n, 2);
  // leftRotate3(arr, n,2);
  // rightRotate(arr, 2);
  // rightRotate2(arr, n, 2);
  // rightRotate3(arr,n, 2);
  // leaders(arr);
  // leaders2(arr,n);
  // cout << maxdiff(arr, n);
  // cout<<maxdiff2(arr, n);
  // printFreq(arr, n);
  // cout<<maxProfit(arr, 0, n-1);
  // cout<<maxProfit2(arr, n);
  // printArr(arr);
}