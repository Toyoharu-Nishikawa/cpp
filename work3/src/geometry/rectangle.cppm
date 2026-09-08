export module geometry.rectangle;

export class Rectangle
{
public:
    Rectangle(double width, double height);

    double area() const;

private:
    double width_;
    double height_;
};
