# Digital Image Processing
### Edge Detection - Numeric Methods II 2024.1
Prof. Dr. Creto Augusto Vidal
- Lucas Cabral Amador Mourão (5th semester)
<br> 
## Algorythm 1: 
1) Smooth the image by applying a Gaussian filter
2) On the image from step 1, apply the Gradient convolutional filter
<br> 2.1) a Sobel filter for the derivative in the x direction, generating an image/matrix, A, with the values of the derivative in each pixel/element of the matrix;
<br> 2.2) a Sobel filter for the derivative in the y direction, generating an image/matrix, B, as the values of the derivative in each pixel/element of the matrix;
<br> 2.3) In each of two matrices, A and B, square the values of their elements;
<br> 2.4) add the two matrices A and B modified in step 2.3 and take the square root of each element of this matrix, C
3) Choose a value (float) for the threshold and
4) generate a final matrix, D, with 
<br> pixel 0 if the corresponding pixel of matrix C is smaller than the threshold.
<br> pixel 0 if the corresponding pixel of matrix C is greater than the threshold.


## Algorythm 2: 
1) Smooth the image by applying a Gaussian filter
2) In the image from step 1, apply the Laplace convolutional filter, generating an image/matrix A
3) For simplicity, generate an image/matrix, B, by looping through image A and writing to B
<br> 1. if the corresponding pixel of matrix A is different from 0 within a tolerance (0.0001, for example)
<br> 0. if the corresponding pixel of matrix A is equal to 0 within a tolerance (0.0001, for example).


### In both algorithms, the Edges will be represented by black pixels and the other pixels will be white.
