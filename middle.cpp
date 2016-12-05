#include<iostream>
#include <vector>
using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

double findMedianSortedArrays(vector<double> A,vector<double> B)
{
    if(A.size() > B.size()){
        findMedianSortedArrays(B,A);
    }

    int m = A.size(), n = B.size();
    int imin = 0,imax = m, i , j, mid = (m+n+1) >> 1;
    double max_of_left,min_of_right;

    while(imin <= imax){
        i = (imin + imax) >> 1;
        j = mid - i;
        if(i < m && B[j-1] > A[i]){
            imin = i + 1;
        }else if(i > 0 && B[j] < A[i-1]){
            imax = i - 1;
        }else{
            if(i == 0){
                max_of_left = B[j-1];
            }else if(j == 0){
                max_of_left = A[i-1];
            }else{
                max_of_left =MAX(A[i-1],B[j-1]);
            }
            break;
        }
    }

    if((m + n) & 1){
        return max_of_left;
    }

    if(i == m){
        min_of_right = B[j];
    }else if(j == n){
        min_of_right = A[i];
    }else{
        min_of_right = MIN(A[i],B[j]);
    }

    return (max_of_left + min_of_right) / 2.0;
}

int main()
{
    double a[] = {0,5,5,6,9};
    double b[] = {2,3,3,4,9};
    vector<double> A(a,a+5);
    vector<double> B(b,b+5);


    cout << findMedianSortedArrays(A, B) << endl;

    return 0;
}
