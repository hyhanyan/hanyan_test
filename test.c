#include<stdio.h>

//static 定义的变量的作用，算值
int fun1()
{
    static int a = 0;
    a++;
    return a;
}

int fun2()
{
    static int a = 1;
    a++;
    return a;
}

//一个长度为n的数组，每次都输出第m 个数字的下标，直到全部输出
//0，1，2，3，4，5   n=6,m=2    ----->   1,3,5,2,0,4
//                        m =10 -------> 3,2,5,0,4,1
void findArray(int arr[],int n,int m)
{
    int count = 0;
    int i=0,j=0;
    while(count != n){
        if(i == n){
            i = 0;
        }
        if((j == m-1) && (i< n) && (arr[i] == 0)){
            arr[i] = 1;

            j = 0;
            i++;
            count++;
        }else if((j == m-1) && arr[i] != 0){
            i++;
        }else if((j != m-1) && arr[i] != 0){
            i++;
        }else{
            i++;
            j++;
        }
    }
}


int main()
{


    int arr[] = {0,0,0,0,0,0};
    findArray(arr,6,10);
    printf("%d\n",fun2());
    printf("%d\n",fun1());
    printf("%d\n",fun2());
    return 0;
}
