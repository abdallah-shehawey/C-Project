#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_NAME_LENGTH 50

typedef struct Student
{
  char name[MAX_NAME_LENGTH];
  int ID;
  int Grade;
  int Level;
  int student;
} Student;

typedef struct Node
{
  Student student;
  struct Node *next;
} Node;

Node *head = NULL;
int student_count = 0;

// Function prototypes
void teacher_mode();
void student_mode();
void add_student();
void print_report();
void show_exam(Node *ptr);
void PYTHON_exam(Node *ptr);
void JAVA_exam(Node *ptr);
void CPP_exam(Node *ptr);
void C_exam(Node *ptr);
int authenticate_user(const char *username, const char *password);

int main()
{
  printf(
      "================================================================\n"
      "**************************MIDTERM EXAM**************************\n"
      "================================================================\n");
  // Main program loop
  while (1)
  {
    int ch;
    printf("SELECT MODE:\n");
    printf("\t1- Teacher Mode.\n");
    printf("\t2- Student Mode.\n");
    printf("\t3- End Exam.\n");
    scanf("%i", &ch);
    fflush(stdin);
    switch (ch)
    {
    case 1:
      teacher_mode();
      break;
    case 2:
      student_mode();
      break;
    case 3: // To End exam by teacher after exam end and it required user_name and pass_wort to make student can't do it
      printf("------------------------------------------------------------------\n");
      char username[MAX_USERNAME_LENGTH];
      char password[MAX_PASSWORD_LENGTH];
      printf("Enter your username: ");
      fgets(username, MAX_USERNAME_LENGTH, stdin);
      username[strcspn(username, "\n")] = '\0'; // Remove newline character
      printf("Enter your password: ");
      fgets(password, MAX_PASSWORD_LENGTH, stdin);
      password[strcspn(password, "\n")] = '\0'; // Remove newline character
      if (authenticate_user(username, password))
      {
        printf("===========================Ending Exam===========================\n");
        // Free memory allocated for student list
        while (head != NULL)
        {
          Node *temp = head;
          head = head->next;
          free(temp);
        }
        return 0;
      }
      else
      {
        printf("===================Invalid Username or Password===================\n");
        printf("------------------------------------------------------------------\n");
      }
    default:
      printf("------------------------------------------------------------------\n");
      printf("===============Invalid selection. Please try again.===============\n");
      break;
    }
  }
}

void teacher_mode()
{
  printf("----------------------------------------------------------------\n");
  printf("============Please Enter Your Username and Password=============\n");
Hamada:
  char username[MAX_USERNAME_LENGTH];
  char password[MAX_PASSWORD_LENGTH];

  printf("Enter your username: ");
  fgets(username, MAX_USERNAME_LENGTH, stdin);
  username[strcspn(username, "\n")] = '\0'; // Remove newline character
  printf("Enter your password: ");
  fgets(password, MAX_PASSWORD_LENGTH, stdin);
  password[strcspn(password, "\n")] = '\0'; // Remove newline character

  if (authenticate_user(username, password))
  {
    printf("----------------------------------------------------------------\n");
    printf("===========================Welcome...===========================\n");
    while (1)
    {
      printf("SELECT CHOOSE: \n");
      printf("\t1- Add Student.\n");
      printf("\t2- Print Report.\n");
      printf("\t3- Exit.\n");
      int ch;
      scanf("%i", &ch);
      fflush(stdin);
      switch (ch)
      {
      case 1:
        add_student();
        break;
      case 2:
        print_report();
        break;
      case 3:
        printf("----------------------------------------------------------------\n");
        return;
      default:
        printf("==============Invalid selection. Please try again.=============\n");
        printf("---------------------------------------------------------------\n");
        break;
      }
    }
  }
  else
  {
    printf("===================Invalid Username or Password===================\n");
    printf("===================Please try again===============================\n");
    goto Hamada;
  }
}

void student_mode()
{
  printf("----------------------------------------------------------------\n");
  printf("Enter your ID: ");
  int ID;
  scanf("%i", &ID);
  fflush(stdin);
  Node *ptr = head;
  while (ptr != NULL && ptr->student.ID != ID)
  {
    ptr = ptr->next;
  }

  if (ptr == NULL)
  {
    printf("=====ID not found=====\n");
    printf("----------------------------------------------------------------\n");
  }
  else
  {
    show_exam(ptr);
  }
}

void add_student()
{
  Node *new_student = (Node *)malloc(sizeof(Node));
  if (new_student == NULL)
  {
    printf("Memory allocation failed.\n");
    return;
  }
  printf("----------------------------------------------------------------\n");
  printf("Enter Student's ID: ");
  scanf("%d", &new_student->student.ID);
  fflush(stdin);
  printf("Enter Student's Name: ");
  fgets(new_student->student.name, MAX_NAME_LENGTH, stdin);
  new_student->student.name[strcspn(new_student->student.name, "\n")] = '\0'; // Remove newline character

  printf("Enter Student's Level: ");
  scanf("%d", &new_student->student.Level);
  fflush(stdin);
  new_student->student.Grade = 0;
  new_student->next = head;
  head = new_student;
  student_count++;

  printf("Student added successfully.\n");
  printf("----------------------------------------------------------------\n");
}

void print_report()
{
  Node *ptr = head;
  for (int I = 1; I <= 4; I++)
  {
    printf("\n\n============================Level (%i)============================\n\n", I);
    for (int II = 20; II >= 0; II -= 4)
    {
      for (int III = 0; III <= student_count, ptr != NULL; III++, ptr = ptr->next)
      {
        if ((ptr->student.Level) == I && (ptr->student.Grade) == II)
        {
          printf("Name: %s\t\t ID: %d\t\t Grade: %d\n", ptr->student.name, ptr->student.ID, ptr->student.Grade);
        }
      }
      ptr = head;
    }
  }
  printf("\n\n----------------------------------------------------------------\n");
}

void show_exam(Node *ptr)
{
  switch (ptr->student.Level)
  {
  case 1:
    PYTHON_exam(ptr);
    break;
  case 2:
    JAVA_exam(ptr);
    break;
  case 3:
    CPP_exam(ptr);
    break;
  case 4:
    C_exam(ptr);
    break;
  }
}

void PYTHON_exam(Node *ptr)
{
  char ch;
  printf("====Your Python Exam====\n");
  printf(
      "**************************Question 1 **************************\n"
      "1- Question: What is the output of the following Python code?\n"
      "```python\n"
      "x = 5\n"
      "print(x)\n"
      "x += 1\n"
      "print(x)\n"
      "---------------------------------------------------------------\n"
      "\tA) 5, 5\n"
      "\tB) 5, 6\n"
      "\tC) 6, 6\n"
      "\tD) 6, 5\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'b' || ch == 'B')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 2 **************************\n"
      "2.**Question: What does the `pass` statement do in Python?**\n"
      "---------------------------------------------------------------\n"
      "\ta) Terminates the program\n"
      "\tb) Skips the current iteration of a loop\n"
      "\tc) Executes a block of code\n"
      "\td) Indicates an empty code block\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'd' || ch == 'D')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 3 **************************\n"
      "3.**Question: In Python, what is the purpose of the `__init__` method in a class?**\n"
      "---------------------------------------------------------------\n"
      "\ta) To initialize the class variables\n"
      "\tb) To define a new instance variable\n"
      "\tc) To create a new object\n"
      "\td) To print the object's state\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'A' || ch == 'a')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 4 **************************\n"
      "4. **Question: What will be the output of the following Python code?**\n"
      "```python\n"
      "numbers = [1, 2, 3, 4, 5]\n"
      "print(numbers[2:4])\n"
      "---------------------------------------------------------------\n"
      "\ta) [1, 2]\n"
      "\tb) [2, 3]\n"
      "\tc) [3, 4]\n"
      "\td) [3, 4, 5]\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'c' || ch == 'C')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 5 **************************\n"
      "5. **Question: Which of the following is a correct way to open a file in Python for reading and writing?**"
      "---------------------------------------------------------------\n"
      "\ta) `open(\"file.txt\", \"rw\")`\n"
      "\tb) `open(\"file.txt\", \"r+\")`\n"
      "\tc) `open(\"file.txt\", \"w+\")`\n"
      "\td) `open(\"file.txt\", \"a\")`\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'C' || ch == 'c')
  {
    ptr->student.Grade += 4;
  }
}

void C_exam(Node *ptr)
{
  int ch;
  printf("====Your C Exam====\n");
  printf(
      "**************************Question 1 **************************\n"
      "1. **Question: What is the output of the following C code?**\n"
      "```C\n"
      "#include <stdio.h>\n"
      "int main() {\n"
      "\tint x = 5;\n"
      "\tprintf(\"%d\", x++);\n"
      "\treturn 0;\n"
      "}\n"
      "---------------------------------------------------------------\n"
      "\ta) 5\n"
      "\tb) 6\n"
      "\tc) 4\n"
      "\td) 7\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'b' || ch == 'B')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 2 **************************\n"
      "2. **Question: Which of the following is not a valid data type in C?**\n"
      "---------------------------------------------------------------\n"
      "\ta) float\n"
      "\tb) char*\n"
      "\tc) long double\n"
      "\td) boolean\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'd' || ch == 'D')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 3 **************************\n"
      "3. **Question: What will be the value of 'result' after the following C code is executed?**\n"
      "```C\n"
      "int a = 10, b = 3;\n"
      "float result = (float)a / b;\n"
      "---------------------------------------------------------------\n"
      "\ta) 3.33\n"
      "\tb) 3\n"
      "\tc) 3.0\n"
      "\td) 4\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'a' || ch == 'A')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 4 **************************\n"
      "4. **Question: In C, what is the purpose of the `typedef` keyword?**\n"
      "---------------------------------------------------------------\n"
      "\ta) To declare a new variable\n"
      "\tb) To define a new data type\n"
      "\tc) To include a header file\n"
      "\td) To specify the size of an array\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'b' || ch == 'B')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 5 **************************\n"
      "5. **Question: What will be the output of the following C code?**\n"
      "```C\n"
      "#include <stdio.h>\n"
      "int main() {\n"
      "\tint i = 0;\n"
      "\tfor (; i < 5; ++i)\n"
      "\tprintf(\"%d\", i);\n"
      "\treturn 0;\n"
      "}\n"
      "---------------------------------------------------------------\n"
      "\ta) 0 1 2 3 4\n"
      "\tb) 1 2 3 4 5\n"
      "\tc) 0 1 2 3\n"
      "\td) 1 2 3 4\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'a' || ch == 'A')
  {
    ptr->student.Grade += 4;
  }
}

void CPP_exam(Node *ptr)
{
  int ch;
  printf("====Your CPP Exam====\n");
  printf(
      "**************************Question 1 **************************\n"
      "1. **Question: What is the output of the following C++ code?**\n"
      "```CPP\n"
      "#include <iostream>\n"
      "using namespace std;\n"
      "int main() {\n"
      "\tint x = 5;\n"
      "\tcout << x++;\n"
      "\treturn 0;\n"
      "}\n"
      "---------------------------------------------------------------\n"
      "\ta) 5\n"
      "\tb) 6\n"
      "\tc) 4\n"
      "\td) 7\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'b' || ch == 'B')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 2 **************************\n"
      "2.**Question: Which C++ keyword is used to dynamically allocate memory?**\n"
      "---------------------------------------------------------------\n"
      "\ta) malloc\n"
      "\tb) allocate\n"
      "\tc) new\n"
      "\td) alloc\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'c' || ch == 'C')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 3 **************************\n"
      "3.**Question: What is the function of the `typeid` operator in C++?**\n"
      "---------------------------------------------------------------\n"
      "\ta) Returns the size of a data type\n"
      "\tb) Returns the type of an object\n"
      "\tc) Checks if a variable is initialized\n"
      "\td) Converts one data type to another\n");
  fflush(stdin);
  scanf(" %c", &ch);
  fflush(stdin);
  if (ch == 'b' || ch == 'B')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 4 **************************\n"
      "4. **Question: In C++, what is a virtual function?**\n"
      "---------------------------------------------------------------\n"
      "\ta) A function that can be called only once\n"
      "\tb) A function that can be overridden in a derived class\n"
      "\tc) A function that is declared in the main function\n"
      "\td) A function that is defined outside the class\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'b' || ch == 'B')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 5 **************************\n"
      "5.**Question: What is the output of the following C++ code?**\n"
      "```CPP\n"
      "#include <iostream>\n"
      "using namespace std;\n"
      "int main() {\n"
      "\tint i = 0;\n"
      "\twhile (i < 5) {\n"
      "\tcout << i <<\" \";\n"
      "\t++i;\n"
      "\treturn 0;\n"
      "}\n"
      "---------------------------------------------------------------\n"
      "\ta) 0 1 2 3 4\n"
      "\tb) 1 2 3 4 5\n"
      "\tc) 0 1 2 3\n"
      "\td) 1 2 3 4\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'a' || ch == 'A')
  {
    ptr->student.Grade += 4;
  }
}

void JAVA_exam(Node *ptr)
{
  char ch;
  printf("====Your JAVA Exam====\n");
  printf(
      "**************************Question 1 **************************\n"
      "1. **Question: What is the output of the following Java code?**\n"
      "```java\n"
      "public class Test {\n"
      "\tpublic static void main(String[] args) {\n"
      "\t\tint x = 5;\n"
      "\t\tSystem.out.print(x++);\n"
      "\t}\n"
      "}\n"
      "---------------------------------------------------------------\n"
      "\ta) 5\n"
      "\tb) 6\n"
      "\tc) 4\n"
      "\td) 7\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'b' || ch == 'B')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 2 **************************\n"
      "2. **Question: Which keyword is used to prevent inheritance in Java?**\n"
      "---------------------------------------------------------------\n"
      "\ta) private\n"
      "\tb) static\n"
      "\tc) final\n"
      "\td) abstract\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'c' || ch == 'C')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 3 **************************\n"
      "3. **Question: What is the purpose of the `super` keyword in Java?**\n"
      "---------------------------------------------------------------\n"
      "\ta) Calls the parent class constructor\n"
      "\tb) Calls a static method in the parent class\n"
      "\tc) Refers to the current instance of the class\n"
      "\td) Indicates the end of a method\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'a' || ch == 'A')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 4 **************************\n"
      "4. **Question: In Java, what is the default value of a boolean variable?**\n"
      "---------------------------------------------------------------\n"
      "\ta) false\n"
      "\tb) true\n"
      "\tc) 0\n"
      "\td) null\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'a' || ch == 'A')
  {
    ptr->student.Grade += 4;
  }
  printf(
      "**************************Question 5 **************************\n"
      "5. **Question: What will be the output of the following Java code?**\n"
      "```java\n"
      "public class Test {\n"
      "\tpublic static void main(String[] args) {\n"
      "\t\tfor (int i = 0; i < 5; ++i)\n"
      "\t\tSystem.out.print(i++ );\n"
      "\t}\n"
      "}\n"
      "---------------------------------------------------------------\n"
      "a) 0 1 2 3 4\n"
      "b) 1 2 3 4 5\n"
      "c) 0 1 2 3\n"
      "d) 1 2 3 4\n");
  fflush(stdin);
  scanf(" %c", &ch);
  if (ch == 'a' || ch == 'A')
  {
    ptr->student.Grade += 4;
  }
}

int authenticate_user(const char *username, const char *password)
{
  // Replace this function with actual authentication logic
  // compare username and password with hardcoded values or from a database
  // Return 1 if authenticated, 0 otherwise
  return (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0);
}
