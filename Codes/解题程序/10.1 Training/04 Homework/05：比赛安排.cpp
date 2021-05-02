#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[500][500] , len ;
inline void func ( int firstLeft , int firstRight , int secondLeft , int secondRight , int len ) ;

int main () {

    scanf ( "%d" , &n ) ;
    len = n ;
    for ( int i = 1 ; i <= n ; i++ ) {
        a[i][1] = i ; // init
    }

    func ( 1 , n , 1 , n , len ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            printf ( "%d " , a[i][j] ) ;
        }
        printf ( "\n" ) ;
    }

    return 0 ;
}

inline void func ( int firstLeft , int firstRight , int secondLeft , int secondRight , int len ) {
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            printf ( "%d " , a[i][j] ) ;
        }
        printf ( "\n" ) ;
    }
    printf ( "%d %d %d %d %d\n\n" , firstLeft , firstRight , secondLeft , secondRight , len ) ;
    
    if ( len >= 2 ) {
        int firstMid = ( firstRight - firstLeft ) / 2 ;
        int secondMid = ( secondRight - secondLeft ) / 2 ;

        for ( int i = 0 ; i < len ; i++ ) {
            if ( ! a[firstRight - i][secondRight] ) {
                a[firstRight - i][secondRight] = a[firstLeft + i][secondLeft] ; // oppsite
            }
            else {
                a[firstLeft + i][secondLeft] = a[firstRight - i][secondRight] ; // oppsite
            }
        }

        len /= 2 ;
        func ( firstLeft , firstLeft + firstMid , secondLeft , secondLeft + secondMid , len ) ; // [1...mid][1...mid]
        func ( firstLeft , firstLeft + firstMid , secondLeft + secondMid + 1 , secondRight , len ) ; // [1...mid][mid + 1...n]
        func ( firstLeft + firstMid + 1 , firstRight , secondLeft , secondLeft + secondMid , len ) ; // [mid + 1...n][1...mid]
        func ( firstLeft + firstMid + 1 , firstRight , secondLeft + secondMid + 1 , secondRight , len ) ; // [mid + 1...n][mid + 1...n]
    }
}

/*
#include <iostream>
#include <stdlib.h>
using namespace std;
int N; //8个
int a[15][15] = {0};
void Calendar(int firstLeft, int secondLeft, int firstRight, int secondRight, int s)
{
    if (s >= 2)
    {
        s = s / 2;
        int firstMid = (firstRight - firstLeft) / 2;
        int secondMid = (secondRight - secondLeft) / 2;
        for (int i = 0; i < 2 * s; i++)
        {
            if (a[firstRight - i][secondRight] == 0)
                a[firstRight - i][secondRight] = a[firstLeft + i][secondLeft];
            else
                a[firstLeft + i][secondLeft] = a[firstRight - i][secondRight];
        }
        Calendar(firstLeft, firstLeft + firstMid, secondLeft, secondLeft + secondMid, s);
        Calendar(firstLeft, firstLeft + firstMid, secondLeft + secondMid + 1, secondRight, s);
        Calendar(firstLeft + firstMid + 1, firstRight, secondLeft, secondLeft + secondMid, s);
        Calendar(firstLeft + firstMid + 1, firstRight, secondLeft + secondMid + 1, secondRight, s);
    }
}

int main()
{
    scanf ( "%d" , &N ) ;
    int s = N;
    for (int i = 1; i <= N; i++)
        a[i][1] = i;

    Calendar(1, 1, N, N, s);
    cout << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << a[i][j] << ' ';

        cout << endl;
    }
    return 0;
}

/*
..............................................
                                      1  2  3  4  5  6  7
                                   1  2  3  4  5  6  7  8
                                   2  1  4  3  6  7  8  5
                                   3  4  1  2  7  8  5  6             
             1  2  3               4  3  2  1  8  5  6  7
           1 2  3  4               5  6  7  8  1  4  3  2
   1       2 1  4  3               6  5  8  7  2  1  4  3
1  2       3 4  1  2               7  8  5  6  3  2  1  4             
2  1       4 3  2  1               8  7  6  5  4  3  2  1
...........................................................................
 (1)           (2)                            (3)

//////////////////
按分治策略,我们可以将所有的选手分为两半,则n个选手的比赛日程表可以通过n/2个选手的比赛日程表来决定.
递归地用这种一分为二的策略对选手进行划分,直到只剩下两个选手时,比赛日程表的制定就变得很简单.
这时只要让这两个选手进行比赛就可以了...
上面是 2个、4个和8个选手的比赛日程表...
（3）是8个选手的比赛日程表.其中左上角与左下角的两小块分别为选手1至选手4和选手5至选手8前3天的比赛日程.
据此.将左上角小块中的所有数字按其相对位置抄到右下角,又将左下角小块中的所有数字按其相对位置抄到右上角,
这样我们就分别安排好了选手1至选手4和选手5至选手8在后4天的比赛日程.依此思想容易将这个比赛日程表推广到具有任意多个选手的情形....
*/