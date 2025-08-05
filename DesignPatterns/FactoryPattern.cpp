#include<bits/stdc++.h>
using namespace std;

class ShapeInterface{
    public:
    virtual void Draw()=0;
};
class Square :public ShapeInterface{
    public:
    void Draw() override{
        cout<<"Square\n";
    }
};
class Circle: public ShapeInterface{
    public:
    void Draw()override{
        cout<<"Circle\n";
    }
};
class ShapeFactory{
    public:
    ShapeInterface* GetShape(string name){
        if(name=="Circle"){
            return new Circle();
        }else if(name=="Square"){
            return new Square();
        }
    }
};
int main(){
    string s;
    cin>>s;
    ShapeFactory sf;
    ShapeInterface* si=sf.GetShape(s);
    si->Draw();
    delete si;
    return 0;
}
