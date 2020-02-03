#include<iostream>
#include<string>

using namespace std;

int main(){
	string exp;
	cin>>exp;
	int i=0;

	if(exp[i] == 'a'){
		while(i<exp.length()-1){
			i++;
			if(!(exp[i] =='a' || exp[i] =='b')){
				break;
			}
		}
		if(exp[i]=='b'){
			if(i==exp.length()-1)
				cout<<"\nBelongs to a(a+b)*b";
			else
				cout<<"\nDoesn't belongs to a(a+b)*b";
		} else {
			cout<<"\nDoesn't belongs to a(a+b)*b";
		}
	} else {
		cout<<"\nDoesn't belongs to a(a+b)*b";
	}
	

	return 0;
}