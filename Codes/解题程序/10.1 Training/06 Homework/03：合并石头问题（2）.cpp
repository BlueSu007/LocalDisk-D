#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 10005
int n , len , x , tmp1 , tmp2 , heap[LEN] ;
inline void push ( int x ) ;
inline void pop () ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &x ) ;
        push (x) ;
    }

    long long ans = 0 ;
    while ( len >= 2 ) {
        tmp1 = heap[1] , pop () ;
        tmp2 = heap[1] , pop () ;
        ans += tmp1 + tmp2 ;
        push ( tmp1 + tmp2 ) ;
    }

    printf ( "%d" , ans ) ;
    
    return 0 ;
}

inline void push ( int x ) {
    int son ;
    heap[++len] = x , son = len ;

    while ( son != 1 && ( heap[son / 2] > heap[son] ) ) {
        swap ( heap[son] , heap[son / 2] ) ;
        son /= 2 ;
    }
}

inline void pop () {
    int parent = 1 , son ;
    heap[1] = heap[len--] ;

    while ( parent * 2 <= len ) {
        if ( parent * 2 + 1 > len || ( heap[parent * 2] < heap[parent * 2 + 1] ) ) {
            son = parent * 2 ;
        }
        else {
            son = parent * 2 + 1 ;
        }

        if ( heap[parent] > heap[son] ) {
            swap ( heap[parent] , heap[son] ) ;
            parent = son ;
        }
        else {
            break ;
        }
    }
}