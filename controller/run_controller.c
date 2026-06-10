#include "../common/common.h"
#include "../service/user_service.h"

int register_user_controller();
int login_user_controller();
int admin(int* break_flag);
int normal_user(int* break_flag);



void run() {

	while (1) {
		printf("功能:\n");
		printf("1.注册用户\t2.登录账号\n");
		printf("0.退出\n");
		printf("\n\n\n\n");
		printf("请输入功能编号:\n");
		int function_id;
		scanf("%d", &function_id);
		switch (function_id) {
		case 1:
			register_user_controller();
			break;
		case 2:
			// 登录账号 
			login_user_controller();
			break;
		case 0:
			return;
		}

	}
	 
} 