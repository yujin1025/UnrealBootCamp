#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	// �⺻ ������
	SimpleVector() : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
	}

	// �뷮 ���� ������
	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
		data = new T[currentCapacity];
	}

	// ���� ������
	SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; ++i) {
			data[i] = other.data[i];
		}
	}

	// �Ҹ���
	~SimpleVector() {
		delete[] data;
	}

	// ���ڷ� ���� ���Ҹ� �� �ڿ� �߰�
	void push_back(const T& value) {
		if (currentSize >= currentCapacity) {
			return;
		}
		data[currentSize++] = value;
	}

	// ������ ���Ҹ� ����
	void pop_back() {
		if (currentSize > 0) {
			--currentSize;
		}
	}

	// ���� ������ ������ ��ȯ
	int size() const {
		return currentSize;
	}

	// ���� �迭�� ũ�⸦ ��ȯ
	int capacity() const {
		return currentCapacity;
	}

	// �迭�� ũ�� ���Ҵ�
	void resize(int newCapacity) {
		if (newCapacity <= currentCapacity) return;

		T* newData = new T[newCapacity];
		for (int i = 0; i < currentSize; ++i) {
			newData[i] = data[i]; 
		}
		delete[] data;

		data = newData; 
		currentCapacity = newCapacity;
	}

	// ���� �����͸� �����ϴ� �Լ�
	void sortData() {
		std::sort(data, data + currentSize);
	}

	void print() const {
		for (int i = 0; i < currentSize; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};