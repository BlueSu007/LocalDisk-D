#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

const string num[10] = { "ling" , "yi" , "er" , "san" , "si" , "wu" , "liu" , "qi" , "ba" , "jiu" } ;
const string bit[10] = { "" , "shi" , "bai" , "qian" , "wan" , "shi" , "bai" , "qian" , "yi" , "shi" } ;
string s ;
int len ;

int main () {

    cin >> s ;
    len = s.size () ;

    for ( int i = 0 ; i < len ; i++ ) {
        int x = s[i] - '0' ;
        if ( ! x ) {
            if ( len - i == 5 || len - i == 9 ) { // 如果是十亿和十万，记得加上亿和万这俩单位
                cout << bit[len - i - 1] << " " ;
            }
            if ( ( len - i ) != 1 && s[i + 1] != '0' ) { // 中间有一或多个0，它的下一位不为0时，它要读0
                cout << "ling " ;
            }
        }
        else if ( ( len == 2 || len == 6 || len == 10 ) && x == 1 && i == 0 ) { // 特判读yishi还是shi，这里是不读yi的情况
            cout << "shi " ;
        }
        else {
            cout << num[x] << " " << bit[len - i - 1] << " " ;
        }
    }

    return 0 ;
}