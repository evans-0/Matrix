# Matrix

A custom linear algebra matrix library implemented from scratch in both **Python** and **C** — without relying on NumPy or any external math libraries. Built to deeply understand the internals of matrix operations used in data science and scientific computing.

---

## 📁 Structure

```
Matrix/
├── python/          # Python implementation of the Matrix class
├── C/               # C implementation (matrix.c + matrix.h)
├── LU_decomp.ipynb  # LU Decomposition — walkthrough and analysis
└── README.md
```

---

## ⚙️ API Reference

### 🐍 Python

#### Creating a Matrix

```python
from matrix import Matrix

# From a 2D list
A = Matrix([[1, 2], [3, 4]])

# Interactively (prompts for element input)
A = Matrix()
A.create(2, 2)
```

#### Methods

| Method | Description |
|--------|-------------|
| `A + B` | Matrix addition |
| `A - B` | Matrix subtraction |
| `A * B` | Matrix multiplication |
| `A * n` | Scalar multiplication (`n` must be `int`) |
| `A.transpose()` | Returns the transpose |
| `A.det()` | Determinant via recursive cofactor expansion |
| `A.adj()` | Adjoint (transpose of cofactor matrix) |
| `A.inverse()` | Inverse via adjoint method |
| `A.element(r, c)` | Element at row `r`, col `c` (1-indexed) |
| `A.dimension()` | Prints dimensions as `r x c` |
| `A.view()` | Formatted matrix display |

#### Example

```python
A = Matrix([[1, 2], [3, 4]])
B = Matrix([[5, 6], [7, 8]])

print(A + B)         # [[6, 8], [10, 12]]
print(A * B)         # [[19, 22], [43, 50]]
print(A * 3)         # [[3, 6], [9, 12]]
print(A.det())       # -2.0
print(A.transpose()) # [[1, 3], [2, 4]]
print(A.inverse())   # [[-2.0, 1.0], [1.5, -0.5]]
A.view()
A.dimension()        # 2 x 2
```

---

### 🔵 C

Matrices are represented as a flat 1D array in row-major order with dynamic memory allocation.

#### Initialisation

```c
Matrix M = init(3, 3);  // initialise 3x3 matrix
create(&M);             // prompt user to enter values
```

#### Functions

| Function | Description |
|----------|-------------|
| `init(r, c)` | Initialise a matrix struct with dimensions |
| `create(&M)` | Allocate memory and read values from stdin |
| `matcpy(&dst, src)` | Deep copy `src` into `dst` |
| `view(M)` | Print matrix with formatted brackets |
| `add(M1, M2)` | In-place addition of M2 into M1 — returns `0` on success |
| `sub(M1, M2)` | In-place subtraction of M2 from M1 — returns `0` on success |
| `mul(&M1, M2)` | In-place matrix multiplication M1 × M2 — returns `0` on success |
| `smul(M, n)` | In-place scalar multiplication by integer `n` |
| `transpose(&M)` | In-place transpose |
| `submatrix(M, r, c)` | Returns submatrix with row `r` and col `c` excluded |
| `det(&f, M)` | Determinant via cofactor expansion, stored in `f` — returns `0` on success |
| `minor(M)` | Returns matrix of minors |
| `cofactor(M)` | Returns cofactor matrix |
| `adjoint(M)` | Returns adjoint (transpose of cofactor matrix) |
| `inverse(&M1, M2)` | Stores inverse of M2 in M1 — returns `0` on success |
| `clean(M)` | Frees dynamically allocated memory |

#### Example

```c
#include "matrix.h"

int main() {
    Matrix A = init(2, 2);
    create(&A);          // enter: 1 2 3 4
    view(A);

    float d;
    det(&d, A);
    printf("det = %.2f\n", d);   // -2.00

    Matrix inv;
    if (inverse(&inv, A) == 0)
        view(inv);

    clean(A);
    clean(inv);
    return 0;
}
```

#### Build

```bash
cd C
gcc matrix.c example.c -lm -o matrix
./matrix
```

---

## 📓 LU Decomposition

The `LU_decomp.ipynb` notebook walks through decomposing a matrix **A** into:

```
A = L * U
```

where **L** is lower triangular and **U** is upper triangular. This is the backbone of efficient linear system solving used in numerical methods, financial modelling, and physics simulations.

---

## 💡 Why build this from scratch?

Using NumPy makes matrix operations trivial — but building them from scratch in Python and C forces a real understanding of:
- Row-major flat array storage and pointer arithmetic in C
- Recursive cofactor expansion for determinants
- The adjoint method for computing inverses
- Memory management — allocation, copying, and freeing in C
- Why optimized libraries like NumPy and LAPACK are so fast

---

## 📚 Tech Stack

![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Jupyter](https://img.shields.io/badge/Jupyter-F37626?style=for-the-badge&logo=jupyter&logoColor=white)

---
## ⚖️ License

This project is licensed under the [GPL-2.0 License](./LICENSE).
