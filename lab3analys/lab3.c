#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct tnode {
    char author[256];
    char title[256];
    char publisher[256];
    int year;
    struct tnode *left;
    struct tnode *right;
} TNODE;

void free_tree(TNODE *node){
    if (node == NULL) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

void print_tree(TNODE *node, FILE *out){
    if (node == NULL) return;
    
    print_tree(node->left, out);
    
    fprintf(out, "%s | %s | %s | %d\n",
            node->author, node->title, node->publisher, node->year);
    
    print_tree(node->right, out);
}

TNODE* find_by_prefix(TNODE *node, const char *prefix){
    if (node == NULL) return NULL;
    int cmp = strncmp(node->author, prefix, 5);

    if (cmp == 0) {
        return node;
    }

    if (cmp > 0) {
        return find_by_prefix(node->left, prefix);
    }
    else {
        return find_by_prefix(node->right, prefix);
    }
}

TNODE* insert(TNODE *node, const char *author, const char *title, 
              const char *publisher, int year){
    if (node == NULL) {
        node = (TNODE*)malloc(sizeof(TNODE));
        strncpy(node->author, author, sizeof(node->author) - 1);
        node->author[sizeof(node->author) - 1] = '\0';
        
        strncpy(node->title, title, sizeof(node->title) - 1);
        node->title[sizeof(node->title) - 1] = '\0';
        
        strncpy(node->publisher, publisher, sizeof(node->publisher) - 1);
        node->publisher[sizeof(node->publisher) - 1] = '\0';
        
        node->year = year;
        node->left = NULL;
        node->right = NULL;
        
        return node;
    }

    int cmp = strcmp(author, node->author);
    if (cmp == 0) {
        cmp = strcmp(title, node->title);
    }

    if (cmp < 0) {
        node->left = insert(node->left, author, title, publisher, year);
    }
    else if (cmp > 0) {
        node->right = insert(node->right, author, title, publisher, year);
    }

    return node;
}

void read_bib_file(const char *filename, TNODE **root){
    FILE *f = fopen(filename, "r");

    char line[1024];
    char author[256] = "";
    char title[256] = "";
    char publisher[256] = "";
    int year = 0;
    int in_entry = 0;

    while (fgets(line, sizeof(line), f) != NULL) {
        char *p = line;
        while (*p && isspace(*p)) p++;

        if (p[0] == '@') {
            if (in_entry && strlen(author) > 0 && strlen(title) > 0) {
                *root = insert(*root, author, title, publisher, year);
            }
            author[0] = title[0] = publisher[0] = '\0';
            year = 0;
            in_entry = 1;
            continue;
        }

        if (!in_entry) continue;

        if (strstr(p, "author") != NULL) {
            char *start = strchr(p, '{');
            if (start) {
                start++;
                char *end = strchr(start, '}');
                if (end) {
                    *end = '\0';
                    strncpy(author, start, sizeof(author) - 1);
                    author[sizeof(author) - 1] = '\0';
                }
            }
        }
        else if (strstr(p, "title") != NULL) {
            char *start = strchr(p, '{');
            if (start) {
                start++;
                char *end = strchr(start, '}');
                if (end) {
                    *end = '\0';
                    strncpy(title, start, sizeof(title) - 1);
                    title[sizeof(title) - 1] = '\0';
                }
            }
        }
        else if (strstr(p, "publisher") != NULL) {
            char *start = strchr(p, '{');
            if (start) {
                start++;
                char *end = strchr(start, '}');
                if (end) {
                    *end = '\0';
                    strncpy(publisher, start, sizeof(publisher) - 1);
                    publisher[sizeof(publisher) - 1] = '\0';
                }
            }
        }
        else if (strstr(p, "year") != NULL) {
            char *start = strchr(p, '{');
            if (start) {
                start++;
                year = atoi(start);
            }
        }
    }

    if (in_entry && strlen(author) > 0 && strlen(title) > 0) {
        *root = insert(*root, author, title, publisher, year);
    }

    fclose(f);
}
int main(int argc, char *argv[])
{
    TNODE *root = NULL;
    FILE *out;
    char prefix[256];

    for (int i = 1; i < argc; i++) {
        read_bib_file(argv[i], &root);
    }

    out = fopen("output.txt", "w");
    
    print_tree(root, out);
    fclose(out);

    printf("Enter first 5 symbols of author surname: ");
    if (scanf("%s", prefix) == 1) {
        TNODE *found = find_by_prefix(root, prefix);
        if (found != NULL) {
            printf("  Author: %s\n", found->author);
            printf("  Title: %s\n", found->title);
            printf("  Publisher: %s, %d год\n", found->publisher, found->year);
        }
    }

    free_tree(root);
    return 0;
}
