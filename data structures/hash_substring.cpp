
#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

long long polyhash(string s)
{
    long long p=1000000007;
    long long x=263;
    long long hash=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        hash=(hash*x+s[i])%p;
    }
    return hash;
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    long long phash=polyhash(s);
    std::vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
    {
        long long thash=polyhash(t.substr(i, s.size()));
        if(thash!=phash)
            continue;
        if(t.substr(i, s.size())==s)
            ans.push_back(i);
    }

    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
