#ifndef READER_H
#define READER_H

#include "headers.h"

class Reader
{
protected:
    Reader(const string path): path_(path) {}
    static Reader* reader_;
    string path_;
public:
    Reader(Reader &other) = delete;
    void operator=(const Reader &) = delete;
    static Reader *GetInstance(const string& path);
    bool** ReadMatrix(ushort x, ushort y);
    bool** ReadMatrix(ushort x);
};
#endif // READER_H
