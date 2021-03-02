#include <stdio.h>
int main() {
    int id = 3;
    int *p_id = &id;
    printf("int: %d\n", id);
    printf("int with &: %p\n", &id);
    printf("pointers start now: \n");
    printf("pointer with no * : %p\n", p_id);
    printf("pointer with * : %p\n", *p_id);
    printf("pointer with & : %p\n", &p_id);
    printf("pointer printed with d : %d\n", *p_id);
    printf("pointer printed with a d and no * : %d\n", p_id);
}