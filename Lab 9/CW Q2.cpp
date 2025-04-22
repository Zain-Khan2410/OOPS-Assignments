#include <iostream>
#include <vector>
using namespace std;

class Logger {
    private:
        vector <string> logs;
        static const int maxLogs;

        void addLog(string severity, string log) {
            if (logs.size() >= maxLogs) logs.erase(logs.begin());
            logs.push_back("[" + severity + "] " + log);
        }

    public:
        void logInfo(string log) { addLog("INFO", log); }
        void logWarning(string log) { addLog("WARN", log); }
        void logError(string log) { addLog("ERROR", log); }

        friend class Auditor;

};

const int Logger::maxLogs = 1000;

class Auditor {
    private:
        string password;
        bool login;

    public:
        Auditor(string pswd) : password(pswd), login(false) {}

        bool authenticate() {
            if (login) return true;
            string pswd;
            cout << "Enter password to view logs: ";
            cin >> pswd; 
            if (password == pswd) {
                cout << "Login successful" << endl;
                login = true;
                return true;
            } else {
                cout << "Incorrect password, login unsuccessful" << endl;
                return false;
            }
        }

        void displayLogs(const Logger& logger) {
            if (authenticate()) {
                for (int i=0; i<logger.logs.size(); i++) {
                    cout << logger.logs[i] << endl;
                }
            }
        }
};


int main() {
    Logger logger;
    Auditor auditor("securepass");

    logger.logInfo("Network module: Connected.");
    logger.logWarning("Database module: Slow response.");
    logger.logError("Auth module: Invalid credentials.");

    auditor.displayLogs(logger); // will enter incorrect password

    auditor.displayLogs(logger); // will enter correct password

    return 0;
}
