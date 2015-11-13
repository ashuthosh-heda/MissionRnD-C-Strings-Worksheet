/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int strcmp1(char* str1, char* str2){
	int i = 0;
	for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++){
		if (str1[i] != str2[i])
			return -1;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
		return 0;

	return -1;
}

int wordsInString(char** words, char* str){
	int count1 = 0;
	int count2 = 0;
	int prevCount = 0;

	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] != ' '){
			words[count1][count2] = str[i];
			count2++;
			prevCount = count1;
		}
		else{
			words[count1][count2] = '\0';
			if(count2 == 0)
				count1 = prevCount;
			else{
				count1++;
				count2 = 0;
			}
		}
	}
	
	words[count1][count2] = '\0';

	if (count1 == 0){
		return 0;
	}

	return count1 + 1;
}

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;

	char **res = (char**)malloc(SIZE * sizeof(char*));
	for (int i = 0; i < SIZE; i++)
		res[i] = (char*)malloc(SIZE * sizeof(char));
	
	char **wstr1 = (char**)malloc(SIZE * sizeof(char*));
	for (int i = 0; i < SIZE; i++)
		wstr1[i] = (char*)malloc(SIZE * sizeof(char));

	char **wstr2 = (char**)malloc(SIZE * sizeof(char*));
	for (int i = 0; i < SIZE; i++)
		wstr2[i] = (char*)malloc(SIZE * sizeof(char));

	int count1 = wordsInString(wstr1, str1);
	int count2 = wordsInString(wstr2, str2);
	int count = 0;

	for (int i = 0; i < count1; i++){
		for (int j = 0; j < count2; j++){
			if (strcmp1(wstr1[i], wstr2[j]) != -1){
				res[count] = wstr1[i];
				count++;
			}
		}
	}

	free(wstr1);
	free(wstr2);

	if (count == 0){
		return NULL;
	}

	return res;
}