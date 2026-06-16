#include "../common/common.h"
#include "../mapper/book_data.h"
#include "../mapper/user_data.h"
#include "../mapper/init_data.h"
int add_book_service(char title[CHAR_MAX_LENGTH], char author[CHAR_MAX_LENGTH]) {
	 
	if (title == NULL || author == NULL || strlen(title) == 0 || strlen(author) == 0) {
		printf(" 用户名或密码不能为空！\n");
		return Fail;
	}

	Book book_temp;
	strcpy(book_temp.author, author);
	strcpy(book_temp.title, title);
	book_temp.book_id = get_book_last_id() + 1;
	book_temp.status = 0;
	
	char info_buf[256];
	sprintf(info_buf, "书名:%s 作者:%s id:%d", title, author, book_temp.book_id);
	ui_info("新增图书", info_buf);
	 
	if (add_book(&book_temp)) {
		return Success;
	}
	return Fail; 
}


int check_book_all_service() { 
	get_book_all();  
	return Success;
}

int check_all_users_service() {
	printf("\n");
	user_info_all();
	printf("\n");
	printf("\n"); 
}


int borrow_book_service( char user_name[CHAR_MAX_LENGTH],int book_id) {
	if ( user_name == NULL || strlen(user_name) == 0 ) {
		ui_error("用户名不能为空");
		return Fail;
	}

	if (get_user(user_name) != Success) {
		ui_error("用户不存在或校验失败，请稍后重试");
		return Fail;
	}

	if (!check_book_exist_id(book_id)) {
		ui_error("不存在的书籍 ID");
		return Fail;
	}

	if (is_book_available(book_id) == 0) {
		ui_info("提示", "该书已被借出");
		return Fail;
	}

	if (borrow_book( get_user_id(user_name) , book_id)) {
		ui_success("借书成功");
		return Success;
	} else {
		ui_error("借书失败");
		return Fail;
	}

	return Fail; 
}

int self_borrow_book_all_service(char user_name[CHAR_MAX_LENGTH]) { 
	self_borrow_book_all(get_user_id(user_name));
	return Success;
}
 
int return_book_service(char user_name[CHAR_MAX_LENGTH],int book_id) {
	if (user_name == NULL || strlen(user_name) == 0) {
		ui_error("用户名不能为空");
		return Fail;
	}
	if (get_user(user_name) != Success) {
		ui_error("用户不存在或校验失败，请稍后重试");
		return Fail;
	}

	if (!check_book_exist_id(book_id)) {
		ui_error("不存在的书籍 ID");
		return Fail;
	}

	if (self_borrow_exist_by_id( get_user_id(user_name) ) == 0) {
		ui_info("提示", "您当前没有借阅记录");
		return Fail;
	}

	if (return_book(get_user_id(user_name), book_id)) {
		ui_success("还书成功");
		return Success;
	}
	else {
		ui_error("还书失败");
		return Fail;
	} 
	return Fail; 
}

int get_book_count_service(Book* book) {
	return get_book_count(book);
}



















