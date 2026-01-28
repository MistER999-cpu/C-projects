#include <stdio.h>
#include <string.h>

float estimat_weight(int age);
float compute_bmi(float weight ,float height);
const char* bmi_status(float bmi);
void print_report(const char* name, int age , float height, float weight, float bmi, const char* status);

int main(){

    char name[50];
    int age = 0;
    float height = 0.0f; 

    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL){
        printf("Invalide name input!\n");
        return 1;
    }
    name[strcspn(name, "\n")] = '\0';
    

    printf("Enter your age :");
    if (scanf("%d", &age) != 1 || age <=0 ){
        printf("Invalide age!!");
        return 1;
    }

    printf("Enter your height :");
    if (scanf("%f", &height) != 1 || height <= 0.0f){
        printf("Invalide height!!");
        return 1;
    }

    float weight = estimat_weight(age);
    float bmi = compute_bmi(weight, height);
    const char* status = bmi_status(bmi);
    
    print_report(name, age, height, weight, bmi, status);
    
    return 0;
}

float estimat_weight(int age){
    return age * 2.5f;
}
float compute_bmi(float weight ,float height){
    return weight / (height * height);
}
const char* bmi_status(float bmi){
    if (bmi < 18.5f) return "Underweight";
    if (bmi < 25.0f) return "Normal";
    return "Overweight";
}
void print_report(const char* name, int age , float height, float weight, float bmi, const char* status){

    printf("\n---Profile report ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f m\n", height);
    printf("Estimated weight: %1.f kg\n", weight);
    printf("BMI: %.1f\n", bmi);
    printf("Status: %s\n", status);
}