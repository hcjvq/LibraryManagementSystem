#include "../common/common.h"


int add_user( User * add_user ) { 
 

	int cnt = 0;
	while (cnt < MAX_NUM && g_users[cnt].id != 0)
	{ 
		cnt++;
	}
	g_users[cnt] = *add_user; 

	return Success;
}

int user_info_all() { 
	int cnt = 0;
	while (cnt < MAX_NUM && g_users[cnt].id != 0)
	{
		printf("用户名:%s\t 用户id：%d\n", g_users[cnt].name, g_users[cnt].id);
		cnt++;
	} 
	return Success; 
}








int get_user(char name[CHAR_MAX_LENGTH]) { 
	int cnt = 0;
	while (cnt < MAX_NUM && g_users[cnt].id != 0)
	{
		if (strcmp(g_users[cnt].name, name) == 0) {
			return Success;
		}
		cnt++;
	}
	return Fail; 
}

int get_user_id(char user_name[CHAR_MAX_LENGTH]) {

 

	int cnt = 0;
	while (cnt < MAX_NUM && g_users[cnt].id != 0)
	{
		if (strcmp(g_users[cnt].name, user_name) == 0) {
			return g_users[cnt].id;
		}
		cnt++;
	} 
	return 0;

}


int get_last_id() {
	 
	int last_id = 0;

	int cnt = 0;
	while (cnt < MAX_NUM && g_users[cnt].id != 0)
	{
		last_id = last_id < g_users[cnt].id ? g_users[cnt].id : last_id;
		cnt++;
	} 
	return last_id;
}

int check_username_password(char name[CHAR_MAX_LENGTH], char password[CHAR_MAX_LENGTH]) { 
	int cnt = 0;
	while (cnt < MAX_NUM && g_users[cnt].id != 0)
	{
		if (strcmp(g_users[cnt].name, name) == 0 && strcmp(g_users[cnt].password, password) == 0) {
			return Success;
		}
		cnt++;
	} 
	return Fail;
}


//User* get_all_user_info() { 
//	FILE* fp = fopen(UserFile, "rb");
//	if (fp == NULL) {
//		printf("获取用户失败！\n");
//		return Fail;
//	}
//	static User users[MAX_NUM];
//	int count = 0; 
//	while (fread(&users[count], sizeof(User), 1, fp) == 1 && count < MAX_NUM) {
//		count++;   
//	}
//	fclose(fp);
//	return users;
//} 