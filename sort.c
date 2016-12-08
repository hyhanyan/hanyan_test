#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void Resverse(char *pBegin,char *pEnd){
    if(pBegin == NULL || pEnd == NULL){
        return;
    }
    while(pBegin < pEnd){
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin++,pEnd--;
    }
}

//翻转字符串
// abcdefg --------------> gfedcba
char* Re(char *pData)
{
    char *pBegin = pData;
    char *pEnd = pData + strlen(pData) -1;
    Resverse(pBegin,pEnd);

    return pData;
}

// 字符串内部翻转
// this is a student. --------------> student. a is this
char* ResverSort(char *str){
    if(str == NULL){
        return NULL;
    }
    char *start = str;
    char *end = str;
    while(*end != '\0'){
        end++;
    }
    end--;
    Resverse(start,end);
    start = end = str;
    while(*start != '\0'){
        if(*start == ' '){
            start++;
            end++;
        }else if(*end == ' ' || *end == '\0'){
            Resverse(start,--end);
            start = ++end;
        }else{
            end++;
        }
    }
    return str;

}

//去掉字符串空格
//h e llo world ----------->helloworld
char * Fundelnu(char *str)
{
    char *p = str;
    char *s = str;

    while(*s != '\0'){
        if(*s != ' '){
            *p++ = *s++;
        }else{
            s++;
        }
    }
    static int o = 9;
    *p = '\0';
    return str;
}

//拷贝字符串
char *strcpy1(char *strDest,const char *strSrc)
{
    if(strDest == NULL || strSrc == NULL){
        return NULL;
    }
    if(strDest == strSrc){
        return strDest;
    }
    char *tempStr = strDest;
    while((*tempStr++ = *strSrc++) != '\0'){}

    return strDest;
}

//一个数组长度为n,并且里面的每个元素的范围不超过n，并且这个数组是有序递增的，请找出这个数组不存在那个小于等于n的那个数字
// 0，1，2，3，4     n=5,  ------->输出5
// 0，1，3，4，5     n=5,  -------->输出2
int find(int arr[],int left,int right);
int findArray(int arr[],int n)
{
    if(arr[0] != 0){
        return 0;
    }
    if(arr[n-1] != n){
        return n;
    }
    int left = 0,right = n;
    int mid = left + (right-left)/2;
    int retvalue = -1;
    if(arr[mid] > n/2){
        retvalue = find(arr,left,mid);
    }else{
        retvalue = find(arr,mid,right);
    }

    return retvalue;
}

int find(int arr[],int left,int right)
{
    if((right - left) <= 1){
        return arr[left] + 1;
    }
    int mid = left + (right-left)/2;
    if(arr[mid] > mid){
        return find(arr,left,mid);
    }else{
        return find(arr,mid,right);
    }
}

int main(){
    char str[] = "This is a student.";
    char str1[] = "ab";
    
    int arr[] = {0,1,2,3,5};

    printf("======================\n");
    printf("%d\n",findArray(arr,5));
    printf("======================\n");

    int o =8;
    printf("%d\n",o);
    char *dest = (char *)malloc(strlen(str)+1);
    printf("%s\n",strcpy1(dest,str));
    //char *k = Fundelnu(str);

//    char *k = Re(str);
    char *k = ResverSort(str);
    int i = strlen(str1);
    printf("%d\n",i);
    printf("%s\n",k);
    free(dest);
    return 0;
}
