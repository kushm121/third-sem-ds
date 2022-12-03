#include <iostream>
using namespace std;

int partition(int arr[],int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for (int j=low; j<=high-1;j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void QuickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}

int main(){
    int arr[10] = {6,1,10,2,7,5,4,3,8,9};
    int l = sizeof(arr)/sizeof(int);
    QuickSort(arr,0,l-1);
    for (int i=0; i<l; i++){
        cout << arr[i] << " ";
    }
}
