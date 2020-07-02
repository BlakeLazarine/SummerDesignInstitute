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

*/

/*
1.a)

Write a function that takes in a 2D array of size n by m that prints out
each value along with its memory address. Use array format (using []).

expected solution: 3 lines
*/
void printArr(int n, int m, int arr[n][m]) {
	//HINT: use printf("value: %d, addr: 0x%x\n", <value>, <address>);
    for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
	        printf("value: %d, addr: 0x%x\n", arr[i][j], &(arr[i][j]));
}


/*
1.b)
Write a function that takes in an array (of length n) of arrays (of length m)
that prints out each value along with its memory address.
Use only pointer format (no [] anywhere).

expected solution: 3 lines

AFTER YOU ARE DONE, THINK: Could this work for the part a?
Don't submit anything for the THINK part, just THINK about it
You might not know enough yet to fully understand and that's OK
*/
void printArrPtr(int n, int m, int **arr) {
	//HINT: use printf("value: %d, addr: 0x%x\n", <value>, <address>);
    for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
	        printf("value: %d, addr: 0x%x\n", *(*(arr + i) + j), (*(arr + i) + j));
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
    int temp = *a;
    *a = *b;
    *b = temp;
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
    if(i >= arr && i < arr + n)
		return 2;
	for(int j = 0; j < n; j++)
		if(*(arr+j) == *i)
			return 1;
	return 0;
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

expected solution: 6 lines
*/
int countlinks(void *p){
    int num = 0;
	while(p != NULL){
		num++;
		p = *((void **)p);
	}
	return num;
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
	return 0xc;//change this to 0xa, 0xb, 0xc, 0xd, or 0xe
}



//here are some tests, but you should make some of your own too, as we will run more than these
//you can leave your main method, our grading system will replace it with ours
int main(){

    //This main method is different from that provided to students

    //problem 1
    int printableArray[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	printArr(3, 4, printableArray);

	int arr1[] = {1,2,3,4};
	int arr2[] = {5,6,7,8};
	int arr3[] = {9,10,11,12};
	int* arrarr[] = {arr1, arr2, arr3};
	printArrPtr(3,4,arrarr);

    //pproblem 2
	int a = 3;
	int b = 4;
	printf("a: %d b:%d\n", a, b);
	swap(&a, &b);
	printf("a: %d b:%d\n", a, b);
    swap(&a, &b);
	printf("a: %d b:%d\n", a, b);

    //problem 3
	int sampleArray[] = {1,2,3,4};
	int isIn = isInArr(sampleArray, sampleArray, 4);

	if(isIn != 2)
		printf("error: isIn should be 2, currently is %d\n", isIn);
	isIn = isInArr(sampleArray + 1, sampleArray, 4);
	if(isIn != 2)
		printf("error: isIn should be 2, currently is %d\n", isIn);
	isIn = isInArr(sampleArray + 2, sampleArray, 4);
	if(isIn != 2)
		printf("error: isIn should be 2, currently is %d\n", isIn);
	isIn = isInArr(sampleArray + 3, sampleArray, 4);
	if(isIn != 2)
		printf("error: isIn should be 2, currently is %d\n", isIn);
	a = 1;
	b = 2;
	int c = 3;
	int d = 4;

	isIn = isInArr(&a, sampleArray, 4);
	if(isIn != 1)
		printf("error: isIn should be 1, currently is %d\n", isIn);
	if(isIn != 1)
		printf("error: isIn should be 1, currently is %d\n", isIn);
	isIn = isInArr(&b, sampleArray, 4);
	if(isIn != 1)
		printf("error: isIn should be 1, currently is %d\n", isIn);
	isIn = isInArr(&c, sampleArray, 4);
	if(isIn != 1)
		printf("error: isIn should be 1, currently is %d\n", isIn);
	isIn = isInArr(&d, sampleArray, 4);
	if(isIn != 1)
		printf("error: isIn should be 1, currently is %d\n", isIn);

	a = 5;
	b = 6;
	c = 7;
	d = 8;

	isIn = isInArr(&a, sampleArray, 4);
	if(isIn != 0)
		printf("error: isIn should be 0, currently is %d\n", isIn);
	isIn = isInArr(&b, sampleArray, 4);
	if(isIn != 0)
		printf("error: isIn should be 0, currently is %d\n", isIn);
	isIn = isInArr(&c, sampleArray, 4);
	if(isIn != 0)
		printf("error: isIn should be 0, currently is %d\n", isIn);
	isIn = isInArr(&d, sampleArray, 4);
	if(isIn != 0)
		printf("error: isIn should be 0, currently is %d\n", isIn);

    //problem 4
	void *p0 = NULL;
	if(countlinks(p0) != 0)
		printf("error: countlinks(p1) should be 0, currently is %d\n", countlinks(p0));
	void *p1 = &p0;
	if(countlinks(p1) != 1)
		printf("error: countlinks(p1) should be 1, currently is %d\n", countlinks(p1));
	void *p2 = &p1;
	if(countlinks(p2) != 2)
        printf("error: countlinks(p1) should be 2, currently is %d\n", countlinks(p2));

	/*
	double doublearr[] = {3.14, 6.28, 1.41, 2.72};
	int n = 4;
	for(void *p = doublearr; p < doublearr + n; p += 8)
	    printf("%f\n", *((double*)p));
	*/
    
    //problem 5
    if(multipleChoice() != 0xc)
	   printf("error: multiple choice %x, correct is c\n", multipleChoice());
    printf("done!");

}
