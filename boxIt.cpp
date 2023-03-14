#include<iostream>
#include<string>

using namespace std;
//Implement the class Box  
class Box{

//l,b,h are integers representing the dimensions of the box
private:
    int l; //length
    int b; //breadth
    int h; //height

public:

// The class should have the following functions : 

// Constructors: 
// Box();
Box() : l(0), b(0), h(0){};

// Box(int,int,int);
    Box(int l, int b, int h) : l(l), b(b), h(h){}

 	Box(Box& a){
		l = a.getLength();
		b = a.getBreadth();
		h = a.getHeight();
 	}



// int getLength(); // Return box's length
int getLength(){return l;}

// int getBreadth (); // Return box's breadth
int getBreadth(){return b;}

// int getHeight ();  //Return box's height
int getHeight(){return h;}

// long long CalculateVolume(); // Return the volume of the box
long long CalculateVolume(){return (long long)l*b*h;}

//Overload operator < as specified
//bool operator<(Box& b)

bool operator<(Box& c){
	Box& a = *this;
	return (l < c.getLength()) || (a.b<c.getBreadth() && a.l==c.getLength()) 
			|| (a.h<c.getHeight() && a.b==c.getBreadth() && a.l==c.getLength());
}

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
friend ostream& operator<<(ostream& out, Box& B){
	out << B.l << " " << B.b << " " << B.h;
	return out;
}

};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}