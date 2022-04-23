#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	char s[11], ts[11];
} P;

int cmpP(const P *a, const P *b) {
	if (strcmp(a->ts, b->ts) < 0) return -1;
	else if (strcmp(a->ts, b->ts) == 0) return 0;
	else return 1;
}

int main() {
	char str[30];
	scanf("%s", str);

	int num[26];
	for (int i = 0;i < 26;i++) {
		char target = 'a' + i;
		for (int j = 0;j < strlen(str);j++) {
			if (str[j] == target) num[i] = j;
		}
	}

	int n;
	scanf("%d", &n);

	P s[50005];
	char input[11];
	for (int i = 0;i < n;i++) {
		scanf("%s", input);
		strcpy(s[i].s, input);
		for (int j = 0;j <= strlen(input);j++) {
			if (input[j] == '\0') s[i].ts[j] = '\0';
			else s[i].ts[j] = num[input[j] - 'a'] + 'a';
		}
	}
	
	qsort(s, n, sizeof(P), cmpP);

	for (int i = 0;i < n;i++) printf("%s\n", s[i].s);

	return 0;
}