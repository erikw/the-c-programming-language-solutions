#define MAX_VARS 26	/* maximum number of variables */

double vars[MAX_VARS];

void push(double f);
double pop(void);
void peekPrint(void);
double peek(void);
void clear(void);
void swap(void);
