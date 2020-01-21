#include<stdio.h>

int main(){
    printf("\n\n");

	FILE *fp;
	fp = fopen("file.txt", "r");
	if(fp==NULL){
		printf("Can't read file\n");
		return 0;
	}

	char c, buf[80];
	while((c=fgetc(fp))!=EOF){
		//exception handling
		if(c=='\"'){
			while((c=fgetc(fp))!='\"')
				continue;
		}

		//main code
		if(c=='/'){
			c=fgetc(fp);
			if(c=='/'){
                fgets(buf, 80, fp);
                printf("%s", buf);
            }
			else if(c=='*'){
				while(1){
					c=fgetc(fp);
					//break condition
					if(c=='*'){
						c=fgetc(fp);
						if(c=='/')
							break;
					}
					printf("%c",c);
				}
			}
		}
	}
    fclose(fp);
    printf("\n\n");
    return 0;
}