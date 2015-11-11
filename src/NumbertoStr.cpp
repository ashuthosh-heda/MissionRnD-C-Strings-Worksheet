/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void strrev1(char* str, int len){
	int st, end, temp;
	st = 0;
	end = len - 1;
	while (st < end){
		temp = str[st];
		str[st] = str[end];
		str[end] = temp;
		st++;
		end--;
	}
}

int inttostr1(int num, char* str, int afterdecimal){
	int i = 0;
	int temp = num;

	if (temp < 0){
		temp = -num;
	}

	while (temp){
		str[i] = (temp % 10) + '0';
		i++;
		temp = temp / 10;
	}

	if (num < 0)
		str[i++] = '-';

	strrev1(str, i);
	str[i] = '\0';
	return i;
}

int pow1(int num, int pow){
	int res = 1;
	for (int i = 0; i < pow; i++){
		res = res * num;
	}
	return res;
}

void number_to_str(float number, char *str,int afterdecimal){
	int in = (int)number;

	float fl = number - (float)in;

	int i = inttostr1(in,str,afterdecimal);

	if (afterdecimal != 0){
		str[i] = '.';

		if (fl < 0)
			fl = -fl;

		fl = fl * pow1(10, afterdecimal);

		inttostr1((int)fl, str + i + 1, afterdecimal);
	}
}
