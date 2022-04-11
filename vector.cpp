#include <iostream>
#include "vector.h"


vector:: vector() {
	data = 0;
	size = 0;
	capacity = 0;
}

vector:: vector(int capacity) {
	size = 0;
	this->capacity = capacity;
	data = new double[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = 0;
}

vector:: vector(const vector& v) {
	resize(v.size);
	data = new double[capacity];

	for (int i = 0; i < size ; i++)
		data[i] = v.data[i];
}

vector:: ~vector() {
	size = 0;
	capacity = 0;
	delete[] data;
}

void vector::resize(int newSize) {

	if (capacity > newSize)
		size = newSize;
	
	else {
		capacity = (newSize + 1) * 2;
		double* tempdata = new double[capacity];
		for (int i = 0; i < capacity; i++) {
			if (i < size)
				tempdata[i] = data[i];
			else
				tempdata[i] = 0;
		}
		size = newSize;
		delete[] data;
		data = tempdata;
	}
}

int vector::getsize() {
	return size;
}

void vector::pushback(double element) {
	
	if (capacity < size + 1)
		resize(size + 1);
	else
		size++;
	data[size - 1] = element;

}

double vector::popback() {
	double tmp = data[size];
	size--;
	return tmp;
}

vector& vector:: operator=(const vector& v) {
	if (&v == this)
		return *this;
	delete[] data;
	capacity = v.capacity;
	size = v.size;
	data = new double[capacity];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];



	return *this;
}

double vector::erase(int index) {
	double tmp = data[index];
	for (int i = index; i < size-1; i++)
		data[i] = data[i + 1];
	size--;
	return tmp;
}

void vector::insert(double element, int index) {
	resize(size + 1);
	for (int i = size - 1; i > index; i--)
		data[i] = data[i - 1];
	data[index] = element;
}