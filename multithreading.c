/*assign4.c*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_NUM 1000.0

double *arr;
double *merged_arr;
int n;

void *insertion_sort(void *args) {
    int start = *((int *)args);
    int end = start + n / 2;

    for (int i = start + 1; i < end; i++) {
        double key = arr[i];
        int j = i - 1;

        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    pthread_exit(0);
}

void *merge_arrays(void *args) {
    int i = 0, j = n / 2;
    int k = 0;

    while (i < n / 2 && j < n) {
        if (arr[i] < arr[j]) {
            merged_arr[k++] = arr[i++];
        } else {
            merged_arr[k++] = arr[j++];
        }
    }

    while (i < n / 2) {
        merged_arr[k++] = arr[i++];
    }

    while (j < n) {
        merged_arr[k++] = arr[j++];
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <array_size>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);

    srand(time(NULL));

    arr = (double *)malloc(n * sizeof(double));
    merged_arr = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % (int)MAX_NUM) + ((double)rand() / RAND_MAX);
    }

    int first_half_start = 0;
    int second_half_start = n / 2;

    clock_t start_time, end_time;
    double time_diff;

    pthread_t sort_thread1, sort_thread2, merge_thread;

    start_time = clock();
    pthread_create(&sort_thread1, NULL, insertion_sort, &first_half_start);
    pthread_create(&sort_thread2, NULL, insertion_sort, &second_half_start);

    pthread_join(sort_thread1, NULL);
    pthread_join(sort_thread2, NULL);

    pthread_create(&merge_thread, NULL, merge_arrays, NULL);
    pthread_join(merge_thread, NULL);
    end_time = clock();

    time_diff = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;
    printf("Sorting is done in %.1fms when two threads are used\n", time_diff);

    start_time = clock();
    insertion_sort(&first_half_start);
    end_time = clock();

    time_diff = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;
    printf("Sorting is done in %.1fms when one thread is used\n", time_diff);

    free(arr);
    free(merged_arr);

    return 0;
}
