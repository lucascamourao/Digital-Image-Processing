# Digital Image Processing
### Edge Detection - Numeric Methods II 2024.1
Prof. Dr. Creto Augusto Vidal
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
3) Por simplicidade, gere uma imagem/matriz, B, percorrendo a imagem A e escrevendo em B
<br> 1. caso o pixel correspondente da matriz A seja diferente de 0 dentro de uma tolerância (0.0001, por exemplo)
<br> 0. cado o pixel correspondente da matriz A seja igual a 0 dentro de uma tolerância (0.0001, por exemplo).


### In both algorithms, the Edges will be represented by black pixels and the other pixels will be white.
