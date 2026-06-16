#include<stdio.h>
#include "common/common.h"
#include "controller/user_controller.h"
#include "controller/data_controller.h"
void run();







void run() {

	 
	while (1) {
		//ui_clear();
		ui_title("图书管理系统 - 主菜单");
		printf("1. 注册用户    2. 登录账号\n");
		printf("0. 退出\n\n");
		ui_prompt("请输入功能编号: ");
		int function_id; 
		if (!input_int(&function_id)) {
			ui_error(INPUT_ERR_STR);
			continue;
		} 
		switch (function_id) {
		case 1: { 
			int res = register_user_controller();
			if (res == Success) {
				ui_success("注册成功");
			}
			else {
				ui_error("注册失败");
			}
			break;
		}
		case 2: {
			// 登录账号 
			int res = login_user_controller();
			if (res == Fail) {
				ui_error("登录失败");
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
