#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

typedef struct node {
    char name ;
    node *leftChild , *rightChild ;
} *qaq ;
string s ;
int qwq ;
inline void createTree ( qaq &tree ) ;
inline void preOrder ( node *tree ) ;

int main () {

    cin >> s ;
    qwq = s.size () ;
    qaq head ;
    createTree ( head ) ;
    preOrder ( head ) ;

    return 0 ;
}

inline void createTree ( qaq &tree ) {
    if ( s[--qwq] != '.' && qwq >= 0 ) {
        tree = new node ;
        tree -> name = s[qwq] ;
        createTree ( tree -> rightChild ) ;
        createTree ( tree -> leftChild ) ;
    }
    else {
        tree = NULL ;
    }
}

inline void preOrder ( node *tree ) {
    if ( tree != NULL ) {
        printf ( "%c" , tree -> name ) ;
        preOrder ( tree -> leftChild ) ;
        preOrder ( tree -> rightChild ) ;
    }
}

// da..cb...
// ..a..b.cd

/*#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string a ;
inline void func ( string s ) ;

int main () {

    cin >> a ;
    func (a) ;
    return 0 ;
}

inline void func ( string s ) {
    if ( s.size () >= 3 ) {
        int len = s.size () ;
        printf ( "%c" , s[len - 1] ) ;

        int i = 0 ;
        while ( s[i] == '.' ) {
            i++ ;
        }
        
        if ( i % 2 ) {
            func ( s.substr ( 3 , len - 4 ) ) ;
        }
        else {
            s += ".." ;
            int lastPos = 0 ;
            for ( int i = 2 ; i < len ; i++ ) {
                if ( ( s[i] != '.'
                && ( ( s[i - 1] == '.' && s[i - 2] != '.' ) || ( s[i - 1] != '.' ) )
                && ( s[i + 1] == s[i + 2] && s[i + 1] == '.' ) ) ) {
                    if ( lastPos ) {
                        func ( s.substr ( lastPos + 1 , len - lastPos - 2 ) ) ;
                    }
                    lastPos = i ;
                    func ( s.substr ( 0 , i ) ) ;
                }
            }
        }
    }
}*/