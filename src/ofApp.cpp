#include "ofApp.h"
#include <myo/myo.hpp>

class DataCollector : public myo::DeviceListener {
public:
    DataCollector()
    : a_x(0), a_y(0), a_z(0), a_x_old(0), a_y_old(0), a_z_old(0), a_x_sub(0), a_y_sub(0), a_z_sub(0)
    {
    }
    
    // units of g
    void onAccelerometerData(myo::Myo* myo, uint64_t timestamp, const myo::Vector3<float>& accel)
    {
        a_x_old = a_x;
        a_y_old = a_y;
        a_z_old = a_z;
        a_x = accel.x();
        a_y = accel.y();
        a_z = accel.z();
        a_x_sub = a_x_old - a_x;
        a_y_sub = a_y_old - a_y;
        a_z_sub = a_z_old - a_z;
        
        std::cout << "a_x_sub = " << a_x_sub << ", a_y_sub = " << a_y_sub << ", a_z_sub " << a_z_sub << std::endl;
    }
    
    float a_x, a_y, a_z;
    float a_x_old, a_y_old, a_z_old;
    float a_x_sub, a_y_sub, a_z_sub;
};


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    DataCollector collector;
    
    try {
        myo::Hub hub("com.labtorium.myo-dance");
        std::cout << "Attempting to find a Myo..." << std::endl;
        myo::Myo* myo = hub.waitForMyo(10000);
        if (!myo) {
            throw std::runtime_error("Unable to find a Myo!");
        }
        
        hub.addListener(&collector);
        
        while (1) {
            hub.run(1000/20);
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Press enter to continue.";
        std::cin.ignore();
        return 1;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
