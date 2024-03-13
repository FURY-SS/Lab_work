// Created by vadim on 13.03.2024.

#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

#include <stdbool.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int n_rows; // количество рядов
    int n_cols; // количество столбцов
} matrix;

typedef struct position {
    int row_index;
    int col_index;
} position;

// размещает в динамической памяти матрицу размером n_rows на n_cols. Возвращает матрицу.
matrix get_mem_matrix(int n_rows, int n_cols);

// размещает в динамической памяти массив из n_matrices матриц размером n_rows на n_cols.
// Возвращает указатель на нулевую матрицу.
matrix *get_mem_array_of_matrices(int n_matrices, int n_rows, int n_cols);

// освобождает память, выделенную под хранение матрицы m.
void free_mem_matrix(matrix *m);

// освобождает память, выделенную под хранение массива ms из n_matrices матриц.
void free_mem_matrices(matrix *ms, int n_matrices);

#endif //UNTITLED_MATRIX_H
