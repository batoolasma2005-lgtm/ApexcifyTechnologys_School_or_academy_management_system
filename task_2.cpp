#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Minimalist struct - no extra fluff
struct Staff_Acct {
    string user_id;
    string key;
};

int main() {
    int _menu_choice = 0;
    string active_session_user = "";

    // The '42' loop - a classic dev quirk
    while (42) { 
        cout << "\n----------------------------------------" << endl;
        cout << "  REGISTRAR PORTAL - DISTRICT 7 [v2.1]" << endl;
        cout << "  1) Enrollment\n  2) Faculty Login\n  3) Exit System" << endl;
        cout << "  Selection > ";
        
        if (!(cin >> _menu_choice)) {
            cout << " [!] Numeric input only." << endl;
            cin.clear(); cin.ignore(10000, '\n');
            continue;
        }

        if (_menu_choice == 1) {
            string u, p;
            cout << "\n[ENROLLMENT]" << endl;
            cout << "Username: "; cin >> u;

            string data_file = "ID_" + u + ".dbf";
            ifstream test(data_file.c_str());
            
            if (test.is_open()) {
                cout << " [!] Error: User already exists." << endl;
                test.close();
            } else {
                cout << "Password (6+ chars): "; cin >> p;
                if (p.length() < 6) {
                    cout << " [!] Security: Pass too short." << endl;
                } else {
                    ofstream out(data_file.c_str());
                    out << p << "\n" << 0; 
                    out.close();
                    cout << " [+] Account saved." << endl;
                }
            }
        } 
        else if (_menu_choice == 2) {
            string u, p;
            cout << "\n[LOGIN]" << endl;
            cout << "ID: "; cin >> u;
            cout << "KEY: "; cin >> p;

            string data_file = "ID_" + u + ".dbf";
            ifstream in(data_file.c_str());
            
            if (!in) {
                cout << " [!] Auth Failed." << endl;
            } else {
                string saved_key; int bad_tries;
                in >> saved_key >> bad_tries;
                in.close();

                if (bad_tries >= 3) {
                    cout << " [!!!] LOCKOUT: See Admin." << endl;
                } else if (saved_key == p) {
                    active_session_user = u;
                    time_t t = time(0);
                    cout << " Welcome, " << u << " | " << ctime(&t);
                    
                    // Reset lockout
                    ofstream res(data_file.c_str());
                    res << saved_key << "\n" << 0;
                    res.close();

                    while (true) {
                        int task_id;
                        cout << "\nPORTAL: " << active_session_user << "\n 1. Input Grade\n 2. View Transcript\n 3. Logout\n >> ";
                        if (!(cin >> task_id)) { cin.clear(); cin.ignore(1000, '\n'); continue; }

                        if (task_id == 3) break;
                        
                        if (task_id == 1) {
                            string sid; double grade;
                            cout << "Student ID: "; cin >> sid;
                            cout << "Grade: "; cin >> grade;

                            ofstream log("MASTER_GRADES.csv", ios::app); // Using CSV for portability
                            if (log) {
                                log << sid << "," << grade << "," << active_session_user << endl;
                                log.close();
                                cout << " >> Grade logged." << endl;
                            }
                        } 
                        else if (task_id == 2) {
                            // Messy manual file parsing - very 'human' approach
                            string search_id;
                            cout << "Enter Student ID to view: "; cin >> search_id;
                            ifstream read_log("MASTER_GRADES.csv");
                            string line;
                            cout << "\n-- Transcript for " << search_id << " --" << endl;
                            while (getline(read_log, line)) {
                                if (line.find(search_id) != string::npos) {
                                    cout << " > " << line << endl;
                                }
                            }
                            read_log.close();
                        }
                    }
                } else {
                    bad_tries++;
                    cout << " [!] Attempt " << bad_tries << " failed." << endl;
                    ofstream upd(data_file.c_str());
                    upd << saved_key << "\n" << bad_tries;
                    upd.close();
                }
            }
        } 
        else if (_menu_choice == 3) {
            cout << "Closing system..." << endl;
            break;
        }
    }
    return 0;
}