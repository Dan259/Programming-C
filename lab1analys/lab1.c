#include <stdio.h>
#include <ctype.h>
int isvowel(int c);

int main()
{
    FILE *F;
    int c;
    char filename[256];
    
    int total = 0;
    int lines = 0;
    int digits = 0; 
    int puncts = 0;
    int spaces = 0;  
    int letters = 0; 
    int lowers = 0; 
    int uppers = 0;  
    int vowels = 0; 
    int cons = 0; 

    printf("Enter filename: ");
    scanf("%s", filename);

    F = fopen(filename, "r");

    while ((c = fgetc(F)) != EOF) {
        total++;

        if (c == '\n') {
            lines++;
        }

        if (isdigit(c)) {
            digits++;
        }

        if (ispunct(c)) {
            puncts++;
        }

        if (isspace(c)) {
            spaces++;
        }

        if (isalpha(c)) {
            letters++;
            
            if (islower(c)) {
                lowers++;
            }
            if (isupper(c)) {
                uppers++;
            }
            
            if (isvowel(c)) {
                vowels++;
            } 
			else {
                cons++;
            }
        }
    }

    fclose(F);

    printf("Total symbols:          %d\n", total);
    printf("Line numbers:           %d\n", lines);
    printf("Digit numbers:          %d\n", digits);
    printf("Puctuation marks:       %d\n", puncts);
    printf("Spaces:                 %d\n", spaces);
    printf("Total letters:          %d\n", letters);
    printf("Lower letters:          %d\n", lowers);
    printf("Upper letters:          %d\n", uppers);
    printf("Vowel:                  %d\n", vowels);
    printf("Consonants:             %d\n", cons);
    return 0;
}

int isvowel(int c)
{
    switch(tolower(c))
    {
        case 'a': 
        case 'e':
        case 'i': 
        case 'o': 
        case 'u': 
        	return 1;
    }
    return 0;
}
