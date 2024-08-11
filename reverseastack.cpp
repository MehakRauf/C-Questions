#include <iostream>
#include <stack>
using namespace std;

//function to reverse a stack
void reverseStack(stack<int> stack){
    //pop elements from the original stack and push them onto the temporary stack
    std::stack<int> tempStack;
    while(!stack.empty()){
        //adding the values
        int element=stack.top();
        stack.pop();
        //pushing the elements
        tempStack.push(element);
    }
    //copying the tempStack to original stack
    stack=tempStack; 
}
int main(){
    stack<int> stack;
    //pushing the elements
    stack.push(25);
    stack.push(24);
    stack.push(26);
    stack.push(28);
    stack.push(27);
    stack.push(21);
    stack.push(22);
    stack.push(23);    
    reverseStack(stack);
    //printing the stack after reversing
    cout<<"Reversed stack: "<<endl;
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }

}