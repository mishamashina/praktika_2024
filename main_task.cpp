#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bitset>
#include <cmath>

using namespace std;

vector<uint16_t> Start;
vector<uint16_t> End;
vector<uint16_t> H;
vector<uint32_t> X;
vector<uint32_t> Y;

uint16_t convert(char end, char start)
{
    stringstream ss;
    string str;
    ss << bitset<8>(end) << bitset<8>(start);
    str  = ss.str();
    cout << "Line bits " << str << endl;
    bitset<16> bit (str);
    //cout << "bit.to_ulong() = "<< bit.to_ulong() << endl;
    return uint16_t(bit.to_ulong());
}

uint32_t convert_four(char fourth, char third, char second, char first)
{
    stringstream ss;
    string str;
    ss << bitset<8>(fourth) << bitset<8>(third) << bitset<8>(second) << bitset<8>(first);
    str  = ss.str();
    cout << "Line bits " << str << endl;
    bitset<32> bit (str);
    //cout << "bit.to_ulong() = "<< bit.to_ulong() << endl;
    return uint32_t(bit.to_ulong());
}


int main()
{
    ifstream binary_data;
    int length_struct = 14;
    int length;
    int N;
    int i = 0;
    int count = 0;

    binary_data.open("binary_data_10", ifstream::binary);

    if (binary_data.is_open())
    {
        cout << "File open" << endl;

        binary_data.seekg(0, binary_data.end);
        int length = binary_data.tellg();
        binary_data.seekg(0, binary_data.beg);

        N = length/length_struct;
        cout << "N = " << N << endl;

        while (count < N)
        {
            char buffer[length_struct];
            i = 0;

            binary_data.read(buffer,length_struct);
            if (binary_data){cout << "STRUCT № " << dec << count+1 << " read successfully" << endl;}
            else {cout << "error: only " << binary_data.gcount() << " could be read" << endl;}

            if (convert(buffer[1], buffer[0]) == uint16_t(4660))
            {
                Start.push_back(convert(buffer[1], buffer[0]));
                H.push_back(convert(buffer[3], buffer[2]));
                X.push_back(convert_four(buffer[7], buffer[6], buffer[5], buffer[4]));
                Y.push_back(convert_four(buffer[11], buffer[10], buffer[9], buffer[8]));
                End.push_back(convert(buffer[13], buffer[12]));

                cout << "Start[" << count <<"] = " << Start[count] << endl;
                cout << "H[" << count <<"] = " << H[count] << endl;
                cout << "X[" << count <<"] = " << X[count] << endl;
                cout << "Y[" << count <<"] = " << Y[count] << endl;
                cout << "End[" << count <<"] = " << End[count] << endl;
            }

            while (i < length_struct)
            {
                cout << bitset<8>(buffer[i]) << endl;
                i++;
            }

            cout << endl;
            count +=1;
        }   
    }
    else(cout << "File not open" << endl);

    return 0;
}