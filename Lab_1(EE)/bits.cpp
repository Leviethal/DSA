#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'changeBits' function below.
 *
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 *  3. STRING_ARRAY queries
 */

void changeBits(string a, string b, vector<string> queries) {
for(int i=0;i<queries.size();i++){
    vector<int> space_index;
    int k=0;
    for(int i=0;i<queries[i].length();i++){
        if(queries[i]==" "){
            space_index.push_back(i);
        }
    }
    if(queries[i][4]=='a'){
        a[a.length()-1]=queries[i][(int)queries.substr(space_index[1]+1,queries[i].length())-space_index[1]-1];
    }
    else if(queries[i][4]=='b'){
        b[a.length()-1]=queries[i][(int)queries .substr(space_index[1]+1,queries[i].length())-space_index[1]-1];
    }
    else{
        int value=stoi(a,nullptr,2)+stoi(b,nullptr,2);
        bitset<32> binary(value);
        string bin=binary.to_string();
        cout<<bin[bin.length()-space_index[0]-2]
    }
}
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int ab_size = stoi(first_multiple_input[0]);

    int queries_size = stoi(first_multiple_input[1]);

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    vector<string> queries(queries_size);

    for (int i = 0; i < queries_size; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    changeBits(a, b, queries);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
