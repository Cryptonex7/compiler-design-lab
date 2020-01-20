#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("vowelFile.txt", "r");
    char ch;
    int letter = 0, word = 0, space = 0, splChar = 0;

    while((ch = fgetc(fp)) != EOF){
        
        if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
            letter++;
        else if (ch == ' '){
            word++;
            space++;
        } else if ((ch == ',' || ch == '.' || ch == ':')){
            word++;
            splChar++;
        } else splChar++;
    }

    printf("\nWords:\t%d\nChars:\t%d\nSpaces:\t%d\n", word, (letter + splChar), space);
    fclose(fp);
    return 0;
}