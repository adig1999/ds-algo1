#include <bits/stdc++.h>

using std::list;
using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    list<string> *elems;

    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:

    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count)
    {
        elems = new list<string>[bucket_count];
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query &query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            list<string>::reverse_iterator i;
            for (i=elems[query.ind].rbegin();i!=elems[query.ind].rend();i++)
                std::cout << *i << " ";
                std::cout << "\n";
                 } else {
                     int it=hash_func(query.s);

            list<string>::iterator k=std::find(elems[it].begin(), elems[it].end(), query.s);

            if (query.type == "find")
            {
                writeSearchResult(k!=elems[it].end());
            }
            else if (query.type == "add") {
                if (k == elems[it].end())
                    elems[it].push_back(query.s);
            } else if (query.type == "del") {
                if (k != elems[it].end())
                    elems[it].erase(k);
            }

                 }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
