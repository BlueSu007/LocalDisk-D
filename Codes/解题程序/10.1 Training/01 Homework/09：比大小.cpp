#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string a , b ;

int main () {

    cin >> a >> b ;
    if ( a.size () > b.size () ) {
        cout << a << endl ;
    }
    else if ( b.size () > a.size () ) {
        cout << b << endl ;
    }
    else {
        cout << max ( a , b ) << endl ;
    }

    return 0 ;
}