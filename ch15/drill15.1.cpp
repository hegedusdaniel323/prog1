/*
    g++ drill15.1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15.1 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;
   	Simple_window win {Point{100,100}, xmax, ymax, "Function graphs"};
	
    int x_orig = xmax/2;
    int y_orig = ymax/2;

	int xlength = 400;
	int ylength = 400;

	int xscale = 20, yscale = 20;
	
	int x_coord = (xmax - xlength)/2;
	int y_coord = (ymax - ylength)/2;

	Axis x {Axis::x, Point{x_coord, y_orig}, xlength, xlength/xscale, "1 = = 20 pixels"};
	Axis y {Axis::y, Point{x_orig, ylength + y_coord}, ylength, ylength/yscale, "1 = = 20 pixels"};
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);

//******************************************************************************************

    int rmin = -10;
    int rmax = 11;  
    int n_points = 400;
	Point origo {x_orig, y_orig};
	
	Function s1 (one, rmin, rmax, origo, n_points, xscale, yscale);
	win.attach(s1);

	Function s2 (slope, rmin, rmax, origo, n_points, xscale, yscale);
	Text t_s2 {Point{100,y_orig+y_orig/2-20},"x/2"};
	win.attach(s2);
	win.attach(t_s2);

	Function s3 (square, rmin, rmax, origo, n_points, xscale, yscale);
	win.attach(s3);

	Function s4 (cos, rmin, rmax, origo, n_points, xscale, yscale);
	s4.set_color(Color::blue);
	win.attach(s4);

	Function s5 (sloping_cos, rmin, rmax, origo, n_points, xscale, yscale);
	win.attach(s5);


    win.wait_for_button();

}
