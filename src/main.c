#include <stdio.h>
#include <stdlib.h>
#include "intvector.h"

void printmas(int *array, size_t capacity)
{
    for (int i = 0; i < capacity; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

int main(){
    size_t capacity=10;
    //1
    intvector *array=int_vector_new(capacity);
    printf("Array new:");
    printmas(array->data, int_vector_get_capacity(array));
    //2
    for(int i=0;i<capacity-1;i++){
	int_vector_set_item(array,i,i+1);
    }
    printf("Set array:");
    printmas(array->data, int_vector_get_capacity(array));
    //3
    int get=int_vector_get_item(array,2);
    printf("Get item:%d\n\n",get);
    //4
    printf("Size:%ld\n\n",int_vector_get_size(array));
    //5
    printf("Capacity:%ld\n\n",int_vector_get_capacity(array));
    //6
    int_vector_push_back(array,5);
    printf("First push back array:");
    printmas(array->data, int_vector_get_capacity(array));
    printf("Second push back array:");
    int_vector_push_back(array,5);
    printmas(array->data, int_vector_get_capacity(array));
    //7
    int_vector_pop_back(array);
    printf("Pop back array:");
    printmas(array->data, int_vector_get_capacity(array));
    //8
    printf("Shrink to fit:%d\n\n",int_vector_shrink_to_fit(array));
    //9
    printf("Resize>:%d\n\n",int_vector_resize(array,12));
    printf("Resize<:%d\n\n",int_vector_resize(array,8));
    printf("Resize=:%d\n\n",int_vector_resize(array,8));
    //10
    printf("Reserve:%d\n\n",int_vector_reserve(array,10));
    //11
    intvector *carray= int_vector_copy(array);
    printf("Copy array:");
    printmas(carray->data,int_vector_get_capacity(array));
    //12
    int_vector_free(array);
    int_vector_free(carray);
}
