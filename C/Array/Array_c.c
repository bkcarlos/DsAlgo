#include "Array_c.h"
#include <stdlib.h>
#include <stdio.h>

Array* init_array(int capacity) {
    // �����ڴ�ռ�
    Array* array = (Array*)malloc(sizeof(Array));
    if(NULL == array) {
        printf("�����ڴ�ʧ��\n");
        return NULL;
    }

    array->data = (DATA_T*)malloc(capacity * sizeof(DATA_T));
    if(NULL == array->data) {
        printf("�����ڴ�ʧ��\n");
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
        printf("û�к��ʵ�����ָ��");
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
        printf("û�к��ʵ�����ָ��");
        return -1;
    }
    //��������Ƿ�Խ��
    if(index < 0 || index >= array->len) {
        printf("index �Ѿ�Խ��\n");
        return -1;
    }

    return array->data[index];
}

bool insert_array(Array* array, int index, DATA_T value) {
    if(NULL == array) {
        printf("û�к��ʵ�����ָ��");
        return false;
    }

    if(array->capacity == array->len) {
        printf("�����Ѿ���!!\n");
        return false;
    }

    //��������Ƿ�Խ��
    if(index < 0 || index > array->len) {
        printf("index �Ѿ�Խ��\n");
        return false;
    }

    // ��index ��ʼ����������ƶ�һ��λ��
    for(int i = array->len; i > index; --i) {
        array->data[i] = array->data[i - 1];
    }

    array->data[index] = value;
    ++array->len;
    return true;
}

bool remove_array(Array* array, int index) {
    if(NULL == array) {
        printf("û�к��ʵ�����ָ��");
        return false;
    }

    //��������Ƿ�Խ��
    if(index < 0 || index >= array->len) {
        printf("index �Ѿ�Խ��\n");
        return false;
    }

    // ��index ��ʼ��������ǰ�ƶ�һ��λ��
    for(int i = index + 1; i < array->len; ++i) {
        array->data[i - 1] = array->data[i];
    }

    --array->len;
    return true;
}

void printf_array_int(Array* array) {
    if(NULL == array) {
        printf("û�к��ʵ�����ָ��");
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