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

    // print matrix
    cout << "Matrix after de Guassian filter:\n";
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

// 2.1 Applying Sobel filter for the derivative in the x direction, generating an image/matrix, A, with the values of the derivative in each pixel/element of the matrix
int Gx_Sobel(float matrix[][4], int n, float result[][2]) {
    int length_filter = 3;
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

    cout << "Matrix after de Sobel filter in the x direction:\n";
    for (int k = 0; k < (n-2); k++) {
        for (int l = 0; l < (n-2); l++) {
            cout << result[k][l] << " "; 
        }
        cout << "\n";
    }

    return (n - length_filter + 1);
}

// 2.2 Applying a Sobel filter for the derivative in the y direction, generating an image/matrix, B, as the values of the derivative in each pixel/element of the matrix;
int Gy_Sobel(float matrix[][4], int n, float result[][2]) {
    int length_filter = 3;
    float filter[length_filter][length_filter] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

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

    cout << "Matrix after de Sobel filter in the y direction:\n";
    for (int k = 0; k < (n-2); k++) {
        for (int l = 0; l < (n-2); l++) {
            cout << result[k][l] << " "; 
        }
        cout << "\n";
    }

    return (n - length_filter + 1);
}

int Sobel_Filter(float matrix_Gx[][2], float matrix_Gy[][2], float result[][2], int n) {
    int length_filter = 3;

    // 2.3 In each of two matrices, A and B, square the values of their elements;

    // squaring the values in matrix_Gx 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix_Gx[i][j] = matrix_Gx[i][j] * matrix_Gx[i][j]; 
        }
    }
    // squaring the values in matrix_Gy 
    for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
            matrix_Gy[k][l] = matrix_Gy[k][l] * matrix_Gy[k][l]; 
        }
    }

    // 2.4 Add the two matrices A and B modified in step 2.3 and take the square root of each element of this matrix, C

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            result[x][y] = sqrt(matrix_Gx[x][y] + matrix_Gy[x][y]); 
            result[x][y] = round(result[x][y] * 1000)/ 1000;
        }
    }

    cout << "Matrix after de Sobel filter:\n";
    for (int aux1 = 0; aux1 < 2; aux1++) {
        for (int aux2 = 0; aux2 < 2; aux2++) {
            cout << result[aux1][aux2] << " "; 
        }
        cout << "\n";
    }

    return (n - length_filter);
}

int main() {
    float result_gaussian[4][4];
    float result_gx[2][2];
    float result_gy[2][2];
    float result_sobel[2][2];
    float matrix_D[2][2];
    float threshold;

    float matrix[6][6] = {{3, 0, 1, 2, 7, 4}, 
                        {1, 5, 8, 9, 3, 1}, 
                        {2, 7, 2, 5, 1, 3},
                        {0, 1, 3, 1, 7, 8},
                        {4, 2, 1, 6, 2, 8},
                        {2, 4, 5, 2, 3, 9}};

    // 1. Using Gaussian filter
    int guassian_length = Gaussian_Filter(matrix, 6, result_gaussian); 

    // 2. Applying Gradient convolutional filter 

    Gx_Sobel(result_gaussian, 4, result_gx);
    Gy_Sobel(result_gaussian, 4, result_gy);

    Sobel_Filter(result_gx, result_gy, result_sobel, guassian_length);

    // 3. Choosing the threshold
    cout << "Enter the threshold: \n";
    cin >> threshold;

    // 4. Generating the matrix D
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (result_sobel[i][j] < threshold) {
                matrix_D[i][j] = 0;
            }
            else {
                matrix_D[i][j] = 1;
            }
        }
    }

    for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
            cout << matrix_D[k][l] << " ";
        }
        cout << "\n";
    }

    return 0;
}
