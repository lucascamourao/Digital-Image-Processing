#include <iostream>
#include <math.h>
#include <string> 
using namespace std;

int gaussian_filter(float matrix[][6], int n) {
    // prints the matrix after the convolution
    int length_filter = 3;
    float result[n-2][n-2];
    float filter[length_filter][length_filter] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};

    //ignore!
    // float teste[length_filter][length_filter] = {{1, 0, -1}, {1, 0, -1}, {1, 0, -1}};
    // vertical edge detection
    // https://www.youtube.com/watch?v=XuD4C8vJzEQ


    /*For every element in the matrix, from row position 0 to (n - length_filter) and column position 0 to (n - length_filter), we will multiply what the 'mask' covers
    with the equivalent positions in the orignal matrix. Then, we sum all of these values (9 values in this case) and that's our element in the result matrix. We do this
    9 times. This process is called Convolution
    The starting point in the original matrix is [0][0] and we use the filter until position [n - length_filter][n - length_filter].
    */ 
    for (int i = 0; i < (n-2); i++) {
        for (int j = 0; j < (n-2); j++) {
            float sum = 0.0;
            for (int x = 0; x < length_filter; x++) {
                for (int y = 0; y < length_filter; y++) {
                    sum += matrix[i + x][j + y] * filter[x][y];
                }
            }
            result[i][j] = sum;
        }
    }

    // print matrix
    for (int k = 0; k < (n-2); k++) {
        for (int l = 0; l < (n-2); l++) {
            cout << result[k][l] << " "; 
        }
        cout << "\n";
    }

    return (n - length_filter);
    // We'll do multiple convolution processes. Thus, the length of the result matrix[?][?] from the previous convolution will be needed. 
    // That's why the function will be returning the length, which can be used for future convolutions. 
}

int sobel_filter(float matrix[][6], int n) {
    // prints the matrix after the convolution
    int length_filter = 3;
    float result[n-2][n-2];
    float filter[length_filter][length_filter] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    for (int i = 0; i < (n-2); i++) {
        for (int j = 0; j < (n-2); j++) {
            float sum = 0.0;
            for (int x = 0; x < length_filter; x++) {
                for (int y = 0; y < length_filter; y++) {
                    sum += matrix[i + x][j + y] * filter[x][y];
                }
            }
            result[i][j] = sum;
        }
    }

    // print matrix
    for (int k = 0; k < (n-2); k++) {
        for (int l = 0; l < (n-2); l++) {
            cout << result[k][l] << " "; 
        }
        cout << "\n";
    }

    return (n - length_filter);
}

int main() {
    float matrix[6][6] = {{3, 0, 1, 2, 7, 4}, 
                        {1, 5, 8, 9, 3, 1}, 
                        {2, 7, 2, 5, 1, 3},
                        {0, 1, 3, 1, 7, 8},
                        {4, 2, 1, 6, 2, 8},
                        {2, 4, 5, 2, 3, 9}};

    int matrix_length = gaussian_filter(matrix, 6); 

    return 0;
}
