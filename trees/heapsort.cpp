#include <iostream>
using namespace std;

void heapify(int arr[], int n, int root){
    //n is size of heap
    int largest=root;
    int l = 2*root +1;
    int r= 2*root +2;

    if (l<n && arr[l]>arr[largest]) {
        largest = l;
    }
    if (r<n && arr[r]> arr[largest]){
        largest = r;
    }

    if (largest!=root){
        swap(arr[root],arr[largest]);

        heapify(arr,n,largest);
    }

}

void heapsort(int arr[], int n){
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for (int i = n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    int arr[10] = {9,5,1,4,10,2,3,8,6,7};
    int l = sizeof(arr)/sizeof(int);
    heapsort(arr,l);
    for (int i=0;i<l;i++){
        cout << arr[i]<<" ";
    }
}
