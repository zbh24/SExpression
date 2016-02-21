
#include<stdio.h>

int pos;
char s[100];

struct token {
    int type; //type == 0 is deafult,1 is a opertor,2 is a number,3 is a expression
    int value;
} token;

void getToken() {
    int i;

    i = 0;
    token.value = token.type = 0;
    while (s[pos] == ' '|| s[pos] == '\t')
      pos++;

    if(s[pos] == '+') {
      token.value = 0;
      token.type = 1;
      pos++;
      return;
    } else if(s[pos] == '-') {
      token.value = 1;
      token.type = 1;
      pos++;
      return;
    } else if(s[pos] == '*') {
      token.value = 2;
      token.type = 1;
      pos++;
      return;
    } else if(s[pos] == '/') {
      token.value = 3;
      token.type = 1;
      pos++;
      return;
    }
    
    while (s[pos] >= '0' && s[pos] <='9') {
	token.type = 2;
	token.value = token.value * 10 + s[pos] - '0';
	pos++;
    }
}

void match(int str) {
   int temp;
    while (s[pos] == ' ' || s[pos] == '\t')
        pos++;
    temp = s[pos];
    if (temp != str)
        printf("It is error\n");
    pos++;
}

int parse() {
  int value1,value2,opertor,result;

    match('(');
    getToken(); // Operator
    opertor = token.value;
    getToken();
    if (token.type == 2) { // it is a number
        value1 = token.value;
    } else {
      //pos--;
        value1 = parse();
    }
    getToken();
    if (token.type == 2) { // it is a number
        value2 = token.value;
    } else {
      // pos--;  
      value2 = parse();
    }
    match(')');

    if(opertor == 0)
      return value1 + value2;
    else if(opertor == 1)
      return value1 - value2;
    else if(opertor == 2)
      return value1 * value2;
    else if(opertor == 3)
      return value1 / value2;

}

int main() {
    int result;
    pos = 0;
    //scanf("%s",s);
    gets(s);
    printf("The result is %d\n",parse());
}



