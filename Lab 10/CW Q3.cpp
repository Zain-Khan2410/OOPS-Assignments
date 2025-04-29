#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string generateDummyUUID(int id) {
    string uuid = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx-";
    string idStr = to_string(id);
    uuid += idStr;
    return uuid;
}

struct User {
    string user_id;
    string first_name;
    string last_name;
    string address;
    string email;
};

struct Product {
    string product_id;
    string product_name;
    string description;
    int price;
};

struct Order {
    string order_id;
    string user_id;
    string product_ordered_id;
    int total_paid;
};

void writeUserData(const string& filename, const vector<User>& users) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.user_id << "," << user.first_name << "," << user.last_name << ","
                 << user.address << "," << user.email << endl;
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

void writeProductData(const string& filename, const vector<Product>& products) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& product : products) {
            file << product.product_id << "," << product.product_name << ","
                 << product.description << "," << product.price << endl;
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

void writeOrderData(const string& filename, const vector<Order>& orders) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& order : orders) {
            file << order.order_id << "," << order.user_id << "," << order.product_ordered_id << ","
                 << order.total_paid << endl;
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

vector<User> readUserData(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            size_t pos4 = line.find(',', pos3 + 1);
            if (pos4 != string::npos) {
                string user_id = line.substr(0, pos1);
                string first_name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string last_name = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string address = line.substr(pos3 + 1, pos4 - pos3 - 1);
                string email = line.substr(pos4 + 1);
                users.push_back({user_id, first_name, last_name, address, email});
            }
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
    return users;
}

vector<Product> readProductData(const string& filename) {
    vector<Product> products;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            if (pos3 != string::npos) {
                string product_id = line.substr(0, pos1);
                string product_name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string description = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string price_str = line.substr(pos3 + 1);
                try {
                    int price = stoi(price_str);
                    products.push_back({product_id, product_name, description, price});
                } catch (const invalid_argument& e) {
                    cerr << "Error: Invalid price format in file: " << filename << endl;
                }
            }
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
    return products;
}

vector<Order> readOrderData(const string& filename) {
    vector<Order> orders;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            if (pos3 != string::npos) {
                string order_id = line.substr(0, pos1);
                string user_id = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string product_ordered_id = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string total_paid_str = line.substr(pos3 + 1);
                try {
                    int total_paid = stoi(total_paid_str);
                    orders.push_back({order_id, user_id, product_ordered_id, total_paid});
                } catch (const invalid_argument& e) {
                    cerr << "Error: Invalid total_paid format in file: " << filename << endl;
                }
            }
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
    return orders;
}

vector<string> getProductsForUser(const string& username,
                                  const vector<User>& users,
                                  const vector<Order>& orders,
                                  const vector<Product>& products) {
    vector<string> productNames;
    string linusId;

    for (const auto& user : users) {
        if (user.first_name == username) {
            linusId = user.user_id;
            break;
        }
    }

    if (linusId.empty()) {
        cout << "User '" << username << "' not found." << endl;
        return productNames;
    }

    vector<string> productIds;
    for (const auto& order : orders) {
        if (order.user_id == linusId) {
            productIds.push_back(order.product_ordered_id);
        }
    }

    for (const auto& productId : productIds) {
        for (const auto& product : products) {
            if (product.product_id == productId) {
                productNames.push_back(product.product_name);
                break;
            }
        }
    }
    return productNames;
}

int main() {
    vector<User> users = {
        {generateDummyUUID(1), "Zain", "Khan", "karachi", "zain.123@gmail.com"},
        {generateDummyUUID(2), "Uzair", "Khan", "Lahore", "rms@gnu.org"},
        {generateDummyUUID(3), "Asad", "Ali", "karachi", "asad.ali@gmail.com"}
    };

    vector<Product> products = {
        {generateDummyUUID(101), "Linux", "An operating system kernel", 0},
        {generateDummyUUID(102), "GCC", "GNU Compiler Collection", 0},
        {generateDummyUUID(103), "C", "Programming Language", 0},
        {generateDummyUUID(104), "GDB", "GNU Debugger", 0}
    };

    vector<Order> orders = {
        {generateDummyUUID(1001), generateDummyUUID(1), generateDummyUUID(101), 0},
        {generateDummyUUID(1002), generateDummyUUID(1), generateDummyUUID(102), 0},
        {generateDummyUUID(1003), generateDummyUUID(2), generateDummyUUID(102), 0},
        {generateDummyUUID(1004), generateDummyUUID(3), generateDummyUUID(103), 0}
    };

    writeUserData("users.txt", users);
    writeProductData("products.txt", products);
    writeOrderData("orders.txt", orders);

    vector<User> readUsers = readUserData("users.txt");
    vector<Product> readProducts = readProductData("products.txt");
    vector<Order> readOrders = readOrderData("orders.txt");

    vector<string> linusProducts = getProductsForUser("Linus", readUsers, readOrders, readProducts);

    cout << "Products ordered by Linus:\n";
    if (linusProducts.empty()) {
        cout << "No products found for Linus.\n";
    } else {
        for (const auto& productName : linusProducts) {
            cout << "- " << productName << endl;
        }
    }

    return 0;
}
