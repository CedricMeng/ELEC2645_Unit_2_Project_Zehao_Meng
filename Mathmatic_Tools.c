#include <stdio.h>
#include <math.h>

void basicCalculator() {
    double num1, num2, result;
    char op;

    printf("\n=== BASIC CALCULATOR (+, -, *, /) ===\n");
    printf("Enter expression (e.g., 3.5 + 4.2): ");
    scanf("%lf %c %lf", &num1, &op, &num2);

    switch (op) {
        case '+':
            result = num1 + num2;
            printf("Result: %.4f + %.4f = %.4f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.4f - %.4f = %.4f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.4f * %.4f = %.4f\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
                return;
            }
            result = num1 / num2;
            printf("Result: %.4f / %.4f = %.4f\n", num1, num2, result);
            break;
        default:
            printf("Error: Invalid operator! Only +, -, *, / are supported.\n");
    }
}

void numericalRootFinder() {
    double num, guess = 1.0;
    int root_order;
    const double tol = 1e-8;  // Convergence tolerance
    const int max_iter = 100; // Max iteration times
    double prev_guess;
    int iter = 0;

    printf("\n=== NUMERICAL ROOT FINDER ===\n");
    printf("Calculate n-th root of a number\n");

    printf("Enter the number: ");
    while (scanf("%lf", &num) != 1) {
        printf("Error: Invalid input! Enter a number: ");
        // Clear input buffer
        while (getchar() != '\n');
    }

    printf("Enter root order (positive integer): ");
    while (scanf("%d", &root_order) != 1 || root_order <= 0) {
        printf("Error: Enter a positive integer: ");
        while (getchar() != '\n');
    }

    if (fabs(num) < tol) {
        printf("√%d(%.4f) = 0.000000\n", root_order, num);
        return;
    }

    if (num < 0 && root_order % 2 == 0) {
        printf("Error: Negative number has no real even root!\n");
        return;
    }

    do {
        prev_guess = guess;
        guess = prev_guess - (pow(prev_guess, root_order) - num) / (root_order * pow(prev_guess, root_order - 1));
        iter++;
    } while (fabs(guess - prev_guess) > tol && iter < max_iter);

    // Output result
    printf("root of (%.4f) is %.6f\n", num, guess);
}