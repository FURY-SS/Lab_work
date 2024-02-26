#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"

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

void test_at_vector_not_empty_vector() {
    int array[] = {5};
    vector v = {array, 1, 1};

    int* element = at_vector(&v, 0);
    assert(*element == 5);
}

void test_at_vector_request_to_last_element() {
    int array[] = {1, 2, 3, 4, 5};
    vector v = {array, 5, 5};

    int *last_element = at_vector(&v, v.size - 1);
    assert(*last_element == 5);
}

void test_back_one_element_in_vector() {
    int array[] = {1, 2, 3};
    vector v = {array, 3, 3};

    int* element = back(&v);
    assert(*element == 3);
}

void test_front_one_element_in_vector() {
    int array[] = {1,2,3};
    vector v = {array, 3, 3};

    int* element = front(&v);

    assert(*element == 1);
}

void test() {
    test_push_back_empty_vector();
    test_push_back_full_vector();
    test_pop_back_not_empty_vector();
    test_at_vector_not_empty_vector();
    test_at_vector_request_to_last_element();
    test_back_one_element_in_vector();
    test_front_one_element_in_vector();
}

int main () {
    test();

    return 0;
}