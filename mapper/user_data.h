
int add_user(User* add_user);
int get_user(char name[CHAR_MAX_LENGTH]);
int get_last_id();
int register_user_data(char name[CHAR_MAX_LENGTH], char password[CHAR_MAX_LENGTH]);
int check_username_password(char name[CHAR_MAX_LENGTH], char password[CHAR_MAX_LENGTH]);
int get_user_id(char user_name[CHAR_MAX_LENGTH]);
int user_info_all();
//User* get_all_user_info();
