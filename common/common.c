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

// ---------------------- UI helpers ----------------------
// 使用简单的 ANSI 转义序列改善控制台显示（在支持 ANSI 的终端上生效）
void ui_clear() {
	// 清屏并移动光标到左上角
	printf("\x1b[2J\x1b[H");
}

void ui_title(const char* title) {
	printf("\n========================================\n");
	printf("  %s\n", title);
	printf("========================================\n\n");
}

void ui_prompt(const char* prompt) {
	printf("%s", prompt);
}

void ui_success(const char* msg) {
	printf("\x1b[32m[成功]\x1b[0m %s\n", msg);
}

void ui_error(const char* msg) {
	printf("\x1b[31m[错误]\x1b[0m %s\n", msg);
}

void ui_info(const char* label, const char* value) {
	printf("\x1b[34m[%s]\x1b[0m %s\n", label, value);
}

// -------------------------------------------------------
