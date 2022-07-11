# ex1
+ What does .data, .word and .text mean?

    .data shows the value you will use (global value)

    .word is the size of data

    .text is your code

+ Run the program to completion. What number did the program output? What does this number represent?

    34. (fib 9)

+ At what address is n stored in memory? Hint: Look at the contents of the registers.

    0x10010000 + 10 = 0x10010010

+ Without actually editing the code (i.e. without going into the “Editor” tab), have the program calculate the 13th fib number (0-indexed) by manually modifying the value of a register. You may find it helpful to first step through the code. If you prefer to look at decimal values, change the “Display Settings” option at the bottom. 

223

# ex2
+ The register representing the variable k.

    in t0

+ The register representing the variable sum.

    in s0

+ The registers acting as pointers to the source and dest arrays.

    source: t3, dest: t2

+ How the pointers are manipulated in the assembly code.

    save t0 and t2 to the memory, then using square function. After finishing the function, read them back from memory.

# ex3
```
java -jar tools/venus.jar lab03/factorial.s
```
Change the code of
```
.data
n: .word NUM
```
to output NUM!

# ex4
```
java -jar tools/venus.jar lab03/factorial.s arg1 arg2 arg3
```

Initial Output:

``` 
9 8 7 6 5 4 3 2 1 0 
9 8 7 6 5 4 3 2 1 0 
```

After change (done in list_map.s):

```
9 8 7 6 5 4 3 2 1 0
81 64 49 36 25 16 9 4 1 0
```