using namespace std;
#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
 public:
    String name;

  public:
    Screen();
    virtual void printHello();
    virtual void printTemplate();
    virtual void printValues(int _index);


};

#endif