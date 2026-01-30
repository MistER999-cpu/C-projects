#include <stdio.h>
#include <unistd.h>

#define CAPACITY 100

int print_menu();
int add_number(int data[], size_t *count);
int remove_number(int data[], size_t *count);
void print_dataset(int data[], size_t count);

long long sum_array(int data[], size_t count);
int minmax_array(const int data[], size_t count, int *out_min, int *out_max);
size_t count_even(int data[], size_t count);
void show_stats(int data[], size_t count);


 int main(){

    int choice;
    int data[CAPACITY];
    size_t count = 0 ;

    do{
        choice = print_menu();

        switch (choice){

           case 1 : 
           add_number(data, &count);
           break;
           case 2 :
           remove_number(data, &count);
           break;
           case 3 :
           print_dataset(data, count);
           break;
           case 4 :
           show_stats (data, count);
           break;
           case 5 :
           printf("beyy");
           break;

        }

    }while (choice != 5);


    return 0;
 }
 int print_menu(){
    int choice;
    int c;

  while(1){
    
        printf("1. Add number\n");
        printf("2. Remove last number\n");
        printf("3. Show dataset\n");
        printf("4. Show statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice :");

        if (scanf("%d", &choice) != 1){
            printf("Invalide choice!!\n");
            while((c = getchar()) != '\n' && c !=EOF) { }
            continue;          
        }
        while((c = getchar()) != '\n' && c !=EOF) { }

        if (choice < 1 || choice > 7){
            printf("Choice must be 1..7\n");
            continue;
        }
        return choice;
    }
}
int add_number(int data[], size_t *count){

    if (*count >= CAPACITY){
        printf("Dataset full (max %d).\n", CAPACITY);
        return 0;
    }
    int value;
    printf("Enter a number :");

    if (scanf("%d", &value) != 1){
        printf("Invalid input.\n");
        int c;
        while((c = getchar()) != '\n' && c != EOF) { }
        return 0;
    }
    int c;
    while((c = getchar()) != '\n' && c != EOF) { }

    data[*count] = value;
    (*count)++;

    printf("Added %d (count=%zu)\n", value, *count);

    return 1;

}
int remove_number(int data[], size_t *count){
    if (*count ==0){
        printf("Nothing to remove (dataset is empty).\n");
        return 0;
    }

    int removed = data[*count - 1];
    (*count)--;

    printf("Removed %d (count=%zu)\n",removed, *count);
}
void print_dataset(int data[], size_t count){
    if (count == 0){
        printf("Dataset is empty.\n");
        return;
    }

    printf("dataser (%zu) :", count);
    for (size_t i = 0; i < count; i++){
        printf("%d", data[i]);
        if (i + 1 < count ) printf(", ");
    }
    printf("\n");
}
 
long long sum_array(int data[], size_t count){
    long long s = 0;
    for (size_t i = 0; i < count; i++){
        s += data[i];
    }
    return s;
}
int minmax_array(const int data[], size_t count, int *out_min, int *out_max){
    if (count == 0) return 0;

    int mn = data[0];
    int mx = data[0];

    for (size_t i = 1; i < count; i++){
        if (data[i] < mn ) mn = data[i];
        if (data[i] > mx ) mx = data[i];
    }

    *out_min = mn;
    *out_max = mx;

    return 1;
}
size_t count_even(int data[], size_t count){
    size_t ev = 0;
    for (size_t i =0; i < count; i++){
        if (data[i] % 2 == 0) ev++;
    }
    return ev;
}
void show_stats(int data[], size_t count){
    if (count == 0){
        printf("Dataset is empty.\n");
        return;
    }

    int mn, mx;
    minmax_array(data, count, &mn, &mx);

    long long s = sum_array(data, count);
    double avg = (double)s / (double)count;

    size_t ev = count_even(data, count);
    size_t od = count - ev;

    printf("----Statistic----");
    printf("Count : %zu\n", count);
    printf("Min : %d\n", mn);
    printf("Max : %d\n", mx);
    printf("Sum : %lld\n", s);
    printf("Avraeg : %.2f\n", avg);
    printf("Even : %zu\n", ev);
    printf("Odds : %zu\n", od);
}