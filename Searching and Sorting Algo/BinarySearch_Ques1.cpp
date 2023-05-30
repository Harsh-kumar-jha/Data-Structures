#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArr(vector<int> &arr){
  for(int i = 0 ; i<arr.size() ; i++){
    cout << arr[i] <<" ";
  }
}

// Linear Search  --- Time Complexity O(n) and Space Complexity O(1)
int linearSearch(vector<int> &arr, int key){
  for(int i = 0; i<arr.size() ; i++){
    if(arr[i] == key) return i;
  }
  return -1;
}

// Binary Search (itrative Approach) -- Time Complexity - O(log n) and Space Complexity - O(1)
int binarySearch(vector<int> &arr , int key){
  int start = 0;
  int end = arr.size()-1;

  while(start <= end){
    int mid = start + (end - start )/2;

    if(arr[mid] == key) return mid;
    else if(arr[mid] < key) start = mid + 1;
    else end = mid - 1;
  }
  return -1;
}

// Binary Search (Recursive Approach) -- Time Complexity - O(log n) and Space Complexity - O(n)

int recBinarySearch(vector<int> &arr , int start , int end , int key){
   int mid = start + (end - start)/2;

   if(start > end ) return -1;
   else if (arr[mid] == key) return mid;
   else if (arr[mid] > key) return recBinarySearch(arr,start,mid-1,key);
   else return recBinarySearch(arr,mid+1,end,key);
}

// find the first Occurance  of the element 
int firstOcc(vector<int> &arr , int key){
  int start = 0;
  int end = arr.size();
  int ans = -1;

  while(start <= end){
    int mid = start + (end - start)/2;
    if(arr[mid] == key){
      ans = mid;
      end = mid -1;
    }else if(arr[mid] > key) end = mid - 1;
    else start = mid +1;
  }
  return ans;
}

// Find the last Occurance of the element 
int lastOcc(vector<int> &arr , int key){
  int start = 0; int end = arr.size()-1;
  int ans = -1;

  while(start <= end){
    int mid = start + (end - start)/2;

    if(arr[mid] == key){
      ans = mid;
      start = mid + 1;
    }else if (arr[mid] > key) end = mid -1;
    else start = mid +1;
  }
  return ans;
}
// Find the total occurance of the element
int totalOcc(vector<int> &arr , int  key){
  int ans1 = firstOcc(arr,key);
  int ans2 = lastOcc(arr,key);

  return ans2 - ans1 + 1;
}

// find the missing element - TC : O(log n)
int missingEle(vector<int> &arr){
  int start = 0;
  int end = arr.size()-1;

  while(start <= end){
    int mid = start + (end - start)/2;

    if(arr[mid] == mid+1){
      start = mid +1;
    }else {
      end = mid -1;
    }
  }
  return start + 1;
}

// Find the Peak element in an mountain array 

int peakEle(vector<int> &arr){
  int start = 0; 
  int end = arr.size()-1;

  while(start < end){
    int mid = start + (end - start)/2;

    if(arr[mid] < arr[mid+1]){
      start = mid +1;
    }else {
      end = mid;
    }
  }
  return start;
} 

// find the pivot element in an array without duplicate 

int pivotEle(vector<int> &arr){
  int start = 0;
  int end = arr.size()-1;

  while(start <= end){
    int mid = start + (end - start)/2;

    if(start == end) {
      return start;
    }
    else if (mid + 1 <= end && arr[mid] > arr[mid+1]) return mid;
    else if (mid -1 >= start && arr[mid-1] > arr[mid]) return mid-1;
    else if (arr[start] > arr[mid]) end = mid -1;
    else start = mid +1;
  }
  return -1;
}

// finding pivot element in an array with duplicates 
int pivotWithDuplicate(vector<int> &arr){
  int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end-start) / 2;

        if (arr[mid] > arr[end]) {
            start = mid + 1;
        } else if (arr[mid] < arr[end]) {
            end = mid;
        } else {
            int pivot = start;
            for (int i = start + 1; i <= end; i++) {
                if (arr[i] < arr[pivot]) {
                    pivot = i;
                }
            }
            return pivot;
        }
    }
    return start;
 
}

// Search in rotated and sorted array 
 int bs(vector<int> &arr, int start, int end, int key){
  while(start <= end){
    int mid = start + (end - start)/2;
    if(arr[mid] == key) return mid;
    else if (arr[mid] > key) end = mid-1;
    else start = mid +1;
  }
  return -1;
}
int search(vector<int> &arr, int key){
  int pivotElement = pivotEle(arr);
  int ans = -1;

  if(key >= arr[0] && key <= arr[pivotElement]){
    ans = bs(arr,0,pivotElement,key);
  }else {
    ans = bs(arr,pivotElement+1,arr.size()-1,key);
  }
  return ans;
}

// Square Root using binary Search 
int findSqrt(int n){
  int s = 0;
  int e = n;
  int ans = -1;

  while(s<=e){
    int m = s+(e-s)/2;
    if(m*m == n) return m;
    else if(m*m > n) e = m-1;
    else {
      ans = m;
      s = m+1;
    }
  }
  return ans;
}

// Applying binary Search on 2d  array 
bool binarySEarch(vector<vector<int>> &arr,int row , int col , int x){
  int s = 0;
  int e = row*col -1;

  while(s<=e){
    int m = s + (e-s)/2;
    int rowIndex = m/col;
    int colIndex = m%col;

    if(arr[rowIndex][colIndex] == x) return true;
    else if (arr[rowIndex][colIndex] > x) e = m-1;
    else s = m+1;
  }
  return false;
}

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> arr(n,vector<int>(m));

 for(int i = 0; i<n ; i++){
   for(int j = 0 ; j<m ; j++){
     cin >> arr[i][j];
   }
 }

  // printArr(arr);
  // cout << linearSearch(arr,40);
  // cout << binarySearch(arr,40);
  // cout << recBinarySearch(arr,0,n,50);
  // cout << firstOcc(arr,50);
  // cout << lastOcc(arr,50);
  // cout << totalOcc(arr,50);
  // cout << missingEle(arr);
  // cout << peakEle(arr);
  // cout << pivotEle(arr);
  // cout << pivotWithDuplicate(arr);
  // cout << search(arr,0);
  // cout << findSqrt(25);
  cout << binarySEarch(arr,n,m,5);

  return 0;
}