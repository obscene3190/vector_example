#include <algorithm>
#include <cassert>

#include "vector.hpp"

    vector_t::vector_t() {
        elements_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    vector_t::vector_t(vector_t const &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        elements_ = new int[capacity_];
        for (int i = 0; i < other.size_; ++i) {
            elements_[i] = other.elements_[i];
        }
    }

    vector_t &vector_t::operator=(vector_t const &other) {
        delete[] elements_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        int *elements_ = new int [capacity_];
        for (int i = 0; i < other.size_; ++i) {
            elements_[i] = other.elements_[i];
        }
        return *this;
    }

    bool vector_t::operator==(vector_t const &other) const {
        if (size_ != other.size_) {
            return false;
        }
        for (int i = 0; i < size_; ++i) {
            if (elements_[i] != other.elements_[i]) {
                return false;
            }
        }
        return true;
    }

    vector_t::~vector_t() {
        delete[] elements_;
    }

    std::size_t vector_t::size() const {
        return size_;
    }

    std::size_t vector_t::capacity() const {
        return capacity_;
    }

    void vector_t::push_back(int value) {
        if (capacity_ == 0) {
		size_ = 1;
		capacity_ = 1;
		elements_ = new int [capacity_];
		elements_[0] = value;
	}
        else {
            int * reserve = new int[size_];
            for (int i = 0; i < size_; ++i) {
                reserve[i] = elements_[i];
            }
            delete[] elements_;
            size_++;
            if ((size_-1)==campacity_) {
                campacity_*=2;
            }
            elements_ = new int[capacity_];
            for (int i = 0; i < size_-2; ++i) {
                elements_[i] = reserve[i];
            }
            elements_[size_-1] = value;
        }
    }

    void vector_t::pop_back() {
        delete elements_[size_-1];
        size_--;
        if (size_ == capacity_/4) {
            capacity_ = capacity_/2;
        }
    }

    int &vector_t::operator[](std::size_t index) {
        return elements_[index];
    }

    int vector_t::operator[](std::size_t index) const {
        return elements_[index];
    }

    bool operator!=(vector_t const &lhs, vector_t const &rhs) {
        bool success = true;
        if (lhs == rhs) {
            success = !success;
        }
        return success;
}
