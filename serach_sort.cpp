#include<iostream>
#include<vector>

using namespace std;
int itBinSearch(int arr[],int l ,int h,int key){
    
    while(l<=h){
        int mid = l + (h-l)/2 ;
        if(key== arr[mid]) return mid;

        if(key<arr[mid]) h= mid -1;
        
        else l =mid + 1;
    }
    return -1;
}


int recBinSearch(int arr[],int l ,int h,int key){
    int mid = l + (h-l)/2;
    if(l<=h){
        if(key == arr[mid]) return mid;
        if(key<arr[mid])  return recBinSearch(arr, l, mid -1,key);
        else if (key>arr[mid]) return recBinSearch(arr, mid + 1, h, key);
        else return -1;
    }

    return -1;
}


void swap(int &x, int &y){
    int temp = x;
    x = y;
    y= temp;
}

void bubbleSort(int arr[], int size){
    

    for(int i= 0; i<size; i++){
        for(int j = 0; j<size-i-1; j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
}


int selectionSort(int arr[], int size){
    int idx = 0;
    for(int i =0; i<size-1; i++){
        idx = i;
        int min = i;
        //get the index of the minimum element of lefteover
        for (int j = i; j < size ; j++)
        {
            if (arr[j]<arr[min])
            {
                min = j;
            }
           
            
        }
         swap(arr[min],arr[idx]);
        

    }
    return 0;

}

void insertionSort(int arr[], int size){
    for(int i=0; i<size; i++){
        int j =i;
        while (j>0 && arr[j] < arr[j-1])
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
        
    }
}

void mergeSortedArray(vector<int> &arr, int low,int mid, int high){
    vector<int> temp;
    
    int left=low, right = mid+1;
    while(left<=mid && right <=high){
        if (arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
            
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
        
    }
    while (left<=mid)
    {
       temp.push_back(arr[left]);
       left++;
       
    }
    while (right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i =low; i<=high; i++){
        arr[i] = temp[i-low];
    }
    
    
}

void mergeSort(vector<int> &arr, int low, int high){
    if (low==high) return;
    
    
    int mid = (low + high)/2;
    // cout << "low: " << low << " mid: " << mid << " high: " << high << endl;
    mergeSort(arr, low,mid);
    mergeSort(arr, mid+1,high);
    mergeSortedArray(arr, low,mid, high);

}
int main(){
    // int arr[]= {12,19,21,24,34,45,67,76, 81,90};
    // int length = sizeof(arr)/ sizeof(arr[0]);
    // cout << itBinSearch(arr, 0, length, 24) << endl;
    // cout << recBinSearch(arr, 0, length, 76) << endl;
    vector<int> arr = {42, 12, 87, 63, 9, 34, 76, 55, 19, 98, 23, 67, 45, 31, 89, 25, 71, 4, 60, 81};

    int size= arr.size();
    cout<< "Unsorted Array: - " ;
    for(const int& i : arr){
        cout<<i<< " ";
    }
    cout << endl;
    // bubbleSort(arr,size);
    mergeSort(arr,0,size-1);
    cout<< "Sorted Array: - " ;
    for(int i = 0; i<size; i++){
        cout<< arr[i] << " ";
    }
        cout << endl;
}