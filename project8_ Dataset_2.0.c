#include <stdio.h>
#include <unistd.h>

#define MAX_NUM 10

static void clear_stdin_line();
static int read_int(const char *prompt, int *out);
int print_menu();
void add_number(int numbers[], int *count);
void clear_dataset(int *count);
void print_numbers(const int numbers[], int count);
void stats(const int numbers[], int count);
void count_even_odd(const int numbers[], int count);
void revers_in_place(int numbers[], int count);



int main(){

    int numbers[MAX_NUM];
    int count = 0;

    while(1){
        int choice = print_menu();

        switch( choice ){
            case 1 :
            add_number(numbers, &count);
            break;
            case 2 :
            clear_dataset(&count);
            break;
            case 3 :
            print_numbers(numbers, count);
            break;
            case 4 :
            stats(numbers, count);
            break;
            case 5 :
            count_even_odd(numbers, count);
            break;
            case 6 :
            revers_in_place(numbers, count);
            print_numbers(numbers, count);
            break;
     
        }
    }

    return 0;
}
static void clear_stdin_line(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
static int read_int(const char *prompt, int *out){
    int x;
    while (1){
        printf("%s", prompt);
        if(scanf("%d", &x) ==1){
            clear_stdin_line();
            *out = x;
            return 1;
        }
        clear_stdin_line();
        printf("Invalid input. Enter a number.\n");
    }
}

int print_menu(){

    int choice;

   while (1){
        printf("\n----MENU----\n");
        printf("1. Add number to dataset\n");
        printf("2. Clear dataset\n");
        printf("3. Print all the numbers\n");
        printf("4. Statistics\n");
        printf("5. Count even/odd\n");
        printf("6. Reverse in-palce\n");
        printf("7. Shift left\n");
        printf("8. Shift right\n");
        printf("9. Second largest\n");
        printf("10. EXIT\n");
        printf("Enter your choice :");
        
        if( scanf("%d", &choice) !=1){
            
            clear_stdin_line();
            printf("Invalid input. Enter a number.\n");
            continue;
        }
        if (choice > 10 || choice < 1){
            printf("choice must be between 1 and 10.\n");
            continue;
        }
        return choice;
   }
}
void add_number(int numbers[], int *count) {
    if (*count >= MAX_NUM) {
        printf("Dataset full.\n");
        return;
    }

    int value;
    printf("Enter a number: ");
    if (scanf("%d", &value) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Invalid input.\n");
        return;
    }

    numbers[*count] = value;
    (*count)++;

    printf("Added. Count = %d\n", *count);
}

void clear_dataset(int *count){
    *count = 0;
    printf("Dataset is cleared.\n");
}
void print_numbers(const int numbers[], int count){
    if (count == 0){
        printf("Dataset is [empty] !!\n");
        return;
    }
    printf("[");
    for (int i = 0; i < count; i++){
        if (i > 0) printf(", ");
        printf("%d", numbers[i]);
    }
    printf("]\n");
}
void stats(const int numbers[], int count){
    if (count == 0){
        printf("Dataset is [empty] !!\n");
        return;
    }
    int sum = 0;
    int min = numbers[0];
    int max = numbers[0];

    for (int i = 0; i < count; i++){
        sum += numbers[i];
        if(numbers[i] < min) min = numbers[i];
        if(numbers[i] > max) max = numbers[i];
    }
    float avg = sum / count;
    printf("count=%d | sum=%d | avg=%.2f | Min=%d | Max=%d\n", count, sum, avg, min, max);
}
void count_even_odd(const int numbers[], int count){
    if (count == 0){
        printf("Dataset is [empty] !!\n");
        return;
    }
    int even = 0;
    int odd = 0;
    for (int i = 0; i < count; i++){ 
        if (numbers[i] % 2 == 0) even++;
        else odd++;    
    }
}
void revers_in_place(int numbers[], int count){
    if (count <=1);
    printf("Nothing to reverse.\n");
    return;

    int i = 0;
    int j = count - 1;

    while (i < j){
        int temporary = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temporary;
        i++;
        j--;
    }
    printf("Reversed.\n");
}

