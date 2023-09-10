#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int att[30];
	int s = 0;
	for (int i = 0; i < 30; i++) {
		att[i] = i + 1;
	}

	for (int i = 0; i < 28; i++) {
		scanf("%d", &s);
		for (int j = 0; j < 30; j++) {
			if (att[j] == s) att[j] = 0;
		}
	}

	for (int k = 0; k < 30; k++) {
		if (att[k] != 0) printf("%d\n", att[k]);
	}
}