using namespace std;

class Program
{
  private:
    String name;
    float value;
    String unit;

  public:
    Program(String name, String unit);
    String getName();
    float getValue();
    String getUnit();
};
