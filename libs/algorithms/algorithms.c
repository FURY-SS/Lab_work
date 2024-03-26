// Created by Vadim on 07.02.2024.

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int get_max(int *a, int n) {
    int max = a[0];

    for (size_t i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

int get_min(int *a, int n) {
    int min = a[0];

    for (size_t i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}