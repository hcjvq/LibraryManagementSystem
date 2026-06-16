#include "common.h"
int input_str(char* out_str, int max_len) {

	char fmt[FORMAT_MAX_LENGTH];
	sprintf(fmt, "%%%ds", max_len - 1);

	if (scanf(fmt, out_str) != 1) {
		while (getchar() != '\n');
		return 0;
	}
	if (strlen(out_str) >= max_len - 1) {
		while (getchar() != '\n');
		return 0;
	}
	return 1;
}

int input_int(int* out_val) {
	if (scanf("%d", out_val) != 1) {
		while (getchar() != '\n');
		return 0;
	}
	return 1;
}
