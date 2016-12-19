#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void Msort(int *arr,int length,int gap)
{
    int *d = (int*)malloc(length*sizeof(int));
    assert(d != NULL);
    int index = 0;
    int low1 = 0;
    int high1 = low1 + gap -1;

    int low2 = high1 + 1;
    int high2 = (low2 + gap -1) > (length-1) ? (length -1) :(low2+gap-1);

    while(low2 <= length-1){
        while((low1<=high1) && (low2<=high2)){
            if(arr[low1] >= arr[low2]){
                d[index++] = arr[low2++];
            }else{
                d[index++] = arr[low1++];
            }
        }

        while((low1<=high1) && (low2 > high2)){
            d[index++] = arr[low1++];
        }

        while((low2<=high2) && (low1 > high1)){
            d[index++] = arr[low2++];
        }

        low1 = high2 + 1;
        high1 = low1 + gap -1;

        low2 = high1+1;
        high2 = (low2+gap-1) > (length-1)?(length-1):(low2+gap-1);
    }

    while(low1 <= length-1){
        d[index++] = arr[low1++];
    }

   int k = 0;
   for(k=0;k<length;k++){
       arr[k] = d[k];
   }

   free(d);

}

void MergeSort(int *arr,int length)
{
    int i;
    for(i = 1;i < length-1;i=i*2){
        Msort(arr,length,i);
    }
}


int main()
{
    int arr[] = {12,4,45,0,758,57,3,6,32,6,76,764,4,34663,252};
    int length = sizeof(arr)/sizeof(arr[0]);

    MergeSort(arr,length);
    int i;
    for(i = 0;i < length;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
