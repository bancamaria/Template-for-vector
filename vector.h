#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
using namespace std;

template <class T, unsigned n>
class Vector
{
    T *elem;
public:
    // constructor
    Vector(T val = 0);
    // function for getting the dimension of vector
    int getVectorSize() const;
    // copy-constructor and assignment
    Vector(const Vector &object);
    // overloading = operator
    Vector& operator=(const Vector& object);
    // function for displaying the vector
    void print() const;
    // overloading [] operator
    T& operator[](int i) const;
    // overloading + operator
    Vector operator+(const Vector& object) const;
    // overloading - operator
    Vector operator-(const Vector& object) const;
    // overloading * operator
    Vector operator*(const Vector& object) const;
    // destructor
    ~Vector();

    // overloading * operator for left-multiplying
    friend Vector operator*(const T& val, const Vector& object){
        Vector<T, n> v4;
        for(int i = 0; i < n; i++)
            v4[i] = object.elem[i] * val;
        return v4;
    }

    // overloading << operator
    friend ostream& operator<<(ostream& out, const Vector& object){
        for(int i = 0; i < n; i++)
            out << object[i] << " ";
        return out;
    }
};

// constructor
template <class T, unsigned n>
Vector<T, n>::Vector(T val):elem(new T[n]){
    for (int i = 0; i < n; i++)
        elem[i] = val;
}

// copy-constructor
template <class T, unsigned n>
Vector<T, n>::Vector(const Vector& object):elem(new T[n]){
    for(int i = 0; i < n; i++)
        elem[i] = object.elem[i];
    }

// function for getting the size of the vector
template <class T, unsigned n>
int Vector<T, n>::getVectorSize() const{
    return n;
}

// overload = operator
template <class T, unsigned n>
Vector<T, n>& Vector<T, n>::operator=(const Vector<T, n>& object){
    if(this == &object){
        return *this;
    }
    for(int i = 0; i < n; i++)
        elem[i] = object.elem[i];
    return *this;
}

// function for displaying the vector
template <class T, unsigned n>
void Vector<T, n>::print() const{
    for(int i = 0; i < n; i++)
        cout << elem[i] << " ";
    cout << "\n";
}

// function for overloading [] operator
template <class T, unsigned n>
T& Vector<T, n>::operator[](int i) const{
    if(i >= 0 && i < n)
        return elem[i];
    else
        throw out_of_range("position outside of vector");
}

// function for overloading + operator
template <class T, unsigned n>
Vector<T, n> Vector<T, n>::operator+(const Vector& object) const{
    Vector<T, n> v1;
    for(int i = 0; i < n; i++)
        v1[i] = object.elem[i] + elem[i]; // object[i] + elem[i]
    return v1;
}

// function for overloading - operator
template <class T, unsigned n>
Vector<T, n> Vector<T, n>::operator-(const Vector& object) const{
    Vector<T, n> v2;
    for(int i = 0; i < n; i++)
        v2[i] = object.elem[i] - elem[i]; // object[i] - elem[i]
    return v2;
}

// function for overloading * operator
template <class T, unsigned n>
Vector<T, n> Vector<T, n>::operator*(const Vector& object) const{
Vector<T, n> v3;
    for(int i = 0; i < n; i++)
        v3[i] = object.elem[i] * elem[i]; // object[i] + elem[i]
    return v3;
}

///Destructor
template <class T, unsigned n>
Vector<T, n>::~Vector(){
    delete[] elem;
}

#endif // VECTOR_H_INCLUDED
