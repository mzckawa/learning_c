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