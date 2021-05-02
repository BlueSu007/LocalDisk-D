#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
using namespace std;

int n , x , ans ;
priority_queue < int , vector < int > , greater < int > > que ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &x ) ;
        que.push (x) ;
    }

    while ( que.size () >= 2 ) {
        int a = que.top () ; que.pop () ;
        int b = que.top () ; que.pop () ;
        ans += a + b ;
        que.push ( a + b ) ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}