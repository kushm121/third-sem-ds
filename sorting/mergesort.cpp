#include <iostream>
using namespace std;

void merge(int arr[],int low, int mid, int high){
    int i=low;
    int k=low;
    int j=mid+1;
    int c[20];

    while (i<=mid && j<=high){
        if (arr[i] < arr[j]){
            c[k++] = arr[i++];
        }

        else{
            c[k++] = arr[j++];
        }
    }
    while (i <= mid){
        c[k++] = arr[i++];
    }
    while (j <= high){
        c[k++] = arr[j++];
    }
    for (i=low;i<k;i++){
        arr[i] = c[i];
    }
}

void mergesort(int arr[], int low, int high){
    int mid;
    if (low < high){
        mid = (low + high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[20] = {3,10,7,4,0,6,2,8,1,5,9};
    int l = 11;
    mergesort(arr,0,10);
    for (int i=0; i<l; i++){
        cout << arr[i] << " ";
    }
}
