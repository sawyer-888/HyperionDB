# HyperionDB

HyperionDB is a lightweight, **file-based** database written in C++ by **Sawyer888**. It allows you to **create tables, insert data, query, and delete records** using a simple command-line interface (CLI) or via a **REST API** using Crow C++.

## Features
- **Table Management**: Create, insert, select, delete records
- **Data Persistence**: Saves data to files automatically
- **Filtering Support**: Query data by column values
- **REST API** (optional) for integration with other applications

---

## Requirements
### **Compiler**
- **MinGW-w64 (Windows)** or **GCC (Linux/MacOS)**
- C++17 or later

### **Dependencies**
- **Boost C++ (Asio)**
- **Crow C++ (for REST API)**

#### Install Boost
**Windows:**
```sh
# Download Boost and extract it to C:/boost_1_87_0
# Then, build it:
cd C:/boost_1_87_0
bootstrap.bat
b2
# You can use other versios I guess, I just used this one lol i dont know
```

**Linux/MacOS:**
```sh
sudo apt install libboost-all-dev
```

#### Install Crow
```sh
git clone https://github.com/CrowCpp/Crow.git
cd Crow
mkdir build && cd build
cmake ..
make -j4
sudo make install
```

---

## **Building HyperionDB**
### **Compile as an Executable (CLI Mode)**
```sh
g++ -std=c++17 -I C:/boost_1_87_0 -I C:/boost_1_87_0/boost -I src/include -L C:/boost_1_87_0/stage/lib -o HyperionDB src/*.cpp -pthread -lboost_system
```

### **Compile as a Shared Library (For Integration)**
```sh
g++ -shared -o libHyperionDB.dll -I src/include src/*.cpp -pthread
```

---

## **Using HyperionDB (CLI Mode)**
Run the executable:
```sh
./HyperionDB
```
### **Commands**
| Command | Description |
|---------|-------------|
| `CREATE table_name` | Creates a new table |
| `INSERT table_name value1 value2 ...` | Inserts a row into a table |
| `SELECT table_name` | Displays all rows in a table |
| `DELETE table_name row_id` | Deletes a row from a table |
| `EXIT` | Saves and exits |

Example:
```sh
HyperionDB> CREATE users
HyperionDB> INSERT users John Doe 25
HyperionDB> SELECT users
HyperionDB> DELETE users 0
HyperionDB> EXIT
```

---

## **Using HyperionDB (REST API Mode)**
Start the server:
```sh
./HyperionDB
```

### **Available API Routes**
| Method | Endpoint | Description |
|--------|---------|-------------|
| **GET** | `/tables` | List all tables |
| **POST** | `/create/{table_name}` | Create a new table |
| **POST** | `/insert/{table_name}` | Insert data into a table |
| **GET** | `/select/{table_name}` | Retrieve all rows from a table |
| **DELETE** | `/delete/{table_name}/{row_id}` | Delete a row from a table |

Example (Using `curl`):
```sh
curl -X POST http://localhost:8080/create/users
curl -X POST http://localhost:8080/insert/users -d "John Doe 25"
curl -X GET http://localhost:8080/select/users
curl -X DELETE http://localhost:8080/delete/users/0
```

---

## **Integrating HyperionDB as a Library**
If you're using **HyperionDB as a C++ library**, link it to your project:

```cpp
#include "database.h"
Database db;
db.createTable("users");
db.insert("users", {"John", "Doe", "25"});
db.select("users");
```

Compile with:
```sh
g++ -std=c++17 -I src/include -L . -lHyperionDB my_app.cpp -o my_app -pthread
```
