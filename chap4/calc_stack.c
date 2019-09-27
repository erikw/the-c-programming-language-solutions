#include <stdio.h>
#include "calc_stack.h"

#define MAXVAL 100	/* maximum depth of val stack */

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void peekPrint(void)
{
	if (sp > 0)
		printf("top of stack: %g\n", val[sp - 1]);
	else {
		printf("error: stack empty\n");
	}
}

double peek(void)
{
	if (sp > 0)
		return val[sp -1];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void clear(void)
{
	sp = 0;
	int i;
	for (i = 0; i < MAX_VARS; ++i) {
		vars[i] = 0.0;
	}
}

void swap(void)
{
	double first = pop();
	double second = pop();
	push(first);
	push(second);
}

void duplicate(void)
{
	push(peek());
}
