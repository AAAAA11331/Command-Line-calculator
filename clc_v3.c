#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

// return to main menu
char main_menu(void);
// part B
float bin_cal (float num1, char oper1, float num2);
// part U
float uni_cal (float num1, char oper1);
// part E
void out ();
// check if the variable had been decleared already or not
float is_in_array(char c);
char variable_array[10];
char variable_A[10];
int initial_value[10];
int i=0;


int main()
{
  // declear local variables
  int temp;// 
  /* 
*temp: used to collect garbage characters
*option: to store the input value in the main page
*operator1: store the user input binary operator
*unary_operator: store the user input unary operator
*variable: get the variable name from the user in option V
*A_option: enter B U E in option A
*variable_array: an array used to store the variable that had been decleared by the user
*variable_A: an array used to store the user input value in option A
*initial_value: an array used to collect the intnitial value for each variable decleared by the user
*found: used as a boolean value to check if the variabel had been decleared already or not
*num1;num2;result: used to store user input value
*/
  char option='B', operator1, unary_operator, variable, A_option; 
  float num1,num2; 

  // welcome message
  puts("Welcome to my Command-Line Calculator (CLC)\nDeveloper: Andrew Lyu\nVersion: 3\nDate: Nov 24,2022\n---------------------------------------");
  // ask for user input
  puts("Select one of the following items: \nB) - Binary Mathematical Operations, such as addition and subtraction. \nU) - Unary Mathematical Operations, such as square root, and log. \nA) - Advances Mathematical Operations, using variables, arrays. \nV) – Define variables and assign them values. \nE) - Exit");
  
  
  while (option!='E'){ //run the program until E is entered
    option = main_menu();; // read the command input
    switch (option) { 
      //start binary calculation
      case 'B':
        // ask the user to enter the first input number
        printf("Please enter the first number:\n"); 
        //check if user entered a numeric number or not
        while(!scanf(" %f", &num1)){
		      while((temp=getchar()) != EOF && temp != '\n'){
		        printf("you enetered invalied value, please try again:\n");}}
        
        // ask the user to enter the operator
        printf("Please enter the operation (+,-,*,/,%%,P,X,I):\n");
        scanf(" %s", &operator1);
        
        // ask the user to enter the second input number
        printf("Please enter the second number:\n");
        //check if user entered a numeric number or not
        while(!scanf(" %f", &num2)){
		      while((temp=getchar()) != EOF && temp != '\n')
		        printf("you enetered invalied value, please try again:\n");
            
          }
        printf("the result is %f\n", bin_cal(num1, operator1, num2));
      break;
        
      
      // #option U
      // unary operation
      case 'U': 
      // ask the user to enter the first input number
      printf("Please enter the first number:\n"); 
      //check if user entered a numeric number or not
      while(!scanf(" %f", &num1)){
		    while((temp=getchar()) != EOF && temp != '\n')
		      printf("you enetered invalied value, please try again:\n");}

      // ask the user to enter the operator
        printf("Please enter an unary operator (S,L,E,C,F):\n");
        scanf(" %s", &unary_operator);
        // call the function and print the result
        printf("the result is %f\n", uni_cal(num1, unary_operator));
        break; // end of case U
      
      
      // # option V
      // intake one variable and one number and store it in an array
      case 'V':
        // ask for input variable
        printf("enter an alphabetic character in lowercase as variable:\n");
        // repeat until user enter a letter between a to e
        while(scanf(" %c", &variable) && (!(variable>='a' && variable<='e')))
          printf("Error, please enter a letter in between a to e\n");

        // ask the user to enter the first input number
        printf("Please enter the initial value:\n"); 
        //check if user entered a numeric number or not
        while(!scanf(" %f", &num1)){
		      while((temp=getchar()) != EOF && temp != '\n')
		        printf("you enetered invalied value, please try again:\n");}

        int k, repeat=0;// int k is to store the position of the repeated variable, and repeat is to check if variable is repeated or not
        
        // check if the variable has an intial value already, if so, find the position and store it ask k
        for (int j=0; j<=i; j++){
          if (variable_array[j]==variable){
            k=j;
            repeat=1;
            break;
            }
        }
        
        if (repeat==0){ // if the variable does not repeat, store the variable and the number
          variable_array[i]=variable;
          initial_value[i]=num1;}
        else { // if the variable repeat, store the user input number into its respective position
          initial_value[k]=num1;
        }
        i++;
        repeat=0;// reset repeat to 0;
        break; // end of case V


      // # case A
      // start to operate when A is entered
      // Advances Mathematical Operations, using variables, arrays.
      case 'A': 
        // ask for user input
        printf("enter one of the following command: B, U, E\n");
        scanf(" %c", &A_option);
        switch (A_option){
          case 'B':
            // ask the user to enter the first input number
            printf("Please enter the first number or entere a variable that you had already decleared:\n"); 
            
            //check if user entered a numeric number or not
            while(scanf(" %s", variable_A) && ((!(variable_A[0]>='a' && variable_A[0]<='e') && isdigit(variable_A[0])==0))){
                printf("Error, please enter a letter in between a to e\n");}

            // convert the string to a number if number is entered
            if (isdigit(variable_A[0]))
              num1=atof(variable_A);
            else 
              num1=is_in_array(variable_A[0]);
          
            // ask the user to enter the operator
            printf("Please enter the operation (+,-,*,/,%%,P,X,I):\n");
            scanf(" %s", &operator1);


            // very similar to asking for the first number input
            // ask the user to enter the second input number
            printf("Please enter the second number, or a variable that had been decleared in option V:\n");
            //check if user entered a numeric number or not
            while(scanf(" %s", variable_A) && ((!(variable_A[0]>='a' && variable_A[0]<='e') && isdigit(variable_A[0])==0))){
                printf("Error, please enter a letter in between a to e\n");}

            // convert the string to a number if number is entered
            if (isdigit(variable_A[0])){
              num2=atof(variable_A);
            }
            // check if the variable already been decleared, if not, set the intial value to 0
            else {
              num2=is_in_array(variable_A[0]);
            }
            // call the function and print the result
            printf("the result is %f\n", bin_cal(num1, operator1, num2));
            break;
                      
          case 'U':
            // ask the user to enter the first input number
            printf("Please enter one number or enter a variable that you had already decleared:\n");  
            //check if user entered a numeric number or not
            while(scanf(" %s", variable_A) && ((!(variable_A[0]>='a' && variable_A[0]<='e') && isdigit(variable_A[0])==0))){
                printf("Error, please enter a letter in between a to e\n");}

            // convert the string to a number if number is entered
            if (isdigit(variable_A[0])){
              num1=atof(variable_A);
            }
            // check if the variable already been decleared, if not, set the intial value to 0
            else {
              num1=is_in_array(variable_A[0]); 
            }
      
            // ask the user to enter the operator
            printf("Please enter an unary operator (S,L,E,C,F):\n");
            scanf(" %s", &unary_operator);
            // call the function and print the result
            printf("the result is %f\n", uni_cal(num1, unary_operator));
            break;

          
          // If the user enters E, the program exits from this part and goes back to the main selection menu. 
          case 'E':
            break;

          default:// catch all other letter
            puts("Oops, something went wrong.");
            break;
        }
        break;// end of case A

      // case E
      case 'E': // exist when E is entered
        out();
        break;

      case ' ': // ignore space
      case '\n': // ignore newlines
      case '\t': // ignore tabs
        break;
    }
  }
}

// function return to the main menu
char main_menu(void){
  char option;
  puts("Please select an option ( B , U , A , V , E )");
  scanf(" %c", &option);
  switch (option){
    case 'B':
    case 'b':
      return 'B';
      break;
    case 'U':
    case 'u':
      return 'U';
      break;
    case 'A':
    case 'a':
      return 'A';
      break;
    case 'V':
    case 'v':
      return 'V';
      break;
    case 'E':
    case 'e':
      return 'E';
      break;
  }
}

// check if the variable that user entered exist or not
float is_in_array(char c){
  for (int g=0; g<i; g++){
    if (variable_array[g]==variable_A[0])
      return initial_value[g];
    else 
      return 0;
    }
  return 0;
}

// part E
void out (){
  puts("Thanks for using my Simple Calculator. Hope to see you again soon. Goodbye!");
}

// part B
float bin_cal (float num1, char oper1, float num2){
  switch (oper1){
    // addition
    case '+': 
      return num1+num2;
      break;
          
    // substraction
    case '-': 
      return num1-num2;
      break;
          
    // multiplication
    case '*': 
      return num1*num2;
      break;
          
    // division
    case '/': 
      while (num2==0){ // show error message if 0 is denominator and ask for user input until valid
        printf("0 cannot be the denominator when doing devision, reenter a number for the second input\n");
        scanf(" %f", &num2);
      }
      return num1/num2;
      break;
          
    // remainder
    case '%': 
      while (num2<=0){ // show error message if 0 is denominator and ask for user input until valid
        printf("invalid, reenter a number greater than 0 for the second input\n");
        scanf(" %f", &num2);
      }
      return (int)num1%(int)num2;
      break;

    // power
    case 'P': 
      return pow(num1, num2);
      break;

    // find the max number 
    case 'X':
      if (num1>num2)
        return num1;
      else
        return num2;
      break;

    // find the min number
    case 'I':
      if (num1<num2)
        return num1;
      else
        return num2;
      break;
    
    default: // error message
      puts("oops, something goes wrong");
      break;
    
  }
}

// part U
float uni_cal (float num1, char oper1){
  // calculation part
  switch (oper1){
    //square root
    case 'S':
    case 's':
      while (num1<0){
        printf("cannot calculate square root of anything that is less than 0, reenter a number for the input\n");
        scanf(" %f", &num1);
      }
      return sqrt(num1);
      break;
    // Log
    case 'L':
    case 'l':
      while (num1<=0){
        printf("cannot calculate log of anything that is less than 0, reenter a number for the input\n");
        scanf(" %f", &num1);
      }
      return log(num1);
      break;
    // e^n
    case 'E':
    case 'e':
      return exp(num1);
      break;
    // the smallest integer value greater than or equal to x
    case 'C':
    case 'c':
      return ceil(num1);
      break;
    // the largest integer value greater than or equal to 𝑥. 
    case 'F':
    case 'f':
      return floor(num1);
      break;
    // default: when there is some problem
    default:
      puts("Oops, something went wrong.");
      break;
    }
}
