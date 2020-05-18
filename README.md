# Simple Vectors Library

## Summary

The Simple Vectors Library (SVL) is written in C++. It is very basic and its sole purpose is to make basic vector mathematics easier in 2D games.

## Setup

SVL is a header-only library so you simply need the `svl.hpp` file. To start working with the library you should write `#include "svl.hpp"` in your source file.
 
## Creating vectors

Vectors can be created like this:

```C++
svl::Vector2<double>       vector1;
svl::Vector2<float>        vector2;
svl::Vector2<int>          vector3;
svl::Vector2<unsigned int> vector4;
```

However, there are shorthands for the more common types:

```C++
svl::Vector2d vector1;
svl::Vector2f vector2;
svl::Vector2i vector3;
svl::Vector2u vector4;
```

Each vector has two components called `x` and `y`. By default, these values are initialized to zero if none are specified. However, you can initialize a vector with specific values:

```C++
svl::Vector2f vector{ 3.4f, 7.2f };
```

## Accessing vector components

You can access the vector components like this:

```C++
// This should print out "X: 3.4" and "Y: 7.2" on separate lines.

svl::Vector2f vector{ 3.4f, 7.2f };

std::cout << "X: " << vector.x << "\n";
std::cout << "Y: " << vector.y << "\n";
```

## Dividing and multiplying vectors by scalars

You can multiply vectors by scalars like this:

```C++
svl::Vector2f vector1{ 0.4f, 0.7f };

svl::Vector2f vector2 = vector1 * 10;

// `vector1` = x: 0.4f, y: 0.7f
// `vector2` = x: 4.0f, y: 7.0f
```

or like this:

```C++
svl::Vector2f vector{ 0.4f, 0.7f };

vector *= 10;

// `vector` = x: 4.0f, y: 7.0f
```

You can divide as well using `/` and `/=`.

## Adding and subtracting vectors

You can add one vector to another like this:

```C++
svl::Vector2f vector1{ 2.6f, 3.8f };
svl::Vector2f vector2{ 1.7f, 7.8f };

svl::Vector2f vector3 = vector1 + vector2;

// `vector1` = x: 2.6f, y: 3.8f
// `vector2` = x: 1.7f, y: 7.8f
// `vector3` = x: 4.3f, y: 11.6f
```

or like this:

```C++
svl::Vector2f vector1{ 2.6f, 3.8f };
svl::Vector2f vector2{ 1.7f, 7.8f };

vector1 += vector2;

// `vector1` = x: 4.3f, y: 11.6f
// `vector2` = x: 1.7f, y: 7.8f
```

You can subtract as well using `-` and `-=`.

## Finding the magnitude of a vector

You can find the magnitude of a vector by using the `magnitude()` function:

```C++
svl::Vector2f vector{ 1.0f, 1.0f };

std::cout << vector.magnitude(); // Output: 1.41421
```

## Normalizing a vector

You can normalize a vector (set its magnitude to 1 while retaining its direction) using the `normalize()` function:

```C++
svl::Vector2f vector{ 1.0f, 1.0f };

std::cout << vector.magnitude() << "\n"; // Output: 1.41421

vector.normalize();

std::cout << vector.magnitude(); // Output: 1
```
If the magnitude of the vector is zero when the `normalize()` function is called, the vector will remain unchanged.

## Setting the magnitude of a vector

You can use the `setMagnitude()` function to change the magnitude of a vector while retaining its direction:

```C++
svl::Vector2f vector{ 1.0f, 1.0f };

std::cout << vector.magnitude() << "\n"; // Output: 1.41421

vector.setMagnitude(3.0f);

std::cout << vector.magnitude() << "\n"; // Output: 3
```

Inside this function simply normalizes the vector then multiplies it by the desired magnitude.

## Finding the dot product of two vectors

You can find the dot product of two vector objects using the `dotProduct()` function:

```C++
svl::Vector2f vector1{ 7.3f, 2.3f };
svl::Vector2f vector2{ 6.4f, 9.1f };

std::cout << vector1.dotProduct(vector2); // Output: 67.65
```
