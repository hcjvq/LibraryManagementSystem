#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Success 200
#define Fail 400

#define BookFile "books.dat"
#define UserFile "users.dat"

typedef struct  {
	int id;
	char name[100];
	char password[100];
} User;

typedef struct  {
	int book_id;
	char title[100];
	char author[100];
	int status;
} Book; 
 
//typedef struct {
//	int id;
//	char title[50];
//	char author[30];
//	float price;
//} Book; 









