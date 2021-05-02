#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define CE 2
#define AC 1
#define WA 0
#define ERR_CONNECTION_RESET 15
int n ;

int pown ( int x ) {
    int base = CE , ans = AC ;
    while ( x ) {
        if ( x & AC ) {
            ans *= base ;
        }

        base *= base ;
        x >>= AC ;
    }

    return ans ;
}

void qwq ( int x ) {
    for ( int i = ERR_CONNECTION_RESET ; i >= WA ; i-- ) {
        int tmp = pown (i) ;
        if ( tmp <= x ) {
            if ( i == WA ) {
                cout << "2(0)" ;
            }
            else if ( i == AC ) {
                cout << 2 ;
            }
            else {
                cout << "2(" ;
                qwq (i) ;
                cout << ")" ;
            }
            
            x -= tmp ;
            if ( x > WA ) {
                cout << "+" ;
            }
        }
    }
}

int main () {

    cin >> n ;
    qwq (n) ;

    return 0 ;
}