#pragma once

#include "entities/base/Entity.hpp"
#include "graphics/RenderTexture.hpp"

namespace app::ent::base
{
	class Drawable : public app::ent::base::Entity
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Drawable() = default;
		virtual ~Drawable() = default;

		Drawable(Drawable const &) = default;
		Drawable & operator=(Drawable const &) = default;

		Drawable(Drawable &&) = default;
		Drawable & operator=(Drawable &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		constexpr math::Vector2d const & getPosition() const { return m_renderRect.getPosition(); }
		constexpr std::double_t const & getRotation() const { return m_renderRect.getRotation(); }
		constexpr math::Vector2d const & getSize() const { return m_renderRect.getSize(); }
		constexpr math::Vector2d const & getOrigin() const { return m_renderRect.getOrigin(); }
		constexpr std::optional<math::Rectd> const & getSourceRect() const { return m_renderRect.getSourceRect(); }

		Drawable & setPosition(math::Vector2d const & position) { m_renderRect.setPosition(position); return *this; }
		Drawable & setRotation(std::double_t const & rotation) { m_renderRect.setRotation(rotation); return *this; }
		Drawable & setSize(math::Vector2d const & size) { m_renderRect.setSize(size); return *this; }
		Drawable & setOrigin(math::Vector2d const & origin) { m_renderRect.setOrigin(origin); return *this; }
		Drawable & setSourceRect(std::optional<math::Rectd> const & sourceRect) { m_renderRect.setSourceRect(sourceRect); return *this; }
		Drawable & setTexture(std::shared_ptr<app::gra::Texture> const & texture) { m_renderRect.setTexture(texture); return *this; }

		virtual void init() override {}
		virtual void update(app::time::seconds const & dt) override {}
		virtual void render(app::gra::Window const & window, app::time::seconds const & dt) override;
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
		app::gra::RenderTexture m_renderRect;
	};

	static_assert(std::is_default_constructible<Drawable>::value, "Drawable must be default constructible");
	static_assert(std::is_destructible<Drawable>::value, "Drawable must be destructible");
	static_assert(std::is_move_constructible<Drawable>::value, "Drawable must be move constructible");
	static_assert(std::is_move_assignable<Drawable>::value, "Drawable must be move assignable");
}

