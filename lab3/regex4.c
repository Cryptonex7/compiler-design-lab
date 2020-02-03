// 01(101)*01

#include<stdio.h>

int main(){
    printf("\n\n");

	char c, buf[80];
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int s4 = 0;
    scanf("%s", buf);

    if(buf[0] == '0' )
        s1 = 1;
        if( buf[1] == '1')
            s2 = 1;
            for(int i = 2; buf[i] != '\0'; i+=3){
                if(buf[i] == '1')
                    s3 = 1;
                    if( buf[i+1] == '0') 
                        s4 = 1;
                        if (buf[i+2] == '1')
                            s4 = 1;
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