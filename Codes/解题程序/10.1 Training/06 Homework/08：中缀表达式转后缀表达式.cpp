#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
#include <cstring>
#include <string>
using namespace std;

typedef struct node {
    char opNum ;
    node *leftChild , *rightChild ;
} *qaq ;

string s ;
inline qaq createTree ( string s , int start , int end ) ;
inline void lastOrder ( node *tree ) ;
inline bool isBigger ( char op1 , char op2 ) ;
inline bool checkBracket ( string s , int start , int end ) ;

int main () {

    cin >> s ;
    int len = s.size () ;
    qaq head = createTree ( s , 0 , len - 1 ) ;
    lastOrder ( head ) ;

    return 0 ;
}

inline qaq createTree ( string s , int start , int end ) {
    if ( s[start] == '(' && s[end] == ')' ) {
		if ( checkBracket ( s , start , end ) ) {
			start++ , end-- ;
		}
	}

	qaq tree = new node ;
	int len = end - start + 1 ;

	if ( len <= 0 ) {
		return NULL ;
	}

	else if ( len == 1 ) {
		tree -> opNum = s[start] ;
		tree -> leftChild = NULL ;
		tree -> rightChild = NULL ;
		return tree ;
	}

	else {
		char op = ' ' ;
		int bracket = 0 , pos = end ;

		for ( int i = start ; i <= end ; i++ ) {
			if ( s[i] == '(' ) {
				bracket++ ;
			}
			else if ( s[i] == ')' ) {
				bracket-- ;
			}
			
			if ( s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' ) {
				continue ;
			}
			if ( ! bracket && isBigger ( op , s[i] ) ) {
				op = s[i] , pos = i ;
			}
		}

		if ( s[pos] != '(' && s[pos] != ')' ) {
			tree -> opNum = s[pos] ;
		}

		tree -> leftChild = createTree ( s , start , pos - 1 ) ;
		tree -> rightChild = createTree ( s , pos + 1 , end ) ;
		return tree ;
	}
}

inline void lastOrder ( node *tree ) {
    if ( tree != NULL ) {
        lastOrder ( tree -> leftChild ) ;
        lastOrder ( tree -> rightChild ) ;
        printf ( "%c" , tree -> opNum ) ;
    }
}

inline bool isBigger ( char op1 , char op2 ) {
    if ( op1 == ' ' ) {
        return true ;
    }

    if ( op1 == '+' || op1 == '-' ) {
        if ( op2 == '*' || op2 == '/' ) {
            return false ;
        }
        else {
            return true ;
        }
    }
    else {
        return true ;
    }
}

inline bool checkBracket ( string s , int start , int end ) {
	string tmp ;
	int flag = true ;

    
	for ( int i = start ; i <= end ; i++ ) {
		if ( s[i] == '(' || s[i] == ')' ) {
			tmp += s[i] ;
		}
	}

	for ( int i = start + 1 ; i < end ; i++ ) {
		if ( tmp[i] == ')' && tmp[i + 1] == '(' ) {
			flag = false ;
		}
	}

	return flag ;
}