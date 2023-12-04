#include <stdio.h>
#include <string.h>

int lengthOfLastWord(const char* s) {
    int length = 0;
    int i = strlen(s) - 1;

    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    char input[100]; 

    printf("Input s: ");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    int result = lengthOfLastWord(input);
    printf("Output: %d\n", result);

    return 0;
}
