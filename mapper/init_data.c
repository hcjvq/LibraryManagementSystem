
#include "../common/common.h"

 

// 定义全局变量实体（只写一次）
User g_users[MAX_NUM] = { 0 };
int g_users_count = 0;

Book g_book_arr[MAX_NUM] = { 0 };
int g_book_count = 0;


int init_data( User * users, Book * books) {
	 
	FILE* fp_users = fopen(UserFile, "rb");

	if (fp_users == NULL) {
		printf("获取用户失败！\n");
		return Fail;
	}

	//static User users[MAX_NUM];
	int count_users = 0;
	while (fread(&users[count_users], sizeof(User), 1, fp_users) == 1 && count_users < MAX_NUM) {
		count_users++;
	}
	fclose(fp_users);
	  
	FILE* fp = fopen(BookFile, "rb");

	if (fp == NULL) {
		printf("获取所有书籍失败！\n");
		return Fail;
	} 
	int count = 0;

	while (fread(&books[count], sizeof(Book), 1, fp) == 1 && count < MAX_NUM) {
		count++; 
	}
	fclose(fp);
	return Success;
}



int save_data(User* users, Book* books,int user_count,int book_count) {
	
	FILE*  fp_users = fopen(BookFile, "wb");
	if (!fp_users) return Fail;
	fwrite(books, sizeof(Book), book_count, fp_users);
	fclose(fp_users);
	 
	FILE*  fp = fopen(UserFile, "wb");
	if (!fp) return Fail;
	fwrite(users, sizeof(User), user_count, fp);
	fclose(fp);  
	return Success;
}

 
int get_user_count(User* users)
{
	int cnt = 0;
	while (cnt < MAX_NUM && users[cnt].id != 0)
	{
		cnt++;
	}
	return cnt;
}

 
int get_book_count(Book* books)
{
	int cnt = 0;
	while (cnt < MAX_NUM && books[cnt].book_id != 0)
	{
		cnt++;
	}
	return cnt;
} 

