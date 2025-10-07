### October 5th, 2025

Meaning of &variable: it gives you the memory address of the variable, not the variable's value. 
That is, printf("The value of the variable is %d", &variable) will give you something like "The value of the variable is 1839040". 

The main function being "int main" is an international standard of the C language. Older compilors used to accept "void main", but now it can cause problems to your programs. 

In C, arrays can't be assigned directly after they are declared. 
When we write something like

char mystring[20] = "Hello"

20 bits are reserved for mystring, and mystring becomes a pointer to a fix location. If, later, we do:

mystring = "Goodbye"

the operator "=" won't try to substitute what is inside mystring; instead, the operator tries to assign pointers. But mystring is a fix address. It can't receive another value. However, we can *copy* different characters on our old array if we want to change it. To achieve that, we may use *strcpy*. If we want to change only one or a few characters, we can do this with mystring[i] = "newcharacter"

*strncmp* compares the lengths of two strings - given a maximun comparison length -, returning 0 if they are equal and a different number if they are not. 

Be careful to not mess up *strncmp* with *strcmp*, because the latter is an unsafe function.

%zu refers to unsigned long values, just like %d refers to int values. 
size_t values are usually seen as unsigned long values. 

strncat(str1, str2, x) concatenates the first x characters of str2 to str1

### October 6th, 2025

Functions in C can only return one value at a time. 
Moreover, if you make a function that modifies arrays and the pointers to these arrays are passed as arguments, you don't need to return anything - the original arrays will be modified automatically. 

When you declare a multidimensional array as a function's parameter, the first dimension doesn't need to be specified, but all the other dimensions do. If it is a local variable, though, you need to specify the first dimension as well.

Found out by myself that x, y = a, b works in C. That made me really happy! 

Single quotes are for characters, double quotes are for strings!

To compare memory address of different types, you can use (void*). It doesn't allow dereferencing, though.

When a pointer is assigned to another pointer, they start to point to the same memory space. 

### October 7th, 2025

%2.f is different from &.2f! 
