/*
    S12A  
	Cabrera, James    <- specs from here
	Cardino, Joaquin
*/

#include <stdio.h>
#include <stdlib.h>

extern void acc(float* data, int* results, int rows);

int main() {
    int rows = 3; cars
    float data[3][3] = {
        {0.0, 62.5, 10.1},
        {60.0, 122.3, 5.5},
        {30.0, 160.7, 7.8},
        
    };
    int results[3];

    acc(&data[0][0], results, rows);

    for (int i = 0; i < rows; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}





////to test the execution time, given number of cars or rows(Y) and random values for vi, vf, and t will be given by the program
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//// External assembly function
//extern void acc(float* data, int* results, int rows);
//
//int main() {
//    int rows = 9027; //9027 max to print asmfunc avg exec time
//
//    /*printf("Enter number of rows: ");
//    scanf_s("%d", &rows);
//
//    if (rows <= 0) {
//        printf("Invalid row count.\n");
//        return 1;
//    }*/
//
//    clock_t start, end;
//    double elapsed_time;
//
//    // Allocate memory
//    float* data = (float*)malloc(sizeof(float) * 3 * rows);
//    int* results = (int*)malloc(sizeof(int) * rows);
//
//    if (!data || !results) {
//        printf("Memory allocation failed.\n");
//        return 1;
//    }
//
//    // Fill the data array with random values
//    for (int i = 0; i < rows; i++) {
//        float vi = (float)(rand() % 201); // 0 to 200 km/h
//        float vf = vi + (float)(rand() % 101); // vi to vi+100 km/h
//        float t = (float)(1 + rand() % 15); // 1 to 15 seconds
//
//        data[i * 3 + 0] = vi;
//        data[i * 3 + 1] = vf;
//        data[i * 3 + 2] = t;
//    }
//
//    start = clock();
//    acc(data, results, rows);
//    end = clock();
//
//    elapsed_time = ((double)(end - start));
//
//    printf("ASMFUNC elapsed time: %f\n", elapsed_time);
//
//    // Output results
//    for (int i = 0; i < rows; i++) {
//        printf("%d\n", results[i]);
//    }
//
//    free(data);
//    free(results);
//
//    return 0;
}


