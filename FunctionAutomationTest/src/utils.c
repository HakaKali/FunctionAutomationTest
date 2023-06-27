#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to test: add()
int add(int a, int b) {
    return a + b;
}

void create_test_cases_file() {
    FILE* file = fopen("test_cases.txt", "w");
    if (file == NULL) {
        printf("Failed to create the file.\n");
        return;
    }

    srand(time(NULL));

    for (int i = 1; i <= 100; i++) {
        int a = rand() % 100;  // Random number between 0 and 99
        int b = rand() % 100;  // Random number between 0 and 99

        fprintf(file, "%d. Test case: add(%d, %d)\n", i, a, b);
        fprintf(file, "Expected: %d\n\n", add(a, b));
    }

    fclose(file);
    //printf("Test cases file created successfully.\n");
}

void run_test_cases() {
    FILE* inputFile = fopen("test_cases.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return;
    }

    FILE* outputFile = fopen("test_results.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to create the output file.\n");
        fclose(inputFile);
        return;
    }

    char line[100];
    int numTestCases = 0;
    int numErrors = 0;
    int failedCases[100];
    int failedIndex = 0;

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        int a, b, expected;

        sscanf(line, "%d. Test case: add(%d, %d)", &numTestCases, &a, &b);

        fgets(line, sizeof(line), inputFile);
        sscanf(line, "Expected: %d", &expected);

        int result = add(a, b);

        fprintf(outputFile, "%d. Test case: add(%d, %d)\n", numTestCases, a, b);
        fprintf(outputFile, "Expected: %d\n", expected);
        fprintf(outputFile, "Result: %d", result);

        if (result != expected) {
            fprintf(outputFile, " [FAILED]\n");
            numErrors++;
            failedCases[failedIndex] = numTestCases;
            failedIndex++;
        } else {
            fprintf(outputFile, " [PASSED]\n");
        }

        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    int numPassed = numTestCases - numErrors;
    double score = (double)numPassed / numTestCases * 100;

    printf("Total test cases: %d\n", numTestCases + 1);
    printf("Errors: %d\n", numErrors);
    printf("Test Score: %.2f\n", score);

    if (numErrors > 0) {
        printf("Failed Test Cases: ");
        for (int i = 0; i < failedIndex; i++) {
            printf("%d ", failedCases[i]);
        }
        printf("\n");
    }

    //printf("Test results written to test_results.txt.\n");
}
