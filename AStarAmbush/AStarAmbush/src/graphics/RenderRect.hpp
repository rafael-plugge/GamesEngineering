#pragma once

#include "graphics/Texture.hpp"
#include "math/Rect.hpp"

namespace app::gra
{
	class RenderRect
	{
	public: // Constructors/Destructor/Assignments
		RenderRect() = default;
		~RenderRect() = default;

		RenderRect(RenderRect const &) = default;
		RenderRect(RenderRect &&) = default;

		RenderRect & operator=(RenderRect const &) = default;
		RenderRect & operator=(RenderRect &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		constexpr SDL_Texture * getTexture() const { return m_texture ? m_texture->get() : nullptr; }
		constexpr std::optional<math::Rectd> const & getSourceRect() const { return m_sourceRect; }
		constexpr math::Vector2d const & getPosition() const { return m_position; }
		constexpr double const & getRotation() const { return m_rotation; }
		constexpr math::Vector2d const & getOrigin() const { return m_origin; }
		constexpr math::Vector2d const & getSize() const { return m_size; }

		RenderRect & setTexture(std::shared_ptr<app::gra::Texture> texture) { m_texture = texture; return *this; }
		RenderRect & setSourceRect(std::optional<math::Rectd> const & sourceRect) { m_sourceRect = sourceRect; return *this; }
		RenderRect & setPosition(app::math::Vector2d const & position) { m_position = position; return *this; }
		RenderRect & setRotation(double const & rotation) { m_rotation = rotation; return *this; }
		RenderRect & setOrigin(app::math::Vector2d const & origin) { m_origin = origin; return *this; }
		RenderRect & setSize(app::math::Vector2d const & size) { m_size = size; return *this; }
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

	static_assert(std::is_default_constructible<RenderRect>::value, "RenderRect must be default constructible");
	static_assert(std::is_destructible<RenderRect>::value, "RenderRect must be destructible");
	static_assert(std::is_copy_constructible<RenderRect>::value, "RenderRect must be copy constructible");
	static_assert(std::is_copy_assignable<RenderRect>::value, "RenderRect must be copy assignable");
	static_assert(std::is_move_constructible<RenderRect>::value, "RenderRect must be move constructible");
	static_assert(std::is_move_assignable<RenderRect>::value, "RenderRect must be move assignable");
}
