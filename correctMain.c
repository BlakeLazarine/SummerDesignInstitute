int main(){
	int printableArray[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	printArr(3, 4, printableArray);

	int arr1[] = {1,2,3,4};
	int arr2[] = {5,6,7,8};
	int arr3[] = {9,10,11,12};
	int* arrarr[] = {arr1, arr2, arr3};
	printArrPtr(3,4,arrarr);

	int a = 3;
	int b = 4;
	printf("a: %d b:%d\n", a, b);
	swap(&a, &b);
	printf("a: %d b:%d\n", a, b);

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
    if(multipleChoice() != 0xc)
	   printf("multiple choice %x, correct is c\n", multipleChoice());
    printf("done!");

}
