#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vector_void.h"

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

void test_vector() {
    test_push_back_empty_vector();
    test_push_back_full_vector();
    test_pop_back_not_empty_vector();
    test_at_vector_not_empty_vector();
    test_at_vector_request_to_last_element();
    test_back_one_element_in_vector();
    test_front_one_element_in_vector();
}

void test_push_back_v_empty_vector() {
    vector_void v = create_vector_void(0, sizeof(int));
    v.size = 0;
    assert(is_empty_v(&v));

    int x = 1;
    push_back_v(&v, &x);

    assert(v.size == 1 && v.capacity == 1);
}


void test_push_back_v_full_vector() {
    vector_void v = create_vector_void(1, sizeof(float));
    v.size = 1;
    assert(is_full_v(&v));

    float x = 2.3;
    push_back_v(&v, &x);

    assert(v.size == 2 && v.capacity == 2);
}

void test_get_vector_value_v() {
    float array[] = {5.55, 6.56, 7.243};
    vector_void v = {array, 3, 3, sizeof(float)};

    float x = 8.23;
    float y = 7.243;
    get_vector_value_v(&v, 2, &x);

    assert(is_full_v(&v));
    assert(x == y);
}

void test_set_vector_value_v() {
    float array[] = {5.55, 6.56, 7.243};
    vector_void v = {array, 3, 3, sizeof(float)};

    float x = 8.23;
    set_vector_value_v(&v, 2, &x);

    assert(is_full_v(&v));
}

void test_vector_shrink_to_fit_v() {
    int array[] = {1, 2, 3};
    vector_void v = {array, 3, 30, sizeof(int)};

    vector_shrink_to_fit_v(&v);
    assert(is_full_v(&v));
}

void test_clear_v() {
    int array[] = {1, 2, 3};
    vector_void v = {array, 3, 3, sizeof(int)};

    clear_v(&v);
    assert(is_empty_v(&v));
}

void test_pop_back_v() {
    int array[] = {1, 2, 3};
    vector_void v = {array, 3, 3, sizeof(int)};

    pop_back_v(&v);
    assert(v.size == 2);
}

void test_vector_void() {
    test_push_back_v_empty_vector();
    test_push_back_v_full_vector();
    test_get_vector_value_v();
    test_set_vector_value_v();
    test_vector_shrink_to_fit_v();
    test_clear_v();
}

void test() {
    test_vector();
    test_vector_void();
}

int main () {
    test();

    return 0;
}