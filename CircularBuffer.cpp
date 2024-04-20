#include "CircularBuffer.h";

using namespace std;

CircularBuffer::CircularBuffer()
{
	Size = 0;
	Capacity = 2;
}

CircularBuffer::CircularBuffer(int size1, int capacity1)
{
	try {
		if (capacity1 < 1) {
			throw "CircularBuffer constructor: capacity must be greater than zero.\n";
		}
		Size = size1;
		Capacity = capacity1;
	}
	catch (const char* e) {
		cout << e;
	}
}

int CircularBuffer::size()
{
	return Size;
}

bool CircularBuffer::isEmpty()
{
	if (Size <= 0) {
		return true;
	}
	return false;
}

bool CircularBuffer::isFull()
{
	if (Size >= Capacity) {
		return true;
	}
	return false;
}

void CircularBuffer::enqueue(int16_t x)
{
	try {
		if (this->isFull()) {
			throw("enqueue: can't enqueue to a full ring.\n");
		}
		q1.push(x);
		Size++;
		if (Size >= Capacity) {
			Capacity *= 2;
		}
	}
	catch (const char* e) {
		cout << e;
	}
}

int16_t CircularBuffer::dequeue()
{
	try {
		if (this->isEmpty()) {
			throw "dequeue: can't dequeue from an empty ring.\n";
		}
		int16_t xReturn = q1.front();
		q1.pop();
		Size--;
		return xReturn;
	}
	catch (const char* e) {
		cout << e;
	}
}

int16_t CircularBuffer::peek()
{
	try {
		if (this->isEmpty()) {
			throw "peek: can't check an empty ring.\n";
		}
		return q1.front();
	}
	catch (const char* e)
	{
		cout << e;
	}
}