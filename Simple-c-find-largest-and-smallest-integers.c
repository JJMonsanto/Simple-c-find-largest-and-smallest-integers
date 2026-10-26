#include <stdio.h>

int findLargest(int a, int b, int c);
int findSmallest(int a, int b, int c);

int main(void) {
    int num1, num2, num3;
    int largest, smallest;

    printf("Enter three integers: ");
    if (3 != scanf("%d %d %d", &num1, &num2, &num3)) {
        printf("Invalid input. Please enter integer values.\n");
        return 1;
    }

    largest = findLargest(num1, num2, num3);
    smallest = findSmallest(num1, num2, num3);

    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);

    return 0;
}

int findLargest(int a, int b, int c) {
    int max;
    max = a;

    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    return max;
}

int findSmallest(int a, int b, int c) {
    int min;
    min = a;

    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }

    return min;
}
