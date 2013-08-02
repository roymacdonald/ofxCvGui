#include "ofxCvGui/Builder.h"

namespace ofxCvGui {
	//----------
	void Builder::init() {
		PanelGroupPtr rootGroup( new Panels::Groups::Grid() );
		controller.init(rootGroup);
	}
	
	//----------
	void Builder::add(PanelPtr panel) {
		controller.add(panel);
	}

	//----------
	ofPtr<Panels::Draws> Builder::add(ofBaseDraws& asset, string caption) {
		ofPtr<Panels::Draws> newPanel( new Panels::Draws(asset) );
		newPanel->setCaption(caption);
		PanelPtr panel(newPanel);
		controller.add(panel);
		return newPanel;
	}

	//----------
	ofPtr<Panels::Image> Builder::add(ofImage& asset, string caption) {
		ofPtr<Panels::Image> newPanel( new Panels::Image(asset) );
		newPanel->setCaption(caption);
		PanelPtr panel(newPanel);
		controller.add(panel);
		return newPanel;
	}
	
    //----------
	ofPtr<Panels::Pixels> Builder::add(const ofPixels& asset, string caption) {
		ofPtr<Panels::Pixels> newPanel( new Panels::Pixels(asset) );
		newPanel->setCaption(caption);
		PanelPtr panel(newPanel);
		controller.add(panel);
		return newPanel;
	}

	//----------
	ofPtr<Panels::PixelsVector> Builder::add(const vector<ofPixels>& asset, string caption) {
		ofPtr<Panels::PixelsVector> newPanel(new Panels::PixelsVector(asset) );
		newPanel->setCaption(caption);
		PanelPtr panel(newPanel);
		controller.add( panel );
		return newPanel;
	}

	//----------
	ofPtr<Panels::Node> Builder::add(ofNode & asset, string caption) {
		ofPtr<Panels::Node> newPanel( new Panels::Node(asset) );
		newPanel->setCaption(caption);
		PanelPtr panel(newPanel);
		controller.add(panel);
		return newPanel;
	}
    
	//----------
	ofPtr<Panels::Base> Builder::addBlank(string caption) {
		ofPtr<Panels::Base> newPanel( new Panels::Base() );
		newPanel->setCaption(caption);
		controller.add(newPanel);
		return newPanel;
	}

	//----------
	ofPtr<Panels::Instructions> Builder::addInstructions() {
		ofPtr<Panels::Instructions> newPanel( new Panels::Instructions() );
		PanelPtr panel(newPanel);
		controller.add(panel);
		return newPanel;
	}

	//----------
	ofPtr<Panels::Groups::Grid> Builder::addGrid() {
		ofPtr<Panels::Groups::Grid> newPanel( new Panels::Groups::Grid() );
		PanelPtr panel(newPanel);
		controller.add(panel);
		return newPanel;
	}

	//----------
	void Builder::drop(PanelPtr &panel) {
		controller.drop(panel);
	}

	//----------
	void Builder::clear() {
		controller.clear();
	}
}