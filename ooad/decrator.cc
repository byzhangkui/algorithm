#include <string>
#include <memory>
#include <iostream>

class Beverage {
public:
  virtual std::string GetDescription() { return descrtion_; }
  virtual int Cost() = 0;

private:
  std::string descrtion_ = "unknown";
};

class HouseBlend : public Beverage {
public:
  std::string GetDescription() override { return "HouseBlend"; }
  virtual int Cost() override { return 23;}
};

class DarkRoast : public Beverage {
public:
  std::string GetDescription() override { return "DarkRoast"; }
  virtual int Cost() override { return 25;}
};

class Condiment : public Beverage {
public:
  Condiment(std::shared_ptr<Beverage> beverage):beverage_(beverage) {}
  std::string GetDescription() override { return "";}

protected:
  std::shared_ptr<Beverage> beverage_;
};

class Milk : public Condiment {
public:
  Milk(std::shared_ptr<Beverage> beverage):Condiment(beverage) {}
  std::string GetDescription() override { return beverage_->GetDescription() + " + Milk"; }
  virtual int Cost() override { return beverage_->Cost() + 3;}
};

class Mocha : public Condiment {
public:
  Mocha(std::shared_ptr<Beverage> beverage):Condiment(beverage) {}
  std::string GetDescription() override { return beverage_->GetDescription() + " + Mocha"; }
  virtual int Cost() override { return beverage_->Cost() + 2;}
};

int main() {
  std::shared_ptr<Beverage> b1(new HouseBlend());
  std::cout << "Description:" << b1->GetDescription() << ",Cost:" << b1->Cost() << std::endl;
  std::shared_ptr<Milk> m1(new Milk(b1));
  std::cout << "Description:" << m1->GetDescription() << ",Cost:" << m1->Cost() << std::endl;
  std::shared_ptr<Milk> m2(new Milk(m1));
  std::cout << "Description:" << m2->GetDescription() << ",Cost:" << m2->Cost() << std::endl; 
  return 0;
}

