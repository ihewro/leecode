//
// Created by hewro on 2021/3/31.
//
#include "Util.hpp"
//定义动物类型
class Animal{
public:
    virtual void say() = 0;
};
class Dog: public Animal{
public:
    void say() override {
        std::cout << "dog" << std::endl;
    }
};
class FemaleDog : public Dog{
public:
    void say() override {
        std::cout << "female dog" << std::endl;
    }
};
class MaleDog : public Dog{
public:
    void say() override {
        std::cout << "male dog" << std::endl;
    }
};
class Cat: public Animal{
public:
    void say() override {
        std::cout << "cat" << std::endl;
    }
};


//工厂父类
class AnimalFactory{
public:
    virtual Animal* createDog() = 0;
    virtual Animal* createCat() = 0;
};

//只为第一分类的子工厂
class MaleAnimalFactory: public AnimalFactory{
public:
    Animal* createDog() override{
        return new MaleDog();
    }
    Animal* createCat() override {
        //...
    };
};

class FemaleAnimalFactory: public AnimalFactory{
public:
    Animal* createDog() override{
        return new FemaleDog();
    };
    Animal* createCat() override{

    };
};

static class Test{


};


int main(){
    AnimalFactory* f = new FemaleAnimalFactory();
    f->createDog()->say();//输出 female dog
    AnimalFactory* ff = new MaleAnimalFactory();
    ff->createDog()->say();//输出 male cat
}