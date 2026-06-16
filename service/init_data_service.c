#include "../common/common.h"
#include "../mapper/init_data.h"

int  init_data_service(User* users, Book* books) {
	init_data(users, books);
	return Success; 
}

int  save_data_service(User* users, Book* books, int user_count, int book_count) {
	save_data(users, books,  user_count, book_count);
	return Success; 
}

//int get_user_count_service(User* users) {
//	return get_user_count(users);
//}
//
//
//int get_book_count_service(Book* book) {
//	return get_book_count(book);
//}