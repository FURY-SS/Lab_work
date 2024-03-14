#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int main () {
    matrix *m = get_mem_array_of_matrices(2,3,3);
    input_matrix(m);
    swap_columns(m, 1,2);
    output_matrix(m);
    return 0;
}