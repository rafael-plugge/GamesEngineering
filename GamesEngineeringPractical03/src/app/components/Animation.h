#ifndef _ANIMATION_H
#define _ANIMATION_H

namespace app::comp
{
	struct Animation
	{
	public: // Struct
	public: // Constructors/Destructor/Assignments
		Animation() = default;
		Animation(Animation const &) = default;
		Animation(Animation &&) = default;

		~Animation() = default;

		Animation & operator=(Animation const &) = default;
		Animation & operator=(Animation &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		std::size_t currentFrame;
		double time, perFrame;
		std::vector<SDL_Rect> frames;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables

	};
}

#endif // !_ANIMATION_H
