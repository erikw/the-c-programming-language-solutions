#include <stdio.h>
#include <math.h>
#include <stdlib.h> 	/* for atof() */
#include <ctype.h>
#include "calc_stack.h"
#include "calc_io.h"

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */
#define VARIABLE '1'	/* signal that an variable */
#define ASSVAR  '2'	/* signal that an assignment variable */
#define MAX_VARS 26	/* maximum number of variables */

int getop(char []);
void handleVars(void);
short int isVar(double c);
void printVars(void);

double vars[MAX_VARS];

/* reverse polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	int h;
	for (h = 0; h < MAX_VARS; ++h)
		vars[h] =0;

	printf("Type expression in reverse polish notation i.e. postfix notation.\n");
	printInSeq();
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case VARIABLE:
			push(vars[s[1] - 'a']);
			break;
		case ASSVAR:
			push(s[0]);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push (pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 == 0.0)
				printf("error: zero divisor\n"); 
			else
				push (pop() / op2);
			break;
		case '%':
			op2 = pop();
			if (op2) 
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '?':
			peekPrint();
			break;
		case '@':
			printVars();
			break;
		case '!':
			clear();
			break;
		case '"':
			swap();
			break;
		case '[':
			push(sin(pop()));
			break;
		case '^':
			op2 = pop();
			push(pow(pop(), op2));
			break; //it down.
		case '}':
			push(exp(pop()));
			break;
		case '=':
			handleVars();
			break;
		case '_':
			op2 = pop();
			vars[0] = op2;
			printf("a = %.8g\n", op2);
			break;
		case '\n':
			printInSeq();
			break;
		default:
			printf("error: unknown command %s\n", s);
		}
	}
	printf("\n");
	return EXIT_SUCCESS;
}


#include "calc_stack.h"
/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, d;	

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-' && c != '+' &&  c != '$' && !isVar(c)) {
		return c; 	/* NaN */
	}
	i = 0;
	if (c == '-' || c == '+') {
		d = getch();
		if (!isdigit(d) && d != '.') {
			ungetch(d);
			return c;
		} else {
			ungetch(d);
		}
	} else if (c == '$') {
		d = getch();
		int e = getch();
		if (isVar(d) && (e == ' ' || e == '\t')) {
			ungetch(e);
			s[1] = d;
			s[2] = '\0';
			return VARIABLE;	/* an variable */
		} else {
			printf("error: not a valid varliable sequence %c%c%c", c, d, e);
			return c;
		}
	} else if (isVar(c)) {
		d = getch();
		if (d == ' ' || d == '\t') {
			ungetch(d);
			return ASSVAR;
		} else {
			ungetch(d);
		}
	}
	c = getch();
	
	while (isdigit(s[++i] = c))
		c = getch();
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

void handleVars(void)
{
	double op2 = pop();
	double op1 = pop();
	if (isVar(op1) && op1 != 'a') {
		vars[(int) op1 - 'a'] = op2;
	} else {
		printf("error: variables but be [b-z], not %g\n", op1);
	}
}

short int isVar(double d)
{
	return  (int) d >= 'a' && (int) d <= 'z';
}

void printVars(void)
{
	int i;
	printf("[");
	for (i = 0; i < MAX_VARS; ++i) {
		printf("%c = %g", ('a' + i), vars[i]);
		if (i != (MAX_VARS - 1))
			printf(", ");
	}
	printf("]\n");
}
