#include<iostream>
#include<cmath>
#include<iomanip>
#define MAX 500
#define pi acos(0)*2

using namespace std;


class shape
{
public:
    static int shape_count;

    virtual double getarea(void){return 0;}
    virtual double getvolume(void){return 0;}
    virtual double getheight(void){return 0;}
    virtual double getbase(void){return 0;}
    virtual double getlength(void){return 0;}
    virtual double getwidth(void){return 0;}
    virtual double getdepth(void){return 0;}
    virtual double getradius(void){return 0;}
} * allshape[MAX];;
int shape::shape_count=0;

class triangle : public shape
{
	double base,height;
public:
    static int triangle_count;

    triangle(){
    cout<<setw(25)<<setfill('-')<<"Triangle drawn"<<endl;}
    double getheight(void){return height;}
    double getbase(void){return base;}
    double getarea(void);
    double getvolume(void);
    friend istream& operator>>(istream& in,triangle& a);
}*p;
int triangle::triangle_count;

double triangle ::getarea(void)
{
	return 0.5*base*height;
}
double triangle::getvolume(void)
{
	return 0;
}

istream& operator>>(istream& in,triangle& tri)
{
    cout<<"Triangle:\n";
    cout<<"\tEnter the BASE of the triangle: ";
    in>>tri.base;
    cout<<"\tEnter the HEIGHT of the triangle: ";
    in>>tri.height;cout<<endl;
    return in;
}


class cuboid: public shape
{
	double height,width,depth;
public:
    static int cuboid_count;
    cuboid(){
        cout.width(25);cout.fill('-');
        cout<<"cuboid drawn"<<endl;
        }
	double getarea(void);
	double getvolume(void);
	 double getheight(void){return height;}
    double getwidth(void){return width;}
    double getdepth(void){return depth;}
	friend istream& operator>>(istream& in,cuboid &a);
}*c;
int cuboid::cuboid_count;

double cuboid ::getarea(void)
{
	return (height*width+width*depth+depth*height)*2.0;
}

double cuboid::getvolume(void)
{
	return height*width*depth*1.0;
}

istream& operator>>(istream& in,cuboid &a)
{
	cout << "cuboid"<< endl;

	cout << "\tEnter the HEIGHT of the cuboid: ";
	in >> a.height;

	cout << "\tEnter the WIDTH of the cuboid: ";
	in >> a.width;

	cout << "\tEnter the DEPTH of the cuboid: ";
	in >> a.depth;cout<<endl;

	return in;

}

class rectangle:public shape
{
    double length;
    double width;
public:
    static int rectangle_count;
    rectangle(){
        cout.width(25);cout.fill('-');
        cout<<"Rectangle drawn"<<endl;}
    double getlength(void){return length;}
    double getwidth(void){return width;}
    double getarea(void);
	double getvolume(void);
	friend istream& operator>>(istream& in,rectangle &a);
}*r;
int rectangle::rectangle_count;

double rectangle ::getarea(void)
{
	return (length*width);
}

double rectangle::getvolume(void)
{
	return 0;
}

istream& operator>>(istream& in,rectangle &a)
{
	cout << "Rectangle"<< endl;

	cout << "\tEnter the LENGTH of the rectangle: ";
	in >> a.length;

	cout << "\tEnter the WIDTH of the rectangle: ";
	in >> a.width;cout<<endl;

	return in;

}

class circle:public shape
{
    double radius;
public:
    static int circle_count;
    circle(){
        cout.width(25);cout.fill('-');
        cout<<"Circle drawn"<<endl;}
    double getradius(void){return radius;}
    double getarea(void);
	double getvolume(void);
	friend istream& operator>>(istream& in,circle &a);
}*ci;
int circle::circle_count;

double circle ::getarea(void)
{
	return (pi*radius*radius);
}

double circle::getvolume(void)
{
	return 0;
}

istream& operator>>(istream& in,circle &a)
{
	cout << "Circle"<< endl;

	cout << "\tEnter the RADIUS of the circle: ";
	in >> a.radius;cout<<endl;

	return in;

}

class cone: public shape
{
	double height,radius;
public:
    static int cone_count;
    cone(){
        cout.width(25);cout.fill('-');
        cout<<"cone drawn"<<endl;
        }
    double getheight(void){return height;}
    double getradius(void){return radius;}
	double getarea(void);
	double getvolume(void);
	friend istream& operator>>(istream& in,cone &a);
}*co;

int cone::cone_count;

double cone ::getarea(void)
{
    double lateral_height=sqrt(pow(radius,2)+pow(height,2));
	return pi*radius*(lateral_height+radius);
}

double cone::getvolume(void)
{
	return height*radius*radius*pi/3;
}

istream& operator>>(istream& in,cone &a)
{
	cout << "Cone"<< endl;

	cout << "\tEnter the RADIUS of the cone: ";
	in >> a.radius;

	cout << "\tEnter the HEIGHT of the cone: ";
	in >> a.height;cout<<endl;

	return in;

}

class cylinder: public shape
{
	double height,radius;
public:
    static int cylinder_count;
    cylinder()
    {
        cout.width(25);cout.fill('-');
        cout<<"cylinder drawn"<<endl;
    }
    double getheight(void){return height;}
    double getradius(void){return radius;}
	double getarea(void);
	double getvolume(void);
	friend istream& operator>>(istream& in,cylinder &a);
}*cy;

int cylinder::cylinder_count;

double cylinder ::getarea(void)
{
	return 2*pi*radius*(height+radius);
}

double cylinder::getvolume(void)
{
	return height*radius*radius*pi;
}

istream& operator>>(istream& in,cylinder &a)
{
	cout << "Cylinder:"<< endl;

	cout << "\tEnter the RADIUS of the cylinder: ";
	in >> a.radius;

	cout << "\tEnter the HEIGHT of the cylinder: ";
	in >> a.height;

	cout<<endl;

	return in;

}


void display_option()
{
    cout<<"Main Menu:\n\t 1.Draw Shapes\n\t 2.Display Shapes\n\t 3.Remove Shapes\n\t 4.Exit\n\n";
    cout<<"Your Choice:";

}

int make_shapes_option()
{
    int n;
    cout<<"What Shape do you want to draw?\n\t1.Triangle\n\t2.cuboid\n\t3.Rectangle\n\t4.Circle\n\t5.Cone\n\t6.Cylinder"<<endl<<endl;
    cout<<"Your Choice: ";
    cin>>n;
    cout<<endl;
    return n;

}


int additional_opt();
int remove_option();
void display_object();
//int st=shape::shape_count;
int main()
{
	int n,i,choice,x,add_opt;
	double area,volume;

	while(1)
	{
	    i=0;
	    display_option();
	    i++;


		cin>>n;
        if(n==1)
        {
            shape::shape_count++;//st++;
                cout<<endl;
           x= make_shapes_option();

           switch(x)
            {
                case 1:
                    p = new triangle;
                    triangle::triangle_count++;
                    cin >> *p;
                    while(1)
                    {
                        add_opt=additional_opt();
                        if(add_opt==1)
                        {
                            cout<<"\tArea of The Triangle: "<<p->getarea()<<endl;cout<<endl;
                        }
                        else if(add_opt==2)
                        {
                            cout<<"\tIt has no volume as it is not a 3D object."<<endl;cout<<endl;
                        }
                        else
                            break;
                    }
                    allshape[shape::shape_count] = p;
                break;
                case 2:
                    c = new cuboid;
                    cin >> *c;
                    cuboid::cuboid_count++;
                    while(1)
                    {
                        add_opt=additional_opt();
                        if(add_opt==1)
                        {
                            cout<<"\tArea of The Cuboid: "<<c->getarea()<<endl;cout<<endl;
                        }
                        else if(add_opt==2)
                        {
                            cout<<"\tVolume of The Cuboid: "<<c->getvolume()<<endl;cout<<endl;
                        }
                        else
                            break;
                    }

                    allshape[shape::shape_count] = c;

                break;
                case 3:
                    r=new rectangle;
                    rectangle::rectangle_count++;
                    cin >> *r;
                    while(1)
                    {
                        add_opt=additional_opt();
                        if(add_opt==1)
                        {
                            cout<<"\tArea of The Rectangle: "<<r->getarea()<<endl;cout<<endl;
                        }
                        else if(add_opt==2)
                        {
                            cout<<"\tIt has no volume as it is not a 3D object."<<endl;cout<<endl;
                        }
                        else
                            break;
                    }
                    allshape[shape::shape_count]=r;

                break;
                case 4:
                    ci=new circle;
                    cin>> *ci;
                    circle::circle_count++;
                    while(1)
                    {
                        add_opt=additional_opt();
                        if(add_opt==1)
                        {
                            cout<<"\tArea of The Circle: "<<ci->getarea()<<endl;cout<<endl;
                        }
                        else if(add_opt==2)
                        {
                            cout<<"\tIt has no volume as it is not a 3D object."<<endl;cout<<endl;
                        }
                        else
                            break;
                    }
                    allshape[shape::shape_count]=ci;

                break;
                case 5:
                    co = new cone;
                    cin >> *co;
                    cone::cone_count++;
                    while(1)
                    {
                        add_opt=additional_opt();
                        if(add_opt==1)
                        {
                            cout<<"\tArea of The Cone: "<<co->getarea()<<endl;cout<<endl;
                        }
                        else if(add_opt==2)
                        {
                            cout<<"\tVolume of The Cone: "<<co->getvolume()<<endl;cout<<endl;
                        }
                        else
                            break;
                    }
                    allshape[shape::shape_count] = co;

                break;
                case 6:
                    cy = new cylinder;
                    cin >> *cy;
                    cylinder::cylinder_count++;
                    while(1)
                    {
                        add_opt=additional_opt();
                        if(add_opt==1)
                        {
                            cout<<"\tArea of The Cylinder: "<<cy->getarea()<<endl;cout<<endl;
                        }
                        else if(add_opt==2)
                        {
                            cout<<"\tVolume of The Cylinder: "<<cy->getvolume()<<endl;cout<<endl;
                        }
                        else
                            break;
                    }
                    allshape[shape::shape_count] = cy;

                break;
                default:
                    cout <<"Invalid choice "<< endl;
                    shape::shape_count--;
                break;
            }
		}
		else if(n==2)
        {
            display_object();
        }
        else if(n==3)
        {
            remove_option();

        }
		else if(n==4){break;}
	}

	cout << endl << endl;

	return 0;
}

int additional_opt()
{
    int choice;
    cout<<"What do you want?\n\t1.Area\n\t2.volume\n\t3.Back to main menu\n\nYour Choice: ";
    cin>>choice;
    cout<<endl;
    return choice;
}
void display_object()
{
    int ii,j;
            if(!shape::shape_count)
                cout << "Nothing To Show" << endl<<endl;
            else
            {
                for (ii = 1,j=1;ii <shape::shape_count,j<shape::shape_count+1;j++,ii++)
                {
                    if(allshape[ii]==p)
                    {

                        cout<<"\tObject No.: "<<ii<<endl;
                        cout<<"\tObject Type: Triangle"<<endl;
                        cout<<"\tHeight: "<<allshape[ii]->getheight()<<endl;
                        cout<<"\tBase: "<<allshape[ii]->getbase()<<endl;
                        cout<<"\tArea: "<<allshape[ii]->getarea()<<endl<<endl;

                    }
                    else if(allshape[ii]==c)
                    {

                        cout<<"\tObject No.: "<<ii<<endl;
                        cout<<"\tObject Type: Cuboid"<<endl;
                        cout<<"\tHeight: "<<allshape[ii]->getheight()<<endl;
                        cout<<"\tWidth: "<<allshape[ii]->getwidth()<<endl;
                        cout<<"\tDepth: "<<allshape[ii]->getdepth()<<endl;
                        cout<<"\tArea: "<<allshape[ii]->getarea()<<endl;
                        cout<<"\tVolume: "<<allshape[ii]->getvolume()<<endl<<endl;
                    }
                    else if(allshape[ii]==r)
                    {

                        cout<<"\tObject No.: "<<ii<<endl;
                        cout<<"\tObject Type: Rectangle"<<endl;
                        cout<<"\tHeight: "<<allshape[ii]->getlength()<<endl;
                        cout<<"\tWidth: "<<allshape[ii]->getwidth()<<endl;
                        cout<<"\tArea: "<<allshape[ii]->getarea()<<endl<<endl;
                    }
                    else if(allshape[ii]==ci)
                    {

                        cout<<"\tObject No.: "<<ii<<endl;
                        cout<<"\tObject Type: Circle"<<endl;
                        cout<<"\tRadius: "<<allshape[ii]->getradius()<<endl;
                        cout<<"\tArea: "<<allshape[ii]->getarea()<<endl<<endl;
                    }
                    else if(allshape[ii]==co)
                    {

                        cout<<"\tObject No.: "<<ii<<endl;
                        cout<<"\tObject Type: Conic"<<endl;
                        cout<<"\tRadius: "<<allshape[ii]->getradius()<<endl;
                        cout<<"\tHeight: "<<allshape[ii]->getheight()<<endl;
                        cout<<"\tArea: "<<allshape[ii]->getarea()<<endl;
                        cout<<"\tVolume: "<<allshape[ii]->getvolume()<<endl<<endl;
                    }
                    else if(allshape[ii]==cy)
                    {

                        cout<<"\tObject No.: "<<ii<<endl;
                        cout<<"\tObject Type: Cylinder"<<endl;
                        cout<<"\tRadius: "<<allshape[ii]->getradius()<<endl;
                        cout<<"\tHeight: "<<allshape[ii]->getheight()<<endl;
                        cout<<"\tArea: "<<allshape[ii]->getarea()<<endl;
                        cout<<"\tVolume: "<<allshape[ii]->getvolume()<<endl<<endl;
                    }
                }
            }
}

int remove_option()
{
    int choice;
    cout<<"Which object do you want to remove?\n\t1.For Entering Object Number\n\t2.For Displaying all objects\n Your Choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        int n;
        cout<<"Enter the number of the object to remove: ";
        while(1)
        {
            cin>>n;
            if (n>shape::shape_count)
            {
                cout<<"Removing the object is not possible"<<endl;
                cout<<"Enter the number of the object again to remove: ";
            }
            else if(n<=shape::shape_count)
            {
                for(int i=n;i<shape::shape_count;i++)
                {
                    allshape[i]=allshape[i+1];

                }
                shape::shape_count--;
                break;
            }
        }

        break;
    case 2:
        display_object();
        cout<<"Enter the number of the object to remove: ";
        while(1)
        {
            cin>>n;
            if (n>shape::shape_count)
            {
                cout<<"Removing the object is not possible"<<endl;
                cout<<"Enter the number of the object again to remove: ";
            }
            else if(n<=shape::shape_count)
            {
                for(int i=n;i<shape::shape_count;i++)
                {
                    allshape[i]=allshape[i+1];

                }
                shape::shape_count--;
                break;
            }
        }

        break;
    default:
        cout<<"Invalid Option"<<endl<<endl;

    }
    return choice;
}

