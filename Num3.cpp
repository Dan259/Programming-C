#include <stdio.h>
#include <string.h>
char str[80];

int main(void)
{
	printf("Enter letter: ");
	scanf("%s",&str);
	str[80] = '\0';
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == 'a')
		{
			str[i] = 'A';
		}
		if(str[i] == 'b')
		{
			str[i] = 'B';
		}
	}
	printf("%s",str);
}
