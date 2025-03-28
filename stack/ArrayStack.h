#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE	100

inline void error( char* str ) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

class ArrayStack
{
	int		data[MAX_STACK_SIZE];
	int		top;

public:
	ArrayStack() { top = -1; }
	~ArrayStack(){}			
	bool isEmpty() { return top == -1; }
	bool isFull()  { return top == MAX_STACK_SIZE-1; }

	void push ( int e ) {	
		if( isFull() ) error ("오버플로우 에러");
		data[++top] = e;
	}

	int pop ( ) {	
		if( isEmpty() ) error ("언더플로우 에러");
		return data[top--];
	}

	int peek ( ){	
		if( isEmpty() ) error ("스택이 비어있습니다.");
		return data[top];
	}

	void display ( ) {
		printf("[스택 %2d] ==> ", top+1) ;
		for (int i=0 ; i<=top ; i++ )
			printf("<%2d>", data[i]);
		printf("\n");
	}
};

