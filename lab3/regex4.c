// 01(101)*01

#include<stdio.h>

int main(){
    printf("\n\n");

	char c, buf[80];
    scanf("%s", buf);

    if(buf[0] == '0' )
        if( buf[1] == '1')
            for(int i = 2; buf[i] != '\0'; i+=3){
                if(buf[i] == '1')
                    if( buf[i+1] == '0') 
                        if (buf[i+2] == '1')
                            continue;
                        else if (buf[i] == '1' && buf[i+1] == '0' && buf[i+2] == '\0'){
                            printf("%s Match: 01(101)*01", buf);
                            break;
                        } else {
                            printf("Match Not found");
                            break;
                        }
            }
    else printf("Match Not found");


    printf("\n\n");
    return 0;
}