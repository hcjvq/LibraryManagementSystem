
#include "../common/common.h"
#include "../service/init_data_service.h"


int init_data_controller(User* users, Book* books) { 
	init_data_service(users, books);
	return Success;
}
 

int save_data_controller(User* users, Book* books, int user_count, int book_count) {
	save_data_service(users, books, user_count, book_count);
	return Success;
}

int get_book_count_controller(Book* book) {
	return get_book_count_service(book);
}

int get_user_count_controller(User* users) {
	return get_user_count_service(users);;
}










