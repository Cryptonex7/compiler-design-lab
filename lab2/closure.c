#include<stdio.h>

int main(){
    printf("\n\n");

	FILE *fp;
	fp = fopen("regex.txt", "r");
	if(fp==NULL){
		printf("Can't read file\n");
		return 0;
	}

	char c, buf[80];
    int a = 0;
	while((c=fgetc(fp))!=EOF){
        // printf("%c",c);
		//a*
		if(c == 'a'){
            a++;
            printf("%c",c);
			while((c=fgetc(fp)) =='a'){
                a++;
                printf("%c",c);
            }
            if ( c == ' ' || c == '\n' || c =='\0'){        //a*
                printf("\t:a* \n");
                a = 0;
            }
            else if ( c == 'b'){
                printf("%c",c);
                while((c=fgetc(fp)) =='b')
                    printf("%c",c);
                if ( c == 'a'){
                    printf("%c",c);
                    while((c=fgetc(fp)) =='a')
                        printf("%c",c);
                    if ( c == ' ' || c == '\n'){            //a*b*a*
                        printf("\t:a*b*a* \n");
                        a = 0;
                    }
                    else {
                        a = 0;
                        printf("%c",c);
                        printf("\t:not a*b*a* \n");
                    }

                } else if ( a == 2 && (c == ' ' || c == '\n')){     //aab*
                    printf("\t:aab* %d \n", a );
                    a = 0;


                }
                else {
                    printf("%c",c);
                    printf("\t:not aab* %d \n", a);
                        a = 0;

                }
            }
            else {
                        a = 0;
                printf(" %c",c);
                printf("\t\t\t:not a* \n");
            }
		}

	// 	//a*b*a*
    //     if(c=='a'){
	// 		while((c=fgetc(fp)) =='a')
    //             printf("%c",c);
    //         if ( c == 'b')
    //             while((c=fgetc(fp)) =='b')
    //                 printf("%c",c);
    //             if ( c == 'b'){
    //                 while((c=fgetc(fp)) =='a')
    //                     printf("%c",c);
    //                 if ( c == ' ')
    //                     printf("\t:a*b*a* \n");
    //                 else printf("\t:not a*b*a*\n");
    //             }
	// 	}

    //     //aab*
        
	// 	if(c=='a'){
	// 		if ((c=fgetc(fp)) == 'a'){
    //             while((c=fgetc(fp)) =='b')
    //                 printf("%c",c);
    //             if ( c == ' ')
    //                 printf("\t:aab* \n");
    //             else printf("\t:not aab*\n");
    //         }
	// 	}
    }
    fclose(fp);
    printf("\n\n");
    return 0;
}