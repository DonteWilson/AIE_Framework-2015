#ifndef VC2_H
#define VC2_H

//use to represent std:: throughout the program.
using namespace std;
//Template labled T. Gives a template for the class Vector2
template<typename T>
class Vector2
{
	//Public variables for Vector2
public:
	//Constructor for Vector2
	Vector2<T>();

	Vector2<T>(T x, T y);
	//Decstructor
	~Vector2<T>();
	//Adds
	Vector2 Add2(Vector2 &a, Vector2 &b);
	//Subtracts
	Vector2 Sub2(Vector2 &a, Vector2 &b);
	//Multiples
	Vector2 Multi2(Vector2 &a, Vector2 &b);
	//float for Magnitude
	float Mag2(Vector2 &a);
	//Normalise.
	Vector2 Norm2(Vector2 &a);
	T DotProduct(Vector2 &a, Vector2 &b);
	//Identifies the x value in the Vector2
	int x;
	//Identifies the y valye in the Vector2
	int y;

	//Private variables wasnt used
private:
};


template<typename T>
//Constructor 
Vector2<T>::Vector2()
{

}
template<typename T>
Vector2<T>::Vector2(T X, T Y)
{
	x = X;
	y = Y;
}
template<typename T>
//Destructor
Vector2<T>::~Vector2()
{

}
template<typename T>
//Function to Add the Vectors/Alongside the overloaded "+" operator.
Vector2<T> Vector2<T>::Add2(Vector2<T> &a, Vector2<T> &b)
{
	Vector2 o;
	//Function for Addition for both x and y
	o.x = a.x + b.x;

	o.y = a.y + b.y;

	return o;


}
template<typename T>
//Function to Sub the Vectors/Alongside the overloaded "-" operator.
Vector2<T> Vector2<T>::Sub2(Vector2<T> &a, Vector2<T> &b)
{
	Vector2 o;
	//Function for Subtraction for both x and y
	o.x = a.x - b.x;

	o.y = a.y - b.y;

	return o;

}
template<typename T>
//Function to obtain the Magnitude for the Vecors
float Vector2<T>::Mag2(Vector2 &a)
{
	//Template for A squared.
	T asquared;

	float Asqrt;

	asquared = (a.x * a.x) + (a.y * a.y);

	Asqrt = sqrt(asquared);

	return Asqrt;
}
template<typename T>
//Function to Normalise
Vector2<T> Vector2<T>::Norm2(Vector2 &a)
{
	Vector2 o;

	T asquared;

	float Asqrt;

	asquared = (a.x * a.x) + (a.y * a.y);

	Asqrt = sqrt(asquared);

	o.x = (a.x / Asqrt);

	o.y = (a.y / Asqrt);

	return o;
}
template<typename T>
//Function for Vector2 Multiplication/Alongside the overloaded "*" operator.
Vector2<T> Vector2<T>::Multi2(Vector2<T> &a, Vector2<T> &b)
{

	Vector2 o;
	//Multiplication function for both x and y
	o.x = a.x * b.x;

	o.y = a.y * b.y;


	return o;

}
template<typename T>
//Function for the Vector2 Dot Product.
T Vector2<T>::DotProduct(Vector2 &a, Vector2 &b)
{
	T A;
	A = (a.x * b.x) + (a.y * b.y);
	return A;


}
#endif VC2_H