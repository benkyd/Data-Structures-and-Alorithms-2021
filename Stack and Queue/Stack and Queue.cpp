#include <iostream>
#include <vector>

class Stack
{
public:
    Stack(int size)
    {
        mStorage = (int*)malloc(size * sizeof(int));
        if (mStorage != nullptr)
               memset(mStorage, NULL, size);
        mSize = size;
        mTop = 0;
    }

    ~Stack()
    {
        delete mStorage;
    }

    void Push(int elem)
    {
        if (mTop > mSize)
            return;
        mStorage[mTop] = elem;
        mTop++;
    }

    int Pop()
    {
        mTop--;
        int elem = mStorage[mTop];
        mStorage[mTop] = NULL;
        return elem;
    }

    int Peek()
    {
        return mStorage[mTop - 1];
    }

    size_t Length()
    {
        return mTop;
    }

private:
    int* mStorage;
    int mSize;
    int mTop;
};

class Queue
{
public:
    Queue(int size)
    {
        mStorage = (int*)malloc(size * sizeof(int));
        if (mStorage != nullptr)
            memset(mStorage, NULL, size);
        mSize = size;
        mHead = 0;
        mLength = 0;
        mTail = size - 1;
    }

    ~Queue()
    {
        delete mStorage;
    }

     // adds to tail
    void Enqueue(int elem)
    {
        mTail = (mTail + 1) % mSize;
        mStorage[mTail] = elem;
        mLength++;
    }

    // deletes head
    int Dequeue()
    {
        int elem = mStorage[mHead];
        mHead = (mHead + 1) % mSize;
        mLength--;
        return elem;
    }

    int Peek()
    {
        return mStorage[mHead];
    }

    size_t Length()
    {
        return mLength;
    }

private:
    int* mStorage;
    int mSize;
    int mLength;
    int mHead, mTail;
};

class StackWithQueue : public Queue
{
public:
    StackWithQueue(int size)
        : Queue(size)
    {
    }

    void Push(int elem)
    {
        Enqueue(elem);
    }

    int Pop()
    {
        for (int i = 0; i < Length() - 1; i++)
        {
            Enqueue(Dequeue());
        }
        return Dequeue();
    }
};

class QueueWithStack : public Stack
{
public:
    QueueWithStack(int size)
        : Stack(size)
    {
    }

    void Enqueue(int elem)
    {
        Push(elem);
    }

    int Dequeue()
    {
        std::vector<int> temp;
        std::cout << "length " << Length();
        for (int i = 0; i < Length() - 1; i++)
        {
            temp.push_back(Pop());
        }
        int elem = Pop();
        for (int i = temp.size(); i > 0; i--)
        {
            Push(temp[i]);
        }
        return elem;
    }
};

int main()
{
    Stack stack{ 50 };
    stack.Push(10);
    stack.Push(9);
    stack.Push(8);
    stack.Push(7);
    stack.Push(6);

    std::cout << stack.Pop() << std::endl;
    std::cout << stack.Pop() << std::endl;
    std::cout << stack.Pop() << std::endl;
    std::cout << stack.Pop() << std::endl;

    // should be 1
    std::cout << stack.Length() << std::endl << std::endl;

    Queue queue{ 50 };
    queue.Enqueue(6);
    queue.Enqueue(5);
    queue.Enqueue(4);
    queue.Enqueue(3);
    queue.Enqueue(2);
    queue.Enqueue(1);

    std::cout << queue.Dequeue() << std::endl;
    std::cout << queue.Dequeue() << std::endl;
    std::cout << queue.Dequeue() << std::endl;
    std::cout << queue.Dequeue() << std::endl;
    std::cout << queue.Length() << std::endl << std::endl;

    StackWithQueue stackWithQueue{ 50 };
    stackWithQueue.Push(9);
    stackWithQueue.Push(8);
    stackWithQueue.Push(7);
    stackWithQueue.Push(6);
    stackWithQueue.Push(5);

    std::cout << stackWithQueue.Pop() << std::endl;
    std::cout << stackWithQueue.Pop() << std::endl;
    std::cout << stackWithQueue.Pop() << std::endl;
    std::cout << stackWithQueue.Pop() << std::endl << std::endl;

    QueueWithStack queueWithStack{ 50 };
//    queueWithStack.Enqueue(9);
    queueWithStack.Enqueue(8);
    queueWithStack.Enqueue(7);
    queueWithStack.Enqueue(6);
    queueWithStack.Enqueue(5);
    queueWithStack.Enqueue(4);

    std::cout << queueWithStack.Dequeue() << std::endl;
    std::cout << queueWithStack.Dequeue() << std::endl;
    std::cout << queueWithStack.Dequeue() << std::endl;
    std::cout << queueWithStack.Dequeue() << std::endl;
    std::cout << queueWithStack.Dequeue() << std::endl;

}

