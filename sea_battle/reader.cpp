#include "headers.h"

Reader* Reader::reader_= nullptr;
Reader* Reader::GetInstance(const string& path)
{
    if(reader_ == nullptr){
        reader_ = new Reader(path);
    }
    return reader_;
}
bool** Reader::ReadMatrix(ushort x, ushort y){
    char c;
    bool **arr = new bool*[x];
    for(int i = 0; i < x; i++){
        arr[i] = new bool[y];
    }

    ifstream s(path_, ios_base::binary);
    if(s.is_open()){
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                s.get(c);
                arr[i][j] = bool(c - '0');
            }
            s.get(c);// \n
            s.get(c);// \r
        }
        s.close();
    } else cerr << "Can't open file\n";
    return arr;
}
bool** Reader::ReadMatrix(ushort x){
    char c;
    bool **arr = new bool*[x];
    for(int i = 0; i < x; i++){
        arr[i] = new bool[x];
    }

    ifstream s(path_, ios_base::binary);
    if(s.is_open()){
        for(int i = 0; i < x; i++){
            for(int j = 0; j < x; j++){
                s.get(c);
                arr[i][j] = bool(c - '0');
            }
            s.get(c);// \n
            s.get(c);// \r
        }
        s.close();
    } else cerr << "Can't open file\n";
    return arr;
}
