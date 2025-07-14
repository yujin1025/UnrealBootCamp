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
	// 기본 생성자
	SimpleVector() : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
	}

	// 용량 지정 생성자
	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
		data = new T[currentCapacity];
	}

	// 복사 생성자
	SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; ++i) {
			data[i] = other.data[i];
		}
	}

	// 소멸자
	~SimpleVector() {
		delete[] data;
	}

	// 인자로 받은 원소를 맨 뒤에 추가
	void push_back(const T& value) {
		if (currentSize >= currentCapacity) {
			return;
		}
		data[currentSize++] = value;
	}

	// 마지막 원소를 제거
	void pop_back() {
		if (currentSize > 0) {
			--currentSize;
		}
	}

	// 현재 원소의 개수를 반환
	int size() const {
		return currentSize;
	}

	// 현재 배열의 크기를 반환
	int capacity() const {
		return currentCapacity;
	}

	// 배열의 크기 재할당
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

	// 내부 데이터를 정렬하는 함수
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