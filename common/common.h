#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Success 200
#define Fail 400

#define CHAR_MAX_LENGTH 100
#define FORMAT_MAX_LENGTH 20

#define MAX_NUM 1000
#define BookFile "books.dat"
#define UserFile "users.dat"





#define INPUT_ERR_STR "您输入的内容格式有问题\n"

#define INPUT_ERR_NUM "您输入的功能编号格式有问题\n"

typedef struct  {
	int id;
	char name[CHAR_MAX_LENGTH];
	char password[CHAR_MAX_LENGTH];
} User;

typedef struct  {
	int book_id;
	char title[CHAR_MAX_LENGTH];
	char author[CHAR_MAX_LENGTH];
	int status;
} Book; 

extern User g_users[MAX_NUM];
extern int g_users_count;

extern Book g_book_arr[MAX_NUM];
extern int g_book_count;

int input_str(char* out_str, int max_len);
int input_int(int* out_val);

// 简单的控制台 UI 辅助函数
void ui_clear();
void ui_title(const char* title);
void ui_prompt(const char* prompt);
void ui_success(const char* msg);
void ui_error(const char* msg);
void ui_info(const char* label, const char* value);

//typedef struct {
//	int id;
//	char title[50];
//	char author[30];
//	float price;
//} Book; 









