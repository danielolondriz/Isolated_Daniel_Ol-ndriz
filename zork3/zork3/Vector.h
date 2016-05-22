#ifndef MY_VECTOR
#define MY_VECTOR
#include<assert.h>

typedef unsigned int uint;
template<class TYPE>
class Vector{
private:
	TYPE *buffer;
	uint capacity = 10;
	uint num_elements = 0;
public:
	//Room *rooms;

public:
	Vector(){
		buffer = new TYPE[capacity];
	}

	Vector(uint size){
		capacity = size;
		buffer = new TYPE[capacity];
	}

	Vector(const Vector& otherclas){
		capacity = otherclas.capacity;
		num_elements = otherclas.num_elements;
		buffer = new TYPE[capacity];
		for (uint i = 0; i < num_elements; i++){
			buffer[i] = otherclas.buffer[i];
		}

	}
	void Push_back(const TYPE &element){
		if (capacity == num_elements){
			TYPE *temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];
			for (uint i = 0; i < num_elements; i++){
				*(temp + i) = *(buffer + i);
			}
			delete[] buffer;
			buffer = temp;
		}
		*(buffer + (num_elements++)) = element;
	}
	void pushfront(const TYPE &element){
		if (capacity == num_elements){
			TYPE *temp = nullptr;
			capacity *= 2;
			temp = new TYPE[capacity];
			for (int i = num_elements; i >= 0; i--){
				*(temp + i + 1) = *(buffer + i + 1);
			}
			delete[] buffer;
			buffer = temp;
		}
		for (int i = num_elements; i >= 0; i--){
			*(buffer + i + 1) = *(buffer + i);
		}
		*(buffer) = element;
		num_elements++;
	}

	TYPE operator[](uint index)const{
		assert(index < num_elements);
		return buffer[index];
	}

	TYPE operator[](uint index){
		assert(index < num_elements);
		return buffer[index];
	}

	void clean(){
		num_elements = 0;
	}

	bool empty(){
		for (TYPE i = 0; i < num_elements; i++){
			if (buffer[i] != NULL){
				return false;
			}
		}
		return true;
	}

	uint size(){
		return num_elements;
	}

	TYPE mcapacity(){
		return capacity;
	}

	bool pop_back(TYPE& value){
		if (num_elements > 0){
			num_elements--;
			value = buffer[num_elements];
			return true;
		}
		return false;
	}

	void shrink_to_fit(){
		capacity = num_elements;
		buffer = new TYPE[capacity];
	}


	~Vector(){
		delete[]buffer;
	}

	

};
#endif