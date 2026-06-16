#include "../common/common.h"

  
int get_book_all() {
	 
	int cnt = 0;
	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{
		printf("book name :%s author : %s bookid:%d bookstatus:%d\n", g_book_arr[cnt].title, g_book_arr[cnt].author, g_book_arr[cnt].book_id, g_book_arr[cnt].status);
		cnt++;
	}
	return Success;
}


int check_book_exist_book_name( char book_name[CHAR_MAX_LENGTH]) {
	// 返回 为 0 不存在 为1存在
	 
	int cnt = 0;
	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{ 
		if (strcmp(book_name, g_book_arr[cnt].title) == 0) {
			return 1;
		}
		cnt++;
	} 
	return 0; 
}


int check_book_exist_id(int book_id) {
	// 返回 为 0 不存在 为1存在
  
	int cnt = 0;
	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{
		if (book_id == g_book_arr[cnt].book_id) {
			return 1;
		}
		cnt++;
	}  
	return 0;
}





int get_book_last_id() {

 
	int last_id = 0; 
	int cnt = 0;
	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{
		last_id = last_id < g_book_arr[cnt].book_id ? g_book_arr[cnt].book_id : last_id;
		cnt++;
	}
	return last_id; 
}


int add_book(Book* add_book) {
  
	int cnt = 0;
	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{ 
		cnt++;
	}
	if (cnt >= MAX_NUM) {
		printf("图书数量已达上限，无法添加！\n");
		return Fail;
	}
	g_book_arr[cnt] = *add_book; 
	return Success;
}


int is_book_available(int book_id) {
	// 返回1 可借 0不可借 
	int cnt = 0;
	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{
		if (book_id == g_book_arr[cnt].book_id && g_book_arr[cnt].status == 0) {
			return 1;
		}
		cnt++;
	} 
	return 0; 
}




int borrow_book(int user_id, int book_id) {

	
	//books 存储的是全部书籍信息 
	// book_index 存储的是 借的书的id
 
 
	int book_index = -1;

	int cnt = 0;
	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{
		if (g_book_arr[cnt].book_id == book_id) {
			book_index = cnt;
		}
		cnt++;
	}

	if (book_index == -1) {
		printf("找不到该书籍！\n");
		return Fail;
	} 
	if (cnt >= MAX_NUM) {
		printf("图书数量已达上限\n");
		return Fail;
	}
	g_book_arr[book_index].status = user_id; 
	return Success; 
}


int self_borrow_book_all(int user_id) {
	int cnt = 0;
	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{
		if (user_id == g_book_arr[cnt].status) {
			printf("book name :%s author : %s bookid:%d bookstatus:%d\n", g_book_arr[cnt].title, g_book_arr[cnt].author, g_book_arr[cnt].book_id, g_book_arr[cnt].status);
		}
		cnt++;
	}
	return 0; 
}


int self_borrow_exist_by_id(int user_id) {
	 

	int cnt = 0;
	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{
		if (user_id == g_book_arr[cnt].status) {
			return 1;
		}
		cnt++;
	} 
	return 0;
	 
}




int return_book(int user_id, int book_id) {

	int book_index = -1;

	int cnt = 0;

	while (cnt < MAX_NUM && g_book_arr[cnt].book_id != 0)
	{
		if (g_book_arr[cnt].book_id == book_id && g_book_arr[cnt].status == user_id) {
			book_index = cnt;
			break;
		}
		cnt++;
	}

	if (book_index == -1) {
		printf("找不到该书籍！\n");
	}

	if (cnt >= MAX_NUM) {
		printf("图书数量已达上限\n");
		return Fail;
	}

	g_book_arr[book_index].status = 0;  
	return Success; 
}




