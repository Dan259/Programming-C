#include <stdio.h>

const char *UP[] = {"A","B","V","G","D","E","Zh","Z","I","Y","K","L","M","N","O","P",
                    "R","S","T","U","F","Kh","Ts","Ch","Sh","Sch","","Y","","E","Yu","Ya"};
const char *LO[] = {"a","b","v","g","d","e","zh","z","i","y","k","l","m","n","o","p",
                    "r","s","t","u","f","kh","ts","ch","sh","sch","","y","","e","yu","ya"};

int main(int argc, char *argv[]) {
    if (argc < 2) { printf("Использование: %s файл.txt\n", argv[0]); return 1; }
    
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen("translit.txt", "w");
    int c, word_len = 0;
    
    while ((c = fgetc(in)) != EOF) {
        if (c >= 0xC0 && c <= 0xDF) {
            fprintf(out, "%s", UP[c - 0xC0]);
            word_len++;
        }
        else if (c >= 0xE0 && c <= 0xFF) {
            fprintf(out, "%s", LO[c - 0xE0]);
            word_len++;
        }
        else if (c == 0xA8) { fprintf(out, "Yo"); word_len++; }
        else if (c == 0xB8) { fprintf(out, "yo"); word_len++; }
        else {
            if (word_len > 0) {
                fprintf(out, " %d\n", word_len);
                word_len = 0;
            }
        }
    }
    if (word_len > 0) fprintf(out, " %d\n", word_len);
    
    fclose(in);
    fclose(out);
    return 0;
}
