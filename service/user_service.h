//注册用户
int register_user_service(char name[CHAR_MAX_LENGTH], char password[CHAR_MAX_LENGTH]);
//用户登录
int login_user_service(char name[CHAR_MAX_LENGTH], char password[CHAR_MAX_LENGTH]); 
//
int check_all_users_service(); 
int get_user_count_service(User* user);