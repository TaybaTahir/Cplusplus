#include<iostream>
using namespace std;

bool  binarySearch(int arr[],int s,int e,int k){
    if(s>e)
        return false;

    int mid = s + (e-s)/2;

    //element found
    if(arr[mid] == k)
        return true;

    if(arr[mid] < k) {
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}

int main(){
    int arr[] = {1,9,6,4,3,2};
    int size = 6;
    int k;
    cout<<"Enter Value to Find:";
    cin>>k;
    bool ans = binarySearch(arr,0,size-1,k);
    if(ans){
        cout<<"Present";
    }else{
        cout<<"Not Present";
    }
}
