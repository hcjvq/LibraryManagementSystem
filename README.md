# 图书管理系统 (C)

一个基于纯 C 的简易图书管理系统示例，演示了控制器（controller）-服务（service）-数据映射（mapper）三层结构。适合作为学习项目或课堂作业。

## 功能
- 用户注册、登录（含 `admin` 特殊用户）
- 管理员可以添加图书、查看所有用户与图书
- 普通用户可以查看书籍、借书、还书、查看个人借阅

## 项目结构

- `main.c`：程序入口，调用 `run()` 启动交互。
- `common/`：共享类型与常量（`common.h`）。
- `controller/`：命令行交互层（`run_controller.c`、`user_controller.c`）。
- `service/`：业务逻辑层（`user_service.c/h`、`book_service.c/h`）。
- `mapper/`：持久化层（以二进制文件存取，`user_data.c/h`、`book_data.c/h`）。

数据文件：
- 默认书籍文件：`books.dat`
- 默认用户文件：`users.dat`

## 编译（Windows + Visual Studio/MSVC）

在 Visual Studio 中打开 `LibraryManagementSystem.slnx`，构建并运行。

或使用命令行（假设已安装 MSVC 命令行工具）：

```powershell
cl /EHsc main.c controller\run_controller.c controller\user_controller.c \
    service\user_service.c service\book_service.c \
    mapper\user_data.c mapper\book_data.c /I common /Fe:LibraryManagementSystem.exe
```

运行生成的可执行文件 `LibraryManagementSystem.exe`。

## 使用说明
- 启动后按提示输入编号完成注册/登录/借还书等操作。
- 默认 `admin` 密码123456

