#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

using std::unordered_map;
using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    unordered_map<int,string>pbook;

for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            if(pbook.find(queries[i].number)!=pbook.end())
            {
                pbook.erase(queries[i].number);
            }
             pbook.insert(make_pair(queries[i].number,queries[i].name));

        }
 else if (queries[i].type == "del") {
                pbook.erase(queries[i].number);

        } else {
            string response = "not found";
                if (pbook.find(queries[i].number)!=pbook.end()) {
                    response = pbook.at(queries[i].number);
                }
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
