#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct word {
    int count;
    char *Word;
} WORD;

WORD *words[100000];
int totalw = 0;

int get_next_word(FILE *F, char *buffer)
{
    int c;
    int len = 0;

    while ((c = fgetc(F)) != EOF) {
        if (isalpha(c)) {
            buffer[len++] = tolower(c);
            break;
        }
    }
    if (c == EOF) return 0;

    while ((c = fgetc(F)) != EOF) {
        if (isalnum(c)) {
            buffer[len++] = tolower(c);
        } 
		else {
            break;
        }
    }

    buffer[len] = '\0';
    return 1;
}

int find_word(const char *w)
{
    for (int i = 0; i < totalw; i++) {
        if (strcmp(words[i]->Word, w) == 0)
            return i;
    }
    return -1;
}

void add_new_word(const char *w)
{
    if (totalw >= 100000) {
        return;
    }
    words[totalw] = (WORD*)malloc(sizeof(WORD));

    words[totalw]->Word = (char*)malloc(strlen(w) + 1);

    strcpy(words[totalw]->Word, w);
    words[totalw]->count = 1;

    totalw++;
}

int cmp_1(const void *a, const void *b)
{
    WORD *w1 = *(WORD**)a;
    WORD *w2 = *(WORD**)b;
    return strcmp(w1->Word, w2->Word);
}

int cmp_2(const void *a, const void *b)
{
    WORD *w1 = *(WORD**)a;
    WORD *w2 = *(WORD**)b;
    return w2->count - w1->count;
}

void print_dictionary(FILE *out)
{
    for (int i = 0; i < totalw; i++) {
        fprintf(out, "%s %d\n", words[i]->Word, words[i]->count);
    }
}


int main(int argc, char *argv[])
{
    FILE *IN, *OUT1, *OUT2;
    char word_buffer[256];

    for (int i = 0; i < 100000; i++)
        words[i] = NULL;

    for (int i = 1; i < argc; i++) {
        IN = fopen(argv[i], "r");
        while (get_next_word(IN, word_buffer)) {
            int idx = find_word(word_buffer);
            if (idx != -1) {
                words[idx]->count++;
            } 
			else {
                add_new_word(word_buffer);
            }
        }
        fclose(IN);
    }

    printf("Total num of unique words: %d\n\n", totalw);


    qsort(words, totalw, sizeof(WORD *), cmp_1);
    OUT1 = fopen("output_1.txt", "w");
    print_dictionary(OUT1);
    fclose(OUT1);

    qsort(words, totalw, sizeof(WORD *), cmp_2);
    OUT2 = fopen("output_2.txt", "w");
    print_dictionary(OUT2);
    fclose(OUT2);

    for (int i = 0; i < totalw; i++) {
        free(words[i]->Word);
        free(words[i]);
    }

    return 0;
}
