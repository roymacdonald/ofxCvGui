#include "Button.h"

namespace ofxCvGui {
	namespace Utils {
		//----------
		Button::Button() {
			this->down = false;

			this->onMouse.addListener([this] (MouseArguments& args) {
				switch (args.action) {
				case MouseArguments::Action::Pressed:
					args.takeMousePress(this);
					break;
				case MouseArguments::Action::Released:
					this->onButtonHit(args);
					break;
				}
			}, this);

			this->onDraw.addListener([this] (DrawArguments& args) {
				if (this->getMouseState() == Element::LocalMouseState::Waiting) {
					this->onDrawUp(args);
				} else {
					this->onDrawDown(args);
				}
			}, this);
		}

		//----------
		Button::~Button() {
			this->onMouse.removeListeners(this);
			this->onDraw.removeListeners(this);
		}

		//----------
		bool Button::isDown() const {
			return this->getMouseState() != Element::LocalMouseState::Waiting;
		}
	}
}
