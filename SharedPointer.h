#pragma once

template <typename T>
class SharedPointer {
public:

	SharedPointer() {
	}

	SharedPointer(T* ptr) {
		this->ptr = ptr;
		ptr_count = new int(1);

	}

	SharedPointer(const SharedPointer& other) {
		++(*other.ptr_count);

		this->ptr_count = other.ptr_count;

		this->ptr = other.ptr;
	}

	SharedPointer& operator=(const SharedPointer& other) {
		if (this != &other) {
			++(*other.ptr_count);

			if (this->ptr_count != 0) {
				delete this->ptr;
			}
			this->ptr_count = other.ptr_count;

			this->ptr = other.ptr;
		}

		return *this;
	}

	void reset() {
		if (*(ptr_count) == 1) {
			delete ptr;
		}
		ptr = nullptr;

		--(*ptr_count);
	}

	T* get() {
		return ptr;
	}

	void swap(SharedPointer& other) {

		if (this->ptr == other.ptr) {
			return;
		}

		T* temp = this->ptr;
		this->ptr = other.ptr;
		other.ptr = temp;
	}

	~SharedPointer() {
		if (*(ptr_count) == 1) {
			delete ptr;
		}
		--(*ptr_count);
	}

private:

	int* ptr_count;
	T* ptr;
};