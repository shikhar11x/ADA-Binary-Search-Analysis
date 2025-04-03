# Binary Search Analysis
## Overview

This program analyzes the recursive implementation of the Binary Search algorithm by calculating the number of steps required in different scenarios:

- **Best Case**: When the target element is found in the middle of the array.
- **Average Case**: When the target element is a randomly chosen value from the array.
- **Worst Case**: When the target element is the last element in the array.

## How It Works

1. The program generates sorted arrays of different sizes.
2. It runs recursive binary search on each array to measure step count in best, average, and worst cases.
3. The results are printed to the console.

## Code Breakdown

- **recursiveBinarySearch()**: Implements the binary search recursively and counts the number of steps taken.
- **analyzbinarysearchRecursive()**: Runs the binary search on arrays of different sizes and logs the results.
- **main()**: Calls the analysis function to execute the program.

# Code
```cpp
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int stepCount=0;
int recursiveBinarySearch(vector<int>& arr,int left,int right,int target){
    stepCount++;
    if(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target)return mid;
        else if(arr[mid]>target)return recursiveBinarySearch(arr,left,mid-1,target);
        else return recursiveBinarySearch(arr,mid+1,right,target);
    }
    return -1;
}

void analyzbinarysearchRecursive(){
    vector<int> inputSizes={10,20,30,40,50,100};
    for(int i=0;i<inputSizes.size();i++){
        int size=inputSizes[i];
        vector<int> arr(size);
        for(int i=0;i<size;i++){
            arr[i]=i+1; 
        }
    // cout<<"Array: [ ";
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<"]"<<endl;

    int bestcase=arr[(size-1)/2];
    int worstcase=arr[size-1];
    srand(time(0));
    int randomindex=rand()%size;
    int randomcase=arr[randomindex];

    cout<<"=================== Input Size: "<<size<<" ==================="<<endl;
    stepCount=0;
    recursiveBinarySearch(arr,0,size-1,bestcase);
    cout<<"Best Case= "<<stepCount<<" steps"<<endl;
    stepCount=0;
    recursiveBinarySearch(arr,0,size-1,randomcase);
    cout<<"Average Case= "<<stepCount<<" steps"<<endl;
    stepCount=0;
    recursiveBinarySearch(arr,0,size-1,worstcase);
    cout<<"Worst Case= "<<stepCount<<" steps"<<endl;
    cout<<"==================================================================="<<endl<<endl;
    }
}

int main(){
    analyzbinarysearchRecursive();
    return 0;
}

```
# Output

```cpp
=================== Input Size: 10 ===================
Best Case= 1 steps
Average Case= 4 steps
Worst Case= 4 steps
===================================================================

=================== Input Size: 20 ===================
Best Case= 1 steps
Average Case= 5 steps
Worst Case= 5 steps
===================================================================

=================== Input Size: 30 ===================
Best Case= 1 steps
Average Case= 4 steps
Worst Case= 5 steps
===================================================================

=================== Input Size: 40 ===================
Best Case= 1 steps
Average Case= 4 steps
Worst Case= 6 steps
===================================================================

=================== Input Size: 50 ===================
Best Case= 1 steps
Average Case= 6 steps
Worst Case= 6 steps
===================================================================

=================== Input Size: 100 ===================
Best Case= 1 steps
Average Case= 3 steps
Worst Case= 7 steps
===================================================================

...
```
# Graph
![Graph](/graph/binary%20Search%20analysis.png)
## Requirements

- C++ Compiler (e.g., g++)
- Standard Library (vector, iostream, ctime, cstdlib)

## Notes

- The random case may vary on different runs due to the use of `rand()`. To ensure reproducibility, a fixed seed can be set using `srand()`.
- The array is always sorted, ensuring binary search works correctly.
