#include <stdio.h>
#include <regex.h>
#include <string.h>

int main() {
    FILE *fp;
    fp = fopen("vowelFile.txt", "r");
    char ch;
    int identifier = 0, word = 0, space = 0, splChar = 0;
    regex_t regex;

    int match = regcomp(&regex, "[a-zA-Z]", 0);

    

    // while((ch = fgetc(fp)) != EOF){
    //     if ( ftell(fp) == 1 && !regexec(&regex, ch, 0, NULL, 0))
    //         printf("%c", ch);
    //     if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
    //         identifier++;
    //     else if (ch == ' '){
    //         word++;
    //         space++;
    //     } else if ((ch == ',' || ch == '.' || ch == ':')){
    //         word++;
    //         splChar++;
    //     } else splChar++;
    // }

    char buf[30];
    while( fscanf(fp, "%s", buf) != EOF ){
        
        if (strcmp(buf, "printf") == 0 || strcmp(buf, "scanf") == 0) {
            puts("Match");
            printf("\t%s\n", buf);
        }
        else {
            puts("No match");
        }
        
    }

    // printf("\nWords:\t%d\nChars:\t%d\nSpaces:\t%d\n", word, (letter + splChar), space);
    fclose(fp);
    return 0;
}