// https://www.luogu.com.cn/blog/Kesdiael3/solution-p1106
#include <iostream> 
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

char s[250 + 5] , ans[250 + 5] ;
int n , len , keep , last , cnt , minn ;

int main () {
    
    scanf ( "%s %d" , s , &n ) ;
    len = strlen (s) ;

    keep = len - n , last = -1 ;
    while ( cnt <= keep ) {
        minn = INT_MAX ;
        for ( int i = last + 1 ; i <= len - keep + cnt ; i++ ) {
            if ( s[i] < minn ){
                minn = s[i] , last = i ;
            }
        }
        ans[++cnt] = s[last] ;
    }

    int start = 0 ;
    while ( ans[++start] == '0' && start < keep ) ;

    for ( int i = start ; i <= keep ; i++ ) {
        // cout << '*' ;
        printf ( "%c" , ans[i] ) ;
    }

    return 0 ;
}