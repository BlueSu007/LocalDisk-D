#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int n , a , b , k , head , tail , step ; // step: the shortest answer
int cupaQue[100000 + 5] , cupbQue[100000 + 5] ;
int final[100000 + 5] , flag[10000 + 5] , vis[1000 + 5][1000 + 5] ;
inline bool checkIfArrived ( int tmpb ) ;
inline void putInQueue ( int tmpa , int tmpb , int i ) ;
inline void bfs ( int cupa , int cupb ) ;
inline void count ( int x ) ; // calculate use how many steps and what are they

int main () {

    scanf ( "%d %d %d" , &a , &b , &n ) ;
    bfs ( a , 0 ) ;

    if ( step == 0 ) {
        printf ( "No solution!" ) ;
    }
    else {
        printf ( "%d" , step ) ;
    }

    return 0 ;
}

inline void putInQueue ( int tmpa , int tmpb , int i ) {
    if ( !vis[tmpa][tmpb] ) { // if not visited
        vis[tmpa][tmpb] = 1 , tail++ ; // label visited , push in queue
        cupaQue[tail] = tmpa , cupbQue[tail] = tmpb ; // recored now moment
        flag[tail] = head ; // label moment
    }
}

inline void bfs ( int cupa , int cupb ) {
    tail++ , flag[tail] = 0 , cupaQue[tail] = cupa , cupbQue[tail] = cupb ;
    vis[cupa][cupb] = 1 ;

    while ( head < tail ) {
        head++ ;
        for ( int i = 1 ; i <= 6 ; i++ ) {
            if ( i == 1 ) { // fill A
                int tmpa = a , tmpb = cupbQue[head] ; // tmpa filled , tmpb continue last moment
                putInQueue ( tmpa , tmpb , i ) ;
                if ( checkIfArrived ( tmpb ) ) {
                    return ;
                }
            }

            if ( i == 2 ) { // fill B
                int tmpa = cupaQue[head] , tmpb = b ; // tmpa continue last moment , tmpb filled
                putInQueue ( tmpa , tmpb , i ) ;
                if ( checkIfArrived ( tmpb ) ) {
                    return ;
                }
            }

            if ( i == 3 ) { // empty A
                int tmpa = 0 , tmpb = cupbQue[head] ; // tmpa emptied , tmpb continue last moment
                putInQueue ( tmpa , tmpb , i ) ;
                if ( checkIfArrived ( tmpb ) ) {
                    return ;
                }
            }

            if ( i == 4 ) { // empty B
                int tmpa = cupaQue[head] , tmpb = 0 ; // tmpa continue last moment , tmpb emptied
                putInQueue ( tmpa , tmpb , i ) ;
                if ( checkIfArrived ( tmpb ) ) {
                    return ;
                }
            }

            if ( i == 5 ) { // pour B -> A
                int tmpa , tmpb , difference = a - cupaQue[head] ; // calculate how many water will be added when it's not full
                if ( difference >= cupbQue[head] ) { // if B cannot satisfy difference
                    tmpa = cupaQue[head] + cupbQue[head] ; // tmpa added cupa and cupb
                    tmpb = 0 ; // tmpb emptied
                }
                else { // other wise
                    tmpa = a ; // tmpa filled
                    tmpb = cupbQue[head] - difference ; // tmpb have left water
                }

                putInQueue ( tmpa , tmpb , i ) ;
                if ( checkIfArrived ( tmpb ) ) {
                    return ;
                }
            }

            if ( i == 6 ) { // pour A -> B
                int tmpa , tmpb , difference = b - cupbQue[head] ; // calculate how many water will be added when it's not full
                if ( difference >= cupaQue[head] ) { // if A cannot satisfy difference
                    tmpa = 0 ; // tmpa emptied
                    tmpb = cupbQue[head] + cupaQue[head] ; // tmpb add cupa and cupb
                }
                else {
                    tmpa = cupaQue[head] - difference ; // tmpa have left water
                    tmpb = b ; // tmpb filled
                }

                putInQueue ( tmpa , tmpb , i ) ;
                if ( checkIfArrived ( tmpb ) ) {
                    return ;
                }
            }
        }
    }
}

inline bool checkIfArrived ( int tmpb ) {
    if ( tmpb == n ) {
        count ( tail ) ;
        return true ;
    }

    return false ;
}

inline void count ( int x ) {
    // if have this step
    if ( flag[x] ) {
        count ( flag[x] ) , step++ ; // go on , steps plus one
    }
}