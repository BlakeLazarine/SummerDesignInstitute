#include <stdio.h>

#define one 1
#define two 2
#define three 3

/* Please put your name in the string */
void printName(){
    char name[30] = "Your Name Here";
    printf("My Name is: %s\n", name);
}


/*     Math functions (dont modify)     */
void divide(double *operand, double mod){
    *operand = *operand/mod;
}

void multiply(double *operand, double mod){
    *operand = *operand*mod;
}

void add(double *operand, double mod){
    *operand = *operand+mod;
}

void subtract(double *operand, double mod){
    *operand = *operand-mod;
}
/*     End Math functions     */

/* custom datatype to represent a single action  */
//expected solution: 1 line
struct operation {
    double modifier;
    struct operation* next;
    /*pointer to function (accepts any of the math functions above). please name it math*/
    /*your code here*/
};

//expected solution: 3 lines
void constructor(struct operation *op, double value, struct operation* next, void (*math)(double *a, double b)){
    /* assign values of op to the passed in values */
    /*Your code here*/
}

/*
the operate function will perform the action outlined by a single operation

Quick exmplanation:
Each operation struct has a math type and a modifier value
the operand should be altered by calling the math method
with a modifier defined by the operation

*/

//expected solution: 1 line
void operate(struct operation* op, double* operand){
    /*call op's math function with the a input being the operand*/
    /*Your code here*/
}

/*
the evaluate function iterates through an entire list of operations

Thinking back to the previous assignment's countlinks function,
evaluate should go from one operation to another using the 'next' field
It should call operate at each step.

*/
//expected solution: 6 lines
double evaluate(double in, struct operation* expression){
    /*     apply the expression to the input     */
    /*Your code here*/
}

/* eqn1 is given as an example */
void eqn1(double test1, double test2, double test3){
    /*     implement expression res = in + 3     */
    struct operation head;
    constructor(&head, three, NULL, add);

    /*   tests, do not modify   */
    double res1 = evaluate(test1, &head);
    double res2 = evaluate(test2, &head);
    double res3 = evaluate(test3, &head);
    double exp1 = test1 + 3;
    double exp2 = test2 + 3;
    double exp3 = test3 + 3;
    printf("test results for eqn1: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn1: %f %f %f\n", exp1, exp2, exp3);
}

void eqn2(double test1, double test2, double test3){
    /*     implement expression res = 2*(in - 1)     */
    struct operation head;
    /*   your code here   */

    /*   tests, do not modify   */
    double res1 = evaluate(test1, &head);
    double res2 = evaluate(test2, &head);
    double res3 = evaluate(test3, &head);
    double exp1 = 2*(test1 - 1);
    double exp2 = 2*(test2 - 1);
    double exp3 = 2*(test3 - 1);
    printf("test results for eqn2: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn2: %f %f %f\n", exp1, exp2, exp3);
}

void eqn3(double test1, double test2, double test3){
    /*     implement expression res = (2*(in + 1) - 3)/6     */
    struct operation head;
    /*   your code here   */

    /*   tests, do not modify   */
    double res1 = evaluate(test1, &head);
    double res2 = evaluate(test2, &head);
    double res3 = evaluate(test3, &head);
    double exp1 = (2*(test1 + 1) - 3)/6;
    double exp2 = (2*(test2 + 1) - 3)/6;
    double exp3 = (2*(test3 + 1) - 3)/6;
    printf("test results for eqn3: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn3: %f %f %f\n", exp1, exp2, exp3);
}


/*
 * Feel free to use main to test.
 * We will automatically rename the function and ignore it's code
 * you can type numbers and whatever else you want here
 */
int main(){
    printName();
    eqn1(4, 7, 9);
    eqn2(2, 42, 78);
    eqn3(44, 92, 71);
    return 0;
}
