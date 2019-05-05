/*#include "DynamicVector.h"
#include <stdexcept>

DynamicVector::DynamicVector() 
{
	this->capacity = 200;
	this->size = 0;
	this->recordings_vector = new TElem[this->capacity];
}

DynamicVector::DynamicVector(const DynamicVector& vector) 
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->recordings_vector= new TElem[this->capacity];

	for (int index = 0; index < this->size; index++)
		this->recordings_vector[index] = vector.recordings_vector[index];
}

DynamicVector& DynamicVector::operator=(const DynamicVector& vector) {
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


void DynamicVector::AddElement(TElem element) {
	int index_element = FoundElement(element);

	if (index_element != -1)
		throw std::invalid_argument("The recording already exists!");
	else
	{
		if (this->size == this->capacity) 
		{
			this->capacity *= 2;
			TElem *new_vector = new TElem[this->capacity];
			for (int index = 0; index < this->size; index++)
				new_vector[index] = this->recordings_vector[index];

			delete[] this->recordings_vector;
			this->recordings_vector = recordings_vector;
		}
		this->recordings_vector[this->size] = element;
		this->size++;
	}
}

void DynamicVector::DeleteElement(TElem element) {
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

void DynamicVector::UpdateElement(TElem element) {
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

int DynamicVector::FoundElement(TElem element)
{
	for (int index = 0; index < this->size; index++) {
		if (strcmp(this->recordings_vector[index].getTitle(), element.getTitle()) == 0)
			return index;
	}
	return -1;
}

int DynamicVector::getNumberOfElements() {
	return this->size;
}

TElem* DynamicVector::getAllElems() const
{
	return this->recordings_vector;
}

DynamicVector::~DynamicVector() {
	delete[] this->recordings_vector;
}*/