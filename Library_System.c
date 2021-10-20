// ConsoleApplication11.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct Book
{
	char bookTitle[100];
	char bookAuthor[100];
	char subject[100];
	int  bookIDNumber;
};
//Declaring book structure

struct Student
{
	int studentID;
	int bookID;
	char nameOfStudent[100];
	
};
//Declaring student structure

int choice;
int PassPin;
int RegisteredBooks;
int RegisteredStudents;
//These Variables above are global variables and i've made them as such as they will be accessed throughout the program

struct Student Students[100];
struct Book Books[100];

void Student();
void studentRegister();
void bookSearch();
void borrowBook();
void returnBook();

void Staff();
void bookAdd();
void bookDelete();
void listBooks();
void listBook(int x);
void listUsers();
void listUser(int x);

bool password();
bool bookInArray(int x);
bool studentInArray(int i);

void Student()
{
	int studentChoice;

	printf("==========================Student Main Menu==========================\n");
	printf("              Press <1-4> if you would like to\n");
	printf("              <1> Register as a student with the library?\n");
	printf("              <2> Search for a particular book\n");
	printf("              <3> Borrow a book\n");
	printf("              <4> Return a book\n");
	printf("              <5> Return back to Main Menu\n");
	printf("=====================================================================\n");
	scanf(" %i", &studentChoice);
	switch (studentChoice)
	{
	case 1:
		studentRegister();
		break;
	case 2:
		bookSearch();
		break;
	case 3:
		borrowBook();
		break;
	case 4:
		returnBook();
		break;
	case 5:
		mainMenu();
		break;
	default:
		printf("This is an invalid choice, please try again.\n");
		Student();
		break;
	}
}

void studentRegister()
{
	char studentName[100];
	char studentID[10];
	printf("=====================================================================\n");
	printf("Name: ");
	scanf("%s", &studentName); 
	studentName[strlen(studentName) + 1] = '\0';
	printf("Student ID: ");
	scanf("%s", &studentID); 
	int studentIDInteger = atoi(studentID);

	if((strcmp(studentName, "")) && (studentIDInteger!=0) && (studentInArray(studentIDInteger)==false))
	{
		strcpy(Students[RegisteredStudents].nameOfStudent, studentName); 
		Students[RegisteredStudents].studentID = studentIDInteger;
		RegisteredStudents++;
		printf("You have been added to our database.\n" );
		printf("=====================================================================\n");
	}
	else
	{
    printf("Sorry, I was unable to add you to our database.\n");
	}
}
void bookSearch()
{
	int ch;
	char searchName[20];
	printf("=====================================================================\n");
	printf("Enter name of the book:");
	scanf("%s", &searchName);
	
	searchName[strlen(searchName) + 1] = '\0';

	for (int x = 0; x < 100; x++)
	{
		if((strcmp(Books[x].bookTitle, searchName)==0)||(strcmp(Books[x].bookAuthor, searchName)==0)||(strcmp(Books[x].subject, searchName)==0))
		{
			listBook(x);
			break; 
		}
		else
		{
			printf("Sorry, I was unable to find that book.\n");
			printf("Would you like to try again?\n");
			printf("<1> Yes\n");
			printf("<2> No\n");
			scanf(" %i", &ch);

			if (ch == 1)
			{
				bookSearch();
			}
			else if (ch == 2)
			{
				mainMenu();
			}
			else
			{
				printf("This is an invalid choice\n");
				exit(4);
			}
			break;
		}
	}
}
void borrowBook()
{
	int ch;
	char studentID[10];
	printf("=====================================================================\n");
	printf("Student ID: ");
	scanf("%s", &studentID); 
	int studentInteger = atoi(studentID);

	char bookID[10];
	printf("Book ID: ");
	scanf("%s", &bookID); 
	int bookInteger = atoi(bookID);


	if((bookInArray(bookInteger)) && (studentInArray(studentInteger)))
	{
		for (int x = 0; x < 100; x++)
		{
			if(Students[x].studentID == studentInteger)
			{
				if(Students[x].bookID == 0)
				{
					Students[x].bookID = bookInteger;
					printf("This book has now been allocated to you. Please proceed to reception to collect. \n");
				}
				else
				{
					printf("Sorry, this book has already been borrowed out of the library.\n");

				}
			}
		}
	}
	else
	{
		printf("Sorry we were unable to complete this instruction.\n");
		printf("Would you like to try again?\n");
		printf("<1> Yes\n");
		printf("<2> No\n");
		scanf(" %i", &ch);

		if (ch == 1)
		{
			borrowBook();
		}
		else if (ch == 2)
		{
			mainMenu();
		}
		else
		{
			printf("This is an invalid choice\n");
			exit(5);
		}
	}
}
void returnBook()
{
	int ch;
	char studentID[10];
	printf("=====================================================================\n");
	printf("Student ID: ");
	scanf("%s", &studentID); 
	int studentInteger = atoi(studentID);

	if(studentInArray(studentInteger))
	{
		for (int x = 0; x < 100; x++)
		{
  			if(Students[x].studentID == studentInteger)
			{
  			Students[x].bookID = 0;
			printf("Book has been returned. Please drop book in reception, on the way out.");
  			}
	   }
	}
	else
	{
     printf("Sorry, but I couldnt find your student ID.\n");
	 printf("Would you like to try again?\n");
	 printf("<1> Yes\n");
	 printf("<2> No\n");
	 scanf(" %i", &ch);

	 if (ch == 1)
	 {
		 returnBook();
	 }
	 else if (ch == 2)
	 {
		 mainMenu();
	 }
	 else
	 {
		 printf("This is an invalid choice\n");
		 exit(6);
	 }
	}
}

void Staff()
{
	int staffChoice;

	printf("==========================Staff Main Menu============================\n");
	printf("              Press <1-4> if you would like to\n");
	printf("              <1> Register a book into the library\n");
	printf("              <2> Remove a book from the library\n");
	printf("              <3> Display the current book list\n");
	printf("              <4> Display the list of current students\n");
	printf("              <5> Return back to main menu\n");
	printf("=====================================================================\n");
	scanf(" %i", &staffChoice);
	switch (staffChoice)
	{
	case 1:
		bookAdd();
		break;
	case 2:
		bookDelete();
		break;
	case 3:
		listBooks();
		break;
	case 4:
		listUsers();
		break;
	case 5:
		mainMenu();
		break;
	default:
		printf("This is an invalid choice, please try again.\n");
		Staff();
		break;
	}
}

bool password()
{
	printf("==========================Password Required==========================\n");
	printf("Password: ");
	scanf("%i", &PassPin);

	if (PassPin == 3456)
	{
		return true;
	}
	else
	{
		printf("Incorrect password. \n");
		return false;
	}
}

void bookAdd()
{
	char bookTitle[100];
	char bookAuthor[100];
	char subject[100];
	char bookID[10];

	printf("=====================================================================\n");
	printf("Title: ");
	scanf("%s", &bookTitle); 
	bookTitle[strlen(bookTitle) + 1] = '\0';
	printf("Author: ");
	scanf("%s", &bookAuthor); 
	bookAuthor[strlen(bookAuthor) + 1] = '\0';
	printf("Subject: ");
	scanf("%s", &subject); 
	subject[strlen(subject) + 1] = '\0';
	printf("Book ID: ");
	scanf("%s", &bookID); 
	int bookInteger = atoi(bookID);


	if((strcmp(bookTitle, "")) && (strcmp(bookAuthor, "")) && (strcmp(subject, "")) && (bookInteger!=0) && (bookInArray(bookInteger)==false))
	{
		strcpy(Books[RegisteredBooks].bookTitle, bookTitle); 
		strcpy(Books[RegisteredBooks].bookAuthor, bookAuthor); 
		strcpy(Books[RegisteredBooks].subject, subject); 
		Books[RegisteredBooks].bookIDNumber = bookInteger;
		RegisteredBooks++;
		printf("\nThis book has now been added \n");
	}
	else
	{
    printf("Sorry, I was unable to add \n");
	}

}
bool bookInArray(int i)
{
	for (int x = 0; x < 100; x++)
	{
		if(Books[x].bookIDNumber == i)
		{
			return true;
		}
	}
	return false;
}

bool studentInArray(int i)
{
	for (int x = 0; x < 100; x++)
	{
		if(Students[x].studentID == i)
		{
			return true;
		}
	}
	return false;
}
void bookDelete()
{
	int ch;
	int bookInteger;
	printf("=====================================================================\n");
	printf("Book ID: ");
	scanf(" %i", &bookInteger); 

	if(bookInArray(bookInteger))
	{
		for (int x = 0; x < 100; x++)
		{
			if(Books[x].bookIDNumber == bookInteger)
			{
				printf("=====================================================================\n");
				printf("Title: %s\n", Books[x].bookTitle );
		  		printf("Author: %s \n", Books[x].bookAuthor );
				printf("Subject: %s \n", Books[x].subject );
				printf("Book ID: %i \n", Books[x].bookIDNumber );
			}
		}
		int choice;
		printf("=====================================================================\n");
		printf("Is this the correct book? \n");
		printf("<1> Yes\n");
		printf("<2> No\n");
		scanf(" %i", &choice );

		if(choice==1)
		{
			for (int x = 0; x < 100; x++)
			{
				if(Books[x].bookIDNumber == bookInteger)
				{
					strcpy(Books[x].bookTitle, "");
					strcpy(Books[x].bookAuthor, "");
					strcpy(Books[x].subject, "");
					Books[x].bookIDNumber = 0;
					RegisteredBooks--;
					printf("Book has been removed from library");
					break;
				}
			}
		}
		else if(choice==2)
		{
			printf("=====================================================================\n");
			printf("Would you like to try again?\n");
			printf("<1> Yes\n");
			printf("<2> No\n");
			scanf(" %i", &ch);

			if (ch==1)
			{
				bookDelete();
			}
			else if (ch==2)
			{
				mainMenu();
			}
			else
			{
				printf("This is an invalid choice\n");
				exit(3);
			}
		}
	}
}
void listBooks()
{
	for (int x = 0; x < 100; x++)
	{
		if(Books[x].bookIDNumber != 0)
		{
			listBook(x);
		}
	}
}
void listBook(int x)
{
	printf("=====================================================================\n");
	printf("Title: %s\n", Books[x].bookTitle );
	printf("Author: %s \n", Books[x].bookAuthor );
	printf("Subject: %s \n", Books[x].subject );
	printf("Book ID: %i \n", Books[x].bookIDNumber );
}

void listUsers()
{
	for (int x = 0; x < 100; x++)
	{
		if(Students[x].studentID != 0)
		{
			listUser(x);
		}
	}
}
void listUser(int x)
{//This will list the currently registered students and if they have any books borrowed, to Staff
	printf("=====================================================================\n");
	printf("Name:%s\n", Students[x].nameOfStudent);
	printf("Student ID: %i \n", Students[x].studentID);
	if (Students[x].bookID==1)
	{
		printf("%i book on loan \n", Students[x].bookID);
	}
	else
	{
		printf("Currently have borrowed no book's");
	}
	

}

void helpPage()
{//This will help the user understand my program, if having troubles to do so.
	printf("==============================Help Page==============================\n");
	printf("              Rules of University of Leeds Library\n");
	printf("              You can borrow one book at a time.\n");
	printf("              When entering information into this \n");
	printf("              System, please enter it as one word e.g\n");
	printf("              your name as AbiyeSelema\n");
	printf("=====================================================================\n");
}
void mainMenu()
{
	printf("\n====================University of Leeds Library======================\n");
	printf("              Press <1-2> if you are a... or <3> for more information \n");
	printf("              <1> Student\n");
	printf("              <2> Staff Member\n");
	printf("              <3> Help page\n");
	printf("=====================================================================\n");
	scanf(" %i", &choice);
	switch (choice)
	{
	case 1:
		Student();
		break;
	case 2:
		if (password() == true)
		{
			Staff();
		}
		break;
	case 3:
		helpPage();
		break;
	default:
		printf("This is an invalid choice, please try again.\n");
		printf("=====================================================================\n");
		break;
	}

}
int main()
{
	while (1) //A loop that will never stop
	{
		mainMenu();
	}
		return 0;
}
