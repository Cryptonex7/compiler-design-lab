#include<iostream>
#include<string>

using namespace std;

int main(){
	string exp;
	cin>>exp;
	int i=0;

	if(exp[i] == 'a'){
		i++;
		if(exp[i]=='a'||exp[i]=='b'){
			i++;
			if(exp[i]=='b'){
				if(i==exp.length()-1)
					cout<<"Belongs to a(a+b)b";
				else
					cout<<"Doesn't belongs to a(a+b)b";
			} else {
				cout<<"Doesn't belongs to a(a+b)b";
			}
		} else {
			cout<<"Doesn't belongs to a(a+b)b";
		}
	} else {
		cout<<"Doesn't belongs to a(a+b)b";
	}
	

	return 0;
}