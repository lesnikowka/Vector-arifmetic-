#pragma once
#include <iostream>


class vector {
	double* data = 0;
	int size = 0;
	int capacity = 0;

	friend std::ostream& operator<< (std::ostream& out, const vector& v) {
		out << "(";
		for (int i = 0; i < v.size; i++)
			out << v.data[i] << "  ";
		out << ")" << std::endl;
		return out;
	}


public:


	vector();
	vector(int capacity);
	~vector();
	vector(const vector& v);

	int getsize();

	void resize(int newSize);

	void pushback(double element);

	double erase(int index);

	void insert(double element, int index);

	vector& operator=(const vector&v);

	double popback();
};