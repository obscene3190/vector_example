#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	lements_ = nullptr;
	size_=0;
	capacity_=0;
}

vector_t::vector_t(vector_t const & other)
{
	size_ = other.size();
	capacity_ = other.capacity();
	elements_ = new int*[size];
	for(int i = 0; i < other.size(); ++i) {
		elements_[i] = other[i];	
	}
}

vector_t & vector_t::operator =(vector_t const & other)
{
	delete[] elements;
	size_ = other.size();
	capacity_ = other.capacity();
	int * elements_ = new int*[size];
	for(int i = 0; i < other.size(); ++i) {
		elements_[i] = other[i];	
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (!(size_ == other.size())) {
		return false;
	}
	for(int i = 0; i < size ++i) {
		if (!(elements_[i] == other[i])) {
			return false;
		}
	}
	return false;
}

vector_t::~vector_t()
{
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	
}

void vector_t::pop_back()
{
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return 0;
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	return true;
}
