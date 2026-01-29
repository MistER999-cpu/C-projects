#include <stdio.h>
#include <unistd.h>

int print_menu();
void count_up_N();
void print_even();

int main(){

    int choice;
    do{
        choice = print_menu();
        if (choice == -1) continue;
        
        switch (choice){
            case 1 : count_up_N(); break;
            case 2 : print_even(); break;
            case 3 : printf("beyy\n"); break;
            default :printf("Invalide choice\n");
            

        }


    }while(choice != 3);


    return 0;
}
int print_menu(){
    int choice;

    printf("1. Count up to N\n");
    printf("2. Print even numbers up to N\n");
    printf("3. Exit\n");
    printf("Enter choice :");

    if (scanf("%d", &choice) != 1){
        printf("Invalid choice!!\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        return -1;
        
    }
    return choice;
}
void count_up_N(){
    int N;
    printf("Enter a intger You want to count to :");
    if (scanf("%d", &N) != 1 || N <= 0){
        printf("Invalid choice!!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        return;

  }
   int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
  
    for(int i = 1; i <= N; i++){
        printf("%d\n", i);
    }
  
}
void print_even(){

    int N;
    printf("Enter a intger You want to count to :");
    if (scanf("%d", &N) != 1 || N <= 0){
        printf("Invalid choice!!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        return;

  }
   int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
  
    for(int i = 1; i <= N; i++){
        if (i % 2 != 0){
            continue;
        } 
        printf("%d\n", i);

        
    }
  
}

    