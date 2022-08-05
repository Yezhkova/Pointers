#include <cstdint>
#include <iostream>
template <typename T>
class SharedPtrControlBlock
{
    T * m_ptr = nullptr;
public:

    template <class... _Types>

    SharedPtrControlBlock(_Types&&... _Args) { // make a shared_ptr to non-array object
        m_ptr = new T(_STD forward<_Types>(_Args)...);
        return m_ptr;
    }

};

template <class _Ty, class... _Types>

make_shared(_Types&&... _Args) { // make a shared_ptr to non-array object
    const auto _Rx = new SharedPtr<_Ty>(_STD forward<_Types>(_Args)...);
    return _Rx;
}


template <typename T>
class SharedPtr
{
private:

    template < class... _Types>

    SharedPtr(_Types&&... _Args) { // make a shared_ptr to non-array object
        const auto _Rx = new SharedPtrControlBlock<T>(_STD forward<_Types>(_Args)...);
        return _Rx;
    }

public:
    SharedPtr<T>(T * obj) : m_ptr(obj) {}

    SharedPtr<T>(SharedPtr & sptr) : m_ptr(sptr.m_ptr) {}

    ~SharedPtr<T>()
    {
        delete m_ptr;
    }

//    ~SharedPtr<T[]>()
//    {
//        delete[] m_ptr;
//    }

    T * getPtr() const
    {
        return m_ptr;
    }

//    SharedPtr<T> makeShared()
//    {
//        T obj = new T;
//        m_ptr = * obj;
//    }

    bool exists()
    {
        return m_ptr != nullptr;
    }

    friend std::ostream& operator<< (std::ostream& output, SharedPtr sptr)
    {
        output << sptr.m_ptr;
        return output;
    }

    friend T operator* (SharedPtr sptr)
    {
        return * sptr.m_ptr;
    }

    friend T** operator& (SharedPtr sptr)
    {
        return & sptr.m_ptr;
    }

};


template <class _Ty, class... _Types>

make_shared(_Types&&... _Args) { // make a shared_ptr to non-array object
    const auto _Rx = new SharedPtr<_Ty>(_STD forward<_Types>(_Args)...);
    return _Rx;
}
