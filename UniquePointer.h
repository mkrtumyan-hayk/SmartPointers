#pragma once

template <typename T>
class UniquePointer {
public:

	UniquePointer() {
	}

	UniquePointer(T* ptr) {
		this->ptr = ptr;
	}

	UniquePointer(const UniquePointer<T>& other) = delete;

	UniquePointer& operator = (const UniquePointer<T>& other) = delete;

	T* get() {
		return ptr;
	}

	void swap(UniquePointer& other) {

		if (this->ptr == other.ptr) {
			return;
		}


		T* temp = this->ptr;
		this->ptr = other.ptr;
		other.ptr = temp;

	}

	void reset() {
		delete ptr;
		ptr = nullptr;
	}

	void release() {
		ptr = nullptr;
	}


	~UniquePointer() {
		delete ptr;
	}

private:
	T* ptr;

};