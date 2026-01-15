#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define NAME_MAX 50
#define PHONE_MAX 20
#define EMAIL_MAX 60

typedef struct{
    int id;
    char name[NAME_MAX];
    char phone[PHONE_MAX];
    char email[EMAIL_MAX];

}Contact;
static void trimnewline(char *s);
static void readline(const char *prompt, char *out, size_t out_size);
static int isvalidphone(const char *s);
static int isvalidemail(const char *s);
static int isduplicated(const Contact *arr, size_t count, const char *phone, const char * email);
int addcontact(Contact **arr, size_t *count, int *next_id);

void listcontacts(const Contact *arr, size_t count);

static void tolowercase(char *dst, const char *src, size_t n);
static int containscaseinsensitive(const char *text, const char *pattern);
void searchcontact(const Contact *arr, size_t count);

static void tolowercase(char *dst, const char *src, size_t n);
static int containscaseinsensitive(const char *text, const char *pattern);
void searchcontact(const Contact *arr, size_t count);
static int findbyid(const Contact *arr, size_t count, int id);
int editcontact(Contact *arr, size_t count);



int main(){
  
  int choice;
  Contact *contatcs = NULL;
  size_t count = 0;
  int next_id = 1;

  while(true){

    printf("\n***Contact Manager***\n\n");
    printf("1. Add Contact\n");
    printf("2. List Contacs\n");
    printf("3. Search Contact\n");
    printf("4. Edit Conatct\n");
    printf("5.Exit\n");
    printf("Enter your choice :");
    scanf("%d", &choice);

int ch;
while ((ch = getchar()) != '\n' && ch != EOF) { }

    switch(choice){
        case 1:
        addcontact(&contatcs, &count, &next_id);
        break;

        case 2:
        listcontacts(contatcs, count);
        break;
        
        case 3:
        searchcontact(contatcs, count);
        break;

        case 4:
        editcontact(contatcs, count);
        break;

        case 5:
        free(contatcs);
        break;
    }
  }  






    return 0;
}

static void trimnewline(char *s){
    size_t n = strlen(s);
    if(n > 0 && s[n - 1] =='\n') s[n -1] ='\0'; // removes \n with fgets
}

static void readline(const char *prompt, char *out, size_t out_size){
   printf("%s", prompt);
   fflush(stdout); // forces the text I just printed to appear on screen
   if(fgets(out, (int)out_size, stdin) == NULL){   //in case f gets fails
    out[0] = '\0';   
    return ;     // to empty output buffer                         
   }
  trimnewline(out);
}

static int isvalidphone(const char *s){
   if(!s || !*s) return 0; // !s s is NULL points to nothing // *s cheks if the string sbi empty cz *s is the first char and if = \0 then string = ""
   for(size_t i = 0; s[i]; i++){
    if(i == 0 && s[i] == '+') continue; //makes sure phone starts with +
    if(!isdigit((unsigned char)s[i])) return 0; // makes sur all that cums after + is all digits
   }
   return 1;
}

static int isvalidemail(const char *s){
    if(!s || !*s) return 0;
    const char *at = strchr(s, '@');  // strchr search a string for a single char
    if(!at) return 0;
    const char *dot = strchr(at, '.');
    if(dot != NULL) return 1;
    else return 0;
}

static int isduplicated(const Contact *arr, size_t count, const char *phone, const char *email){
  for(size_t i = 0; i < count; i ++){
    if(strcmp(arr[i].phone , phone) == 0) return 1;
    if(strcmp(arr[i].email , email) == 0) return 1;
  }
  return 0;
}

int addcontact(Contact **arr, size_t *count, int *next_id){
    Contact c;

    readline("Name :", c.name, sizeof(c.name));
    readline("Phone :", c.phone, sizeof(c.phone));
    readline("Email :", c.email, sizeof(c.email));
   

    if(c.name[0] == '\0'){
        printf("Error name cannot be empty!!\n");
        return 0;
    }

    if(!isvalidphone(c.phone)){
        printf("Error phone must be all digits (it can be leading with +)!!\n");
        return 0;
    }
    if(!isvalidemail(c.email)){
        printf("Error invalid email!!\n");
        return 0;
    }
    if(isduplicated(*arr, *count, c.phone, c.email)){
        printf("Error phone or email already exists\n");
        return 0;
    }
    c.id = (*next_id)++;

    Contact *tmp = realloc(*arr, (*count +1) * sizeof(Contact));
    if(tmp == NULL){ 
        printf("Memory error.\n"); //takes amount of byts for evry contatcs * all the contacts + the new one and allocates the place for allv them in memory
        return 0;
    }
    *arr = tmp; //“Update the contacts array pointer to the new memory location after realloc.”
    (*arr)[*count] = c; //“Put the new contact c at position count in the array.”
    (*count)++; //“We added one contact, so increase the total count.”

    printf("OK contact added (id=%d)", c.id);
    return 1;
}
void listcontacts(const Contact *arr, size_t count){
    if(count == 0){
        printf("No contacts.\n");
        return;
    }
    printf("\n---- contact(%zu)----\n", count);

    for(size_t i = 0; i < count; i++){
        printf("%d | %s | %s | %s\n", arr[i].id, arr[i].name, arr[i].phone, arr[i].email);
    }
}

static void tolowercase(char *dst, const char *src, size_t n){ //dst = Destination buffer
    size_t i = 0;                                                 
    for(; i + 1 < n && src[i]; i++) {
        dst[i] = (char)tolower((unsigned char)src[i]); //(unsigned char)src[i] , tolower expects a value representable as unsigned char (or EOF).
    }
                                                            //src = Source string (input)                                    
      dst[i] = '\0';                                                         //n is the size of dst      

}
static int containscaseinsensitive(const char *text, const char *pattern){
    char t[NAME_MAX], p[NAME_MAX];

    tolowercase(t, text, sizeof(t));
    tolowercase(p, pattern, sizeof(p));

    return strstr(t, p)  !=  NULL;

}
void searchcontact(const Contact *arr, size_t count){
    if(count ==0){
        printf("No contact to search.\n");
        return;
    }
    char q[EMAIL_MAX];
    readline("Search (name/phone/email):", q, sizeof(q));

    if(q[0] == '\0'){
        printf("Empty search!!\n");
        return ;
    }
    int found = 0;
    for(size_t i=0; i < count; i++){
        if(containscaseinsensitive(arr[i].name, q) || 
             strstr(arr[i].phone, q) !=NULL ||
             containscaseinsensitive(arr[i].email, q)){

                printf("%d | %s | %s |%s\n", arr[i].id, arr[i].name, arr[i].phone, arr[i].email);
                found = 1;
             } 
    }
    if(!found) printf("No match !!\n");

}
static int findbyid(const Contact *arr, size_t count, int id){
    for(size_t i = 0 ; i < count; i++){
        if(arr[i].id == id ) return (int)i; //“Find the contact whose id equals id, and tell me where it is in the array.
        //So it returns:
        //the index if found
        //-1 if not found
    
    }
    return -1;
}
int editcontact(Contact *arr, size_t count){
    if(count == 0){
        printf("No contatcs to edit.\n");
        return 0;  
    }

    char buf[32];
    readline("Enter ID to edit: ", buf, sizeof(buf));
    int id = atoi(buf); //converts the user’s input (a string) into an integer.
    

    int idx = findbyid(arr, count, id);
    if(idx == -1){
        printf("ID not found.\n");
        return 0;
    } 
    printf("Editing: %d | %s | %s | %s\n",arr[idx].id, arr[idx].name, arr[idx].phone, arr[idx].email);

    Contact *c = &arr[idx];

    readline("Enter new name: ", buf, sizeof(buf));
    if(buf[0] != '\0'){
        strncpy((*c).name, buf, NAME_MAX);
        (*c).name[NAME_MAX - 1] = '\0';
        //This forces the last character to be '\0'
        //the string is always properly terminated
        //printing with %s and using strcmp will not read beyond the array
    }
    readline("Enter new phone: ", buf, sizeof(buf));
    if(buf[0] != '\0'){
        if(!isvalidphone(buf)){
            printf("Invalid phone.\n");
            return 0;
        }
        strncpy((*c).phone, buf , PHONE_MAX);
        (*c).phone[PHONE_MAX - 1] = '\0';
    }
    readline("Enter new email: ", buf, sizeof(buf));
    if(buf[0] != '\0'){
        if(!isvalidemail(buf)){
            printf("Invalid email.\n");
            return 0;
        }
        strncpy((*c).email, buf , EMAIL_MAX);
        (*c).email[EMAIL_MAX - 1] = '\0';
    }
    printf("Contact Uploaded.\n");
    return 1;

}
    