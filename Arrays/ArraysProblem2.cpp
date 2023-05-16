#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Q.1 Trapping rain water 
// i/p : {2,0,3}
//o/p : 2

// Naive Approach  time complexity : O(n^2) and Space complexity : O(1)
int getHeight(vector<int>& arr){
  int n = arr.size();
  int tapwaterHeight = 0;
  for(int i = 1; i<n-1; i++){
    int leftMax = 0, rightMax = 0;
    for(int j = 0; j<=i ; j++){
      leftMax = max(leftMax,arr[j]);
    }
    for(int j = i; j<n ; j++){
      rightMax = max(rightMax,arr[j]);
    }

    tapwaterHeight += max(0,min(leftMax,rightMax)-arr[i]);
  }

  return tapwaterHeight;
}

// Efficient approach  Tc And SC : O(n)
int getHeight2(vector<int> &arr){
  int n = arr.size();
  if(n <= 2){
    return 0;   //not enough bar to store 
  }
  vector<int> leftMx(n);
  vector<int> rightMx(n);

  leftMx[0] = arr[0];
  for(int i = 0; i<n ; i++){
    leftMx[i] = max(leftMx[i-1],arr[i]);
  }

  rightMx[n-1] = arr[n-1];
  for(int i = n-2 ; i>=0 ; i--){
    rightMx[i] =  max(rightMx[i+1],arr[i]);
  }

  int storingTapWater = 0;
  for(int i = 0 ; i<n ; i++){
    int minHeight = min(rightMx[i],leftMx[i]);
    storingTapWater += minHeight - arr[i];
  }
  return storingTapWater;
}

// Q.2 Maximum Consecutive 1s in binary Array
// i/p : [0, 1, 1, 0 ,1,0]
// o/p : 2

// Naive Approach  tc : O(n^2)
int mxConOnes(vector<int> &arr){
  int res = 0;
  for(int i = 0 ; i<arr.size() ; i++){
    int curr = 0;
    for(int j = 1 ; j<arr.size() ; j++){
      if(arr[j] == 1) {
        curr++;
      }
      else {
        break;
      }
    }
    res = max(res,curr);
  }
  return res;
}

// efficient Approach  --- tC: O(n)
int mxConOnes2(vector<int> &arr){
  int res = 0;
  int  curr = 0;
  for(int i = 0; i<arr.size(); i++){
    if(arr[i] == 1){
      curr++;
      res = max(res,curr);
    }
    else {
      curr = 0;
    }
  }
  return res;
}

// Q.3 Maximum Sum SubArray 
// i/p : [2,3,-8,7,-1,2,3]
// o/p : 11 ->(7+(-1)+2+3)

// naive Approach  -- Tc : O(n^2)
int mxSum(vector<int> &nums){
  int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int currSum = 0;
        for (int j = i; j < n; j++) {
            currSum += nums[j];
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
    }

    return maxSum;
}

// efficient Approach based on Kanade's Algo which has time complexity as O(n)
int mxSum2(vector<int> &arr){
  int n = arr.size();
  int mxSum = INT_MIN;
  int currSum = 0;

  for(int i = 0 ;i<n; i++){
    currSum += arr[i];

    if(currSum < arr[i]){
      currSum = arr[i];
    }
    if(currSum > mxSum) {
      mxSum = currSum;
    }
  }
  return mxSum;
}

// Q.4 Maximum Length Even-odd subArray 
// i/p : {10,12,14,7,8}
// o/p : 3 (14,7,8)

// Naive Approach -- O(n^2)
int mxLenEvenOdd(vector<int> &arr){
  int res = 1;
  for(int i = 0 ; i< arr.size(); i++){
    int curr = 1;
    for(int j = i+1 ; j<arr.size(); j++){
      if((arr[j] % 2 == 0 && arr[j-1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j-1] % 2 == 0)){
        curr++;
      }else {
        break;
      }
    }
    res = max( res, curr);
  }
  return res;
}

// Efficient approach  -- O(n)
int mxLenEvenOdd2(vector<int> &arr){
  int n = arr.size();
  int currMax = 1 , maxLen = 1;
  for(int i = 1 ; i<n ; i++){
    if((arr[i] % 2 == 0 && arr[i-1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i-1] % 2 == 0)){
      currMax++;
      maxLen = max(currMax , maxLen);
    }
  }
  return maxLen;
}

// Q.5 Maximum Circular SubArray Sum 
// i/p : {10 , -5, 5}
// o/p : 15

// Naive Approach -- O(n*n)
int maxCirSubArrSum(vector<int> &arr){
  int curMxSum = arr[0];
  for(int i = 0 ; i<arr.size() ; i++){
    int currSum = arr[i];
    int currMax = arr[i];
    for(int j = 1; j <  arr.size() ; j++){
      int index = (i+j) % arr.size();
      currSum += arr[index];
      currMax = max(currSum , currMax);
    }
    curMxSum = max(curMxSum,currMax);
  }
  return curMxSum;
}

// efficient approach O(n)

int maxSubArrSum(vector<int> &arr){
  int n = arr.size();
  int currSum = 0;
  int mxSum = INT_MIN;
  for(int i = 0; i<n ;i++){
    currSum += arr[i];
    currSum = max(currSum,arr[i]);
    mxSum = max(currSum,mxSum);
  }
  return mxSum;
}

int maxCirSubArrSum2(vector<int> &arr){
  int n = arr.size();
  int maxSum1 = maxSubArrSum(arr);

  int totalSum = 0;
  for(int  i = 0 ; i<n ; i++){
    totalSum += arr[i];
    arr[i] = -arr[i];
  }
  int maxSum2 = totalSum + maxSubArrSum(arr);

  return max(maxSum1,maxSum2);
}

// Q.6 Majority Element 
// i/p : [8,3,4,8,8]
// o/p : Any index of 8 ie : 0 or 3 or 4

// naive Approach -- Tc:O(n^2)
int majorityEle(vector<int> &arr){
  int n = arr.size();

  for(int i = 0; i<n ; i++){
    int count = 1;
    for(int j = i+1; j<n; j++){
      if(arr[i] == arr[j]){
        count++;
      }
    }
    if(count > n/2 ){
      return i;
    }
  }
  return -1;
}

// efficient approach  tc : O(n)
int majorityEle2(vector<int>&arr){
  int n = arr.size();
  int majorityElement = 0;
  int count = 1;
  for(int i = 1; i<n ;i++){
    if(arr[i] == arr[majorityElement] ){
      count++;
    }else {
      count--;
    }

    if(count == 0){
      majorityElement = i;
      count = 1;
    }
  }
  count = 0;
  for(int i = 0 ;i<n ;i++){
    if(arr[i] == arr[majorityElement] ){
      count++;
    }
  }
  if(count > n/2){
    return majorityElement;
  }
  return -1;
}

// Q.7 Minimum Group flips to make Same 
// i/p : [1,1,0,0,0,1]
// o/p : 2 to 4

void printGrp(vector<int>&arr){   /// time complexity O(n)
  for(int i = 1; i<arr.size(); i++){
    if(arr[i] != arr[i-1]){
      if(arr[i] != arr[0]){
        cout << i << " ";
      } else {
        cout << i-1 << " ";
      }
    }
  }
  if(arr[arr.size()-1] != arr[0]) {
    cout << arr.size()-1 << " ";
  }
}

// Q.8 find the sum of k consecutive elements (sliding window Tech)
// i/p : [1,8,30,-5,20,7] k = 3
// o/p : 45

// Naive Approach : tc:O(n^2)
int conMaxSum(vector<int> &arr , int k){
  int n = arr.size();
  int maxSum = INT_MIN;
  for(int i = 0 ; i+k-1 < n ;i++){
    int sum = 0;
    for(int j = 0 ; j<k ; j++){
      sum += arr[i+j];
    }
    maxSum = max(maxSum , sum );
  }
  return maxSum;
}

// Efficient Approach  TC:O(n)
int consMaxSum2(vector<int> &arr , int k){
  int n = arr.size();
  int currSum = 0;
  for(int i = 0 ; i<k ; i++){
    currSum +=arr[i];
  }
  int maxSum = currSum;
  for(int i = k ; i<n ; i++){
    currSum += (arr[i] - arr[i-k]);
    maxSum = max(maxSum, currSum);
  }
  // cout << currSum << endl;
  return maxSum;
}

// Q.9  Given an unsorted array of non-negative intergers.find if there is a sub array with given sum 
// i/p : [1,4,20,3,10,5] sum = 33
// o/p : yes

bool isSubSum(vector<int> &arr , int sum){  // TC : O(n)
  int n = arr.size();
  int currSum = arr[0];
  int s = 0;
  for(int e = 1 ; e<n ; e++){
    while(currSum > sum && s < e-1 ){
      currSum -= arr[s++];
    }
    if(currSum == sum ) return true;
    if(e < n ){
      currSum += arr[e];
    }
  }
  return (currSum == sum );
}







int main() {
int n;
  cin >> n;
  vector<int> arr(n);

  for(int i = 0; i<n ; i++) {
    cin >> arr[i];
  }

  // cout << getHeight(arr)<<endl;
  // cout << getHeight2(arr)<<endl;
  // cout << mxConOnes(arr);
  // cout << mxConOnes2(arr);
  // cout<<mxSum(arr);
  // cout<<mxSum2(arr);
  // cout << mxLenEvenOdd(arr);
  // cout << mxLenEvenOdd2(arr);
  // cout<< maxCirSubArrSum(arr);
  // cout<< maxCirSubArrSum2(arr);
  // cout << majorityEle(arr);
  // cout << majorityEle2(arr);
  // printGrp(arr);
  // cout << conMaxSum(arr,3);
  // cout << consMaxSum2(arr,3);
  cout << isSubSum(arr,33);
  
}