# simple-Memory_Allocator
Creating a memory allocator in C/C++ involves managing a fixed-size memory pool, allocating memory dynamically, and deallocating it when no longer needed. This process requires careful memory management to prevent memory leaks and fragmentation, ensuring efficient utilization of available memory resources.

The provided code is an implementation of a simple memory allocator in C. Here's a detailed description of the code:

1. **Memory Allocation Logic**:
   - The memory allocator manages a fixed-size memory pool (`memory_pool`) and maintains a linked list of memory blocks to keep track of allocated and free memory segments.
   - Each block in the memory pool is represented by the `Block` structure, which contains information about the size of the block, its allocation status (`free`), and a pointer to the next block.

2. **Initialization**:
   - The `initialize` function initializes the memory allocator by setting up the initial free block in the memory pool. It sets the size of the free block to the total memory size minus the size of the `Block` structure.

3. **Memory Allocation**:
   - The `allocate` function is responsible for allocating memory from the memory pool. It traverses the linked list of blocks to find a free block that can accommodate the requested size.
   - If a fitting block is found, it either allocates the entire block or splits it into two blocks if there's unused space.

4. **Memory Deallocation**:
   - The `deallocate` function deallocates memory previously allocated using the `allocate` function. It marks the corresponding block as free and merges adjacent free blocks if possible to prevent memory fragmentation.

5. **Main Function**:
   - The `main` function serves as a testbed for the memory allocator. It allocates memory for an array of integers, populates the array with values, prints the array, and then deallocates the memory.

6. **Error Handling**:
   - The code includes basic error handling to check for memory allocation failures and to ensure proper initialization of the memory allocator.

7. **Comments and Readability**:
   - The code includes comments to explain the purpose of each function and important code segments, enhancing its readability and maintainability.

Overall, this memory allocator provides a basic framework for managing dynamic memory allocation in C programs. It demonstrates fundamental concepts such as memory pooling, block splitting, and linked list management, which are essential for understanding more complex memory management systems.
