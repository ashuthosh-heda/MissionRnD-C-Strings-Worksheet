/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include <stdio.h>

char removeSpaces(char *str) {
	if (str == NULL || str == "")
		return '\0';

	int i = 0;
	int t = 0;

	for (i = 0; str[i] != '\0'; i++){
		if (str[i] != ' '){
			str[t] = str[i];
			t++;
		}
	}
	str[t] = '\0';

	return 0;
}