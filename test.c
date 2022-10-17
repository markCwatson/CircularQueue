#include "assert.h"
#include "cqueue/cqueue.h"

int main(int argc, int** argv)
{
    // Test setup
    int test_data[6] = {1, 2, 3, 4, 5, 6};
    cqueue_s myCqueue;
    cqueue_init(&myCqueue, 5, sizeof(int), NULL);

    // Test 1: Inserting one element into an empty cqueue
    int peek;
    assert(("Test 1a: cqueue is empty", cqueue_is_empty(&myCqueue) == 1));
    cqueue_enque(&myCqueue, &test_data[0]);
    cqueue_peek(&myCqueue, &peek);
    assert(("Test 1b: valid element", peek == test_data[0]));
    assert(("Test 1c: Valid size", 1 == cqueue_get_size(&myCqueue)));

    // Test 2: Inserting one element into a non-empty cqueue
    cqueue_enque(&myCqueue, &test_data[1]);
    cqueue_peek(&myCqueue, &peek);
    assert(("Test 2a: valid element", peek == test_data[0]));
    assert(("Test 2b: Valid size", 2 == cqueue_get_size(&myCqueue)));

    // Test 3: Fill cqueue
    int dequeue;

    for (int i = 2; i < 6; i++)
    {
        cqueue_enque(&myCqueue, &test_data[i]);
        assert(("Test 3a: Valid size", (i + 1) > 5 ? 5 : (i + 1) == cqueue_get_size(&myCqueue)));
    }

    for (int i = 1; i < 5; i++)
    {
        cqueue_deque(&myCqueue, &dequeue);
        assert(("Test 3b: valid element", dequeue == test_data[i]));
        assert(("Test 3c: Not empty", cqueue_is_empty(&myCqueue) == 0));
    }

    cqueue_deque(&myCqueue, &dequeue);
    assert(("Test 3d: valid element", dequeue == test_data[5]));
    assert(("Test 3e: cqueue is empty", cqueue_is_empty(&myCqueue) == 1));

    // Test 4: Inersting another element into a cqueue that has been filled then emptied.
    cqueue_enque(&myCqueue, &test_data[0]);
    cqueue_peek(&myCqueue, &peek);
    assert(("Test 4a: valid element", peek == test_data[0]));
    assert(("Test 4b: Not empty", cqueue_is_empty(&myCqueue) == 0));
    assert(("Test 4c: Valid size", 1 == cqueue_get_size(&myCqueue)));
    cqueue_deque(&myCqueue, &dequeue);
    assert(("Test 4d: valid element", dequeue == test_data[0]));
    assert(("Test 4e: cqueue is empty", cqueue_is_empty(&myCqueue) == 1));

    // Test 5: Long term/several cycles through cqueue
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cqueue_enque(&myCqueue, &test_data[j]);
        }

        cqueue_peek(&myCqueue, &peek);
        assert(("Test 5a: valid element", peek == test_data[0]));
        assert(("Test 5b: Not empty", cqueue_is_empty(&myCqueue) == 0));
        assert(("Test 5c: Valid size", 5 == cqueue_get_size(&myCqueue)));
    }

    // Test teardown
    cqueue_close(&myCqueue);

    printf("All tests passed!");

    return 0;
}