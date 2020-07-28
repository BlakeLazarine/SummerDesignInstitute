#include <stdio.h>

/* Please put your name in the string */
void printName(){
    char name[30] = "Your Name Here";
    printf("My Name is: %s\n", name);
}
/*

expected solution lengths are suggestions not requirements
warnings for print statements saying that %x usually wants unsigned are not important and can be ignored
These problems are given in no particular order, so feel free to jump around

I HEAVILY recommend you look at the main method and run tests of your code
also it may be a good idea to write more test cases of your own,
since the grading system has its own as well.

Also, please please make sure your code compiles when you submit it

grading scheme
code compiles - 4 points
name included - 1 point
each problem - 3 points
partial credit is possible for most categories
total: 20 points


*/

/*
1.a)

Write a function that takes in a 2D array of size n by m that prints out
each value along with its memory address. Use array format (using []).

expected solution: 3 lines
*/
void printArr(int n, int m, int arr[n][m]) {
	//HINT: copy paste this when you want to print
    // printf("value: %d, addr: %p\n", <value>, <address>);
}


/*
1.b)
Write a function that takes in an array (of length n) of arrays (of length m)
that prints out each value along with its memory address.
Use only pointer format (no [] anywhere).

IMPORTANT: this is NOT a normal 2D array. It is an array of pointers (which are other arrays)
a diagram can be seen in the powerpoint
expected solution: 3 lines

AFTER YOU ARE DONE, THINK: Could this work for the part a?
Don't submit anything for the THINK part, just THINK about it
You might not know enough yet to fully understand and that's OK
*/
void printArrPtr(int n, int m, int **arr) {
	//HINT: use printf("value: %d, addr: %p\n", <value>, <address>);
}


/*
2.
write a function that takes in pointers to 2 integers and swaps the values they point to

HINT: this will be called like this:
int a = 3;
int b = 4;
swap(&a, &b);
//now b == 3 and a == 4


expected solution: 3 lines
*/
void swap(int *a, int *b) {

}


/*
3.
write a function that checks if i points to part of array arr (of length n).
Return 2 is i is part of arr,
1 if i is not part of arr, but its pointed value can be found within arr,
and 0 otherwise.

expected solution: 6 lines
*/

int isInArr(int *i, int *arr, int n){
	return 0; // replace this
}


/*
4.
I have made a special pointer.
It is a pointer to a pointer to a pointer to a pointer to a pointer to a...
and so on.
At the end is NULL.
Write a function that counts how many times you need to follow a pointer to get to the end.
ex.
void *p0 = NULL;
countlinks(p0);//returns 0
void *p1 = &p0;
countlinks(p1);//returns 1

HINT: It can be kind of confusing to know how to interperet p.
In the intended solution, use no cast to check if the end has been reached
we also use (void**)p to interperet p as a pointer to a pointer.
You can think of this sort of like (void*)*, but syntax forces certain parentheses
To try and make sense of this, think back to lecture, where we had this line
int a = *(int*)p;
This line casts p to be a pointer to an int and gets the integer value it points to.
if we replace the word int with void* we get
void* a  = *(void**)p
in this line, we cast p to be a pointer to another void pointer and get the void pointer value pointed to by p
That may be a lot of the word pointer but if you just think through it word by word it makes sense

expected solution: 6 lines
*/
int countlinks(void *p){
	return 0; // replace this
}


/*
5.
If I wanted to use a void pointer to iterate through an array arr of n doubles
(which consist of 8 bytes), how would I write the loop?
Have the function return 0x<your answer>.
Also write 1 sentence explaining your choice
and 1 sentence explaining what *((double*)p) is doing.

HINT: you can write a program and tests what works.

a.
for(void *p = arr; p < arr + n; p += 1)
	printf("%f\n", *((double*)p));

b.
for(void *p = arr; p < arr + 8*n; p += 8)
	printf("%f\n", *((double*)p));

c.
for(void *p = arr; p < arr + n; p += 8)
	printf("%f\n", *((double*)p));

d.
for(void *p = arr; p < arr + 8*n; p += 1)
	printf("%f\n", *((double*)p));

e.
Cannot be done
*/
int multipleChoice(){
	/*
    abracadabra    This line is used for grading please dont delete it

    <<Type your explanation here>>

    alakazam    This line is used for grading please dont delete it
	*/
	return 0x0;//change this to 0xa, 0xb, 0xc, 0xd, or 0xe
}



//here are some tests, but you should make some of your own too, as we will run more than these
//you can leave your main method, our grading system will replace it with ours
int main(){
    printName();

	/*     1a     */
	int printableArray[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	printArr(3, 4, printableArray);
	printf("\n");

	/*     1b     */
	int arr1[] = {1,2,3,4};
	int arr2[] = {5,6,7,8};
	int arr3[] = {9,10,11,12};
	int* arrarr[] = {arr1, arr2, arr3};
	printArrPtr(3,4,arrarr);


	/*     2     */
	int a = 3;
	int b = 4;
	printf("a: %d b:%d\n", a, b);
	swap(&a, &b);
	printf("a: %d b:%d\n", a, b);


	/*     3     */
	int sampleArray[] = {1,2,3,4};
	int isIn = isInArr(sampleArray+2, sampleArray, 4);
	if(isIn != 2)
		printf("error: isIn should be 2, currently is %d\n", isIn);


	a = 3;
	isIn = isInArr(&a, sampleArray, 4);
	if(isIn != 1)
		printf("error: isIn should be 1, currently is %d\n", isIn);


	a = 5;
	isIn = isInArr(&a, sampleArray, 4);
	if(isIn != 0)
		printf("error: isIn should be 0, currently is %d\n", isIn);


	/*     4     */
    void *p0 = NULL;
	if(countlinks(p0) != 0)
		printf("error: countlinks(p1) should be 0, currently is %d\n", countlinks(p0));
	void *p1 = &p0;
	if(countlinks(p1) != 1)
		printf("error: countlinks(p1) should be 1, currently is %d\n", countlinks(p1));


	/*     5     */
	printf("multiple choice %x", multipleChoice());

    printf("done!\n");

}
