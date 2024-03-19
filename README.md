# Digital Image Processing
### Edge Detection - Numeric Methods II 2024.1
Prof. Dr. Creto Augusto Vidal
<br> 
## Algorythm 1: 
1) Smooth the image by applying a Gaussian filter
2) On the image from step 1, apply the Gradient convolutional filter
<br> 2.1) um filtro de Sobel para a derivada na direção x, gerando uma imagem/matriz, A, com os valores da derivada em cada pixel/elemento da matriz;
<br> 2.2) um filtro de Sobel para a derivada na direção y, gerando uma imagens/matriz, B, com os valores da derivada em cada pixel/elemento da matriz;
<br> 2.3) em cada uma das matrizes, A e B, eleve ao quadrado os valores dos elementos;
<br> 2.4) some as duas matrizes A e B modificadas no passo 2.3 e tire a raiz quadrada  de cada elemento dessa matriz, C
3) Choose a value (float) for the threshold and
4) generate a final matrix, D, with 
<br> pixel 0 caso o pixel correspondente da matriz C seja menor do que o threshold.
<br> pixel 1. caso o pixel correspondente da matriz C seja maior do que o threshold.


## Algorythm 2: 
1) Smooth the image by applying a Gaussian filter
2) Na imagem do passo 1, aplique o filtro convolucional de Laplace, gerando uma imagem/matriz A
3) Por simplicidade, gere uma imagem/matriz, B, percorrendo a imagem A e escrevendo em B
<br> 1. caso o pixel correspondente da matriz A seja diferente de 0 dentro de uma tolerância (0.0001, por exemplo)
<br> 0. cado o pixel correspondente da matriz A seja igual a 0 dentro de uma tolerância (0.0001, por exemplo).


### In both algorithms, the Edges will be represented by black pixels and the other pixels will be white.
