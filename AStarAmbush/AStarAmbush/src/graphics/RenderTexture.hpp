#pragma once

#include "graphics/Texture.hpp"
#include "math/Rect.hpp"

namespace app::gra
{
	class RenderTexture
	{
	public: // Constructors/Destructor/Assignments
		RenderTexture() = default;
		~RenderTexture() = default;

		RenderTexture(RenderTexture const &) = default;
		RenderTexture(RenderTexture &&) = default;

		RenderTexture & operator=(RenderTexture const &) = default;
		RenderTexture & operator=(RenderTexture &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		constexpr SDL_Texture * getTexture() const { return m_texture ? m_texture->get() : nullptr; }
		constexpr std::optional<math::Rectd> const & getSourceRect() const { return m_sourceRect; }
		constexpr math::Vector2d const & getPosition() const { return m_position; }
		constexpr double const & getRotation() const { return m_rotation; }
		constexpr math::Vector2d const & getOrigin() const { return m_origin; }
		constexpr math::Vector2d const & getSize() const { return m_size; }

		RenderTexture & setTexture(std::shared_ptr<app::gra::Texture> texture) { m_texture = texture; return *this; }
		RenderTexture & setSourceRect(std::optional<math::Rectd> const & sourceRect) { m_sourceRect = sourceRect; return *this; }
		RenderTexture & setPosition(app::math::Vector2d const & position) { m_position = position; return *this; }
		RenderTexture & setRotation(double const & rotation) { m_rotation = rotation; return *this; }
		RenderTexture & setOrigin(app::math::Vector2d const & origin) { m_origin = origin; return *this; }
		RenderTexture & setSize(app::math::Vector2d const & size) { m_size = size; return *this; }
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
		std::shared_ptr<app::gra::Texture> m_texture;
		std::optional<math::Rectd> m_sourceRect;
		math::Vector2d m_position;
		math::Vector2d m_origin;
		math::Vector2d m_size;
		std::double_t m_rotation;
	};

	static_assert(std::is_default_constructible<RenderTexture>::value, "RenderTexture must be default constructible");
	static_assert(std::is_destructible<RenderTexture>::value, "RenderTexture must be destructible");
	static_assert(std::is_copy_constructible<RenderTexture>::value, "RenderTexture must be copy constructible");
	static_assert(std::is_copy_assignable<RenderTexture>::value, "RenderTexture must be copy assignable");
	static_assert(std::is_move_constructible<RenderTexture>::value, "RenderTexture must be move constructible");
	static_assert(std::is_move_assignable<RenderTexture>::value, "RenderTexture must be move assignable");
}
