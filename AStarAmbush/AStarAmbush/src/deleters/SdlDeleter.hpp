#pragma once

namespace app::del
{
	class SdlDeleter
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		SdlDeleter() = default;
		~SdlDeleter() = default;

		SdlDeleter(SdlDeleter const &) = default;
		SdlDeleter & operator=(SdlDeleter const &) = default;

		SdlDeleter(SdlDeleter &&) = default;
		SdlDeleter & operator=(SdlDeleter &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void operator()(SDL_Window * pWindow) const;
		void operator()(SDL_Renderer * pRenderer) const;
		void operator()(SDL_Texture * pTexture) const;
		void operator()(SDL_Surface * pSurface) const;
		void operator()(SDL_GameController * pGameController) const;
		void operator()(SDL_Haptic * pHaptic) const;
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

	static_assert(std::is_default_constructible<SdlDeleter>::value, "SdlDeleter must be default constructible");
	static_assert(std::is_destructible<SdlDeleter>::value, "SdlDeleter must be destructible");
	static_assert(std::is_copy_constructible<SdlDeleter>::value, "SdlDeleter must be copy constructible");
	static_assert(std::is_copy_assignable<SdlDeleter>::value, "SdlDeleter must be copy assignable");
	static_assert(std::is_move_constructible<SdlDeleter>::value, "SdlDeleter must be move constructible");
	static_assert(std::is_move_assignable<SdlDeleter>::value, "SdlDeleter must be move assignable");

	// Unique Pointers
	typedef std::unique_ptr<SDL_Renderer, SdlDeleter> UPtrRenderer;
	typedef std::unique_ptr<SDL_Window, SdlDeleter> UPtrWindow;
	typedef std::unique_ptr<SDL_Texture, SdlDeleter> UPtrTexture;
	typedef std::unique_ptr<SDL_Surface, SdlDeleter> UPtrSurface;
	typedef std::unique_ptr<SDL_GameController, SdlDeleter> UPtrGameController;
	typedef std::unique_ptr<SDL_Haptic, SdlDeleter> UPtrHaptic;
}

