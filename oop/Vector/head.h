#ifndef HEAD
#define HEAD
#define BLOCK_SIZE 8
#include<iostream>
#include<vector>
using namespace std;
template <class T>
class Vector {
public:
    Vector() :m_nCapacity(BLOCK_SIZE), m_nSize(0)
    {
        m_pElements = new T[m_nCapacity];
        cout << "call Vector()" << endl;
    };                      // creates an empty vector
    Vector(int size):m_nSize(size)
    {
        m_nCapacity = BLOCK_SIZE;
        while (m_nCapacity < m_nSize)
        {
            m_nCapacity += BLOCK_SIZE;
        }
        m_pElements = new T[m_nCapacity]();
        cout << "call Vector(int size)" << endl;
    };              // creates a vector for holding 'size' elements
    Vector(const Vector& r)
    {
        cout << "call Vector(const Vector& r)" << endl;
        m_nCapacity = r.m_nCapacity;
        m_nSize = r.m_nSize;
        m_pElements = r.m_pElements;
    };       // the copy ctor
    ~Vector()
    {
        cout << "call ~Vector()" << endl;
    };                     // destructs the vector 
    T& operator[](int index)
    {
        cout << "call operator[](int index)" << endl;
        return m_pElements[index];
    };      // accesses the specified element without bounds checking
    T& at(int index)
    {
        cout << "call at(int index)" << endl;
        if (index < 0 || index >= m_nSize)
        {
            cout << "out_of_range" << endl;
            //throw("std::out_of_range");
        }
        return m_pElements[index];
    };              // accesses the specified element, throws an exception of
    // type 'std::out_of_range' when index <0 or >=m_nSize
    int size() const
    {
        cout << "call size()" << endl;
        return m_nSize;
    };              // return the size of the container
    void push_back(const T& x)
    {
        cout << "call push_back(const T& x)" << endl;
        if (m_nSize < m_nCapacity)
        {
            m_pElements[m_nSize] = x;
            m_nSize++;
        }
        else
        {
            inflate();
            m_pElements[m_nSize] = x;
            m_nSize++;
        }
    };    // adds an element to the end 
    void clear()
    {
        delete m_pElements;
        m_nSize = 0;
        m_nCapacity = BLOCK_SIZE;
        m_pElements = new T[m_nCapacity];
        cout << "call clear()" << endl;
    };                  // clears the contents
    bool empty() const
    {
        cout << "call empty()" << endl;
        return !m_nSize;
    };            // checks whether the container is empty 
private:
    void inflate()
    {
        cout << "call inflate()" << endl;
        m_nCapacity += BLOCK_SIZE;
    };                // expand the storage of the container to a new capacity,
    // e.g. 2*m_nCapacity
    T* m_pElements;                // pointer to the dynamically allocated storage
    int m_nSize;                   // the number of elements in the container
    int m_nCapacity;               // the total number of elements that can be held in the
    // allocated storage
};
#endif // !HEAD