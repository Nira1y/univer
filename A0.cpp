#include <stdio.h>

int main(){

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int n;
    fscanf(input, "%d", &n);

    int flashlights[101] = {0};

    for(int i = 0; i < n; i++){

        int x, y, left_r, right_r;

        fscanf (input, "%d %d", &x, &y);

        left_r = x - y;
        right_r = x + y;

        if (left_r < 0){
            left_r = 0;
        }

        if (right_r > 100){
            right_r = 100;
        }

        for (int j = left_r; j < right_r; j++){

            flashlights[j]++;  
        }
    }

    int max_flashlights = 0;

    for(int i = 0; i <= 100; i++){
        if (flashlights[i] > max_flashlights) {
            max_flashlights = flashlights[i];
        }
    } 
    
    fprintf(output, "%d", max_flashlights);

    return 0;

}