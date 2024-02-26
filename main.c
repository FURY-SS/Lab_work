#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/ordered_array_set/ordered_array_set.h"

void test_push_back_empty_vector() {
    vector v = create_vector(0);
    v.size = 0;
    assert(is_empty(&v));

    push_back(&v, 1);

    assert(v.size == 1 && v.capacity == 1);
}


void test_push_back_full_vector() {
    vector v = create_vector(1);
    v.size = 1;
    assert(is_full(&v));

    push_back(&v, 2);

    assert(v.size == 2 && v.capacity == 2);
}

void test_pop_back_not_empty_vector() {
    vector v = create_vector(0);
    push_back(&v, 10);
    assert(v.size == 1);

    pop_back(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test() {
    test_push_back_empty_vector();
    test_push_back_full_vector();
    test_pop_back_not_empty_vector();
}

int main () {
    test();

    return 0;
}