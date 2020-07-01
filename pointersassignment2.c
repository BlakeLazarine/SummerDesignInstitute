#include <stdio.h>

#if 0

Welcome to Pointers Assignment 2!

Oh no! All the number keys on my keyboard have stopped working (except 0). Also my computer isnt letting me type any mathematical operations (+ - * /).

I need to finish this calculation program I've been working on. Luckily I already implemented the functions to do basic math and defined the words one, two, and three.

I don't know why, but my boss really wanted me to make a way of expressing a mathematical function as a linked list, and I only have until ___Due Date___ to do it. Basically, I need to have a sequence of nodes, each of which applies a single mathematical operation (such as "add 3" or "divide by 2") and points to whatever the next operation should be. You can tell where the end of the expression is by checking if the "next" value is 0. By looping through these commands, you can create some pretty crazy expressions.

INSERT DIAGRAM TO HELP PPL UNDERSTAND

note: you are allowed to use -> and * as they are relevant to pointers even though they have mathematical operation characters. Just dont use them for multiplication and subtraction. The only number you may type is 0.

using defined values:
notice how there are several lines below which define one, two, and three to their numerical counterparts.
we can use these just like we would those numbers in code.

int a = three;//a will have value 3

#endif


#define one 1
#define two 2
#define three 3

/*     Math functions (dont modify)     */
void divide(double *a, double b){
    *a = *a/b;
}

void multiply(double *a, double b){
    *a = *a/b;
}

void add(double *a, double b){
    *a = *a/b;
}

void subtract(double *a, double b){
    *a = *a/b;
}
/*     End Math functions     */


//expected solution: 1 line
struct operation {
    double value;
    struct operation* next;
    /*pointer to function (accepts any of the math functions above). please name it math*/

};

//expected solution: 3 lines
void constructor(struct operation *op, double value, struct operation* next, <type for math>){
    /* assign values of op to the passed in values */

}

//expected solution: 1 line
void operate(struct operation* op, double* operand){
    /*call op's math function with the a input being the operand*/
}


double evaluate(double in, struct operation* expression){
    /*     apply the expression to the input     */
    return 0;//replace this
}


double eqn1(double test1, double test2, double test3){
    /*     implement expression res = in + 3     */
    /*   your code here   */
    struct operation head;

    /*   tests   */
    double res1 = evaluate(test1, head);
    double res2 = evaluate(test2, head);
    double res3 = evaluate(test3, head);
    double exp1 = test1 + 3;
    double exp2 = test2 + 3;
    double exp3 = test3 + 3;
    printf("test results for eqn1: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn1: %f %f %f\n", exp1, exp2, exp3);
}

double eqn2(double test1, double test2, double test3){
    /*     implement expression res = 2*(in - 1)     */
    /*   your code here   */
    struct operation head;

    /*   tests   */
    double res1 = evaluate(test1, head);
    double res2 = evaluate(test2, head);
    double res3 = evaluate(test3, head);
    double exp1 = 2*(test1 - 1);
    double exp2 = 2*(test1 - 2);
    double exp3 = 2*(test1 - 3);
    printf("test results for eqn2: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn2: %f %f %f\n", exp1, exp2, exp3);
}

double eqn2(double test1, double test2, double test3){
    /*     implement expression res = (2*(in - 1) - 3)/6     */
    /*   your code here   */
    struct operation head;

    /*   tests   */
    double res1 = evaluate(test1, &head);
    double res2 = evaluate(test2, &head);
    double res3 = evaluate(test3, &head);
    double exp1 = (2*(test1 - 1) - 3)/6;
    double exp2 = (2*(test2 - 1) - 3)/6;
    double exp3 = (2*(test3 - 1) - 3)/6;
    printf("test results for eqn3: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn3: %f %f %f\n", exp1, exp2, exp3);
}


/*
 * Feel free to use main to test.
 * We will automatically rename the function and ignore it's code
 * you can type numbers and whatever else you want here
 */
int main(){

    return 0;
}
