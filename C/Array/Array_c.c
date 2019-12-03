#include "Array_c.h"
#include <stdlib.h>
#include <stdio.h>

Array* init_array(int capacity) {
    // 分配内存空间
    Array* array = (Array*)malloc(sizeof(Array));
    if(NULL == array) {
        printf("申请内存失败\n");
        return NULL;
    }

    array->data = (DATA_T*)malloc(capacity * sizeof(DATA_T));
    if(NULL == array->data) {
        printf("申请内存失败\n");
        free(array);
        return NULL;
    }

    array->capacity = capacity;
    array->len = 0;

    return array;
}

int find_array(Array* array, DATA_T value) {
    int pos = -1;

    if(NULL == array) {
        printf("没有合适的数组指针");
        return pos;
    }

    for(int i = 0; i < array->len; ++i) {
        if(value == array->data[i]) {
            pos = i;
            break;
        }
    }

    return pos;
}

int get_array(Array* array, int index) {
    if(NULL == array) {
        printf("没有合适的数组指针");
        return -1;
    }
    //检查数据是否越界
    if(index < 0 || index >= array->len) {
        printf("index 已经越界\n");
        return -1;
    }

    return array->data[index];
}

bool insert_array(Array* array, int index, DATA_T value) {
    if(NULL == array) {
        printf("没有合适的数组指针");
        return false;
    }

    if(array->capacity == array->len) {
        printf("数组已经满!!\n");
        return false;
    }

    //检查数据是否越界
    if(index < 0 || index > array->len) {
        printf("index 已经越界\n");
        return false;
    }

    // 将index 开始的数据向后移动一个位置
    for(int i = array->len; i > index; --i) {
        array->data[i] = array->data[i - 1];
    }

    array->data[index] = value;
    ++array->len;
    return true;
}

bool remove_array(Array* array, int index) {
    if(NULL == array) {
        printf("没有合适的数组指针");
        return false;
    }

    //检查数据是否越界
    if(index < 0 || index >= array->len) {
        printf("index 已经越界\n");
        return false;
    }

    // 将index 开始的数据向前移动一个位置
    for(int i = index + 1; i < array->len; ++i) {
        array->data[i - 1] = array->data[i];
    }

    --array->len;
    return true;
}

void printf_array_int(Array* array) {
    if(NULL == array) {
        printf("没有合适的数组指针");
    }

    for(int i = 0; i < array->len; ++i) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int array_test(int argc, char** argv) {
    Array* array = init_array(5);

    insert_array(array, 0, 3);
    insert_array(array, 0, 4);
    insert_array(array, 1, 5);
    insert_array(array, 3, 9);
    insert_array(array, 3, 10);

    printf("%d\n", find_array(array, 4));
    remove_array(array, 0);

    printf_array_int(array);

    free(array->data);
    free(array);

    return 1;
}