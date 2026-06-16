#include "../common/common.h"
#include "../service/user_service.h"

//int register_user_controller();
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
		if (scanf("%d", &function_id) != 1) { 
			while (getchar() != '\n'); 
			printf("输入无效，请输入数字！\n");
			continue; 
		}
		switch (function_id) {
			case 1: {
					char name[CHAR_MAX_LENGTH];
					char password[CHAR_MAX_LENGTH];
					printf("请输入您要注册的用户名:");
					scanf("%99s", name);
					printf("请输入该用户的密码:");
					scanf("%99s", password);
					int res = register_user_service(name, password);
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
				//login_user_controller();
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
		}

	}
	 
} 