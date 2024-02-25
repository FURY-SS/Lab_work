// Created by vadim on 25.02.2024.

#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений.
vector create_vector(size_t capacity);

// изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t new_capacity);

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v);

// освобождает память, выделенную поднеиспользуемые элементы.
void vector_shrink_to_fit(vector *v);

// освобождает память, выделенную вектору.
void delete_vector(vector *v);

#endif //UNTITLED_VECTOR_H