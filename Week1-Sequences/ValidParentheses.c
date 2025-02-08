//I was thinking for over an hour and then realised it is just need a stack, so i made my version
#define STACK_SIZE 100

struct Stack{
    char items[STACK_SIZE];
    int top;
};

void initStack(struct Stack* stack){
    stack->top = -1;
}
bool isEmpty(struct Stack* stack){
    return stack->top == -1 ? true:false;
}

bool push(char c, struct Stack* stack){
    if(stack->top >= STACK_SIZE){
        return false;
    }
    stack->items[++stack->top] = c;
    return true;
}
char pop(struct Stack* stack){
    if(isEmpty(stack)){
        return '\0';
    }
    return stack->items[stack->top--];
}


bool isMatching(char open, char close){
    if( open == '(' && close == ')'){
        return true;
    }
    else if( open == '[' && close == ']'){
        return true;
    }
    else if( open == '{' && close == '}'){
        return true;
    }
    return false;
}

bool isValid(char* s) {
    struct Stack stack;
    initStack(&stack);

    for(int i = 0; s[i] != '\0'; i ++){
        char current = s[i];
        if(current == '(' || current == '[' || current == '{'){
            push(current, &stack);
        }
        else if (current == ')' || current == ']' || current == '}'){
            char topItem = pop(&stack);
            if(isMatching(topItem,current) == false){
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}
