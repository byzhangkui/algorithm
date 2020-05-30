
#include <mutex>

class MyClass {
  
  public:
  MyClass& GetInstance() {
    static MyClass my_class;
    return my_class;
  }

};

class MyClass2 {
  public:

  //非多线程版本
  MyClass2* GetInstance() {
   static MyClass2* instance = nullptr;
   if (nullptr == instance) {
     instance = new MyClass2;
   }
   return instance;
  }
};

class MyClass3 {
  private:
  MyClass3();
  ~MyClass3();

  public:
  MyClass3* GetInstance() {
    static MyClass3* instance = nullptr;
    if (nullptr == instance) {
      //创建时加锁
      std::lock_guard<std::mutex> lock(lock_);
      if (nullptr == instance) {
        instance = new MyClass3;
      }
    }
    return instance;
  }

  static std::mutex lock_;
};

//模版方法
template<class T>
T* MakeInstance(T* t) {
  static T* instance = nullptr;
}