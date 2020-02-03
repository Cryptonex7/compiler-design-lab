// ab(aa+bb)ab

#include<stdio.h>

int main(){
    printf("\n\n");

	char c, buf[80];
    scanf("%s", buf);

    if(
        (buf[0] == 'a' && buf[1] == 'b') && 
        ((buf[2] == 'a' && buf[3] == 'a') || (buf[2] == 'b' && buf[3] == 'b')) &&
        (buf[4] == 'a' && buf[5] == 'b') &&
        (buf[6] == '\0')
    )
        printf("%s OK ab(a+b)ab\n\n", buf);
    else {
        printf("%s Not ab(a+b)ab\n\n", buf);
        exit(0);
    }

    printf("\n\n");
    return 0;
}