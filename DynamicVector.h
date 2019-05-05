#pragma once
#include "Recordings.h"

template <typename T>
class DynamicVector {
private:
	T *recordings_vector;
	int capacity;
	int size;
public:
	DynamicVector();
	DynamicVector(const DynamicVector<T>& vector);
	DynamicVector<T>& operator=(const DynamicVector<T>& vector);
	void AddElement(T element);
	void DeleteElement(T element);
	void UpdateElement(T element);
	int FoundElement(T element);
	int getNumberOfElements();
	T* getAllElems() const;
	T getElem(int index) const;
	int GetSize() const;
	int Filtered(char location[], int times_accessed, int starting_point);
	~DynamicVector();
};

template <typename T>
DynamicVector<T>::DynamicVector()
{
	this->capacity = 200;
	this->size = 0;
	this->recordings_vector = new T[this->capacity];
}
template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->recordings_vector = new T[this->capacity];

	for (int index = 0; index < this->size; index++)
		this->recordings_vector[index] = vector.recordings_vector[index];
}
template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& vector) {
	if (this == &vector)
		return *this;

	this->size = vector.size;
	this->capacity = vector.capacity;

	delete[] this->recordings_vector;
	this->recordings_vector = new TElem[this->capacity];
	for (int index = 0; index < this->size; index++)
		this->recordings_vector[index] = vector.recordings_vector[index];

	return *this;
}

template <typename T>
void DynamicVector<T>::AddElement(T element) 
{
	int index_element = FoundElement(element);

	if (index_element != -1)
		throw std::invalid_argument("The recording already exists!");
	else
	{
		if (this->size == this->capacity)
		{
			this->capacity *= 2;
			T *new_vector = new T[this->capacity];
			for (int index = 0; index < this->size; index++)
				new_vector[index] = this->recordings_vector[index];

			delete[] this->recordings_vector;
			this->recordings_vector = recordings_vector;
		}
		this->recordings_vector[this->size] = element;
		this->size++;
	}
}
template <typename T>
void DynamicVector<T>::DeleteElement(T element) {
	int index_element = FoundElement(element);

	if (index_element == -1)
		throw std::invalid_argument("That recording does not exist!");
	else {
		for (int index = index_element; index < this->size - 1; index++) {
			this->recordings_vector[index] = this->recordings_vector[index + 1];
		}
		this->size--;
	}
}
template <typename T>
void DynamicVector<T>::UpdateElement(T element) {
	int index_found_element = FoundElement(element);

	if (index_found_element == -1)
		throw invalid_argument("The required recording does not exist!");
	else {
		this->recordings_vector[index_found_element].setLocation(element.getLocation());
		this->recordings_vector[index_found_element].setCreationDate(element.getCreationDate());
		this->recordings_vector[index_found_element].setTimesAccessed(element.getTimesAccessed());
		this->recordings_vector[index_found_element].setFootagePreview(element.getFootagePreview());
	}
}
template <typename T>
int DynamicVector<T>::FoundElement(T element)
{
	for (int index = 0; index < this->size; index++) {
		if (strcmp(this->recordings_vector[index].getTitle(), element.getTitle()) == 0)
			return index;
	}
	return -1;
}
template <typename T>
int DynamicVector<T>::Filtered(char location[],int times_accessed,int starting_point)
{
	for (int index = starting_point; index < this->size; index++) {
		if (strstr(this->recordings_vector[index].getLocation(), location) != NULL  && this->recordings_vector[index].getTimesAccessed()<times_accessed)
			return index;
	}
	return -1;
}
template <typename T>
int DynamicVector<T>::getNumberOfElements() 
{
	return this->size;
}
template <typename T>
T* DynamicVector<T>::getAllElems() const
{
	return this->recordings_vector;
}

template <typename T>
T DynamicVector<T>::getElem(int index) const
{
	return this->recordings_vector[index];
}
template <typename T>
int DynamicVector<T>::GetSize() const
{
	if (this->size == 0)
		std::exception("Size is 0");
	return this->size;
}
template <typename T>
DynamicVector<T>::~DynamicVector() {
	delete[] this->recordings_vector;
}