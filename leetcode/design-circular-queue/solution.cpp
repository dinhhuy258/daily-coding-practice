class MyCircularQueue {
private:
    std::vector<int> data;
    int lastPosition = 0;
    int firstPosition = 0;
    int count = 0;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        size = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }


        data[lastPosition++] = value;
        if (lastPosition == size) {
            lastPosition = 0;
        }
        ++count;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        ++firstPosition;
        --count;
        if (firstPosition == size) {
            firstPosition = 0;
        }

        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return data[firstPosition];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return data[lastPosition - 1 < 0 ? size - 1 : lastPosition - 1];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

