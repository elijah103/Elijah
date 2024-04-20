#include "CircularBuffer.h"

int main(int argc, char* argv[])
{
	CircularBuffer A(0, 0);
	CircularBuffer B(0, 1);
	CircularBuffer C(1, 1);
	int16_t x = 5;
	C.enqueue(x);
	CircularBuffer D(0, 1);
	D.enqueue(x);
	D.dequeue();
	D.dequeue();
	D.peek();
	return 0;
}