#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *inp = fopen(argv[1], "r");
    FILE *out = fopen("output.bin", "w");
    
    long long count_A = 0, count_C = 0, count_G = 0, count_T = 0, count_N = 0;

    unsigned long long buffer = 0; 
    int bits_count = 0;

    int c;
    while ((c = fgetc(inp)) != EOF) {
        int val = -1;

        if (c == 'A') { val = 1; count_A++; }
        else if (c == 'C') { val = 2; count_C++; }
        else if (c == 'G') { val = 4; count_G++; }
        else if (c == 'T') { val = 7; count_T++; }
        else if (c == 'N') { val = 0; count_N++; }
        else { continue; }

        if (bits_count + 3 <= 64) { 
            buffer = (buffer << 3) | val;
            bits_count += 3;
        } 
        else {
            
            int space = 64 - bits_count;
            
            int top_bits = val >> (3 - space); 
            buffer = (buffer << space) | top_bits;
            
            fwrite(&buffer, sizeof(unsigned long long), 1, out);
            
            buffer = 0;
            bits_count = 0;
            
            int remaining_bits = 3 - space;
            int mask = (1 << remaining_bits) - 1;
            int bottom_bits = val & mask;
            
            buffer = bottom_bits;
            bits_count = remaining_bits;
        }


        if (bits_count == 64) {
            fwrite(&buffer, sizeof(unsigned long long), 1, out);
            buffer = 0;
            bits_count = 0;
        }
    }

    if (bits_count > 0) {
        buffer = buffer << (64 - bits_count);
        fwrite(&buffer, sizeof(unsigned long long), 1, out);
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
