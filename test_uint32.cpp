/**
 * Copyright (c) 2020, SeekLoud Team.
 * Manager:
    * 2020/12/27: hewro
 * Develper: hewro
 * Description: 
 * Refer:
 */
#include <iostream>

class PictureMixer {

    virtual void setCanvasSize(uint32_t width, uint32_t height) = 0;
    virtual uint32_t getCanvasWidth() = 0;

    /**
    * 获取画布的高度
    * @return 画布高度
    */
    virtual uint32_t getCanvasHeight() = 0;

};
class Test:PictureMixer{
    uint32_t outWidth;
    uint32_t outHeight;

public:
    void setCanvasSize(uint32_t width, uint32_t height) override {
        outWidth = width;
        outHeight = height;
    }

    uint32_t getCanvasWidth() override {
        return outWidth;
    }

    uint32_t getCanvasHeight() override {
        return outHeight;
    }

};

int main(){
    Test* test = new Test();
    test->setCanvasSize(640,360);
    std::cout << test->getCanvasWidth() << std::endl;
}
