#ifndef MATRIX_H
#define MATRIX_H

// matrix structure
typedef struct {
  int r, c;
  float *arr;
} Matrix;

void create(Matrix *M); // create a matrix
void matcpy(Matrix *dst, Matrix src);  // matrix copy
void view(Matrix M);  // view the matrix
int add(Matrix M1, Matrix M2);   // add two matrices
int sub(Matrix M1, Matrix M2);   // subtract two matrices
int mul(Matrix *M1, Matrix M2);   // matrix multiplication
void smul(Matrix M, int n);   // scalar multiplication
void transpose(Matrix *M);   // tranpose of a matrix
int det(float *f, Matrix M);  // determinant of a matrix
Matrix minor(Matrix M);  // minor of a matrix
Matrix cofactor(Matrix M);  // cofactor of a matrix
Matrix adjoint(Matrix M);  // adjoint of a matrix
int inverse(Matrix *M1, Matrix M2); // inverse of a matrix
void clean(Matrix M);  // free the allocated space

#endif
