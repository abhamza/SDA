#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const size_t BUFFER_SIZE = 2048;

static void freeBuffers(char** words, char** definitions, size_t numWords) {
    for (size_t i = 0; i < numWords; i++) {
        free(words[i]);
        free(definitions[i]);
    }

    free(words);
    free(definitions);
}

int main(void) {
    size_t numWords = 0;
    size_t size = 0;
    char** words = NULL;            // List of words
    char** definitions = NULL;      // List of definitions
    char** tmp;

    // Read words and definitions from file
    FILE* fd = fopen("dico.txt", "r");
    if (fd == NULL) {
        return -1;
    }

    char buffer[BUFFER_SIZE];
    char buffer_word[BUFFER_SIZE];
    char buffer_definition[BUFFER_SIZE];

    while (fgets(buffer, sizeof(buffer), fd) != NULL) {
        // Scan word + definition
        sscanf(buffer, "%s\t%[^\n]", buffer_word, buffer_definition);

        // Allocate memory and copy
        char* word = malloc((strlen(buffer_word) + 1) * sizeof(char));
        if (word == NULL) {
            freeBuffers(words, definitions, numWords);
            fclose(fd);
            return -1;
        } else {
            strcpy(word, buffer_word);
        }

        char* definition = malloc((strlen(buffer_definition) + 1) * sizeof(char));
        if (word == NULL) {
            freeBuffers(words, definitions, numWords);
            free(word);
            fclose(fd);
            return -1;
        } else {
            strcpy(definition, buffer_definition);
        }

        // Resize lists if needed
        if (numWords >= size) {
            if (size == 0) {
                size = 64;
            } else {
                size *= 2;
            }

            tmp = realloc(words, size * sizeof(char*));
            if (tmp == NULL){
                freeBuffers(words, definitions, numWords);
                free(word);
                free(definition);
                fclose(fd);
                return -1;
            } else {
                words = tmp;
            }

            tmp = realloc(definitions, size * sizeof(char*));
            if (tmp == NULL){
                freeBuffers(words, definitions, numWords);
                free(word);
                free(definition);
                fclose(fd);
                return -1;
            } else {
                definitions = tmp;
            }
        }

        // Append the word/definition pair
        words[numWords] = word;
        definitions[numWords] = definition;
        numWords++;
    }

    fclose(fd);

    // Do things (using words and definitions lists)
    // ...

    // Free resources
    freeBuffers(words, definitions, numWords);

    return 0;
}
