

#include "../common/common.h"
#include "../service/user_service.h"
#include "../service/book_service.h"
 

  
int register_user_controller() {
	char name[CHAR_MAX_LENGTH];
	char password[CHAR_MAX_LENGTH];
	printf("请输入您要注册的用户名:"); 
	if (!input_str(name,sizeof(name))) {
		printf(INPUT_ERR_STR);
		return Fail;
	} 
	printf("请输入该用户的密码:");
	if (!input_str(password, sizeof(password))) {
		printf(INPUT_ERR_STR);

		return Fail;
	}
	register_user_service(name, password); 
	return Success;
}



int admin_controller(int* break_flag,char user_name[CHAR_MAX_LENGTH]) {
	printf("1.添加书籍\t 2.查看所有用户信息\n");
	printf("3.查看所有书籍\t \n");
	printf("0.退出\n");
	printf("\n\n\n\n");
	printf("请输入功能编号:\n");
	int function_id; 
	if (!input_int(&function_id)) {
		printf(INPUT_ERR_STR); 
		return Fail;
	} 
	switch (function_id) {
	case 1:{
		printf("添加书籍\n");
		char title[CHAR_MAX_LENGTH];
		char author[CHAR_MAX_LENGTH];
		printf("请输入书名:"); 
		if (!input_str(title, sizeof(title))) {
			printf(INPUT_ERR_STR); 
			return Fail;
		}
		printf("请输入该书的作者:"); 
		if (!input_str(author, sizeof(author))) {
			printf(INPUT_ERR_STR); 
			return Fail;
		} 
		add_book_service(title, author); 
		break;
	}
	case 2:
		printf("查看用户信息\n");
		check_all_users_service();
		break;
	case 3:
		printf("查看所有书籍\n");
		check_book_all_service();
		break;
	case 0:
		*break_flag = 0;
		return Success;
	default:
		printf("不存在该功能编号，请重新选择！\n");
		break;
	} 
	return Success; 
}

int normal_user_controller(int* break_flag, char user_name[CHAR_MAX_LENGTH]) {
	printf("1.借书\t2.还书\n");
	printf("0.退出\n");
	printf("\n\n\n\n");
	printf("请输入功能编号:\n");
	int function_id; 
	if (!input_int(&function_id)) {
		printf(INPUT_ERR_STR); 
		return Fail;
	} 
	switch (function_id) {
	case 1:{
		printf("借书\n");
		printf("书籍信息\n");
		check_book_all_service(); 
		printf("\n\n\n\n");

		int book_id = -1;
		printf("请输入书籍ID:");
		if (!input_int(&book_id)) {
			printf(INPUT_ERR_STR);
			break;
		} 
		borrow_book_service(user_name, book_id);
		break;
	}
		case 2:{
			printf("还书\n");
			self_borrow_book_all_service(user_name); 
			int book_id = -1;
			printf("请输入书籍ID:");
			if (!input_int(&book_id)) {
				printf(INPUT_ERR_STR);
				break;
			}
			return_book_service(user_name, book_id);
			break;
	} 
	case 0:
		*break_flag = 0;
		return;
	default:
		printf("不存在该功能编号，请重新选择！\n");
		break;
	}
	return Success; 
}



int login_user_controller() {
	
	char name[CHAR_MAX_LENGTH];
	char password[CHAR_MAX_LENGTH];
	printf("请输入您要登录的用户名:\n");
	if (!input_str(name, sizeof(name)))
	{
		printf("您输入的用户名格式有问题\n");
		return Fail;
	}
	printf("请输入该用户的密码:\n");
	if (!input_str(password, sizeof(password)))
	{
		printf("您输入的密码格式有问题\n");
		return Fail;
	}

	int flag = login_user_service(name, password);

	if (flag == Success) {
		int break_flag = 1;
		while (break_flag) { 
			printf("欢迎您：%s\n", name);
			if (strcmp(name, "admin") == 0) {
				admin_controller(&break_flag, name); 
			}
			else {
				normal_user_controller(&break_flag, name);
			}
		}

	}
	else { 
		return Fail;
	}
	return Success;
}

 




 
 




















































