#include <stdio.h>

int countDigitOne(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 10 == 1) {
            count++;
        }
        n /= 10;
    }
    return count;
}

int main() {
    int n;

    printf("Input n: ");
    scanf("%d", &n);

    int totalCount = 0;
    for (int i = 0; i <= n; i++) {
        totalCount += countDigitOne(i);
    }
    printf("Output: %d\n", totalCount);

    return 0;
}
