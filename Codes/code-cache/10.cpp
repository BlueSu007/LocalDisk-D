#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int az = a.find("."); //a 的整数部分长度
    int bz = b.find(".");

    int ax = a.length() - az - 1; //a 的小数部分长度
    int bx = b.length() - bz - 1;

    int z, x; //整数、小数部分的最长长度
    az > bz ? z = az : z = bz;
    ax > bx ? x = ax : x = bx;

    string saz = a.substr(0, az);  //a 的整数部分
    string sax = a.substr(az + 1); //a 的小数部分
    string sbz = b.substr(0, bz);
    string sbx = b.substr(bz + 1);

    while (saz.size() != z) //整数部分补零
        saz = "0" + saz;
    while (sbz.size() != z)
        sbz = "0" + sbz;
    while (sax.size() != x) //小数部分补零
        sax = sax + "0";
    while (sbx.size() != x)
        sbx = sbx + "0";

    int c = 0;
    string xiao = "", zheng = "";

    for (int i = x - 1; i >= 0; i--)
    { //字符转 int ：char -‘0’；int 转字符：4 + ‘0’
        xiao += ((c + (sax[i] - '0') + (sbx[i] - '0')) % 10 + '0');
        c = (c + (sax[i] - '0') + (sbx[i] - '0')) / 10;
    }

    for (int i = z - 1; i >= 0; i--)
    {
        zheng += ((c + (saz[i] - '0') + (sbz[i] - '0')) % 10 + '0');
        c = (c + (saz[i] - '0') + (sbz[i] - '0')) / 10;
    }

    if (c != 0)
        zheng += (c + '0');

    int k; //小数部分去零
    for (k = 0; k < xiao.length(); k++)
        if (xiao[k] != '0')
            break;
            
    reverse(zheng.begin(), zheng.end());

    cout << zheng << ".";

    for (int i = xiao.length() - 1; i >= k; i--)
        cout << xiao[i];
    cout << endl;

    system("pause");
}