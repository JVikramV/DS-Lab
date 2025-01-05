#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    if (queue) {
        queue->front = 0;
        queue->rear = 0;
        queue->size = 0;
    } else {
        return NULL; // Explicitly return NULL if malloc fails
    }
    return queue;
}

void myQueuePush(MyQueue* queue, int value) {
    if (queue == NULL || queue->size == MAX_QUEUE_SIZE) return;
    
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->size++;
}

int myQueuePop(MyQueue* queue) {
    if (queue == NULL || queue->size == 0) return -1;

    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return value;
}

int myQueuePeek(MyQueue* queue) {
    if (queue == NULL || queue->size == 0) return -1;

    return queue->data[queue->front];
}

bool myQueueEmpty(MyQueue* queue) {
    if (queue == NULL) return true;

    return (queue->size == 0);
}

void myQueueFree(MyQueue* queue) {
    if (queue == NULL) return;
    free(queue);
}
