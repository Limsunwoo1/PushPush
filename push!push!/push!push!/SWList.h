#pragma once
#include <iostream>

namespace sw
{
	template <typename T>
	struct Node
	{
		Node()
			: mData(NULL)
			, mNext(nullptr)
			, mPrev(nullptr)
		{

		}
		Node(const T& data)
			: mData(data)
			, mNext(nullptr)
			, mPrev(nullptr)
		{

		}
		~Node()
		{

		}

		T mData;
		Node<T>* mNext;
		Node<T>* mPrev;
	};

	template <typename T>
	class list
	{
	public:
		class iterator
		{
		public:
			iterator()
				: mPtr(nullptr)
			{

			}
			iterator(Node<T>* ptr)
				: mPtr(ptr)
			{

			}
			iterator(const iterator& other)
				: mPtr(other.mPtr)
			{

			}
			Node<T>* getPtr() { return mPtr; }
			Node<T>* operator++() // ÀüÀ§
			{
				if (mPtr != nullptr
					&& mPtr->mNext != nullptr)
				{
					mPtr = mPtr->mNext;
				}
				
				return *this;
			}
			iterator operator++(int) // ÈÄÀ§
			{
				iterator temp(*this);
				if (mPtr != nullptr
					&& mPtr->mNext != nullptr)
				{
					mPtr = mPtr->mNext;
				}
				
				return temp;
			}
			T& operator*()
			{
				if (mPtr != nullptr)
					return mPtr->mData;
			}
			/////////////////////////////////////////////// ¼÷Á¦
			iterator& operator--()
			{
				if (mPtr->mPrev != nullptr)
				{
					mPtr = mPtr->mPrev;
				}

				return *this;
			}
			iterator operator--(int)
			{
				iterator temp(*this);
				if (mPtr->mPrev != nullptr)
				{
					mPtr = mPtr->mPrev;
				}

				return temp;
			}
			/////////////////////////////////////////////////
			iterator& operator=(iterator& other)
			{
				mPtr = other.mPtr;

				return *this;
			}
			bool operator!=(const iterator& other) const
			{
				return !(this->mPtr == other.mPtr);
			}
			bool operator==(const iterator& other) const
			{
				return (this->mPtr == other.mPtr);
			}
		private:
			Node<T>* mPtr;
		};

		list()
		{
			mfirst = new Node<T>();
			mlast = new Node<T>();

			mfirst->mNext = mlast;
			mfirst->mPrev = nullptr;

			mlast->mNext = nullptr;
			mlast->mPrev = mfirst;

			mCount = 0;
		}
		list(const list& other)
		{
			mfirst = other.mfirst;
			mlast = other.mlast;
			mCount = other.mCount;
		}
		~list()
		{
			mCount = 0;
			while (mfirst != nullptr)
			{
				Node<T>* ptr = nullptr;
				ptr = mfirst;
				mfirst = mfirst->mNext;

				delete ptr;
				ptr = nullptr;
			}
		}

		size_t size() { return mCount; }
		bool empty() { return (mCount == 0 ? true : false); }

		iterator begin() const
		{
			return iterator(mfirst);
		}

		iterator end() const
		{
			return iterator(mlast);
		}

		void push_back(const T& data)
		{
			if (mCount == 0)
			{
				mfirst->mData = data;
				mCount++;
				return;
			}
			Node<T>* newNode = new Node<T>(data);
			Node<T>* lastPrev = mlast->mPrev;

			lastPrev->mNext = newNode;
			newNode->mPrev = lastPrev;

			newNode->mNext = mlast;
			mlast->mPrev = newNode;

			mCount++;
		}
		void pop_back()
		{
			Node<T>* to_delete = mlast->mPrev;

			mlast->mPrev = to_delete->mPrev;
			to_delete->mPrev->mNext = mlast;

			delete to_delete;
			to_delete = nullptr;
		}
		//////////////////////////////////////////////////// ¼÷Á¦
		void push_front(const T& data)
		{
			if (mfirst->mData == NULL)
			{
				mfirst->mData = data;
				
				mCount++;
				return;
			}

			Node<T>* temp = new Node<T>(data);

			temp->mNext = mfirst;
			mfirst->mPrev = temp;

			mfirst = temp;
			
			mCount++;
		}
		void pop_front()
		{
			if (mfirst->mData == NULL)
			{
				mCount = 0;
				return;
			}

			mfirst = mfirst->mNext;

			delete mfirst->mPrev;
			mfirst->mPrev = nullptr;

			mCount--;
		}
		void clear()
		{
			Node<T>* buffer = mlast->mPrev;
			while (buffer != mfirst)
			{
				Node<T>* to_delete = buffer;
				buffer = buffer->mPrev;

				mlast->mPrev = to_delete->mPrev;
				to_delete->mPrev->mNext = mlast;

				delete to_delete;
				to_delete = nullptr;
			}

			mfirst->mData = NULL;
			mCount = 0;
		}
		iterator erase(iterator other)
		{
			Node<T>* temp = other.getPtr();
			
			temp->mPrev->mNext = temp->mNext;
			temp->mNext->mPrev = temp->mPrev;

			delete temp;
			temp = nullptr;
		}
		//////////////////////////////////////////////////////
	private:
		size_t mCount;
		Node<T>* mfirst;
		Node<T>* mlast;
	};
}