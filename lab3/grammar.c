#include<stdio.h>


void B() {
    printf("c");
}


void C() {
    printf("d");
}


void D() {
    printf("a");
}

void A(char str[], int ptr) {
    if( ptr == 1){
        printf("a");
        A(str, ++ptr);
        B();
        C();
        D();
    }  else {
        B();
    }
}

void main() {
    char a[10] = "accda";
    int ptr = 1;
    A(a, ptr);
    printf("a\n");

}