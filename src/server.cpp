#include "include/database.h"
#include "crow_all.h"

Database db;  

int main() {
    crow::SimpleApp app; 


    CROW_ROUTE(app, "/create/<string>")([](const std::string& table) {
        db.createTable(table);
        return crow::response(200, "Table '" + table + "' created.");
    });


    CROW_ROUTE(app, "/insert/<string>/<string>")([](const std::string& table, const std::string& data) {
        db.insert(table, {data});
        return crow::response(200, "Inserted '" + data + "' into " + table);
    });

  
    CROW_ROUTE(app, "/select/<string>")([](const std::string& table) {
        std::ostringstream result;
        db.select(table);
        return crow::response(200, result.str());
    });

   
    CROW_ROUTE(app, "/delete/<string>/<int>")([](const std::string& table, int id) {
        db.deleteRow(table, id);
        return crow::response(200, "Deleted row " + std::to_string(id) + " from " + table);
    });

 
    app.port(8080).multithreaded().run();
}
