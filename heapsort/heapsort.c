#include<stdio.h>


void Swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HeapAdjust(int *arr,int start,int end)
{
    int temp = arr[start];
    int father = start;

    int i;
    for(i=2*start+1;i<=end;i=i*2+1){
        if(i < end && arr[i] < arr[i+1]){
            i++;
        }
        if(temp < arr[i]){
            arr[father] = arr[i];
            father = i;
        }else{
            break;
        }
    }

    arr[father] = temp;
}

void HeapSortkkk(int *arr,int length,int k)
{
    int i = 0;
    for(i=(length-2)/2;i>=0;i--){
        HeapAdjust(arr,i,length-1);
    } 

    for(i=0;i< k-1;i++){
        printf("%d,",arr[0]);
        Swap(&arr[0],&arr[length-1-i]);
        HeapAdjust(arr,0,length-2-i);
    }
}

void HeapSort(int *arr,int length)
{
    int i;
    for(i=(length-2)/2;i>=0;i--){
        HeapAdjust(arr,i,length-1);
    }
    for(i=0;i<length;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
    for(i=0;i<length-1;++i){
        Swap(&arr[0],&arr[length-1-i]);
        HeapAdjust(arr,0,length-2-i);
    }
}

int main()
{
    int arr[] = {34,12,6,9,56,0,7,78,65,43};

    int length = sizeof(arr)/sizeof(arr[0]);

    //HeapSort(arr,length);

    HeapSortkkk(arr,length,4);
    int i;
    for(i=0;i<length;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
