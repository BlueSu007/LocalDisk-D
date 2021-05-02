#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

/*
brain line:
------------------start-----------------------
1:input[string]
2:change to number[int]
	(1)ask length
	(2)[false]direction input to mul1/mul2
3:do multiple caculate----num[i+j]
4:do sum plus untill length1+length2
5:output
	(1)cal- "0"(if have reqiurment)
	(2)[true]direction output number
-------------------end-------------------------
*/ 
string a,b;
int mul1[10001000],mul2[10001000],num[20002000];

int main(){
	
	//1.
	cin>>a>>b;
	
	//2.(1)
	int len1=a.size();
	int len2=b.size();
	
	//2.(2)
	for(int i=0;i<len1;i++)	mul1[i]=a[len1-1-i]-'0';
	for(int j=0;j<len2;j++)	mul2[j]=b[len2-1-j]-'0';
	
	//3.
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			num[i+j]+=mul1[i]*mul2[j];
		}
	}
	
	//4.
	for(int i=0;i<len1+len2;i++){
		num[i+1]+=num[i]/10;
		num[i]%=10;
	}
	
	//5.(1)
	int firstnumber=len1+len2;
	for(;firstnumber>0;firstnumber--){
		if(num[firstnumber]!=0){
			break;
		}
	}
	
	//5.(2)
	for(int i=firstnumber;i>=0;i--){
		cout<<num[i];
	}
	
	cout<<endl;
	
	return 0;
}
