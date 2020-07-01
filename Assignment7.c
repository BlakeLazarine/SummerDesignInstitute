#include <stdio.h>

/* Please put your name in the string */
void printName(){
    char name[30] = "Your Name Here";
    printf("My Name is: %s\n", name);
}
//expected solution lengths are suggestions not requirements
//warnings for print statements saying that %x usually wants unsigned are not important and can be ignored

/*
1.a)
Write a function that takes in a 2D array of size n by m that prints out each value along with its memory address. Use array format (no [] anywhere).

expected solution: 3 lines
*/
void printArr(int n, int m, int arr[n][m]) {
	//HINT: use printf("value: %d, addr: 0x%x\n", <value>, <address>);
}


/*
1.b)
Write a function that takes in an array (of length n) of arrays (of length m) that prints out each value along with its memory address. Use only pointer format (no [] anywhere).

expected solution: 3 lines

AFTER YOU ARE DONE, THINK: Could this work for the part a?
*/
void printArrPtr(int n, int m, int **arr) {
	//HINT: use printf("value: %d, addr: 0x%x\n", <value>, <address>);
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
write a function that checks if a variable passed by reference is part of array arr (of length n). Return 2 is i is part of the passed array, 1 if i is not part of the array, but its value can be found within it, and 0 otherwise.

expected solution: 6 lines
*/

int isInArr(int *i, int *arr, int n){
	return 0; // replace this
}


/*
4.
I have made a special pointer. It is a pointer to a pointer to a pointer to a pointer to a pointer to a... and so on. At the end is NULL. Write a function that counts how many times you need to follow a pointer to get to the end.
ex.
void *p1 = NULL;
countlinks(p1);//returns 1
void *p2 = &p;
countlinks(p2);//returns 2

HINT: It can be kind of confusing to know how to interperet p.
In the intended solution, use no cast to check if the end has been reached
we also use (void**)p to interperet p as a pointer to a pointer.

expected solution: 6 lines
*/
int countlinks(void *p){
	return 0; // replace this
}


/*
5.
If I wanted to use a void pointer to iterate through an array arr of n doubles (which consist of 8 bytes), how would I write the loop? Have the function return 0x<your answer>. Also write 1 sentence explaining your choice and 1 sentence explaining what *((double*)p) is doing.

HINT: you can write a program and tests what works. Make sure you understand why your answer is correct before you submit.

a.
for(void *p = arr; p < arr + n; p += 1)
	printf("%f\n", *((double*)p));

b.
for(void *p = arr; p < arr + 8n; p += 8)
	printf("%f\n", *((double*)p));

c.
for(void *p = arr; p < arr + n; p += 8)
	printf("%f\n", *((double*)p));

d.
for(void *p = arr; p < arr + 8n; p += 1)
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
//you can leave your main method, our grading system will
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


	a = 1;
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
