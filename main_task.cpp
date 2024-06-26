#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bitset>
#include <cmath>

using namespace std;

struct hxy
{
    uint16_t Start;
    uint16_t H;
    uint32_t X;
    uint32_t Y;
    uint16_t End;
}__attribute__((packed));

vector<hxy> structs;

hxy convert(char* data)
{
    return (*(reinterpret_cast<hxy*>(data)));
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

            structs.push_back(convert(buffer));
            if (structs[count].Start == (uint16_t)(4660) && structs[count].End == (uint16_t)(22136))
            {
                cout << "Start[" << count <<"] = " << structs[count].Start << endl;
                cout << "H[" << count <<"] = " << structs[count].H << endl;
                cout << "X[" << count <<"] = " << structs[count].X << endl;
                cout << "Y[" << count <<"] = " << structs[count].Y << endl;
                cout << "End[" << count <<"] = " << structs[count].End << endl;
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