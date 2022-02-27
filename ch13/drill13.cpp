/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"


int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;
    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};
//-------------------------------------------------
	int x_size = 800;
	int y_size = 800;
	int x_grid = x_size/8;
	int y_grid = y_size/8;
	
	Lines grid;
	for (int x = 0; x<=x_size; x+=x_grid)
	{
		grid.add(Point{x,0},Point{x,y_size});			//fuggoleges vonalak
	}
	for (int y = 0; y<=y_size; y+=y_grid)		
	{
		grid.add(Point{0,y},Point{x_size,y});			//vizszintes
	}

	win.attach(grid);
//------------------------------------------------------------------
	Vector_ref<Rectangle> rect;
	for(int i=1; i <= 8; i++)
	{
		rect.push_back(new Rectangle{Point{100*(i-1), 100*(i-1)}, 100, 100});
		rect[i-1].set_color(Color::invisible);
		rect[i-1].set_fill_color(Color::red);
		win.attach(rect[i-1]);
	}
//------------------------------------------------------------------------
	Vector_ref<Image> img;
	for (int i=1; i<=3; i++)
	{
		img.push_back(new Image{Point{200*i,200*(i-1)},"kep200.jpg"});
		win.attach(img[i-1]);
	}
//-----------------------------------------------------------------------
	int oszlop=1;
	int sor=0;

	while(sor < 800)
	{
		Image kep {Point{100*(oszlop-1),sor},"kep100.jpg"};
		oszlop++;
		if(oszlop == 9)
		{
			sor+=100;
			oszlop = 1;
		}
		win.attach(kep);
		win.wait_for_button();
	}

    //win.wait_for_button();

}
