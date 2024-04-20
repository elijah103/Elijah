#include <iostream>
#include <stdint.h>
#include <queue>
#include <stdexcept>

using namespace std;

class CircularBuffer
{
public:
	CircularBuffer();
	CircularBuffer(int size1, int capacity1);
	int size();
	bool isEmpty();
	bool isFull();
	void enqueue(int16_t x);
	int16_t dequeue();
	int16_t peek();
	queue <int> q1;
	int Size = 0;
	int Capacity = 0;
private:
};