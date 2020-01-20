#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("numberFile.txt", "r");
    char ch;
    int letter = 0, sign = 0, pos = 0, neg = 0;

    while((ch = fgetc(fp)) != EOF){
        
        if (ch == '-')
            sign = 1;
        else if (sign == 0 && (ch >= 48 && ch <= 57))
            pos++;
        else if (sign == 1 && (ch >= 48 && ch <= 57)){
            neg++;
            sign = 0;
        }
        else sign = 0;
    }

    printf("\nPos:\t%d\nNeg:\t%d\nTot:\t%d\n", pos, neg, (pos + neg));
    fclose(fp);
    return 0;
}