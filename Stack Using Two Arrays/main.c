/* Emircan KÝREZ - Ch3rry */
/* Last Update: 06/07/2022 */
/*
----------------------- INFORMATION ---------------------------
• It is recommended to read the README.md file before proceeding to the project.
• For any questions and suggestions related to the project, via the e-mail address "emircan200123@hotmail.com", you can contact me by
typing "Github | C-EN / Stack Using Two Arrays" to the subject line 
*/

#include <stdio.h>                                                                                                                                                                  
#define MAX 1 //MAX is set to 1 to test the functions. My total stack size is 2 MAX.

//Function Prototypes
int isFull(int );
void push(int );
int isEmpty(int );
void pop();

//Global variables - so that we don't always pass them as parameters
int stackA[MAX], stackB[MAX];
int aMax = -1;
int bMax = -1;

int main(){
    push(1);
    push(2);
    push(3);
    pop();
    push(4);

    return 0;
}


int isFull(int max){
    if(max == MAX - 1){
        return 1;
    }
    return 0;
}

//while pushing, stackA must be checked first, then stackB
void push(int value){
    if(isFull(aMax)){
        if(isFull(bMax)){
            printf("Could not add value %d because stack is full !!\n", value);
        }else{
            stackB[++bMax] = value;
            printf("The value %d has been added to the stack. Total number of elements: %d\n", value, aMax + bMax + 2);
        }
    }else{
        stackA[++aMax] = value;
        printf("The value %d has been added to the stack. Total number of elements: %d\n", value, aMax + bMax + 2);
    }
}

int isEmpty(int max){
    if(max == -1){
        return 1;
    }
    return 0;
}

//while popping, stackB must be checked first, then stackA
void pop(){
	int poppedValue;
    if(isEmpty(bMax)){
        if(isEmpty(aMax)){
            printf("No values could be popped from the stack because the stack is empty !!\n");
        }else{
        	poppedValue = stackA[aMax--];
            printf("The value %d has been popped from the stack. Total number of elements: %d\n", poppedValue, aMax + bMax + 2);
        }
    }else{
    	poppedValue = stackB[bMax--];
        printf("The value %d has been popped from the stack. Total number of elements: %d\n", poppedValue, aMax + bMax + 2);
    }
}
