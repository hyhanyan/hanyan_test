#include<stdio.h>

// 翻转有序数组后，找出最大的
// 0，1，2，4，5，6，7 数组向左翻转变成 5，6，7，0，1，2，4
int findMax(int arr[],int length)
{
    int left =0;
    int right = length-1;

    while(left < right){
        if(arr[left] < arr[right]){
            return arr[right];
        }
        int mid = left + ((right-left)>>1);
        if(arr[left] <= arr[mid]){
            left = mid;   // right = mid;  也可以
        }else{
            right = mid - 1;
        }
    }

    return arr[right];
}

// 翻转有序数组后，找出最小的
// 0，1，2，4，5，6，7 数组向左翻转变成 5，6，7，0，1，2，4
int findMin(int arr[],int length)
{
    int left = 0;
    int right = length -1;

    while(left < right){
        if(arr[left] < arr[right]){
            return arr[left];
        }
        int mid = left + ((right-left)>>1);
        if(arr[left] <= arr[mid]){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    
    return arr[left];
}


// 翻转有序数组后，找出目标的值
// 0，1，2，4，5，6，7 数组向左翻转变成 5，6，7，0，1，2，4
int findTarget(int arr[],int length,int target)
{
    int left =0;
    int right = length-1;

    while(left <= right){
        int mid = left + ((right-left)>>1);
        if(arr[mid] == target){
            return mid;
        }
        if(arr[left] <= arr[mid]){
            if((arr[left] < target) && (target < arr[mid])){
                right = mid-1;
            }else{
                left = mid +1;
            }
        }else{
            if((arr[mid] < target) && (target < arr[right])){
                left = mid + 1;
            }else{
                right = mid -1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {5,6,7,0,1,2,4};

    printf("%d\n",findMax(arr,7));
    printf("%d\n",findMin(arr,7));
    printf("%d\n",findTarget(arr,7,2));
    return 0;
}
