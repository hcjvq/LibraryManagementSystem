#include "../common/common.h"


int add_user( User * add_user ) { 
	FILE* fp = fopen(UserFile, "ab");  
	if (fp == NULL) { 
		return Fail;
	}
	printf("%s", (*add_user).name);
	fwrite(add_user, sizeof(User), 1, fp); 
	fclose(fp); 
	return Success;
}

int user_info_all() {
	FILE* fp = fopen(UserFile, "rb");
	if (fp == NULL) {
		printf("获取用户失败！\n");
		return Fail;
	}
	User users[1000];
	int count = 0;

	while (fread(&users[count], sizeof(User), 1, fp) == 1) {
		printf("用户名:%s\t 用户id：%d\n", users[count].name, users[count].id);
		count++;  // 每读成功一个，数量+1
	} 

}








int get_user(char name[100]) {
	FILE* fp = fopen(UserFile, "rb");
	if (fp == NULL) {
		printf("获取用户失败！\n");
		return Fail;
	}
	User users[1000]; 
	int count = 0; 
	while (fread(&users[count], sizeof(User), 1, fp) == 1) {
		
		if (strcmp(users[count].name, name) == 0) {
			return Success;
		}
		count++;  // 每读成功一个，数量+1
	}
}

int get_user_id(char user_name[100]) {
	FILE* fp = fopen(UserFile, "rb");
	if (fp == NULL) {
		printf("获取用户失败！\n");
		return Fail;
	}
	User users[1000];
	int count = 0;
	while (fread(&users[count], sizeof(User), 1, fp) == 1) { 
		if (strcmp(users[count].name, user_name) == 0) {
			return users[count].id;
		}
		count++;  // 每读成功一个，数量+1
	}
	return 0;
}


int get_last_id() {
	FILE* fp = fopen(UserFile, "rb");
	if (fp == NULL) {
		printf("获取id失败！\n");
		return Fail;
	}
	User users[1000];
	int count = 0;
	int last_id = 0;
	while (fread(&users[count], sizeof(User), 1, fp) == 1) {
		last_id = last_id < users[count].id ? users[count].id : last_id;
		count++;  
	}
	return last_id;
}

int check_username_password(char name[100], char password[100]) {
	FILE* fp = fopen(UserFile, "rb");
	if (fp == NULL) {
		printf("获取id失败！\n");
		return Fail;
	}
	User users[1000];
	int count = 0;
	int flag = Fail;
	while (fread(&users[count], sizeof(User), 1, fp) == 1) {
		//printf("用户信息:name:%s password:%s", users[count].name, users[count].password);
		if (strcmp(users[count].name, name) == 0 && strcmp(users[count].password, password) == 0) {
			return Success;
		}
		count++;
	}
	return flag;
}




//
//
//int register_user_data(char name[100], char password[100]) {
//	
//	 
//
//	FILE* fp = fopen(UserFile, "ab");
//	if (fp == NULL) {
//		printf("文件打开失败！\n");
//		return Fail;
//	}
//
//	 
//
//	
//
//
//	 
//
//
//	 
//	return Success;
//}
//
//
//


