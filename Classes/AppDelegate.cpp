#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include"GameMenuScene.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {


    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

	//glview->setDesignResolutionSize(480,800,ResolutionPolicy::SHOW_ALL);
	//glview->setFrameSize(640,960);
	Size frameSize =  glview->getFrameSize();
		log("frameSize.width : %f", frameSize.width);
		log("frameSize height : %f", frameSize.height);

		/*Size winSize = Size(640.0, 960.0);
		float widthRate = frameSize.width / winSize.width;
		float heightRate = frameSize.height / winSize.height;*/
		glview->setDesignResolutionSize(640.0, 960.0, ResolutionPolicy::FIXED_HEIGHT); //设计分辨率大小及模式

		//如果是if中的语句，说明逻辑的高度有点大了，就把逻辑的高缩小到和宽度一样的比率
		//if (widthRate > heightRate)
		//{
		//	log("winSize.height*heightRate / widthRate : %f ", winSize.height*heightRate / widthRate);
		//	glview->setDesignResolutionSize(winSize.width, winSize.height*heightRate / widthRate, ResolutionPolicy::NO_BORDER); //设计分辨率大小及模式

		//}
		//else
		//{
		//	log("winSize.width*widthRate / heightRate : %f ", winSize.width*widthRate / heightRate);

		//	glview->setDesignResolutionSize(winSize.width*widthRate / heightRate, winSize.height, ResolutionPolicy::NO_BORDER); //设计分辨率大小及模式

		//}
	//glview->setFrameSize(1080,1920);

	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Ino.plist");
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Sakura.plist");
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Karin.plist");

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	auto scene = GameMenuScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
