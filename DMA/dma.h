//
// Created by HP on 2019/6/25.
//

#ifndef DMA_DMA_H
#define DMA_DMA_H


#include <iostream>

class baseDMA {
private:
    char* label;
    int rating;
public:
    baseDMA(const char* l = "null",int r = 0);
    baseDMA(const baseDMA& rs);
    virtual ~baseDMA();
    baseDMA&operator=(const baseDMA & rs);
    friend std::ostream&operator<<(std::ostream& os,const baseDMA& rs);
};

class lacksDMA:public baseDMA
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "bank", const char* l = "null", int r = 0);
    lacksDMA(const char* c, const baseDMA& rs);
    friend std::ostream&operator<<(std::ostream& os, const lacksDMA& rs);
};

class hasDMA:public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char* s = "none", const char* l = "null", int r = 0);
    hasDMA(const char* s, const baseDMA& rs);
    hasDMA(const hasDMA&);
    ~hasDMA();
    hasDMA&operator=(const hasDMA& rs);
    friend std::ostream&operator<<(std::ostream& os, const hasDMA& rs);
};
#endif //DMA_DMA_H
