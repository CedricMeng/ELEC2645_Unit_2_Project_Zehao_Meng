#include <stdio.h>
#include <math.h>
#include "Unit_transfer.h"

double convert_power() {
    int direction;
    double value;

    printf("\n=== Power Converter ===\n");
    printf("Select conversion:\n");
    printf("1. dBm to mW\n");
    printf("2. mW to dBm\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &direction);

    printf("Enter value to convert: ");
    scanf("%lf", &value);

    if (direction == 1) {
        double result = pow(10.0, value / 10.0);
        printf("%.2f dBm = %.4f mW\n", value, result);
        return result;
    } else if (direction == 2) {
        if (value <= 0.0) {
            printf("Error: Power must be positive\n");
            return -1.0;
        }
        double result = 10.0 * log10(value);
        printf("%.4f mW = %.2f dBm\n", value, result);
        return result;
    } else {
        printf("Invalid input!\n");
        return 0.0;
    }
}

double convert_frequency() {
    int direction;
    double value;

    printf("\n=== Frequency Converter ===\n");
    printf("Select conversion:\n");
    printf("1. Hz to rad/s\n");
    printf("2. rad/s to Hz\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &direction);

    printf("Enter value to convert: ");
    scanf("%lf", &value);

    const double pi = 3.141592653589793;

    if (direction == 1) {
        double result = 2*pi * value;
        printf("%.2f Hz = %.4f rad/s\n", value, result);
        return result;
    } else if (direction == 2) {
        double result = value / 2*pi;
        printf("%.4f rad/s = %.4f Hz\n", value, result);
        return result;
    } else {
        printf("Invalid input!\n");
        return 0.0;
    }
}