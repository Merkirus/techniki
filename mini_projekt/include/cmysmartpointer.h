#pragma once

class RefCounter {
    public:
        RefCounter() {value = 0;}
        int value;
        void operator--(int) {--value;}
        void operator++(int) {++value;}
        bool operator==(int x) {return x == value;}
};

template<typename T>
class CMySmartPointer {
public:
    CMySmartPointer<T>();
    CMySmartPointer<T>(T *ptr);
    CMySmartPointer<T>(CMySmartPointer& other);
    ~CMySmartPointer();
    CMySmartPointer& operator=(CMySmartPointer& other);
    T& operator*();
private:
    T *ptr;
    RefCounter *ref;
};

template<typename T>
CMySmartPointer<T>::CMySmartPointer()
{
}

template<typename T>
CMySmartPointer<T>::CMySmartPointer(T *ptr)
{
    ref = new RefCounter;
    (*ref)++;

    this->ptr = ptr;
}

template<typename T>
CMySmartPointer<T>::CMySmartPointer(CMySmartPointer& other)
{
    ref = other.ref;
    (*ref)++;

    ptr = other.ptr;
}

template<typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
    (*ref)--;

    if (*ref == 0) {
        delete ptr;
        delete ref;
    }
}

template<typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(CMySmartPointer& other)
{
    return CMySmartPointer<T>(other);
}

template<typename T>
T& CMySmartPointer<T>::operator*()
{
    if (ptr)
        return *ptr;
}
