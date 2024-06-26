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

int printHXY(hxy data)
{
    cout << "H = " << data.H << endl;
    cout << "X = " << data.X << endl;
    cout << "Y = " << data.Y << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    ifstream binary_data;
    int length_struct = 14;
    int length;
    int N;
    int i = 0;
    int count = 0;
    int k = 0;
    hxy temp;

    binary_data.open(argv[1], ifstream::binary);

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
                printHXY(structs[count]);
            }

            cout << endl;
            count +=1;  
        }

        cout << "########## Sorted H ##########" << endl;

        for (int i = 0; i < N - 1; i++) 
        {
            for (int j = 0; j < N - i - 1; j++) 
            {
                if (structs[j].H > structs[j + 1].H) 
                {
                    temp = structs[j];
                    structs[j] = structs[j + 1];
                    structs[j + 1] = temp;
                }
            }
        }

        while (k < N)
        {
            cout << "Struct № " << k+1 << endl;
            printHXY(structs[k]);
            cout << endl;
            k++;
        }

        cout << "########## Sorted distance ##########" << endl;
        k = 0;

        for (int i = 0; i < N - 1; i++) 
        {
            for (int j = 0; j < N - i - 1; j++) 
            {
                if (pow(pow(structs[j].X, 2) + pow(structs[j].Y, 2), 0.5) < pow(pow(structs[j+1].X, 2) + pow(structs[j+1].Y, 2), 0.5)) 
                {
                    temp = structs[j];
                    structs[j] = structs[j + 1];
                    structs[j + 1] = temp;
                }
            }
        }

        while (k < N)
        {
            cout << "Struct № " << k+1 << endl;
            printHXY(structs[k]);
            cout << endl;
            k++;
        }
    }

    else(cout << "File not open" << endl);
    return 0;
}