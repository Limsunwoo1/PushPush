#pragma once

namespace sw
{
	template <typename T>
	class vector
	{
	public:
		// ctrl + m + o 함수 모두 접기
		// ctrl + m + n 함수 하나만접고펴기
		vector(size_t cap = DEFAULT_CAP)
			: mArr(new T[cap])
			, mSize(0)
			, mCapacity(cap)
		{

		}

		vector(vector& other)
			: mArr(new T[other.mCapacity])
			, mSize(other.mSize)
			, mCapacity(other.mCapacity)
		{
			for (size_t i = 0; i < other.mSize; i++)
			{
				mArr[i] = other.mArr[i];
			}
		}

		~vector()
		{
			delete[] mArr;
		}

		vector& operator =(vector& other)
		{
			if (this != nullptr)
			{
				if (mCapacity < other.mCapacity)
				{
					delete[] mArr;
					mArr = nullptr;
					mCapacity = other.mCapacity;
					mArr = new T[mCapacity];
				}

				for (size_t i = 0; i < other.mSize; i++)
				{
					mArr[i] = other.mArr[i];
				}
				mSize = other.mSize;
			}

			return *this;
		}

		T& operator[](size_t idx) { return mArr[idx]; }
		void push_back(const T& data)
		{
			if (mSize >= mCapacity)
			{
				if (mCapacity < DEFAULT_CAP)
				{
					mCapacity = DEFAULT_CAP;
				}
				else
				{
					mCapacity *= 2;
				}

				T* newArr = new T[mCapacity];
				for (size_t i = 0; i < mSize; i++)
				{
					newArr[i] = mArr[i];
				}


				delete[] mArr;
				mArr = nullptr;
				mArr = newArr;
			}

			mArr[mSize] = data;
			mSize++;
		}
		void pop_back()
		{
			mSize = mSize > 0 ? mSize - 1 : 0;
		}

	public:
		size_t size() { return mSize; }
		size_t capacity() { return mCapacity; }
		bool empty()
		{
			if (mSize == 0)
				return true;

			return false;
		}
		void clear() { mSize = 0; }

	private:
		static constexpr size_t DEFAULT_CAP = 32;

		T* mArr;
		size_t mSize;
		size_t mCapacity;
	};
}