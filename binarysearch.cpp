#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end - start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        //go to right wala part
        if(key>arr[mid]){
            start =mid+1;
        }
        //go to left wala part
        else
            {end = mid -1;}


        mid = start + (end - start)/2;
        }

    return -1;
       
    }
//time complexity O(logn)


int main(){
    int even[6] ={2,4,6,8,10,12};
    int odd[5]= {3,8,11,14,16};
    int index = binarysearch(even,6,18);
    cout<<index;

    return 0;
}