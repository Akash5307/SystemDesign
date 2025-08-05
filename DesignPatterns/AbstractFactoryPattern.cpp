#include<bits/stdc++.h>
using namespace std;

class ShapeInterface{
    public:
    virtual void Draw()=0;
};
class Circle:public ShapeInterface{
    public:
    void Draw(){
        cout<<"Circle\n";
    }
};
class Square: public ShapeInterface{
    public:
    void Draw(){
        cout<<"Square\n";
    }
};
class ShapeFactoryInterface{
    public:
    virtual ShapeInterface* GetShape(string& name)=0;
};
class TwoDShapeFactory:public ShapeFactoryInterface{
    public:
    ShapeInterface* GetShape(string& name){
        if(name=="Circle"){
            return new Circle();
        }else if(name=="Square"){
            return new Square();
        }
    }
};
class ThreeDShapeFactory: public ShapeFactoryInterface{
    public:
    ShapeInterface* GetShape(string& name){
        if(name=="Circle"){
            return new Circle();
        }else if(name=="Square"){
            return new Square();
        }
    }
};
void DisplayOnMonitor(ShapeInterface* shape_factory){

}
void DisplayOnVR(ShapeInterface* shape_factory){

}
int main(){
    ShapeFactoryInterface* two_d_factory= new TwoDShapeFactory();
    ShapeFactoryInterface* three_d_factory=new ThreeDShapeFactory();

}
