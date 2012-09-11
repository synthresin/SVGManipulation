#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/svg/Svg.h"
#include "cinder/svg/SvgGl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SVGManipulationApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    svg::DocRef mDoc;
};

void SVGManipulationApp::setup()
{
    mDoc = svg::Doc::create( loadResource("logoFrag1.svg") );
    
    printf("width: %i \nheight: %i\naspect ratio: %f",mDoc->getWidth(),mDoc->getHeight(),mDoc->getAspectRatio());
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
	gl::clear( Color( 255, 255, 255 ) );
    gl::draw( *mDoc );
}

CINDER_APP_BASIC( SVGManipulationApp, RendererGl )
