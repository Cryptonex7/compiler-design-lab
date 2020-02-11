#include <stdio.h>
#include <ctype.h>
#include <string.h>

void followfirst(char, int, int);
void follow(char c);
void findfirst(char, int, int);

int count, n = 0, m = 0, k, e;
char first_i[10][100], follow_i[10][100], P[10][10], f[10], first[10], ck;

int main(){
	int jm = 0, km = 0, i, choice, ptr = -1, kay;
	count = 7;
	char c, ch, done[count];

	strcpy(P[0], "E=TX");
	strcpy(P[1], "X=+TX");
	strcpy(P[2], "X=#");
	strcpy(P[3], "T=FY");
	strcpy(P[4], "Y=*FY");
	strcpy(P[5], "F=(E)");
	strcpy(P[6], "F=!");

	for (k = 0; k < count; k++)
		for (kay = 0; kay < 100; kay++)
			first_i[k][kay] = '!';
	int point1 = 0, point2, xxx;

	for (k = 0; k < count; k++){
		c = P[k][0];
		point2 = 0;
		xxx = 0;

		for (kay = 0; kay <= ptr; kay++)
			if (c == done[kay])
				xxx = 1;

		if (xxx == 1)
			continue;

		findfirst(c, 0, 0);
		ptr += 1;

		done[ptr] = c;
		printf("\n First(%c) = { ", c);
		first_i[point1][point2++] = c;

		for (i = 0 + jm; i < n; i++){
			int lark = 0, chk = 0;
			for (lark = 0; lark < point2; lark++)
				if (first[i] == first_i[point1][lark]){
					chk = 1;
					break;
				}
			if (chk == 0){
				printf("%c, ", first[i]);
				first_i[point1][point2++] = first[i];
			}
		}
		printf("}\n");
		jm = n;
		point1++;
	}
	printf("\n\n");
	char donee[count];
	ptr = -1;

	for (k = 0; k < count; k++)
		for (kay = 0; kay < 100; kay++)
			follow_i[k][kay] = '!';
	point1 = 0;
	int land = 0;
	for (e = 0; e < count; e++){
		ck = P[e][0];
		point2 = 0;
		xxx = 0;

		for (kay = 0; kay <= ptr; kay++)
			if (ck == donee[kay])
				xxx = 1;

		if (xxx == 1)
			continue;
		land += 1;

		follow(ck);
		ptr += 1;

		donee[ptr] = ck;
		printf(" Follow(%c) = { ", ck);
		follow_i[point1][point2++] = ck;

		for (i = 0 + km; i < m; i++){
			int lark = 0, chk = 0;
			for (lark = 0; lark < point2; lark++)
				if (f[i] == follow_i[point1][lark]){
					chk = 1;
					break;
				}
			if (chk == 0){
				printf("%c, ", f[i]);
				follow_i[point1][point2++] = f[i];
			}
		}
		printf(" }\n\n");
		km = m;
		point1++;
	}
}

void follow(char c){
	int i, j;

	if (P[0][0] == c)
		f[m++] = '$';

	for (i = 0; i < 10; i++)
		for (j = 2; j < 10; j++)
			if (P[i][j] == c){
				if (P[i][j + 1] != '\0')
					followfirst(P[i][j + 1], i, (j + 2));

				if (P[i][j + 1] == '\0' && c != P[i][0])
					follow(P[i][0]);
			}
}

void findfirst(char c, int q1, int q2){
	int j;

	if (!(isupper(c)))
		first[n++] = c;
	for (j = 0; j < count; j++)
		if (P[j][0] == c)
			if (P[j][2] == '#')
				if (P[q1][q2] == '\0')
					first[n++] = '#';
				else if (P[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
					findfirst(P[q1][q2], q1, (q2 + 1));
				else
					first[n++] = '#';
			else if (!isupper(P[j][2]))
				first[n++] = P[j][2];
			else
				findfirst(P[j][2], j, 3);
}

void followfirst(char c, int c1, int c2){
	int k;

	if (!(isupper(c)))
		f[m++] = c;
	else{
		int i = 0, j = 1;
		for (i = 0; i < count; i++)
			if (first_i[i][0] == c)
				break;

		while (first_i[i][j] != '!')
		{
			if (first_i[i][j] != '#')
				f[m++] = first_i[i][j];
			else
				if (P[c1][c2] == '\0')
					follow(P[c1][0]);
				else
					followfirst(P[c1][c2], c1, c2 + 1);
			j++;
		}
	}
}
