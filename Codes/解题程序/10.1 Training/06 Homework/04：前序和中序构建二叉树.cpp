#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

string preOrder , midOrder ;
inline void lastOrder ( string preOrder , string midOrder ) ;

int main () {

    cin >> preOrder >> midOrder ;
    lastOrder ( preOrder , midOrder ) ;

    return 0 ;
}

inline void lastOrder ( string preOrder , string midOrder ) {
    if ( midOrder.size () > 0 ) {
        char ch = preOrder[0] ;
        int pos = midOrder.find ( ch ) ;
        
        lastOrder ( preOrder.substr ( 1 , pos + 1 ) , midOrder.substr ( 0 , pos ) ) ;
        lastOrder ( preOrder.substr ( pos + 1 , midOrder.size () - pos ) , midOrder.substr ( pos + 1 ) ) ;
        printf ( "%c" , ch ) ;
    }
}