#ifndef MY_CALC_H
#define MY_CALC_H

int precedCmp(char *oper1, char *oper2);
int infixCalc(char **tokens, int tokenLens);
int prefixCalc(char **tokens, int tokenLens);
int postfixCalc(char **tokens, int tokenLens);

#endif // MY_CALC_H
