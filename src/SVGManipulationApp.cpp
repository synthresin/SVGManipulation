#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/svg/Svg.h"
#include "cinder/svg/SvgGl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SVGManipulationApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    void keyDown( KeyEvent event );
    
    
    
    int mRotate;
    
    svg::DocRef mDoc;
    MatrixAffine2f mTransform;
    
    PolyLine2f mPolyLine;
    std::vector<Vec2f> mPoints;
};

void SVGManipulationApp::keyDown( KeyEvent event )
{
    if(event.getChar() == 'o') {
        mRotate +=1;
    } else if (event.getChar() == 'l') {
        mRotate -=1;
    }
}

void SVGManipulationApp::setup()
{
    mDoc = svg::Doc::create( loadResource("logoFrag1.svg") );
    mTransform = MatrixAffine2f();
    mTransform.setToIdentity();
    mTransform.scale(Vec2f(2.0, 2.0));
    mDoc->setTransform(mTransform);
    std::list<svg::Node*> docChildren = mDoc->getChildren();
    
    std::cout << docChildren.size() << std::endl;
    
    svg::Polygon *docPolygon = (svg::Polygon *)docChildren.front();
    
    mPolyLine = docPolygon->getPolyLine();
    mPoints = mPolyLine.getPoints();
    std::cout << "오늘의 밥셔틀 : " << std::endl;
    printf("%i", Rand::randInt(1, 4));
    mRotate = 0;
    
    
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
    gl::color( Color(CM_HSV,randFloat(0, 1.0), randFloat(0.7, 0.9) ,randFloat(0.7, 0.8)) );
    PolyLine2f newPolyLine;

        for( vector<Vec2f>::iterator p = mPoints.begin(); p != mPoints.end(); p++ ){
            Vec2f np = *p - Vec2f(mDoc->getWidth()/2, mDoc->getHeight()/2) + Vec2f(randInt(0, 2),randInt(0, 2));
            newPolyLine.push_back(np);
        }
    gl::pushMatrices();
    gl::translate(getWindowCenter());
    gl::rotate(mRotate);
    gl::scale(2.0, 2.0);
    
    //gl::scale(3, 3);
    gl::drawSolid(newPolyLine);
    gl::popMatrices();
}

CINDER_APP_BASIC( SVGManipulationApp, RendererGl )
