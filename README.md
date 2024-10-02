# Vector2 C++
![vector2](https://github.com/user-attachments/assets/d73ff8c2-8c48-4fc6-b94f-860a5d49706b)

## 1. Description

Math library that handles 2D positions and vectors with floating-point coordinates. 

## 2. Setup 
Add the Vector2Lib folder to your project. This folder contains the Vector2.cpp and Vector2.h files. Ensure that the folder or the path to Vector2.h is added to your project's include path so that #include "Vector2.h" can be resolved correctly.

## 3. Documentation

### 3.1 Constructors

|||
| ------------- | ------------- |
|Vector2()  |Constructs a new `Vector2` with all components set to 0.
|Vector2 ( float x, float y )| Constructs a new `Vector2` with the given x and y coordinates.

### 3.2 Static Constants 

|||
| ------------- | ------------- |
| down |  Vector2(0, -1)  |
|left|  Vector2(-1, 0)  |
|right|  Vector2(1, 0)|
|up|  Vector2(0, 1)|
|zero|  Vector2(0, 0)|

### 3.3 Public Methods

||| |
| ------------- | ------------------------------- | ------------- |
|float| magnitude() | Returns the length of this vector.
|Vector2| normalized() | Returns a vector based on this vector with a magnitude of 1. 
|void| RotatedDegrees(float angle) | Rotates this vector by the specified angle in degrees.
|void| RotatedRadians(float angle) | Rotates this vector by the specified angle in radians.
|float| sqrMagnitude() | Returns the squared length of this vector.

### 3.4 Static Methods

||| |
| ------------- | ------------------------------- | ------------- | 
|float|AngleInDegrees(const Vector2& from, const Vector2& to)| Returns the unsigned angle in degrees between the vectors `from` and `to`, ranging from 0 to 180.
|float| AngleInRadians(const Vector2& from, const Vector2& to)| Returns the unsigned angle in radians between the vectors `from` and `to`, ranging from 0 to π.
|float|AngleFullDegrees(const Vector2& a, const Vector2& b)| Returns the unsigned angle in degrees between the vectors `from` and `to` ranging from 0 to 360.
|float|AngleFullRadians(const Vector2& a, const Vector2& b)| Returns the unsigned angle in radians between the vectors `from` and `to`, ranging from 0 to π.
|Vector2| ClampMagnitude(Vector2& vector,float maxLength)|  Returns a new vector with its magnitude clamped to maxLengt.
|float| Cross(const Vector2& a, const Vector2& b)| Returns the scalar value of the 2D cross product between vectors `a` and `b`.
|float| Distance(Vector2& a,  Vector2& b)|Returns the distance between `a` and `b`.|
|float| Dot(const Vector2& lhs,const Vector2& rhs)| Returns the dot product between `lhs` and `rhs`.
|Vector2| Lerp(Vector2& a, Vector2& b, float t)|Returns the interpolated vector between vectors `a` and `b` by `t`, where `t` ranges from 0.0 to 1.0.
|Vector2| LerpUnclamped(Vector2& a, Vector2& b, float t)|Returns the interpolated vector between vectors `a` and `b` by `t`, where `t` can take any value.
|Vector2| Max(Vector2& lhs, Vector2& rhs) | Returns a vector with the maximum elements of vectors `lhs` and `rhs`.
|Vector2| Min(const Vector2& lhs, const Vector2& rhs)| Returns a vector with the minimum elements of vectors `lhs` and `rhs`.
|Vector2|MoveToward(const &current, const &target, float delta)| Returns a new vector that moves `current` towards `target` by a fixed `delta` amount, without exceeding the final value.
|Vector2| Perpendicular(Vector2& inDirection)|Returns a perpendicular vector rotated 90 degrees counter-clockwise from the original.
|Vector2| PerpendicularClockwise(const Vector2& inDirection)| Returns a perpendicular vector rotated 90 degrees clockwise from the original.
|Vector2| Projection(Vector2& from, Vector2& to)|Returns the result of projecting the vector `from` onto the vector `to`.
|float| SignedAngleInDegrees(const Vector2& from, const Vector2& to) |Returns the signed angle in degrees between the vectors `from` and `to`, ranging from -180 to 180.
|float| SignedAngleInRadians(const Vector2& from, const Vector2& to) | Returns the signed angle in radians between the vectors `from` and `to`, ranging from -π to π.
|Vector2| Reflect(Vector2 inDirection, Vector2 inNormal)| Returns the result of reflecting the vector `inDirection` off the surface defined by `inNormal`.
|Vector2| Scale(const Vector2& a, const Vector2& b)| Multiplies two vectors element-wise.

### 3.5 Operators

|| |
| ------------- | ------------- |
|operator+ | Adds one vector to another.
|operator- | Subtracts one vector from another.
|operator* | Multiplies a vector by a number or another vector.
|operator/ | Divides a vector by a number or another vector.
|operator== | Returns true if two vectors are exactly equal.
|operator<< | Prints the vector’s components in the format (x, y) to the stream.

### 3.6 Examples of Usage:

#### 3.6.1 Creating two vectors:
    Vector2 v1(3,4); 
    Vector2 v2(7,8);

#### 3.6.2 Calculting the distance between two points:
    float distance = Vector2::Distance(v1,v2); 

#### 3.6.3 Calculating the angle between two points:
    float angleDeg = Vector2::AngleFullDegrees(Vector2::right,Vector2::up);

## 5. Examples of Using This Library for Games:

There are many use cases for Vector2 functions. Here are a few examples:

### Distance Calculation:  
Calculate the distance between an enemy and the player to trigger different AI behaviors based on proximity, such as attacking or fleeing.
### Linear Interpolation (Lerp): 
Interpolate the camera position between different viewpoints or targets to create smooth camera pans and zooms.
### Normalization: 
When moving diagonally, normalizing the movement vector ensures consistent speed in all directions. For example, without normalization, diagonal movement might be faster than movement along the axis. Normalization adjusts the diagonal vector so that the movement speed remains constant regardless of direction.
### ClampMagnitude: 
Use the ClampMagnitude function to limit the speed of an object, such as a falling character or projectile, to ensure it doesn’t exceed a certain velocity.
### MoveToward: 
Make characters follow the player or other target objects, such as homing missiles.
### Perpendicular Vectors: 
Calculate the perpendicular vector of a surface to navigate a character around its outline.
