#pragma once

namespace util
{
	template<typename KeyType>
	class KeyHandler
	{
	public:
	public:
		KeyHandler() = default;

		void updateKey(KeyType const & key, bool const & pressed);
		void update();

		bool isKeyDown(KeyType const & key) const;
		bool isKeyDown(std::initializer_list<KeyType> const & keys) const;
		bool isKeyUp(KeyType const & key) const;
		bool isKeyUp(std::initializer_list<KeyType> const & key) const;
		bool isKeyPressed(KeyType const & key) const;
	private:
		std::map<const KeyType, bool> _keyNowMap;
		std::map<const KeyType, bool> _keyPrevMap;
	};

	#pragma region Implementation


	template<typename KeyType>
	void util::KeyHandler<KeyType>::updateKey(KeyType const & key, bool const & pressed)
	{
		if (auto itt = _keyNowMap.find(key); itt != _keyNowMap.end())
		{
			auto &[key, value] = *itt;
			value = pressed;
		}
		else
		{
			_keyNowMap.insert({ key, pressed });
			_keyPrevMap.insert({ key, !pressed });
		}
	}

	template<typename KeyType>
	void util::KeyHandler<KeyType>::update()
	{
		_keyPrevMap = _keyNowMap;
	}

	template<typename KeyType>
	bool util::KeyHandler<KeyType>::isKeyDown(KeyType const & key) const
	{
		if (auto const & itt = _keyNowMap.find(key); itt != _keyNowMap.end())
		{
			auto const &[key, value] = *itt;
			return value;
		}
		return false;
	}

	template<typename KeyType>
	bool util::KeyHandler<KeyType>::isKeyDown(std::initializer_list<KeyType> const & keys) const
	{
		for (auto const &[mapKey, mapValue] : _keyNowMap)
		{
			if (mapValue && std::find(keys.begin(), keys.end(), mapKey) != keys.end()) { return true; }
		}
		return false;
	}

	template<typename KeyType>
	bool util::KeyHandler<KeyType>::isKeyUp(KeyType const & key) const
	{
		if (auto const & itt = _keyNowMap.find(key); itt != _keyNowMap.end())
		{
			auto const &[key, value] = *itt;
			return !value;
		}
		return false;
	}

	template<typename KeyType>
	bool util::KeyHandler<KeyType>::isKeyUp(std::initializer_list<KeyType> const & keys) const
	{
		for (auto const &[mapKey, mapValue] : _keyNowMap)
		{
			if (!mapValue && std::find(keys.begin(), keys.end(), mapKey) != keys.end()) { return true; }
		}
		return false;
	}

	template<typename KeyType>
	bool util::KeyHandler<KeyType>::isKeyPressed(KeyType const & keyPressed) const
	{
		if (auto const & itt = _keyNowMap.find(keyPressed); itt != _keyNowMap.end())
		{
			auto const &[key, value] = *itt;

			if (auto const & prevItt = _keyPrevMap.find(key); prevItt != _keyPrevMap.end())
			{
				auto const &[prevKey, prevValue] = *prevItt;
				return value && !prevValue;
			}
			return value;
		}
		return false;
	}


	#pragma endregion

}