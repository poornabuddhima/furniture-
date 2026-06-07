#include <stdio.h>

#define NUM_SUBJECTS 5

int main() {
    float marks[NUM_SUBJECTS];
    float total = 0.0, percentage;
    int i;
    int failed = 0;

    printf("--- Student Result Analyzer ---\n\n");

    // 1. Input marks for each subject
    for (i = 0; i < NUM_SUBJECTS; i++) {
        printf("Enter marks for Subject %d (out of 100): ", i + 1);
        if (scanf("%f", &marks[i]) != 1 || marks[i] < 0 || marks[i] > 100) {
            printf("Invalid input! Marks must be between 0 and 100.\n");
            return 1; // Exit program on invalid input
        }

        // Cumulative total
        total += marks[i];

        // Check for individual subject failure (passing mark assumed to be 40)
        if (marks[i] < 40) {
            failed++;
        }
    }

    // 2. Calculations
    percentage = (total / (NUM_SUBJECTS * 100)) * 100;

    // 3. Display Results Summary
    printf("\n=============================\n");
    printf("       RESULT SUMMARY        \n");
    printf("=============================\n");
    printf("Total Marks Obtained: %.2f / %d\n", total, NUM_SUBJECTS * 100);
    printf("Percentage:           %.2f%%\n", percentage);

    // 4. Determine Grade and Pass/Fail Status
    printf("Final Status:         ");
    if (failed > 0) {
        printf("FAILED (%d subject(s) below passing score of 40)\n", failed);
        printf("Grade:                F\n");
    } else {
        printf("PASSED\n");

        // Grade allocation based on percentage
        if (percentage >= 90) {
            printf("Grade:                A+ (Excellent)\n");
        } else if (percentage >= 80) {
            printf("Grade:                A (Very Good)\n");
        } else if (percentage >= 70) {
            printf("Grade:                B (Good)\n");
        } else if (percentage >= 60) {
            printf("Grade:                C (Above Average)\n");
        } else if (percentage >= 50) {
            printf("Grade:                D (Pass)\n");
        } else {
            printf("Grade:                E (Just Passed)\n");
        }
    }
    printf("=============================\n");

    return 0;
}
