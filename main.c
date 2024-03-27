#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithms.h"

void test_swap_min_max_rows_different_rows() {
    matrix m = create_matrix_from_array((int[]){1,2,3,
                                                         4,5,6,
                                                         7,8,9}, 3, 3);

    matrix check = create_matrix_from_array((int[]){7,8,9,
                                                             4,5,6,
                                                             1,2,3}, 3,3);

    swap_min_max_rows(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}

void test_swap_min_max_rows_equal_rows() {
    matrix m = create_matrix_from_array((int[]){7,7,7,
                                                7,7,7,
                                                7,7,7}, 3, 3);

    matrix check = create_matrix_from_array((int[]){7,7,7,
                                                    7,7,7,
                                                    7,7,7}, 3, 3);

    swap_min_max_rows(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}

void test_swap_min_max_rows() {
    test_swap_min_max_rows_different_rows();
    test_swap_min_max_rows_equal_rows();
}

void test_sort_rows_by_max_element_different_rows() {
    matrix m = create_matrix_from_array((int[]){1,1,2,
                                                9,1,1,
                                                4,1,1}, 3, 3);

    matrix check = create_matrix_from_array((int[]){1,1,2,
                                                    4,1,1,
                                                    9,1,1}, 3, 3);

    sort_rows_by_max_element(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}

void test_sort_rows_by_max_element_equal_max_value() {
    matrix m = create_matrix_from_array((int[]){1,1,7,
                                                7,1,1,
                                                7,1,1}, 3, 3);

    matrix check = create_matrix_from_array((int[]){1,1,7,
                                                    7,1,1,
                                                    7,1,1}, 3, 3);

    sort_rows_by_max_element(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}

void test_sort_cols_by_min_element_difference_value() {
    matrix m = create_matrix_from_array((int[]) {3, 5, 2, 4, 3, 3,
                                                 2, 5, 1, 8, 2, 7,
                                                 6, 1, 4, 4, 8, 3}, 3, 6);

    matrix check = create_matrix_from_array((int[]) {5, 2, 3, 3, 3, 4,
                                                     5, 1, 2, 2, 7, 8,
                                                     1, 4, 6, 8, 3, 4},3, 6);

    sort_cols_by_min_element(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}

void test_sort_cols_by_min_element_min_value_equal() {
    matrix m = create_matrix_from_array((int[]) {3, 5, 2, 1, 3, 1,
                                                 2, 5, 1, 8, 1, 7,
                                                 1, 1, 4, 1, 8, 3}, 3, 6);

    matrix check = create_matrix_from_array((int[]) {3, 5, 2, 1, 3, 1,
                                                 2, 5, 1, 8, 1, 7,
                                                 1, 1, 4, 1, 8, 3}, 3, 6);

    sort_cols_by_min_element(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}

void test_sort() {
    test_sort_rows_by_max_element_different_rows();
    test_sort_rows_by_max_element_equal_max_value();
    test_sort_cols_by_min_element_difference_value();
    test_sort_cols_by_min_element_min_value_equal();
}

void test_mul_matrices_difference_value() {
    matrix m1 = create_matrix_from_array((int[]){1,2,3,
                                                4,5,6,
                                                7,8,9}, 3, 3);

    matrix m2 = create_matrix_from_array((int[]){1,2,3,
                                                4,5,6,
                                                7,8,9}, 3, 3);

    matrix res = mul_matrices(m1, m2);

    matrix check = create_matrix_from_array((int[]){30,36,42,
                                                    66,81,96,
                                                    102,126,150},3,3);

    assert(are_two_matrices_equal(&res, &check));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
    free_mem_matrix(&res);
    free_mem_matrix(&check);
}

void test_mul_matrices_to_null_matrix() {
    matrix m1 = create_matrix_from_array((int[]){1,2,3,
                                                 4,5,6,
                                                 7,8,9}, 3, 3);

    matrix m2 = create_matrix_from_array((int[]){1,0,0,
                                                 0,1,0,
                                                 0,0,1}, 3, 3);

    matrix res = mul_matrices(m1, m2);

    matrix check = create_matrix_from_array((int[]){1,2,3,
                                                 4,5,6,
                                                 7,8,9}, 3, 3);

    assert(are_two_matrices_equal(&res, &check));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
    free_mem_matrix(&res);
    free_mem_matrix(&check);
}

void test_mul_matrices_to_e_matrix() {
    matrix m1 = create_matrix_from_array((int[]){1,2,3,
                                                 4,5,6,
                                                 7,8,9}, 3, 3);

    matrix m2 = create_matrix_from_array((int[]){0,0,0,
                                                 0,0,0,
                                                 0,0,0}, 3, 3);

    matrix res = mul_matrices(m1, m2);

    matrix check = create_matrix_from_array((int[]){0,0,0,
                                                    0,0,0,
                                                    0,0,0}, 3, 3);

    assert(are_two_matrices_equal(&res, &check));

    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
    free_mem_matrix(&res);
    free_mem_matrix(&check);
}

void test_mul_matrices() {
    test_mul_matrices_difference_value();
    test_mul_matrices_to_null_matrix();
    test_mul_matrices_to_e_matrix();
}

void test_get_square_of_matrix_if_symmetric_symmetric_matrix() {
    matrix m = create_matrix_from_array((int[]) {1, 2, 3,
                                                 2, 5, 6,
                                                 3, 6, 9}, 3, 3);

    matrix check = create_matrix_from_array((int[]) {14, 30, 42,
                                                     30, 65, 90,
                                                     42, 90, 126}, 3, 3);

    get_square_of_matrix_if_symmetric(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}

void test_get_square_of_matrix_if_symmetric_not_symmetric_matrix() {
    matrix m = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix check = create_matrix_from_array((int[]) {1, 2, 3,
                                                     4, 5, 6,
                                                     7, 8, 9}, 3, 3);

    get_square_of_matrix_if_symmetric(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}

void test_get_square_of_matrix_if_symmetric_e_matrix() {
    matrix m = create_matrix_from_array((int[]) {1, 0, 0,
                                                 0, 1, 0,
                                                 0, 0, 1}, 3, 3);

    matrix check = create_matrix_from_array((int[]) {1, 0, 0,
                                                     0, 1, 0,
                                                     0, 0, 1}, 3, 3);

    get_square_of_matrix_if_symmetric(&m);

    assert(are_two_matrices_equal(&m, &check));

    free_mem_matrix(&m);
    free_mem_matrix(&check);
}

void test_get_square_of_matrix_if_symmetric() {
    test_get_square_of_matrix_if_symmetric_symmetric_matrix();
    test_get_square_of_matrix_if_symmetric_not_symmetric_matrix();
    test_get_square_of_matrix_if_symmetric_e_matrix();
}



void test() {
    test_swap_min_max_rows();
    test_sort();
    test_mul_matrices();
    test_get_square_of_matrix_if_symmetric();
}

int main () {
    test();
}