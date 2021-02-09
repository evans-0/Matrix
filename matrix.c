#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int row;
    int column;
    float *arr;
} Matrix;

signed int exponent(int base, signed int pow);      // Exponent function
Matrix create(int r, int c);                        // Create a matrix of given rows and columns
void view(Matrix m);                                // View the matrix
Matrix add(Matrix M1, Matrix M2);                   // Add two matrices
Matrix sub(Matrix M1, Matrix M2);                   // Subtract two matrices
Matrix mul(Matrix M1, Matrix M2);                   // Multiply two matrices
Matrix smul(Matrix M, float n);                      // Scalar multiplication
Matrix transpose(Matrix M);                         // Transpose of a matrix
Matrix submatrix(Matrix M, int r, int c);           // Submatrix
float det(Matrix M);                                 // Determinant of a matrix  
Matrix minor(Matrix M);                             // Minor of a matrix
Matrix cofactor(Matrix M);                          // Cofactor of a matrix
Matrix adjoint(Matrix M);                           // Adjoint of a matrix
Matrix inverse(Matrix M);                           // Inverse of a matrix

int main()
{
    while (1)
    {
        int ch;
        printf("\nMatrix Operations:\n\t1. Add\n\t2. Subtract\n\t3. Matrix Multiplication");
        printf("\n\t4. Scalar Multiplication\n\t5. Transpose\n\t6. Determinant\n\t7. Minor");
        printf("\n\t8. Cofactor\n\t9. Adjoint\n\t10. Inverse\n\t11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch==1) //Add
        {
            int r, c;
            printf("Enter order of Matrix 1: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M1 = create(r, c);
            
            printf("Enter order of Matrix 2: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M2 = create(r, c);

            if ((M1.row==M2.row) && (M1.column==M2.column))
            {
                Matrix sum = add(M1, M2);

                view(M1);
                printf("+\n");
                view(M2);
                printf("=\n");
                view(sum);
            }
            else
            {
                printf("\nCan't add matrices with different orders.\n\n");
            }
        }
        else if (ch==2) // Subtract
        {
            int r, c;
            printf("Enter order of Matrix 1: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M1 = create(r, c);
            
            printf("Enter order of Matrix 2: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M2 = create(r, c);

            if ((M1.row==M2.row) && (M1.column==M2.column))
            {
                Matrix diff = sub(M1, M2);

                view(M1);
                printf("+\n");
                view(M2);
                printf("=\n");
                view(diff);
            }
            else
            {
                printf("\nCan't subtract matrices with different orders.\n\n");
            }
        }
        else if (ch==3) // Matrix multiplication
        {
            int r, c;
            printf("Enter order of Matrix 1: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M1 = create(r, c);
            
            printf("Enter order of Matrix 2: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M2 = create(r, c);

            if (M1.column==M2.row)
            {
                printf("Product is\n\n");
                Matrix result = mul(M1, M2);
                view(result);
            }
            else
            {
                printf("Matrix multiplication not defined.");
            }
        }
        else if (ch==4) // scalar multiplication
        {
            int r, c;
            printf("Enter order of Matrix: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M = create(r, c);
            printf("Matrix\n");
            view(M);

            float s;
            printf("Enter the scalar: ");
            scanf("%f", &s);

            printf("\nProduct\n");
            Matrix res = smul(M, s);
            view(res);
        }
        else if(ch==5)  // transpose
        {
            int r, c;
            printf("Enter order of Matrix: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M = create(r, c);

            printf("Original\n");
            view(M);

            printf("\nTranspose\n");
            Matrix res = transpose(M);
            view(res);

        }
        else if (ch==6) // determinant
        {
            int r, c;
            printf("Enter order of Matrix: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M = create(r, c);

            if (M.row==M.column)
            {
                int res = det(M);
                printf("\nDeterminant -> %d\n\n", res);
            }
            else
            {
                printf("\nDeterminant does not exist.\n\n");
            }
        }
        else if (ch==7) // minor
        {
            int r, c;
            printf("Enter order of Matrix: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M = create(r, c);
            
            printf("Original\n");
            view(M);

            if (M.row==M.column)
            {
            printf("\nMinor\n");
            Matrix res = minor(M);
            view(res);
            }
            else
            {
                printf("Minor does not exist.\n");
            }
        }
        else if (ch==8)  // cofactor
        {
            int r, c;
            printf("Enter order of Matrix: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M = create(r, c);
            
            printf("Original\n");
            view(M);

            if (M.row==M.column)
            {
            printf("\nCofactor\n");
            Matrix res = cofactor(M);
            view(res);
            }
            else
            {
                printf("Cofactor does not exist.\n");
            }
        }
        else if (ch==9)  // adjoint
        {
            int r, c;
            printf("Enter order of Matrix: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M = create(r, c);
            
            printf("Original\n");
            view(M);

            if (M.row==M.column)
            {
            printf("\nAdjoint\n");
            Matrix res = adjoint(M);
            view(res);
            }
            else
            {
                printf("Adjoint does not exist.\n");
            }
        }
        else if (ch==10) // inverse
        {
            int r, c;
            printf("Enter order of Matrix: ");  // <row>x<column>
            scanf("%dx%d", &r, &c);
            Matrix M = create(r, c);

            printf("Original\n");
            view(M);

            if ((det(M)==0) || (M.row!=M.column))
            {
                printf("Inverse does not exist.\n");
            }
            else
            {
                Matrix I = inverse(M);  // Inverse
                printf("\nInverse\n");
                view(I);
            }
        }
        else if(ch==11)  //exit
        {
            break;
        }
        else
        {
            printf("\nInvalid choice!\n\n");
        }
    }
}

signed int exponent(int base, signed int pow)
{
    long double result = 1;
    if (pow>0)
    {
        for (int i = 0; i<pow; i++)
        {
            result = result*base;
        }
    }
    else if (pow<0)
    {
        for (int i = 0; i<abs(pow); i++)
        {   
            result = result/base;
        }
    }
    return result;
}

Matrix create(int r, int c)
{
    Matrix M;
    M.row = r;
    M.column = c;

    M.arr = malloc(r * c * sizeof(float));
    for (int i = 0; i<r; i++)
    {
        for (int j = 0; j<c; j++)
        {
            printf("Enter element at (%d, %d): ", i+1, j+1);
            scanf("%f", &M.arr[c*i + j]);
        }
    }
    return M;
}

void view(Matrix m)
{
    if ((m.row>0) && (m.column>0))
    {
        for (int i = 0; i<m.row; i++)
        {
            for (int j = 0; j<m.column; j++)
            {
                printf(" %.2f ", m.arr[m.column*i + j]);
            }
            printf("\n");
        }
    }
}

Matrix add(Matrix M1, Matrix M2)
{
    Matrix res;
    res.row = M1.row;
    res.column = M1.column;
    res.arr = malloc(M1. row * M1.column * sizeof(float));

    int p; //position
    for (int i = 0; i<M1.row; i++)
    {
        for (int j = 0; j<M1.column; j++)
        {
            p = (M1.column*i +j);
            res.arr[p] = M1.arr[p] + M2.arr[p];
        }
    }
    return res;
}

Matrix sub(Matrix M1, Matrix M2)
{
    if ((M1.row==M2.row) && (M1.column==M2.column))
    {
        Matrix res;
        res.row = M1.row;
        res.column = M1.column;
        res.arr = malloc(M1. row * M1.column * sizeof(float));

        int p; //position
        for (int i = 0; i<M1.row; i++)
        {
            for (int j = 0; j<M1.column; j++)
            {
                p = (M1.column*i +j);
                res.arr[p] = M1.arr[p] - M2.arr[p];
            }
        }
        return res;
    }
    else
    {
        Matrix res;
        res.row = 0;
        res.column = 0;
        return res;
    }
}

Matrix mul(Matrix M1, Matrix M2) //Vector multiplication
{
    Matrix res;
    res.row = M1.row;
    res.column = M2.column;
    res.arr = malloc(res.row * res.column * sizeof(float));

    for (int i = 0; i<M1.row; i++)
    {
        for (int j = 0; j<M2.column; j++)
        {
            int ele = 0;
            for (int k = 0; k<M1.column; k++)
            {
                ele+=M1.arr[i*M1.column + k] * M2.arr[k*M2.column + j];
            }
            res.arr[i*res.column + j] = ele;
        }
    }

    return res;
}

Matrix smul(Matrix M, float n) // Scalar multiplication
{
    Matrix res;
    res.row = M.row;
    res.column = M.column;
    res.arr = malloc(res.row * res.column * sizeof(float));

    for (int i = 0; i<M.row; i++)
    {
        for (int j = 0; j<M.column; j++)
        {
            res.arr[i*M.column + j] = n*M.arr[i*M.column + j];
        }
    }

    return res;
}

Matrix transpose(Matrix M)
{
    Matrix res;
    res.row = M.column;
    res.column = M.row;
    res.arr = malloc(M.row * M.column * sizeof(float));

    for (int i = 0; i<M.row; i++)
    {
        for (int j = 0; j<M.column; j++)
        {
            res.arr[(i + res.column*j)] = M.arr[M.column*i + j];
        }
    }

    return res;
}

Matrix submatrix(Matrix M, int r, int c) // submatrix
{
    float *l = malloc((M.row-1) * (M.column-1) * sizeof(float));
    int k = 0;
    for (int i = 0; i<M.row; i++)
    {
        for (int j = 0; j<M.column; j++)
        {
            if ((i!=r) && (j!=c))
            {
                l[k] = M.arr[M.row*i + j];
                k++;
            }
        }
    }

    Matrix res;
    res.row = M.row - 1;
    res.column = M.column - 1;
    res.arr = l;

    return res;
}

float det(Matrix M)
{
    if (M.row==1)
    {
        return M.arr[0];
    }
    else if (M.row==2)
    {
        return ((M.arr[0]*M.arr[3]) - (M.arr[1]*M.arr[2]));
    }
    else
    {
        int d = 0;
        int i = 0;
        for (int j = 0; j<M.column; j++)
        {
            Matrix sub = submatrix(M, i, j);
            d+= exponent(-1, i+j+2)*M.arr[j]*det(sub);
        }
        return d;
    }
}

Matrix minor(Matrix M)
{
    Matrix res;
    res.row = M.row;
    res.column = M.column;
    res.arr = malloc(res.row * res.column * sizeof(float));
    
    Matrix sub;
    int ele;

    for (int i = 0; i<M.row; i++)
    {
        for (int j = 0; j<M.column; j++)
        {
            sub = submatrix(M, i, j);
            ele = det(sub);

            res.arr[i*M.column + j] = ele;;
        }
    }

    return res;
}

Matrix cofactor(Matrix M)
{
    Matrix res;
    res.row = M.row;
    res.column = M.column;
    res.arr = malloc(res.row * res.column * sizeof(float));
    
    Matrix sub;
    int ele;

    for (int i = 0; i<M.row; i++)
    {
        for (int j = 0; j<M.column; j++)
        {
            sub = submatrix(M, i, j);
            ele = det(sub);

            res.arr[i*M.column + j] = exponent(-1, i+j)*ele;;
        }
    }

    return res;
}

Matrix adjoint(Matrix M)
{
    Matrix cf = cofactor(M);  // Cofactor

    Matrix res = transpose(cf);
    return res;
}

Matrix inverse(Matrix M)
{
    float d = 1/det(M); // determinant
    Matrix ad = adjoint(M); //adjoint
    printf("det -> %f, Inverse of det -> %f\n", det(M), d);
    Matrix res = smul(ad, d);

    return res;
}