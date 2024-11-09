#include "RingBufferQueue.h"
#include "SimpleTest.h"

using namespace std;
const int kDefaultCapacity = 10;
/**
 * TODO: write a method comment
 */
RBQueue::RBQueue() {
    _capacity = kDefaultCapacity;
    _elements = new int[_capacity];
    _head = 0;
    _numUsed = 0;

    // We can also use the `this` keyword
    // this->_capacity = kDefaultCapacity;
    // this->_elements = new int[_capacity];
    // this->_head = 0;
    // this->_numUsed = 0;

}

/**
 * TODO: write a method comment
 */
RBQueue::~RBQueue() {
    // Delete these lines, then implement
    // this method.
    delete[] _elements;
}

/**
 * TODO: write a method comment
 */
void RBQueue::enqueue(int elem) {
    if (isFull()) {
        error("Can't enqueue to already full queue!");
    }

    int tail = (_head + _numUsed) % _capacity;
    _elements[tail] = elem;
    _numUsed++;
}

/**
 * TODO: write a method comment
 */
int RBQueue::dequeue() {
    if (isEmpty()) {
        error("Can't dequeue from an empty queue!");
    }

    int front = _elements[_head];
    _head = (_head + 1) % _capacity;
    _numUsed--;
    return front;
}

/**
 * TODO: write a method comment
 */
int RBQueue::peek() {
    if (isEmpty()) {
        error("Can't peek from an empty queue!");
    }

    return _elements[_head];
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isEmpty() {
    return _numUsed == 0;
}

/**
 * TODO: write a method comment
 */
bool RBQueue::isFull() {
    return _numUsed == _capacity;
}

/**
 * TODO: write a method comment
 */
int RBQueue::size() {
    return _numUsed;
}

/**
 * TODO: write a method comment
 */
ostream& operator<<(ostream& out, const RBQueue& queue) {
    // The following lines are just here to
    // disable compiler warnings and errors.
    // Delete these lines, then implement
    // this method.
    (void) queue;
    return out;
}

/* Provided Tests Below This Line */

PROVIDED_TEST("Simple Example From Handout") {
    RBQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQUAL(q.peek(), 1);
    q.enqueue(4);
    q.enqueue(5);
    EXPECT(!q.isFull());
    EXPECT_EQUAL(q.dequeue(), 1);
    EXPECT_EQUAL(q.dequeue(), 2);
    EXPECT_EQUAL(q.peek(), 3);
    q.enqueue(6);
    EXPECT_EQUAL(q.dequeue(), 3);
    EXPECT_EQUAL(q.dequeue(), 4);
    EXPECT_EQUAL(q.dequeue(), 5);
    EXPECT_EQUAL(q.dequeue(), 6);
    EXPECT(q.isEmpty());
}
