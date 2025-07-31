/*
    S12A  
	Cabrera, James    <- specs from here
	Cardino, Joaquin
*/

#include <stdio.h>
#include <stdlib.h>

extern void acc(float* data, int* results, int rows);

int main() {
    int rows;

    // Ask user for number of cars to test
    printf("How many cars do you want to test? ");
    scanf_s("%d", &rows);

    if (rows <= 0) {
        printf("Invalid number of cars. Please enter a positive number.\n");
        return 1;
    }

    // Allocate memory for data and results
    float* data = (float*)malloc(sizeof(float) * 3 * rows);
    int* results = (int*)malloc(sizeof(int) * rows);

    if (!data || !results) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get input data from user for each car
    printf("\nEnter data for each car:\n");
    for (int i = 0; i < rows; i++) {
        printf("\nCar %d:\n", i + 1);
        printf("  Initial velocity (km/h): ");
        scanf_s("%f", &data[i * 3 + 0]);

        printf("  Final velocity (km/h): ");
        scanf_s("%f", &data[i * 3 + 1]);

        printf("  Time (seconds): ");
        scanf_s("%f", &data[i * 3 + 2]);
    }

    // Call the assembly function
    acc(data, results, rows);

    // Display results
    printf("\n--- Acceleration Results ---\n");
    for (int i = 0; i < rows; i++) {
        printf("Car %d: %d m/s^2\n", i + 1, results[i]);
    }

    // Free allocated memory
    free(data);
    free(results);

    return 0;
}


/*  USED FOR TESTING 30 RANDOM TEST CASES
    Needed for AVG run time
 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void acc(float* data, int* results, int rows);

int main() {
    int rows = 5000;
    int num_runs = 30;
    double total_time = 0.0;

    float* data = (float*)malloc(sizeof(float) * 3 * rows);
    int* results = (int*)malloc(sizeof(int) * rows);

    if (!data || !results) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Fill the data array with random values (once)
    srand((unsigned int)time(NULL));
    for (int i = 0; i < rows; i++) {
        float vi = (float)(rand() % 201);
        float vf = vi + (float)(rand() % 101);
        float t = (float)(1 + rand() % 15);

        data[i * 3 + 0] = vi;
        data[i * 3 + 1] = vf;
        data[i * 3 + 2] = t;
    }

    printf("Running assembly function %d times...\n", num_runs);

    // Run the function 30 times and measure execution time
    for (int run = 0; run < num_runs; run++) {
        clock_t start = clock();
        acc(data, results, rows);
        clock_t end = clock();

        double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
        total_time += elapsed;

        printf("Run %2d: %.6f seconds\n", run + 1, elapsed);
    }

    double average_time = total_time / num_runs;

    printf("\n--- Runtime Statistics ---\n");
    printf("Total runs: %d\n", num_runs);
    printf("Total time: %.6f seconds\n", total_time);
    printf("Average runtime: %.6f seconds\n", average_time);

    // Output first few results as verification
    printf("\nFirst 10 acceleration results (from last run):\n");
    for (int i = 0; i < 10 && i < rows; i++) {
        printf("%d\n", results[i]);
    }

    free(data);
    free(results);

    return 0;
}
*/
