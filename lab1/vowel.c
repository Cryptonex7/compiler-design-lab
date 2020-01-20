#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("vowelFile.txt", "r");
    char ch;
    int vowel = 0, consonant = 0;

    while((ch = fgetc(fp)) != EOF){
        
        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' )
            vowel++;
        else if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
            consonant++;
    }

    printf("\nVowel:\t%d\nConsonants:\t%d\n", vowel, consonant);
    fclose(fp);
    return 0;
}