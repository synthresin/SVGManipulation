#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SVGManipulationApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void SVGManipulationApp::setup()
{
}

void SVGManipulationApp::mouseDown( MouseEvent event )
{
}

void SVGManipulationApp::update()
{
}

void SVGManipulationApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( SVGManipulationApp, RendererGl )
