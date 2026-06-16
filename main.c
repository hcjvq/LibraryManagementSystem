#include<stdio.h>
#include "common/common.h"
#include "controller/user_controller.h"
#include "controller/data_controller.h"
void run();







void run() {

	 
	while (1) {
		
		printf("功能:\n");
		printf("1.注册用户\t2.登录账号\n");
		printf("0.退出\n");
		printf("\n\n\n\n");
		printf("请输入功能编号:\n");
		int function_id; 
		if (!input_int(&function_id)) {
			printf(INPUT_ERR_STR);
			continue;
		} 
		switch (function_id) {
		case 1: { 
			int res = register_user_controller();
			if (res == Success) {
				printf("注册成功\n");
			}
			else {
				printf("注册失败\n");
			}
			break;
		}
		case 2: {
			// 登录账号 
			int res = login_user_controller();
			if (res == Success) {
				printf("登录成功\n");
			}
			else {
				printf("登录失败\n");
			}
			break;
		}
		case 0:
			return;

		default:
			printf("不存在该功能编号，请重新选择！\n");
			break;
		}

	}

}


int main() {
	init_data_controller(g_users,g_book_arr); 
	run(g_users, g_book_arr);
	int user_count = get_user_count_controller(g_users);
	int book_count = get_book_count_controller(g_book_arr);
	save_data_controller(g_users, g_book_arr, user_count, book_count);
	return 0;
}
