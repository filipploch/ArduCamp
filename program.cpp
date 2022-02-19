using namespace std;

#include <Arduino.h>
#include "program.h"


using namespace std;




    Program::Program(String _name, String _unit)
    {
      name = _name;
      unit = _unit;
    }

    String Program::getName()
    {
      return name;
    }
    
    float Program::getValue()
    {
      return value;
    }

    String Program::getUnit()
    {
      return unit;
    }
