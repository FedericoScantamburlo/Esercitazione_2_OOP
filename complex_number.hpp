#include<iostream>
using namespace std;

template <typename T> requires std::floating_point<T>

class complex_number
{
	T a, b;
	
public:
	// default constructor
	complex_number()
		: a(0.0), b(0.0)
	{}
	
	// user defined converting constructor
	explicit complex_number(T x)
		: a(x), b(0.0)
	{
		std::cout << "converting constructor called" << std::endl;
    }
	
	// user defined constructor
	complex_number(T x, T y)
        : a(x), b(y)
    {}
	
	// re, im, coniug methods
	T re(void) const{
		return a;
	}
	
	T im(void) const{
		return b;
	}
	
	complex_number coniug(void) const{
		return complex_number(a, -b);
	}
	
	//operators += and +
	complex_number& operator+=(const complex_number& z_2) {
        T a_2 = z_2.re();
        T b_2 = z_2.im();
        a += a_2;
        b += b_2;
        return *this;
	}
	
	complex_number operator+(const complex_number& z_2) {
		complex_number z = *this;
		z += z_2;
		return z;
	}
	
	complex_number& operator+=(const T& a_2) {
		a += a_2;
		return *this;
	}
	
	complex_number operator+(const T& a_2) {
		complex_number z = *this;
		complex_number z_2 = complex_number(a_2);
		z += z_2;
		return z;
	}
		
	
	//operators *= and *
	complex_number& operator*=(const complex_number& z_2) {
		T a_2 = z_2.re();
        T b_2 = z_2.im();
		a = a*a_2 - b*b_2;
		b = a*b_2 + b*a_2;
		return *this;
	}
	
	complex_number operator*(const complex_number& z_2) {
		complex_number z = *this;
		z *= z_2;
		return z;
	}
	
	complex_number& operator*=(const T& a_2) {
		a *= a_2;
		b *= a_2;
		return *this;
	}
	
	complex_number operator*(const T& a_2) {
		complex_number z = *this;
		complex_number z_2 = complex_number(a_2);
		z *= z_2;
		return z;
	}	
};

//making operators + and * commutative
template <typename T>
complex_number<T>
operator+(const T& r, complex_number<T>& z)
{
    return z + r;
}

template <typename T>
complex_number<T>
operator*(const T& r, complex_number<T>& z)
{
	return z * r;
}

//print
template <typename T>
std::ostream&
operator<<(std::ostream& os, const complex_number<T>& z) {
    if (abs(z.im()) < 1e-12)
        os << z.re();
    else if (abs(z.re()) < 1e-12)
		if (z.im() == 1)
			os << "i"; 
		else if (z.im() == -1)
			os << "-i";
        else 
			os << z.im() << "i";
	else 
		if (z.im() == 1)
			os << z.re() << " + i";
		else if (z.im() == -1)
			os << z.re() << " - i";
		else
			if (z.im() < 0.0)
				os << z.re() << " - " << abs(z.im()) << "i";
			else
				os << z.re() << " + " << z.im() << "i"; 

    return os;
}