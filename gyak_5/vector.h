#pragma once
#include <algorithm>
#include <initializer_list>
namespace nik {
	template < typename T>
	class vector {
	public:
		vector() = default;
		vector(const size_t size);
		vector(const size_t size, const T& value);
		vector(const std::initializer_list<T>& list);
		vector(const vector& other); // copy constructor
		~vector();

		vector& operator=(const vector& other);
		T operator[](const size_t index);

		size_t size() const;

	private:
		T* mData = nullptr;
		size_t mCapacity = 0;
		size_t mSize = 0;

	};

	template<typename T>
	T vector<T>::operator[](const size_t index)
	{
		return mData[index];
	}

	template<typename T>
	size_t vector<T>::size() const {
		return mSize;
	}

	template<typename T>
	vector<T>& vector<T>::operator=(const vector& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] mData;
		mData = newT[other,mCapacity];
		mCapacity = other.mCapacity;
		mSize = other.mSize;
		std::copy(other.mData, other.mData + other.mSize, mData);

		return *this;
	}

	template<typename T> vector<T>::vector(const vector& other)
		: mData(new T[other.mCapacity])
		, mCapacity(other.mCapacity)
		, mSize(other.mSize)
	{
		std::copy(other.mData, other.mData + other.mSize,mData);
	}

	template<typename T> vector<T>::vector(const size_t size)
		:mData(new T[size])
		, mCapacity(size)
		, mSize(size)
	{

	}

	template<typename T> vector<T>::vector(const std::initializer_list<T>& list)
		: mData(new T[list.size()])
		, mCapacity(list.size())
		, mSize(list.size())
	{
		
		std::copy(list.begin(), list.end(), mData);
			//for (size_t i = 0; i < mSize; ++i)
			//{
			//	mData[i] = list[i];
			//}
	}

	template<typename T> vector<T>::vector(const size_t size, const T& value)
		:vector(size)
	{
		std::fill(mData, mData + mSize, value);
		/*for (auto& element : mData)
		{
			element = value;
		}*/
	}

	template<typename T>
	vector<T>::~vector()
	{
		delete[] mData;
	}
}