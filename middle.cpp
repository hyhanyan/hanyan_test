#include<iostream>
#include <vector>
using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

/*
        left_part          |        right_part
  A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
  B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

  PS:默认B数组的长度(n) > A数组的长度(m).

  我们要保证：
  len(left_part) == len(right_part) 奇数咋办？往后看!
  max(left_part) <= min(right_part)
  这样的话(max(left_part) + min(right_part)) / 2 就是中位数.
  新数组为奇数时 max(left_part) 就是中位数. 这里很重要.

  确定中卫数的方法就是:
  B[j - 1] <= A[i] && B[j] >= A[i - 1]
  这时 max(left_part) = max(A[i - 1], B[j - 1])
       min(right_part)= min(A[i], B[j])

  我们规定：
  i 属于 [0, m]                                                   1 2 2 3
  j = (m + n + 1) / 2 - i                                        2 4 4 5

  Q:为什么要加1
  A:我们先看这两个数组

       1th                           left    right      mid
   [1, 2 | 3, 4] -----------------> [1, 2]   [3, 4] --> 2.5
   len(1th) = 4
   len(left) = (4 / 2) == ((4 + 1) / 2) == 2 = len(right)
   len(left) * 2 == len(right) * 2 == len(1th)
   对于偶数加不加1都没事,取整变0了.

       2nd                           left    right      mid
   [5, 6, 7] == [5, (6 | 6), 7] --> [5, 6]   [6, 7] -->  6
   len(2nd) = 3
   len(left) = (3 / 2) == 1
   问题来了
   len(left) != len(right)
   违反了算法要保证的
   len(left_part) == len(right_part)
   所以我们给数组补一个“中位数”,即2nd中补了一个6, (6 + 6) / 2 == 6,中位数不变！

   所以新数组为偶数的时候:
   (m + n + 1) / 2 == (m + n) / 2 (中位数位置不变)
   所以新数组为奇数的时候:
   (m + n + 1) / 2 中位数位置变成我们新补充的那个数,结果还是中位数
   好处就是公式统一了.

   剩下的看:https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation
   只要整明白(m + n + 1)为什么要加1就好懂了.
   这个算法并没有比较中位数的大小,而是趋近一种夹逼策略,来逐渐确定中位数的位置(j随着i的变化而变化,i变大j变小)
  
 */

double findMedianSortedArrays(vector<double> A,vector<double> B)
{
    if(A.size() > B.size()){
        findMedianSortedArrays(B,A);
    }

    int m = A.size(), n = B.size();
    int imin = 0,imax = m, i , j, mid = (m+n+1) >> 1;//mid为什么+1 除以2，见上面
    double max_of_left,min_of_right; // i一直在A的数组里面，j也一定在B的数组里面，因为B的长度大于等于A的长度
    while(imin <= imax){
        i = (imin + imax) >> 1;
        j = mid - i;
        if(i < m && B[j-1] > A[i]){
            imin = i + 1;
        }else if(i > 0 && B[j] < A[i-1]){
            imax = i - 1;
        }else{
            if(i == 0){     //i==0的时候，说明i一直往左走，说明imax在减小，所以A[0]要比整个合并后的中位数要大，所以max_of_left不是A中的
                max_of_left = B[j-1];
            }else if(j == 0){  //和i==0同理
                max_of_left = A[i-1];
            }else{
                max_of_left =MAX(A[i-1],B[j-1]);
            }
            break;
        }
    }

    if((m + n) & 1){ //合并后为奇数是
        return max_of_left;
    }

    if(i == m){   //当i==m时，说明i一直往右走,imin在一直增大,所以可以看出A[m-1]比整个合并后的中位数要小，所以min_of_right不是A中的
        min_of_right = B[j];
    }else if(j == n){ //和i==m类似
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
