#include <iostream>
#include <math.h>
#include <string> 
using namespace std;

/*Note: This Kernel ou Gaussian filter is NOT normalized. To normalize, divide all the elements in the filter by the sum of all of them (1/16).
Normalization ensures that the overall brightness of the image is preserved after applying the filter. It is used because when convolutioning 
with normal kernel the resulting values can become larger or smaller than the original values in the image. */
int Gaussian_Filter(float matrix[][6], int n, float result[][4]) {
    // prints the matrix after the convolution
    int length_filter = 3;
    float filter[length_filter][length_filter] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};

    /*For every element in the matrix, from row position 0 to (n - length_filter) and column position 0 to (n - length_filter), we will multiply what the 'mask' covers
    with the equivalent positions in the orignal matrix. Then, we sum all of these values (9 values in this case) and that's our element in the result matrix. We do this
    9 times. This process is called Convolution (3x3).
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

    cout << "Matrix after the Guassian filter:\n";
    for (int k = 0; k < (n-2); k++) {
        for (int l = 0; l < (n-2); l++) {
            cout << result[k][l] << " "; 
        }
        cout << "\n";
    }

    return (n - length_filter + 1);
    // We'll do multiple convolution processes. Thus, the length of the result matrix[?][?] from the previous convolution will be needed. 
    // That's why the function will be returning the length, which can be used for future convolutions. 
}

// Using second order derivative to determine whether an edge pixel lies on the light or dark side of an edge. Therefore, we use it to measure the rate of change of the image intensity.
// ∇²f(x, y) = ∂²f/∂x² + ∂²f/∂y²
int Laplace_Filter(float matrix[][4], int n, float result[][2]) {
    int length_filter = 3;
    float filter[length_filter][length_filter] = {{0, 1, 0}, {1, -4, 1}, {0, 1, 0}};

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

    cout << "Matrix after the Laplace filter:\n";
    for (int k = 0; k < (n-2); k++) {
        for (int l = 0; l < (n-2); l++) {
            cout << result[k][l] << " "; 
        }
        cout << "\n";
    }

    return (n - length_filter + 1); 
}

int main() {
    float result_gaussian[4][4];
    float result_laplace[2][2];
    float matrix_B[2][2];

    float matrix[6][6] = {{3, 0, 1, 2, 7, 4}, 
                        {1, 5, 8, 9, 3, 1}, 
                        {2, 7, 2, 5, 1, 3},
                        {0, 1, 3, 1, 7, 8},
                        {4, 2, 1, 6, 2, 8},
                        {2, 4, 5, 2, 3, 9}};

    // 1. Using Gaussian filter
    int guassian_length = Gaussian_Filter(matrix, 6, result_gaussian); 

    // 2. Using the Laplace convolutional filter

    Laplace_Filter(result_gaussian, guassian_length, result_laplace);

    // 3. Generating the matrix B
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (abs(result_laplace[i][j] - 0) <= 0.0001) {
                matrix_B[i][j] = 0;
            }
            else {
                matrix_B[i][j] = 1;
            }
        }
    }

    for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
            cout << matrix_B[k][l] << " ";
        }
        cout << "\n";
    }

    return 0;
}
