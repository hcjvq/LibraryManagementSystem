 

 // 获取书籍最大id
int get_book_last_id(); 
// 添加书籍
int add_book(Book* book_temp);
// 打印所有书籍
int get_book_all();
// 借书
int borrow_book(int user_id, int book_id);
// 还书
int return_book(int user_id, int book_id);
// 是否可借
int is_book_available(int book_id);

int check_book_exist_id(int book_id);
int check_book_exist_book_name(char book_name[CHAR_MAX_LENGTH]);
int self_borrow_book_all(int user_id);
int self_borrow_exist_by_id(int user_id);