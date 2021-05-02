#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string s ;
int cnt = 1 ;

int main () {

    cin >> s ;
    int len = s.size () ;

    for ( int i = 1 ; i <= len ; i++ ) {
        if ( s[i] == s[i - 1] ) {
            cnt++ ;
        }
        else {
            if ( cnt > 1 ) {
                printf ( "%c%d" , s[i - 1] , cnt ) ;
            }
            else {
                printf ( "%c" , s[i - 1] ) ;
            }
            cnt = 1 ;
        }
    }

    return 0 ;
}