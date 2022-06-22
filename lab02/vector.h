#ifndef CS61C_VECTOR_H_
#define CS61C_VECTOR_H_
/* vector.h originally written by Jeremy Huddleston <jeremyhu@eecs.berkeley.edu> Sp2004
 *
 * So it looks like you've decided to venture into the "other" files of this
 * lab.  Good.  C Header files (the .h extension) are a way of telling other .c
 * files what they can have access to.  You usually include stdlib.h in your
 * C programs, and this process is identical to including this .h file with the
 * one change being:
 *
 * #include "file.h"
 * versus
 * #include <file.h>
 *
 * The difference is that the <> notation is for system header files and the ""
 * is for ones you provide yourself (in your local directory for instance).
 *
 * The header file starts off with
 * #ifndef CS61C_VECTOR_H_
 * #define CS61C_VECTOR_H_
 *
 * and ends with a final #endif.  This prevents the file from being included
 * more than once which could've possibly resulted in an infinite loop of
 * file inclusions.
 *
 * First, we define the 'vector_t' datatype.  This next line says that a 'vector_t'
 * is the same as a 'struct vector_t'.  So anywhere in the code after this, we
 * can use 'vector_t *' to mean a pointer to a 'struct vector_t' (which is defined in
 * vector.c).  We can get away with doing this even though we don't know what a
 * struct vector is because all struct pointers have the same representation in memory.
 */

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct vector_t vector_t;

/*
 *  Next, we provide the prototypes for the functions defined in vector.c.  This
 *  is a way of telling the .c files that #include this header what they will
 *  have access to.
 */

/* Create a new vector */
vector_t *vector_new();

/* Free up the memory allocated for the passed vector */
/* YOUR CODE HERE */
void vector_delete(vector_t *v);
/* Return the value in the vector */
int vector_get(vector_t *v, size_t loc);

/* Set a value in the vector */
/* YOUR CODE HERE */
void vector_set(vector_t *v, size_t loc, int value);

/* Define what our struct is */
struct vector_t {
    size_t size;
    int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
vector_t *bad_vector_new() {
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data =(int*) malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Another suboptimal way of creating a vector */
vector_t also_bad_vector_new() {
    /* Create the vector */
    vector_t v;

    /* Initialize attributes */
    v.size = 1;
    v.data = (int*) malloc(sizeof(int));
    if (v.data == NULL) {
        allocation_failed();
    }
    v.data[0] = 0;
    return v;
}

/* Create a new vector with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
vector_t *vector_new() {
    /* Declare what this function will return */
    vector_t *retval;

    /* First, we need to allocate memory on the heap for the struct */
    retval = /* YOUR CODE HERE */ (vector_t*)malloc(sizeof(vector_t));

    /* Check our return value to make sure we got memory */
    if (/* YOUR CODE HERE */retval == NULL) {
        allocation_failed();
    }

    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
    retval->size = /* YOUR CODE HERE */1;
    retval->data = /* YOUR CODE HERE */(int*)malloc(sizeof(int));

    /* Check the data attribute of our vector to make sure we got memory */
    if (/* YOUR CODE HERE */retval->data == NULL) {
        free(retval);				//Why is this line necessary?
        allocation_failed();
    }

    /* Complete the initialization by setting the single component to zero */
    /* YOUR CODE HERE */retval->data[0] = 0;

    /* and return... */
    return retval;
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if(v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    if (loc < v->size/* YOUR CODE HERE */) {
        return /* YOUR CODE HERE */v->data[loc];
    } else {
        return 0;
    }
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
    /* YOUR SOLUTION HERE */
    free(v->data);
    free(v);
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
    /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */

    /* YOUR SOLUTION HERE */
    if(loc < v->size){
        v->data[loc] = value;
        return;
    }
    int new_size = v->size;
    while(new_size <= loc){
        new_size = new_size * 2;
    }
    int *new_data = (int*)realloc(v->data, new_size * sizeof(int));
    if(new_data == NULL){
        allocation_failed();
    }
    for(int i = v->size; i < new_size; ++i){
        new_data[i] = 0;
    }
    new_data[loc] = value;
    v->data = new_data;
    v->size = new_size;
}
#endif
