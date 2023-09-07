/* Name: Esat Duman
   UIN: 662726641
   Course: Data Structures
   Project 4 Shape List
*/


#pragma once

using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public:  // varables that everyone can use. public interface that everyone can access.
        Shape() {

            this->setX(0);   // mutators - setters // provide direct setting to private data members 
            this->setY(0);  // can change private data members

        } // implement this 
        Shape(int x, int y) {

            this->setX(x); // mutators
            this->setY(y);

        }
            
        virtual ~Shape()
        {

        }
         // destructor 

        virtual Shape* copy()
        {
            return new Shape(*this);
        } // copy for the new shape 

        int getX() const // accessor remember : An accessor function accesses data members but does not modify a class' data members.
        {
            return this-> x;
        } 

        int getY() const // accessor
        { 
           return this-> y; 
        }
        void setX(int xAxis) // pass in a value in our case int
        {
            this->x = xAxis;
        }  
        void setY(int yAxis)
        {
            this->y = yAxis;
        }
        
        virtual void printShape() const
        {
           cout << "it's a Shape at x: " << this-> getX() << "," << " y: " << this-> getY() << endl; // display the print shape message.
        }
};


class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle()
        {
            this->setX(0); // setting to 0 
            this->setY(0); // setting to 0 
            this->setRadius(0); // setting to 0   
        }
        Circle(int r)
        {
            this->setX(0);
            this->setY(0);
            this->setRadius(r);
        }
        Circle(int x, int y, int r)
        {
            this->setX(x);
            this->setY(y);
            this->setRadius(r);

        }  // r for the radius of the circle 

        virtual ~Circle()
        {

        }  // destructor 

        virtual Circle* copy()
        {
             return new Circle(*this);
        }
        
        int getRadius() const
        {
            return this->radius;
        } // accessor 

        void setRadius(int r)
        {
            this->radius = r;  // setting the radius to r
        }
        
        virtual void printShape() const
        {
            cout << "it's a Circle at: " << this-> getX() << "," << " y: " << this-> getY() << "," << " radius: " << getRadius() << endl;
        }
};


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle()
        {
          this->setX(0);
          this->setY(0);
          this->setWidth(0);
          this->setHeight(0);     
        }
        Rectangle(int w, int h)
        {
          this->setX(0);          
          this->setY(0);
          this->setWidth(w);
          this->setHeight(h);  
        }
        Rectangle(int x, int y, int w, int h)
        {
            this->setX(x);
            this->setY(y);
            this->setWidth(w);
            this->setHeight(h);
        } // need to do 
        
        virtual ~Rectangle()
        {

        } //destructor

        virtual Rectangle* copy()
        {
            return new Rectangle(*this);
        }
        
        int getWidth() const
        {
            return this->width;
        }
        int getHeight() const
        {
            return this->height;
        }
        void setWidth(int w) // added w as an identifier
        {
            this->width = w;
        }  
        void setHeight(int h) // added h as an identifier
        {
            this->height = h;
        } 
        
        virtual void printShape() const
        {
            cout << "it's a Rectangle at x: " << this-> getX() << "," << " y: " << this-> getY() << " with width: " << this->getWidth() << " and height: " << this->getHeight() << endl;
        }
};

class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle()
        {
            this->setX(0);
            this->setY(0);
            this->setBase(0);
            this->setHeight(0);
        }
        RightTriangle(int b, int h)
        {
            this->setX(0);
            this->setY(0);
            this->setBase(b);
            this->setHeight(h);
        }
        RightTriangle(int x, int y, int b, int h)
        {
            this->setX(x);
            this->setY(y);
            this->setBase(b);
            this->setHeight(h);
        }
        
        virtual ~RightTriangle()
        {

        } // destructor

        virtual RightTriangle* copy() 
        {
            return new RightTriangle(*this);
        }
        
        int getBase() const
        {
            return this->base;
        }
        int getHeight() const
        {
            return this->height;
        }
        void setBase(int b)
        {
            this->base = b;
        }
        void setHeight(int h)
        {
            this->height = h;
        }

        virtual void printShape() const
        {
            cout << "it's a Right Triangle at: " << this-> getX() << "," <<" y: " << this-> getY() << "with base: " << this->getBase() << " and height: " << this->getHeight() << endl;
        }
};
