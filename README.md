# Advanced_workshop_at_-C_Assignment_1
This assignment was given to me to do during a class in "Advanced workshop at C", in my first year as a student.
In the first question, I was asked to do a function called "arrangeArray", thats gets am address of a pointer to a dynamic array that is setteled with N numbers(int) and its size is n. The array is divided to be to parts of a sequence of numbers that go up, that the minimal number of the first group is really big from the maximal number of the second group. k parameter is defined to be (0<=k<=n) - the size of the first group. I was given to do :
1. The function needs to find the value of k and return it.
2. The function needs to sort the array in an efficient way with the use of function **realloc and memcpy**.

In the second question, I was needed to make a program, that what it does is to get from the user a polygon with n vertices, and and it calculates the scope of the polygon:
**Function scanPoint:** gets the address of the struct type point, asking from the user to set values.
**Function scanPolygon:** gets an address of a struct type polygon, asking from the user to implement the wanted points, does a dynamic allocation of the array with the points and uses scanPoint to scan every point.
**Function distance:** gets the address of two points and calculates the distance between them.
**Function calculateScope:** gets the address of a struct type polygon setted, calculates its scope and saving the scope value in the scope parameter that this struct has.
**Function freeMemory:** gets the address of type of polygon and is making sure that we "free" the memory.

