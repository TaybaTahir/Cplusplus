#include <iostream>
#include <vector>
using namespace std;


//// Function to find first occurrence of key***************************************
//int first(int arr[], int size, int key) {
//    int start = 0;
//    int end = size - 1;
//    int ans = -1;
//
//    while (start <= end) {
//        int mid = start + (end - start) / 2;
//
//        if (arr[mid] == key) {
//            ans = mid;
//            end = mid - 1;  
//        } else if (key < arr[mid]) {
//            end = mid - 1;
//        } else {
//            start = mid + 1;
//        }
//    }
//    return ans;
//}
//
//// Function to find last occurrence of key************************************************
//int last(int arr[], int size, int key) {
//    int start = 0;
//    int end = size - 1;
//    int ans = -1;
//
//    while (start <= end) {
//        int mid = start + (end - start) / 2;
//
//        if (arr[mid] == key) {
//            ans = mid;
//            start = mid + 1;  
//        } else if (key < arr[mid]) {
//            end = mid - 1;
//        } else {
//            start = mid + 1;
//        }
//    }
//    return ans;
//}
//
//int main() {
//    int arr[11] = {1,2,3,4,4,4,4,5,6,7,8};
//    cout << "First Occurrence: " << first(arr, 11, 4) << endl;
//    cout << "Last Occurrence: "  << last(arr, 11, 4) << endl;
//    return 0;
//}


//                                                find pivot in rotated array **********************************************

int getPivot(vector<int>& arr, int n) {
    int start = 0, end = n - 1;
    int mid;
    
    while (start < end) {
        mid = start + (end - start) / 2;
        
        // If middle element >= first element, pivot is to the right
        if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            // Pivot is to the left including mid
            end = mid;
        }
    }
    // start now points to smallest element ? pivot is start - 1
    return start - 1;
}

int main() {
int a[] = {4, 5, 6, 7, 1, 2, 3};   // ? create an array
    vector<int> arr(a, a + 7);
	int n = arr.size();
    
    int pivot = getPivot(arr, n);
    cout << "Pivot index: " << pivot << endl;
    cout << "Pivot element: " << arr[pivot] << endl;
    
    return 0;
}


