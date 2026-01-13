#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(){

    char function[50];
    float num1 = 0.0f;
    float num2 = 0.0f;
    float result = 0.0f;
    int choice = 0;

    
    printf("*** SMART CALCULATOR ***\n\n");


    printf("1\n");
    printf("add(+)\n");
    printf("subtraction(-)\n");
    printf("multiply(*)\n");
    printf("divide(/)\n\n");

    printf("2\n");
    printf("power(^)\n");
    printf("absolute(abs)\n");
    printf("square root(sqrt)\n\n");

    printf("woulf you like to use the set of funtions #1 or #2 :");
    scanf("%d", &choice);
    getchar(); // FOR FGET TO WORK TO CONSUME THE \n


 
    if(choice == 1){

    printf("\nEnter (+ - * /) :");
    fgets(function, 50, stdin);
    function[strlen(function) - 1] ='\0';
    

    printf("\nEnter your first number :");
    scanf("%f", &num1);

    printf("Enter your second number :");
    scanf("%f", &num2);
    
        
      if(strcmp(function, "+") == 0){
        result = num1 + num2;
    }
      else if(strcmp(function, "-") == 0){
        result = num1 - num2;
    }
      else if(strcmp(function, "*") == 0){
        result = num1 * num2;
    }
      else if(strcmp(function, "/") == 0){
        if(num2 == 0){
            printf("Error : you cant divide by \"0\" !!");
            return 0;
        }
        result = num1 / num2;
        
    }
      else{
        printf("Error : Unknown operation !!\n");
        return 0;
    }

    printf("Your result is %.1f", result);


    }
    else if(choice == 2){

    float num = 0; // local var
    float result = 0.0f;


        printf("\nEnter (^, abs, sqrt) :");
    fgets(function, 50, stdin);
    function[strlen(function) - 1] ='\0';
    

    printf("\nEnter your number :");
    scanf("%f", &num);

    if(strcmp(function, "^") == 0){

        float power ;
        float result = 1.0f;
    

        printf("Power of what :");
        scanf("%f", &power);

        for(int i = 0; i < power; i++){
            result *= num; 

        }
        printf("%.1f", result);

        
    }
    
        if(strcmp(function, "abs") == 0){

          result =num;

           if(num < 0){

            result = -num;

           }
           printf("The absolut value of the number is %.1f", result);

  
        }
        if(strcmp(function, "sqrt") == 0){



            if(num < 0){

                printf("Error you cant sqrt a negative number !!");
                return 0;

            }else{

                result = sqrt(num);
            }
            printf("The sqrt of the number is %.1f", result);

        }

    




    }

    

  


    return 0;
}