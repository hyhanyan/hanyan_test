#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;

int partition(int *arr,int low,int high)
{
    int temp = arr[low];

    while(low < high){
        while((low < high) && (temp >= arr[high])){
            high--;
        }
        if(low < high){
            arr[low] = arr[high];
        }

        while((low < high) && temp <= arr[low]){
            low++;
        }
        if(low < high){
            arr[high] = arr[low];
        }

    }

    arr[low] = temp;
    return low;
}

void QuickSort(int *arr,int low,int high)
{
    int parti = partition(arr,low,high);

    if(parti+1 < high){
        QuickSort(arr,parti+1,high);
    }
    if(parti-1 > low){
        QuickSort(arr,low,parti-1);
    }
}

int Quick_Max_k(int *arr,int low,int high,int k)
{
    int parti = partition(arr,low,high);

    if( k-1 > parti){
        return Quick_Max_k(arr,parti+1,high,k);
    }else if(k-1 < parti){
        return Quick_Max_k(arr,low,parti-1,k);
    }else{
        return arr[parti];
    }
}

void QuickSort1(int *arr,int low,int high){
    stack<int> st;

    int mid = partition(arr,low,high);

    if(mid-1 > low){
        st.push(low);
        st.push(mid-1);
    }

    if(mid+1 < high){
        st.push(mid+1);
        st.push(high);
    }

    while(!st.empty()){
        int q = st.top();
        st.pop();
        int p = st.top();
        st.pop();

        mid = partition(arr,p,q);

        if(mid-1 > p){
            st.push(p);
            st.push(mid-1);
        }

        if(mid+1 < high){
            st.push(mid+1);
            st.push(high);
        }
    }

    
}

int main()
{
    int arr[] = {45,56,5,1,8,9,4,3,1,1,5,7,907,6,23};
    int len = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,len-1);

    int i = 0;
    for(i = 0;i < len;i++){
        printf("%d\n",arr[i]);
    }
    printf("================\n");
    int h = Quick_Max_k(arr,0,len-1,11);
    printf("%d\n",h);
    return 0;
}
