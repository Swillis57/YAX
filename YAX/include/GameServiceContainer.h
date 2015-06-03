#ifndef _GAME_SERVICE_CONTAINER_H
#define _GAME_SERVICE_CONTAINER_H

#include <exception>
#include <unordered_map>
#include <typeinfo>
#include <type_traits>
#include "IGameService.h"


namespace YAX
{
	class GameServiceContainer
	{
	public:
		GameServiceContainer();

		template<typename Type>
		void AddService(const Type& service)
		{
			const auto& t = typeid(Type);

			//If the service already exists or the provided object isn't a service, throw
			if (_services.find(t) != _services.end())
				throw std::invalid_argument("A service of this type is already registered.");
			if (!std::is_base_of<IGameService, type>::value)
				throw std::invalid_argument("A service must inherit from the IGameService interface.");

			_services[t] = &service;
		}
		
		template<typename Type>
		IGameService* GetService()
		{
			const auto& t = typeid(Type);

			if (_services.find(t) == _services.end())
				return nullptr;
			
			return _services[t];
		}
		
		template<typename Type>
		void RemoveService()
		{
			const auto& t = typeid(Type)

			if (_services.find(t) != _services.end())
				_services.erase(t);
		}


	private:
		std::unordered_map<std::type_info, IGameService*> _services;
	};
}
 


#endif