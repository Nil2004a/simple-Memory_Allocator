#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MEMORY_SIZE 1024 
char memory_pool[MEMORY_SIZE];
typedef struct Block {
    size_t size;
    bool free;
    struct Block *next;
} Block;
Block *freeList = (Block*)memory_pool;
void initialize() {
    freeList->size = MEMORY_SIZE - sizeof(Block);
    freeList->free = true;
    freeList->next = NULL;
}
void split(Block *fitting_slot, size_t size) {
    Block *newBlock = (Block*)((char*)fitting_slot + size + sizeof(Block));
    newBlock->size = fitting_slot->size - size - sizeof(Block);
    newBlock->free = true;
    newBlock->next = fitting_slot->next;
    fitting_slot->size = size;
    fitting_slot->free = false;
    fitting_slot->next = newBlock;
}
void *allocate(size_t size) {
    Block *current, *prev;
    void *result;
    if (!(freeList->size)) {
        initialize();
        printf("Memory initialized\n");
    }
    current = freeList;
    while (((current->size) < size || !(current->free)) && (current->next != NULL)) {
        prev = current;
        current = current->next;
    }
    if ((current->size) == size) {
        current->free = false;
        result = (void*)(current + 1);
        return result;
    } else if ((current->size) > (size + sizeof(Block))) {
        split(current, size);
        result = (void*)(current + 1);
        return result;
    }
    return NULL;
}
void deallocate(void *ptr) {
    if (((void*)memory_pool <= ptr) && (ptr <= (void*)(memory_pool + MEMORY_SIZE))) {
        Block *current = (Block*)ptr - 1;
        current->free = true;
        Block *temp = freeList;
        while (temp != NULL) {
            if (temp->free && temp->next && temp->next->free) {
                temp->size += temp->next->size + sizeof(Block);
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
    }
}
int main() {
    printf("Memory allocator \n");
    int *array = (int*)allocate(10 * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    //[changes can be made]
    for (int i = 0; i < 10; i++) {
        array[i] = i + 1;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", array[i * 5 + j]);
        }
        printf("\n");
    }
    //[changes can be made]
    deallocate(array);
    return 0;
}
