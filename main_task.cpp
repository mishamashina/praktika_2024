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


struct hxy
{
    uint16_t H;
    uint32_t X;
    uint32_t Y;
}__attribute__((packed));

vector<hxy> all_structs;

hxy convert_new(char* data)
{
    return (*(reinterpret_cast<hxy*>(data)));
}

uint16_t convert(char end, char start)
{
    uint16_t result = (end << 8) + start;
    return result;
}

uint32_t convert_four(char fourth, char third, char second, char first)
{
    uint32_t result = (fourth << 24) + (third << 16) + (second << 8) + first;
    return result;
}

uint32_t convert_four_pointer(char* data)
{
    return (*(reinterpret_cast<uint32_t*>(data)));
}

uint16_t convert_foo(char* data)
{
    return (*(reinterpret_cast<uint16_t*>(data))); // reinterpret_cast< target-type >( expression )  Преобразует типы, переосмысливая базовый битовый шаблон ; Returns a value of type target-type. 
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

            if (convert_foo(buffer) == uint16_t(4660))
            {
                //convert_new(buffer+2);
                all_structs.push_back(convert_new(buffer+2));
                // Start.push_back(convert_foo(buffer));
                // H.push_back(convert_foo(buffer+2));
                // X.push_back(convert_four(buffer[7], buffer[6], buffer[5], buffer[4]));
                // Y.push_back(convert_four(buffer[11], buffer[10], buffer[9], buffer[8]));
                // // X.push_back(convert_four_pointer(buffer+4));
                // // Y.push_back(convert_four_pointer(buffer+8));
                // End.push_back(convert_foo(buffer+12));

                // cout << "Start[" << count <<"] = " << Start[count] << endl;
                cout << "H[" << count <<"] = " << all_structs[count].H << endl;
                cout << "X[" << count <<"] = " << all_structs[count].X << endl;
                cout << "Y[" << count <<"] = " << all_structs[count].Y<< endl;
                // cout << "End[" << count <<"] = " << End[count] << endl;
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