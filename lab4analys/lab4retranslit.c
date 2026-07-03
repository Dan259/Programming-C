#include <stdio.h>
#include <string.h>
#include <ctype.h>

int match(const char *s, const char *pattern) {
    int len = strlen(pattern);
    for (int i = 0; i < len; i++)
        if (tolower(s[i]) != pattern[i]) return 0;
    return len;
}

int main(int argc, char *argv[]) {
    if (argc < 2) { printf("Использование: %s translit.txt\n", argv[0]); return 1; }
    
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen("russian.txt", "w");
    char line[1000];
    
    while (fgets(line, sizeof(line), in)) {
        int i = 0;
        while (line[i] == ' ') i++;
        
        int start = i;
        while (line[i] && line[i] != ' ' && line[i] != '\n') i++;
        line[i] = '\0';
        
        if (i == start) { fprintf(out, "\n"); continue; }
        
        char *w = line + start;
        int j = 0;
        while (w[j]) {
            int len = 0;
            int is_up = isupper(w[j]);
            
            if      ((len = match(w+j, "sch"))) fprintf(out, is_up ? "Щ" : "щ");
            else if ((len = match(w+j, "zh")))  fprintf(out, is_up ? "Ж" : "ж");
            else if ((len = match(w+j, "kh")))  fprintf(out, is_up ? "Х" : "х");
            else if ((len = match(w+j, "ts")))  fprintf(out, is_up ? "Ц" : "ц");
            else if ((len = match(w+j, "ch")))  fprintf(out, is_up ? "Ч" : "ч");
            else if ((len = match(w+j, "sh")))  fprintf(out, is_up ? "Ш" : "ш");
            else if ((len = match(w+j, "yu")))  fprintf(out, is_up ? "Ю" : "ю");
            else if ((len = match(w+j, "ya")))  fprintf(out, is_up ? "Я" : "я");
            else if ((len = match(w+j, "yo")))  fprintf(out, is_up ? "Ё" : "ё");
            else {
                switch(tolower(w[j])) {
                    case 'a': fprintf(out, is_up ? "А" : "а"); break;
                    case 'b': fprintf(out, is_up ? "Б" : "б"); break;
                    case 'v': fprintf(out, is_up ? "В" : "в"); break;
                    case 'g': fprintf(out, is_up ? "Г" : "г"); break;
                    case 'd': fprintf(out, is_up ? "Д" : "д"); break;
                    case 'e': fprintf(out, is_up ? "Е" : "е"); break;
                    case 'z': fprintf(out, is_up ? "З" : "з"); break;
                    case 'i': fprintf(out, is_up ? "И" : "и"); break;
                    case 'y': fprintf(out, is_up ? "Ы" : "ы"); break;
                    case 'k': fprintf(out, is_up ? "К" : "к"); break;
                    case 'l': fprintf(out, is_up ? "Л" : "л"); break;
                    case 'm': fprintf(out, is_up ? "М" : "м"); break;
                    case 'n': fprintf(out, is_up ? "Н" : "н"); break;
                    case 'o': fprintf(out, is_up ? "О" : "о"); break;
                    case 'p': fprintf(out, is_up ? "П" : "п"); break;
                    case 'r': fprintf(out, is_up ? "Р" : "р"); break;
                    case 's': fprintf(out, is_up ? "С" : "с"); break;
                    case 't': fprintf(out, is_up ? "Т" : "т"); break;
                    case 'u': fprintf(out, is_up ? "У" : "у"); break;
                    case 'f': fprintf(out, is_up ? "Ф" : "ф"); break;
                    default:  fputc(w[j], out);
                }
                len = 1;
            }
            j += len;
        }
        fprintf(out, "\n");
    }
    
    fclose(in);
    fclose(out);
    return 0;
}
