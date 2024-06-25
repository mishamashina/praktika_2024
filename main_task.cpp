#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bitset>
#include <cmath>

using namespace std;

vector<uint16_t> H;

uint16_t convert(char end, char start)
{
    stringstream ss;
    string str;
    ss << bitset<8>(end) << bitset<8>(start);
    str  = ss.str();
    cout << "Line bits " << str << endl;
    bitset<16> bit (str);
    cout << "bit.to_ulong() = "<< bit.to_ulong() << endl;
    return uint16_t(bit.to_ulong());
}

int main()
{
    ifstream binary_data;
    stringstream start_stream;
    stringstream H_stream;
    string start_string;
    string H_string;
    int length_struct = 14;
    int length;
    int length_iteration = 2;
    int N;
    int i;
    int count = 0;
    int k = 0;
    uint16_t max = 0;



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
                H.push_back(convert(buffer[3], buffer[2]));
                cout << "H[" << count <<"] = " << H[count] << endl;
            }
            // convert(buffer[1], buffer[0]);
            // convert(buffer[3], buffer[2]);


            // start_stream << bitset<8>(buffer[1]) << bitset<8>(buffer[0]);
            // start_string  = start_stream.str();
            // cout << start_string << endl; 
            // bitset<16> start (start_string);
            // cout << start.to_ulong() << endl;

            // start_stream.str(string());

            // start_stream << bitset<8>(buffer[3]) << bitset<8>(buffer[2]);
            // start_string  = start_stream.str();
            // cout << start_string << endl; 
            // bitset<16> start1 (start_string);
            // cout << start1.to_ulong() << endl;






            //
            //
            //

            // while (i < length_struct)
            // {
            //     cout << dec << int((*(buffer+i)))<< " ";
            //     //cout << hex << int((*(buffer+i)))<< " ";
            //     i++;
            // }
            // cout << endl;

            i = 0;
            while (i < length_struct)
            {
                //ss << bitset<8>(buffer[i]);
                // if (i == 1)
                // {
                //     ss << bitset<8>(buffer[i]) << bitset<8>(buffer[i-1]) << " ";
                // }

                //cout << hex << uint16_t((*(buffer+i)))<< " ";
                cout << bitset<8>(buffer[i]) << endl;

                //ss << bitset<8>(buffer[i]) << " ";
                //cout << hex << int((*(buffer+i)))<< " ";
                i++;
            }

            cout << endl;

            // uint16_t result = (buffer[3] << 8) | buffer[2];
            // H.push_back(result);
            // if (count == 4)
            // {
            //     //cout << "count == 4 " << hex << int(buffer[2]);
            //     while (i < length_struct)
            //     {
            //         cout << hex << int((*(buffer+i))) << " ";
            //         // if (i == 2) 
            //         // {
            //         //     unsigned char a = *(buffer+i+1);
            //         //     unsigned char b = *(buffer+i);
            //         //     unsigned int result = (a << 8) | b;
            //         //     cout << "result " << result << "! ";
            //         //     H.push_back(result);
            //         // }
            //         // //H[0] = ((*(buffer+i+1)) << 8) | (*(buffer+i));
            //         // // unsigned char a = *(buffer+i+1);
            //         // // unsigned char b = *(buffer+i);
            //         // // unsigned int result = (a << 8) | b;
            //         // ss << hex << (int)(*(buffer+i)) << " ";
            //         i++;
            //     }
            // }

            //mystr  = ss.str();
            //cout << mystr << endl;

            
            count +=1;
        }


        // i = 0;
        // int numb = 0;
        // while (i < 16)
        // {
        //     //cout << "mystr[i] = " << mystr[i] << " ";
        //     if (char(mystr[i]) != '0')
        //     {
        //         //cout << "char(mystr[i]) = " << char(mystr[i]) << " ";
        //         numb += pow(2, 15-i);
        //         //cout << "nubm = " << numb << " ";
        //     }
        //     i++;
        // }
        //cout << "nubm = " << numb << endl;

        // while (k < N)
        // {
        //     if (max < H[k]){max = H[k];}
        //     cout << "H = " << H[k] << " k = " << k+1 << endl;
        //     k ++;
        // }

        // cout << "max = " << max << endl;
        // char buffer[];

        // // int buffer[] = {12, 23}; 
   
        // // cout << buffer << endl;
        // // cout << *buffer << endl;
        // // cout << buffer[0] << endl;
        // // cout << buffer[1] << endl;
        // // cout << *(buffer+1) << endl;

        // cout << "Reading " << length << " characters... " << endl;

        // binary_data.read(buffer,length);
        // if (binary_data){cout << "all characters read successfully" << endl;}
        // else {cout << "error: only " << binary_data.gcount() << " could be read" << endl;}

        // while (i < length)
        // {
        //     cout << hex << (int)(*(buffer+i)) << " ";
        //     //if(i )
        //     // ss << hex << (int)(*(buffer+i));
        //     i++;
        // }
        // cout << endl;

        // i = 0;
        // binary_data.seekg(0, binary_data.cur);
        // binary_data.read(buffer,length);

        // while (i < length)
        // {
        //     cout << hex << (int)(*(buffer+i)) << " ";
        //     //if(i )
        //     // ss << hex << (int)(*(buffer+i));
        //     i++;
        // }
        // cout << endl;


        // mystr  = ss.str();
        // cout << mystr;    
    }
    else(cout << "File not open" << endl);

    return 0;
}

// int sjoin(const char *str1, const char *str2, char * &dst)
// {
//     int len1 = 0, len2 = 0;
//     for (len1; str1[len1]; ++len1);
//         for (len2; str1[len2]; ++len2);
//     dst = new char[len1 + len2 + 1];
//         for (int i = 0; i < len1; ++i)
//         dst[i] = str1[i];
//     for (int i = 0; i < len2; ++i)
//         dst[len1 + i] = str2[i];
//     dst[len1 + len2] = '\0';
//     return len1 + len2;
// };