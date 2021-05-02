#include <iostream>
#include <string>
using namespace std;

string c = "I can't do that!\n--------------------\n";
string d = "I'm a computer,I have brain!\n====================\n";
string e = "I'm not bad,isn't I!\n####################\n";
string f = "Computer is happy!/^_^/\n++++++++++++++++++++\n";
string g;

int main(){
	
	string a;
	char b; 
	cout << "请输入操作码：0=结束；1=（无）；2=你这个罪该万死的机器！" << endl;
	cout << "              3=夸夸电脑；4=你有脑子吗？；5=你能换句话吗？" << endl;
	cout << "              6=你让电脑说的话" << endl; 
	while(1){
		cin >> b;
		if(b == '0'){ 
			cout << "电脑下线啦~  GoodBye!丿^_^丿" << endl << "**************";
			break;
		}
		else if(b == '1'){
			cout << c << endl;
		}
		else if(b == '2'){
			cout << e << endl;
		}
		else if(b == '3'){
			cout << f << endl;
		}
		else if(b == '4'){
			cout << d << endl;
		}
		else if(b == '5'){
			cout << "你希望我说什么？（不能含空格）" << endl;
			cin >> a;
			g = a; 
		}
		else if(b == '6'){
			cout << g << endl;
		}
		else{
			cout << "操作码不对，请重新输入操作码！" << endl;
		}
	}
	
	return 0;
}
