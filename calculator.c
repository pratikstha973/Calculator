#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
void standardOperations();
void userDefinedOperation();

double getNumber(const char *prompt);
int getInt(const char *prompt);

int main() {
    int choice;
    do {
        menu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: standardOperations(); break;
            case 2: userDefinedOperation(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 0);
    return 0;
}

void menu() {
    printf("\n===== Simple Calculator =====\n");
    printf("1. Standard Operations\n");
    printf("2. User-Defined Input Operation\n");
    printf("0. Exit\n");
}

void standardOperations() {
    int op;
    double a, b;
    printf("\n--- Standard Operations ---\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n");
    printf("6. Power\n7. Square Root\n8. Factorial\n9. Sine\n10. Cosine\n");
    printf("Choose operation: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            a = getNumber("Enter first number: ");
            b = getNumber("Enter second number: ");
            printf("Result: %.2lf\n", a + b);
            break;
        case 2:
            a = getNumber("Enter first number: ");
            b = getNumber("Enter second number: ");
            printf("Result: %.2lf\n", a - b);
            break;
        case 3:
            a = getNumber("Enter first number: ");
            b = getNumber("Enter second number: ");
            printf("Result: %.2lf\n", a * b);
            break;
        case 4:
            a = getNumber("Enter numerator: ");
            b = getNumber("Enter denominator: ");
            if (b != 0)
                printf("Result: %.2lf\n", a / b);
            else
                printf("Error: Division by zero.\n");
            break;
        case 5:
            a = getNumber("Enter first integer: ");
            b = getNumber("Enter second integer: ");
            printf("Result: %d\n", (int)a % (int)b);
            break;
        case 6:
            a = getNumber("Enter base: ");
            b = getNumber("Enter exponent: ");
            printf("Result: %.2lf\n", pow(a, b));
            break;
        case 7:
            a = getNumber("Enter number: ");
            if (a >= 0)
                printf("Result: %.2lf\n", sqrt(a));
            else
                printf("Error: Cannot take square root of a negative number.\n");
            break;
        case 8: {
            int n = getInt("Enter a non-negative integer: ");
            if (n < 0) {
                printf("Error: Factorial of negative number doesn't exist.\n");
            } else {
                unsigned long long fact = 1;
                for (int i = 1; i <= n; i++) fact *= i;
                printf("Result: %llu\n", fact);
            }
            break;
        }
        case 9:
            a = getNumber("Enter angle in degrees: ");
            printf("Result: %.2lf\n", sin(a * M_PI / 180));
            break;
        case 10:
            a = getNumber("Enter angle in degrees: ");
            printf("Result: %.2lf\n", cos(a * M_PI / 180));
            break;
        default:
            printf("Invalid operation.\n");
    }
}

void userDefinedOperation() {
    int n;
    double numbers[50];
    printf("\n--- User-Defined Input Operation ---\n");
    do {
        printf("Enter how many numbers (2 to 50): ");
        scanf("%d", &n);
    } while (n < 2 || n > 50);

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &numbers[i]);
    }

    printf("Choose operation:\n");
    printf("1. Add All\n2. Multiply All\n3. Subtract Sequentially\n4. Divide Sequentially\n");
    int op;
    scanf("%d", &op);

    double result = numbers[0];
    switch (op) {
        case 1:
            for (int i = 1; i < n; i++) result += numbers[i];
            printf("Sum: %.2lf\n", result);
            break;
        case 2:
            for (int i = 1; i < n; i++) result *= numbers[i];
            printf("Product: %.2lf\n", result);
            break;
        case 3:
            for (int i = 1; i < n; i++) result -= numbers[i];
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            for (int i = 1; i < n; i++) {
                if (numbers[i] == 0) {
                    printf("Error: Division by zero at element %d\n", i + 1);
                    return;
                }
                result /= numbers[i];
            }
            printf("Result: %.2lf\n", result);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

double getNumber(const char *prompt) {
    double num;
    printf("%s", prompt);
    scanf("%lf", &num);
    return num;
}

int getInt(const char *prompt) {
    int num;
    printf("%s", prompt);
    scanf("%d", &num);
    return num;
}
