#include<iostream>
#include<string>

using namespace std;


int B(string str, int i){
	if(str[i] == 'c')
		i++;
	return i;
}

int C(string str, int i){
	if(str[i] == 'd')
		i++;
	return i;
}

int D(string str, int i){
	if(str[i] == 'a')
		i++;
	return i;
}

int A(string str, int i){
	if(str[i] == 'a'){
		i++;
		i = A(str, i);
		i = B(str, i);
		i = C(str, i);
		i = D(str, i);
	} else {
		i = B(str, i);
	}
	return i;
}

int main(){
	string str;
	cin>> str; //accda
	int i=0;
	i = A(str, i);
	if(i == str.length())
		cout<<"String matched\n";
	else
		cout<<"String did not match\n";
}