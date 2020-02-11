#include<iostream>
#include<string>

using namespace std;

int E(string, int);

int F(string str, int i){
	if(str[i] == '('){
		i++;
		i = E(str, i);
		if(str[i] == ')')
			i++;
	} else if (str[i] == 'i' && str[i+1] == 'd'){
		i+=2;
	}
	return i;
}

int T_dash(string str, int i){
	if(str[i] == '*'){
		i++;
		i = F(str, i);
		i = T_dash(str, i);
	}
	return i;
}

int T(string str, int i){
	i = F(str, i);
	i = T_dash(str, i);
	return i;
}

int E_dash(string str, int i){
	if(str[i] == '+'){
		i++;
		i = T(str, i);
		i = E_dash(str, i);
	}
	return i;
}


int E(string str, int i){
	i = T(str, i);
	i = E_dash(str, i);
	return i;
}

int main(){
	string str;
	cin>> str;
	int i=0;
	i = E(str, i);
	if(i == str.length())
		cout<<"Matched";
	else
		cout<<"Not match " <<i;
}