#include <stdint.h>

class Framebuffer;
class Gamepad;

class IPlatform
{
	public:
		virtual ~IPlatform() {};
		virtual void init() = 0;
		virtual void done() = 0;
		virtual void update() = 0;

		virtual Framebuffer &getFramebuffer() = 0;
		virtual Gamepad &getGamepad() = 0;

		virtual uint32_t getTicks() = 0;
		virtual bool doQuit() = 0;

};
