#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibonacci(int v ) {
    if (v<= 1) {
        return v;
    } else {
        return fibonacci(v - 1) + fibonacci(v- 2);
    }
}

int main() {
    int n, i;

    // Ask user for the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Print Fibonacci series up to n terms
    printf("Fibonacci series up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
