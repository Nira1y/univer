#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n){
    int swapped;
    for (int i = 0; i < n - 1; i++){
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped = 0){
            break;
        }
    }
}

int max(int a, int b){

    if (a >= b){
        return a;
    }
    else{
        return b;
    }

}

int main(){
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int N, L;
    fscanf(input, "%d %d", &N, &L);

    int* flight_time = (int*)malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++){
        fscanf(input, "%d", &flight_time[i]);
    }

    bubble_sort(flight_time, N);

    int total_time = flight_time[0];

    for (int i = 0; i < N; i++){

        int start; 
        start = max(total_time, flight_time[i]);
        total_time = start + L;

    }

    fprintf(output, "%d", total_time);
    return 0;
}