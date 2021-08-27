#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

Matrix init(int r, int c)
{
	Matrix M;
	M.r = r;
	M.c = c;
	return M;
}

void create(Matrix *M)
{
    M->arr = malloc(M->r * M->c * sizeof(float));
    printf("Enter matrix: \n");
    for (int i = 0; i < M->r; i++)
        for (int j = 0; j < M->c; j++)
            scanf("%f", (M->arr + M->c*i + j));
}

void matcpy(Matrix *dst, Matrix src)	// copy src matrix to dst matrix
{
    dst->r = src.r;
    dst->c = src.c;
    dst->arr = malloc(dst->r * dst->c * sizeof(float));
    for (int i = 0; i < dst->r; i++)
	for (int j = 0; j < dst->c; j++)
	{
	    int index = i*dst->c + j;
	    dst->arr[index]  = src.arr[index];
      	}
}

void view(Matrix M)          // Displaying matrix
{
    if ((M.r>0) && (M.c>0))
    {
        for (int i = 0; i < M.r; i++)
        {
	    printf("[");
            for (int j = 0; j < M.c; j++)
                printf("%.2f ", *(M.arr + M.c*i + j));
            printf("]\n");
        }
    }
}

int add(Matrix M1, Matrix M2) // Addition of matrices
/* returns 0 if addition successful else 1 */
{
    if ((M1.r == M2.r) && (M1.c == M2.c))
    {
        for (int i = 0; i < M1.r; i++)
	    for (int j = 0; j < M1.c; j++)
	        *(M1.arr + M1.c*i + j) += *(M2.arr + M1.c*i + j);
		return 0;
    }
    else
        return 1;
}

int sub(Matrix M1, Matrix M2) // Subtraction of matrices
/* returns 0 if successful else 1 */
{
    if ((M1.r == M2.r) && (M1.c == M2.c))
    {
        for (int i = 0; i < M1.r; i++)
	    for (int j = 0; j < M1.c; j++)
  	        *(M1.arr + M1.c*i + j) -= *(M2.arr + M1.c*i + j);
	return 0;
    }
    else
      	return 1;
}

int mul(Matrix *M1, Matrix M2) // Matrix multiplication
/* returns 0 if success else 1 */
{
    if (M1->c == M2.r)
    {
        float *arr = malloc(M1->r * M2.c * sizeof(float));
        for (int i = 0; i<M1->r; i++)
      	{
 	    for (int j = 0; j<M2.c; j++)
	    {
	        float ele = 0;
		for (int k = 0; k<M1->c; k++)
		    ele+=M1->arr[i*M1->c + k] * M2.arr[k*M2.c + j];
		arr[i*M2.c + j] = ele;
	    }
	}
        M1->c = M2.c;
        free(M1->arr);
        M1->arr = arr;
        return 0;
    }
    else
        return 1;
}

void smul(Matrix M, int n) // Matrix scalar multiplication
{
    for (int i = 0; i < M.r; i++)
        for (int j = 0; j < M.c; j++)
	    *(M.arr + i*M.c + j) *= n;
}

void transpose(Matrix *M)     // Transpose of a matrix
{
    float *arr = malloc(M->r * M->c * sizeof(float));
    for (int i = 0; i<M->r; i++)
        for (int j = 0; j<M->c; j++)
            arr[M->r*j + i] = M->arr[M->c*i + j];
    free(M->arr);
    int temp = M->r;
    M->r = M->c;
    M->c = temp;
    M->arr = arr;
}

Matrix submatrix(Matrix M, int r, int c) // submatrix
{
    float *l = malloc((M.r-1) * (M.c-1) * sizeof(float));
    int k = 0;
    for (int i = 0; i < M.r; i++)
        for (int j = 0; j < M.c; j++)
            if ((i!=r) && (j!=c))
                l[k++] = M.arr[M.r*i + j];
    Matrix res;
    res.r = M.r - 1;
    res.c = M.c - 1;
    res.arr = l;
    return res;
}

int det(float *f, Matrix M)
// returns 0 if determinant exists else returns 1
{
    if (M.r != M.c)
        return 1;
    else {
        float res = 0;
        if (M.r == 1)
            res = M.arr[0];
        else if (M.r == 2)
            res = ((M.arr[0]*M.arr[3]) - (M.arr[1]*M.arr[2]));
        else {
            float d = 0;
            int i = 0;
            for (int j = 0; j < M.c; j++) {
              Matrix sub = submatrix(M, i, j);
              det(f, sub);
              d += pow(-1, i + j) * M.arr[j] * (*f);
            }
            res = d;
        }
        *f = res;
        return 0;
    }
}

Matrix minor(Matrix M)
// minor of a Matrix
{
    Matrix res;
    res.r = M.r;
    res.c = M.c;
    res.arr = malloc(res.r * res.c * sizeof(float));
    Matrix sub;
    float ele;
    for (int i = 0; i < M.r; i++)
    {
        for (int j = 0; j < M.c; j++)
        {
            sub = submatrix(M, i, j);
            det(&ele, sub);
            res.arr[i * M.c + j] = ele;
        }
    }
    return res;
}

Matrix cofactor(Matrix M)
// minor of a Matrix
{
    Matrix res;
    res.r = M.r;
    res.c = M.c;
    res.arr = malloc(res.r * res.c * sizeof(float));
    Matrix sub;
    float ele;
    for (int i = 0; i < M.r; i++)
    {
        for (int j = 0; j < M.c; j++)
        {
            sub = submatrix(M, i, j);
            det(&ele, sub);
            res.arr[i * M.c + j] = pow(-1, i+j) * ele;
        }
    }
    return res;
}

Matrix adjoint(Matrix M)
// Adjoint of a matrix
{
  Matrix res = cofactor(M);
  transpose(&res);
  return res;
}

int inverse(Matrix *M1, Matrix M2)
// returns 0 if inverse exists else returns 1
{
    float d;
    if (det(&d, M2))
        return 1;
    if (d == 0)
        return 1;
    else
    {
        Matrix res = adjoint(M2);
        smul(res, 1/d);
        matcpy(M1, res);
        return 0;
    }
}

void clean(Matrix M)
{
    free(M.arr);
}
