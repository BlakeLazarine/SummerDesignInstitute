

/*this one is for grading only*/
double eqn4(double test1, double test2, double test3){
/*     implement expression res = (3*(in+2) - 7) * 2/3     */
    struct operation head;
    struct operation div3;
    struct operation mult2;
    struct operation sub31;
    struct operation sub32;
    struct operation sub1;
    struct operation mult3;
    struct operation add2;

    constructor(&div3, three, NULL, divide);
    constructor(&mult2, two, &div3, multiply);
    constructor(&sub31, three, &mult2, subtract);
    constructor(&sub32, three, &sub31, subtract);
    constructor(&sub1, one, &sub32, subtract);
    constructor(&mult3, three, &sub1, multiply);
    constructor(&head, two, &mult3, add);


    double res1 = evaluate(test1, &head);
    double res2 = evaluate(test2, &head);
    double res3 = evaluate(test3, &head);
    double exp1 = (3*(test1+2) - 7) * 2/3;
    double exp2 = (3*(test2+2) - 7) * 2/3;
    double exp3 = (3*(test3+2) - 7) * 2/3;
    printf("test results for eqn4: %f %f %f\n", res1, res2, res3);
    printf("expected results eqn4: %f %f %f\n", exp1, exp2, exp3);
}

/*
 * Feel free to use main to test.
 * We will automatically rename the function and ignore it's code
 * you can type numbers and whatever else you want here
 */
int main(){
    eqn1(1,5,8);
    eqn1(7,9,43);

    eqn2(1,5,8);
    eqn2(9,127,64);

    eqn3(1,5,8);
    eqn3(7,4,6);

    eqn4(1,5,8);
    eqn4(21,67,32);
    return 0;
}
