#include "../common/common.h"

  
int get_book_all() {

	FILE* fp = fopen(BookFile, "rb");

	if (fp == NULL) {
		printf("获取所有书籍失败！\n");
		return Fail;
	}

	Book books[1000];

	int count = 0; 

	while (fread(&books[count], sizeof(Book), 1, fp) == 1) {  

		printf("book name :%s author : %s bookid:%d bookstatus:%d\n", books[count].title, books[count].author, books[count].book_id, books[count].status);

		count++;

	}

	return count;
}


int check_book_exist_book_name( char book_name[100]) {
	// 返回 为 0 不存在 为1存在
	FILE* fp = fopen(BookFile, "rb");
	if (fp == NULL) {
		printf("获取所有书籍失败！\n");
		return Fail;
	}
	Book books[1000];
	int count = 0;
	while (fread(&books[count], sizeof(Book), 1, fp) == 1) {
		printf("循环一次\n");
		if (strcmp(book_name, books[count].title) == 0) {
			return 1;
		}
		//printf("book name :%s author : %s bookid:%d bookstatus:%d", books[count].title, books[count].author, books[count].book_id, books[count].status);
		count++;
	}
	return 0; 
}


int check_book_exist_id(int book_id) {
	// 返回 为 0 不存在 为1存在
	FILE* fp = fopen(BookFile, "rb");
	if (fp == NULL) { 
		return Fail;
	}
	Book books[1000];
	int count = 0;
	while (fread(&books[count], sizeof(Book), 1, fp) == 1) { 
		if (book_id ==  books[count].book_id) {
			return 1;
		}
		//printf("book name :%s author : %s bookid:%d bookstatus:%d", books[count].title, books[count].author, books[count].book_id, books[count].status);
		count++;
	}
	return 0;
}





int get_book_last_id() {

	FILE* fp = fopen(BookFile, "rb");
	if (fp == NULL) {
		printf("获取书籍id失败！\n");
		return Fail;
	}
	Book books[1000];
	int count = 0;
	int last_id = 0;
	while (fread(&books[count], sizeof(Book), 1, fp) == 1) {
		last_id = last_id < books[count].book_id ? books[count].book_id : last_id;
		count++;
	}

	return last_id; 
}


int add_book(Book* add_book) {
	FILE* fp = fopen(BookFile, "ab");
	if (fp == NULL) {
		return Fail;
	}
	printf("%s", (*add_book).title);
	fwrite(add_book, sizeof(Book), 1, fp);
	fclose(fp);
	return Success;
}


int is_book_available(int book_id) {
	// 返回1 可借 0不可借 
	FILE* fp = fopen(BookFile, "rb");
	if (fp == NULL) {
		return Fail;
	}
	Book books[1000];
	int count = 0;
	while (fread(&books[count], sizeof(Book), 1, fp) == 1) {
		if (book_id == books[count].book_id && books[count].status == 0) {
			return 1;
		}
		//printf("book name :%s author : %s bookid:%d bookstatus:%d", books[count].title, books[count].author, books[count].book_id, books[count].status);
		count++;
	}  
	return 0; 
}




int borrow_book(int user_id, int book_id) {

	// 把 book_id 改为 user_name的id 
	FILE* fp = fopen(BookFile, "rb");
	if (fp == NULL) {
		printf("获取所有书籍失败！\n");
		return Fail;
	}

	//books 存储的是全部书籍信息 
	// book_index 存储的是 借的书的id
	Book books[1000];
	int count = 0;
	int book_index = -1;

	while (fread(&books[count], sizeof(Book), 1, fp) == 1) {
		if (books[count].book_id == book_id) {
			book_index = count;
		}
		count++;
	}
	fclose(fp); 
	if (book_index == -1) {
		printf("找不到该书籍！\n");
	} 
	books[book_index].status = user_id; 
	fp = fopen(BookFile, "wb");
	if (!fp) return Fail;
	fwrite(books, sizeof(Book), count, fp);
	fclose(fp); 
	return Success; 
}


int self_borrow_book_all(int user_id) {
	FILE* fp = fopen(BookFile, "rb");
	if (fp == NULL) {
		return Fail;
	}
	Book books[1000];
	int count = 0;
	while (fread(&books[count], sizeof(Book), 1, fp) == 1) {
		if (user_id ==books[count].status) {
			printf("book name :%s author : %s bookid:%d bookstatus:%d\n", books[count].title, books[count].author, books[count].book_id, books[count].status);
		}
		//printf("book name :%s author : %s bookid:%d bookstatus:%d", books[count].title, books[count].author, books[count].book_id, books[count].status);
		count++;
	}
	return 0;


}


int self_borrow_exist_by_id(int user_id) {
	FILE* fp = fopen(BookFile, "rb");
	if (fp == NULL) {
		return Fail;
	}
	Book books[1000];
	int count = 0;
	while (fread(&books[count], sizeof(Book), 1, fp) == 1) {
		if (user_id == books[count].status) {
			return 1;
		}
		//printf("book name :%s author : %s bookid:%d bookstatus:%d", books[count].title, books[count].author, books[count].book_id, books[count].status);
		count++;
	}
	return 0;
	 
}




int return_book(int user_id, int book_id) {
	
	// 把 book_status 改为 0
	FILE* fp = fopen(BookFile, "rb");
	if (fp == NULL) {
		printf("获取所有书籍失败！\n");
		return Fail;
	}

	//books 存储的是全部书籍信息 
	// book_index 存储的是 借的书的id
	Book books[1000];
	int count = 0;
	int book_index = -1;

	while (fread(&books[count], sizeof(Book), 1, fp) == 1) {
		if (books[count].book_id == book_id && books[count].status == user_id) {
			book_index = count;
		}
		count++;
	}
	fclose(fp);
	if (book_index == -1) {
		printf("找不到该书籍！\n");
	}
	books[book_index].status = 0;
	fp = fopen(BookFile, "wb");
	if (!fp) return Fail;
	fwrite(books, sizeof(Book), count, fp);
	fclose(fp);
	return Success; 
}

