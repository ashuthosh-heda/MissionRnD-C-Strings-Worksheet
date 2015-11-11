/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <stdio.h>

void revStr1(char* str, int len){
	int st = 0;
	int en = len - 1;
	int temp;

	while (st < en){
		temp = str[st];
		str[st] = str[en];
		str[en] = temp;
		st++;
		en--;
	}
}

void str_words_in_rev(char *input, int len){
	revStr1(input, len);
	
	int i = 0;
	int t = 0;

	for (i = 0; i < len; i++){
		if (input[i] == ' '){
			revStr1(&input[t], i - t);
			t = i + 1;
		}
	}
	revStr1(&input[t], i - t);
}
