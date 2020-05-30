#include <iostream>

class A
{
  public:
    A ():m_iVal(0){test();}
    virtual void func() { std::cout<<m_iVal<< "";}
    void test(){func();}
  public:
      int m_iVal;
};
class B : public A
{
  public:
    B(){test();}
    virtual void func()
    {
      ++m_iVal;
      std::cout << m_iVal << "";
      }
};

    int Sum_Solution(int n) {
        if (1 == n) {
            return 1;
        }
        int sum = n + Sum_Solution(n - 1);
        return sum;
    }


	void replaceSpace(char *str,int length) {
        if (0 == str) {
            return;
        }
        
        int original_count = 0;
        int blank_count = 0;
        for (int i = 0; i < length && str[i] != '\0'; ++i) {
            if (str[i] == ' ') {
                ++blank_count;
            }
            ++original_count;
        }
        
        int new_length = original_count + blank_count*2;
        if (new_length > length) {
            return;
        }
        
        int pos = new_length - 1;
        for (int i = original_count - 1; i >= 0; --i,--pos) {
            if (str[i] != ' ') {
                str[pos] = str[i];
            } else {
              str[pos] = '0';
              --pos;
              str[pos] = '2';
              --pos;
              str[pos] = '%';
            }
        }
	}
  
int main(int argc ,char* argv[])
{
  A*p = new B;
  p->test();

  std::cout << Sum_Solution(10) << std::endl;
  return 0;
}