#include "../common/common.h"
#include "../mapper/user_data.h"
#include "../mapper/init_data.h"
int register_user_service(char name[CHAR_MAX_LENGTH], char password[CHAR_MAX_LENGTH]) {

	if (name == NULL || password == NULL || strlen(name) == 0 || strlen(password) == 0) {
		printf(" 用户名或密码不能为空！\n");
		return Fail;
	}

	if (get_user(name) == Success) {
		printf("该用户名已被注册过了:\n");
		return Fail;
	}
	 
	int last_id = get_last_id(); 
	User user_temp; 
	user_temp.id = last_id + 1; 
	strncpy(user_temp.name, name, sizeof(user_temp.name) - 1);
	strncpy(user_temp.password, password, sizeof(user_temp.password) - 1); 
	if (add_user(&user_temp) == Success) {
		printf("添加用户成功\n");
	} 
	return Success;
}

int login_user_service(char name[CHAR_MAX_LENGTH], char password[CHAR_MAX_LENGTH]) {
	if (name == NULL || password == NULL || strlen(name) == 0 || strlen(password) == 0) {
		printf(" 用户名或密码不能为空！\n");
		return Fail;
	}
	return check_username_password(name, password); 
}

int get_user_count_service(User * user) {
	return get_user_count(user);
}




