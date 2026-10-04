#include <stdio.h> //Header file

int scores[3] = { 90, 85, 95 }; //Array

int main()
{
    /* use the global scores array declared above */
    printf("first array:  [");
    for (int i = 0; i < 3; ++i) {
        printf("%d%s", scores[i], (i + 1 < 3 ? ", " : ""));
    }
    printf("]\n");
    
    // Use a floating-point array for precise values
    double preciseScores[3] = { 90.5, 85.0, 95.0 };
    printf("second array: [");
    for (int i = 0; i < 3; ++i) {
        printf("%.1f%s", preciseScores[i], (i + 1 < 3 ? ", " : ""));
    }
    printf("]\n");

    return 0; 
}