#include<iostream>
using namespace std;
bool linearSearch(int arr[],int size,int k){
    if(size==0){
        return false;
    }else if(arr[0]==k){
        return true;
    }else{
        bool remainingPart = linearSearch(arr+1,size-1,k);
        return remainingPart;
    }
}

int main(){
    int arr[] = {1,9,3,4,6};
    int size = 5;
    int k;
    cout<<"Enter Value to Find:";
    cin>>k;
    bool ans = linearSearch(arr,size,k);
    if(ans){
        cout<<"Present";
    }else{
        cout<<"Not Present";
    }
}
