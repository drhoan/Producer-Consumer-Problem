#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5  // Size of the shared buffer
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2
#define NUM_ITEMS 10    // Number of items each producer produces

// Shared buffer
int buffer[BUFFER_SIZE];
int count = 0; // Number of items in buffer
int in = 0;    // Points to the next free position
int out = 0;   // Points to the next item to consume

// Synchronization variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

// Producer function
void* producer(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < NUM_ITEMS; i++) {
        int item = rand() % 100;  // Produce a random item
        
        pthread_mutex_lock(&mutex);
        
        while (count == BUFFER_SIZE) {
            // TODO: Implement the wait condition when the buffer is full

        }

        // Add item to buffer
        buffer[in] = item;
        printf("Producer %d produced: %d\n", id, item);
        in = (in + 1) % BUFFER_SIZE;
        count++;

        // TODO: Signal the consumers that buffer is not empty

        
        pthread_mutex_unlock(&mutex);

        usleep(rand() % 100000); // Simulate processing time
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < NUM_ITEMS; i++) {
        
        pthread_mutex_lock(&mutex);
        
        while (count == 0) {
            // TODO: Implement the wait condition when the buffer is empty

        }

        // Remove item from buffer
        int item = buffer[out];
        printf("Consumer %d consumed: %d\n", id, item);
        out = (out + 1) % BUFFER_SIZE;
        count--;

        // TODO: Signal the producers that buffer is not full

        
        pthread_mutex_unlock(&mutex);

        usleep(rand() % 150000); // Simulate processing time
    }
    return NULL;
}

int main() {
    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];
    int producer_ids[NUM_PRODUCERS], consumer_ids[NUM_CONSUMERS];

    // Create producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producer_ids[i] = i + 1;
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
    }

    // Create consumer threads
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumer_ids[i] = i + 1;
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }

    // Join producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    // Join consumer threads
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    printf("All producer and consumer threads have finished.\n");
    return 0;
}
