# Pre-Check
+ C is a pass-by-value language
TRUE
+ What is a pointer?
a sequence of bits, interpreted as memory address
+ Dereference a variable that is not a pointer? Free one?
visit illegal memory address, it will segfault
+ When use heap over the stack? Do they grow?
If you need to keep access to data over several function calls, use heap. If yu're dealing with large piece of data, passing around a pointer to sth one the heap is more efficient than passing around the data itself. Heaps grow up an stacks grow down.
# Memory Management
+ Static variables
Static
+ Local variables
Stack
+ Global variables
Static
+ Constants
Code, static, 
+ Machine Instructions
Code
+ Result of Malloc
Heap
+ String Literals
Static or Heap