#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;


int C(string str, int i){
	if(str[i] == 'c'){
		i++;
        i = C(str, i);
    }
    else if(str[i] == 'd')
		i++;
    else {
        cout<<"Not Matched";
        exit(0);
    }
	return i;
}
int B(string str, int i){
	if(str[i] == 'b'){
		i++;
        i = B(str, i);
    }
    else i = C(str, i);
	return i;
}

int D(string str, int i){
	if(str[i] == 'd'){
		i++;
        i = D(str, i);
    }
	return i;
}

int A(string str, int i){
    i = B(str, i);
    int j = C(str, i);
    int k = D(str, j);
	return k;
}

int main(){
	string str;
	cin>> str; //accda
	int i=0;
	i = A(str, i);
	if(i == str.length())
		cout<<"String matched, "<<i<<endl;
	else
		cout<<"String did not match "<<i<<endl;
}