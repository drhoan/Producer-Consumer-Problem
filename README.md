# Producer-Consumer Problem Using Condition Variables in C
## Objective:
Implement the Producer-Consumer problem using POSIX threads (pthreads), mutexes, and condition variables in C.

## Problem Statement:
You need to implement a bounded buffer where multiple producers generate data and multiple consumers retrieve it. The buffer should be thread-safe and protect shared resources using mutexes and condition variables.

## Requirements:
1. Implement a circular buffer of fixed size (e.g., 5 slots).

2. Use pthreads, mutexes, and condition variables to synchronize access.

3. Multiple producer threads should be able to add items to the buffer.

4. Multiple consumer threads should be able to remove items from the buffer.

5. Implement proper waiting and signaling so that:

  - Producers wait if the buffer is full.

  - Consumers wait if the buffer is empty.

6. Ensure no race conditions or deadlocks.

## Student tasks: 
- Filling in the missing wait and signal statements in the given placeholders.
- Observe behavior before and after synchronization.
- Compile and run the program:
    `gcc producer_consumer.c -o producer_consumer -pthread`
    `./producer_consumer`

## Expected Learning Outcomes:
- Understanding how condition variables synchronize threads.

- Learning to write and correctly place wait and signal operations.

- Avoiding race conditions and ensuring proper thread coordination.
