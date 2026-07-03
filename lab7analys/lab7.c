#include <stdio.h>
#include <stdlib.h>

int get_dna_code(char c) {
    switch (c) {
        case 'N': return 0;
        case 'A': return 1;
        case 'C': return 2;
        case 'G': return 4;
        case 'T': return 7;
        default:  return -1;
    }
}

int main(int argc, char *argv[]) {
    FILE *inp = fopen(argv[1], "r");
    FILE *out = fopen("output.bin", "wb"); 

    long long count_A = 0, count_C = 0, count_G = 0, count_T = 0, count_N = 0;
    long long int buffer = 0; 
    int bits_count = 0;
    int c;

    while ((c = fgetc(inp)) != EOF) {
        int val = get_dna_code(c);
    
        if (val == -1) continue; 

        if (c == 'A') count_A++;
        else if (c == 'C') count_C++;
        else if (c == 'G') count_G++;
        else if (c == 'T') count_T++;
        else if (c == 'N') count_N++;

        buffer |= ((long long int)val << bits_count);
        bits_count += 3;

        if (bits_count == 63) {
            fwrite(&buffer, sizeof(long long int), 1, out);
            buffer = 0;
            bits_count = 0;
        }
    }

    if (bits_count > 0) {
        fwrite(&buffer, sizeof(long long int), 1, out);
    }

    fclose(inp);
    fclose(out);

    printf("Statistic:\n");
    printf("A: %lld\n", count_A);
    printf("C: %lld\n", count_C);
    printf("G: %lld\n", count_G);
    printf("T: %lld\n", count_T);
    printf("N: %lld\n", count_N);
    printf("Total: %lld\n", count_A + count_C + count_G + count_T + count_N);

    return 0;
}
