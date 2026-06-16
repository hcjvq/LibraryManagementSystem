int add_book_service();
int check_book_all_service();
int borrow_book_service(char user_name[CHAR_MAX_LENGTH],int book_id);
int return_book_service(char user_name[CHAR_MAX_LENGTH], int book_id);
int self_borrow_book_all_service(char user_name[CHAR_MAX_LENGTH]);

 
int save_user_info_service();
int get_user_count_service(User* users);