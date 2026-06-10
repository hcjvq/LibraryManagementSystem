

#include "../common/common.h"
#include "../service/user_service.h"
#include "../service/book_service.h"
int admin(int* break_flag,char user_name[100]);
int normal_user(int* break_flag, char user_name[100]);

char g_user_name[100];


int register_user_controller() {
	char name[100];
	char password[100];
	printf("请输入您要注册的用户名:");
	scanf("%s", name);
	printf("请输入该用户的密码:");
	scanf("%s", password);

	register_user(name, password);

	return 200;
}



int admin(int* break_flag,char user_name[100]) {
	printf("1.添加书籍\t 2.查看所有用户信息\n");
	printf("3.查看所有书籍\t \n");
	printf("0.退出\n");
	printf("\n\n\n\n");
	printf("请输入功能编号:\n");
	int function_id;
	scanf("%d", &function_id);

	switch (function_id) {
	case 1:
		printf("添加书籍\n");
		add_book_service();
		break;
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
		return;
	}
}

int normal_user(int* break_flag, char user_name[100]) {
	printf("1.借书\t2.还书\n");
	printf("0.退出\n");
	printf("\n\n\n\n");
	printf("请输入功能编号:\n");
	int function_id;
	scanf("%d", &function_id);
	switch (function_id) {
	case 1:
		printf("借书\n");
		printf("书籍信息\n");
		check_book_all_service(); 
		printf("\n\n\n\n");
		borrow_book_service(user_name);
		break;
	case 2:
		printf("还书\n");
		self_borrow_book_all_service(user_name);
		return_book_service(user_name);
		break;
	case 0:
		*break_flag = 0;
		return;
	}
}



int login_user_controller() {
	
	char name[100];
	char password[100];
	printf("请输入您要登录的用户名:");
	scanf("%s", name);
	printf("请输入该用户的密码:");
	scanf("%s", password);

	int flag = login_user_service(name, password);
	if (flag == Success) {
		printf("登录成功!\n");
		 
		int break_flag = 1;
		while (break_flag) { 
			printf("欢迎您：%s\n", name);
			if (strcmp(name, "admin") == 0) {
				admin(&break_flag, name);
			}
			else {
				normal_user(&break_flag, name);
			}
		}

	}
	else {
		printf("登录失败!\n");
	}
	return 200;
}




















































