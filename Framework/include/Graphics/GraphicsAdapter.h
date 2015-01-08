#ifndef _GRAPHICS_ADAPTER_H
#define _GRAPHICS_ADAPTER_H

#include <memory>
#include <vector>
#include <string>
#include "../Utils.h" 
#include "DisplayMode.h"

struct GLFWmonitor;

namespace YAX
{
	enum class SurfaceFormat : int;
	enum class DepthFormat : int;
	enum class GraphicsProfile : int;

	typedef std::vector<DisplayMode> DisplayModeCollection;
	//typedef std::tuple<SurfaceFormat, DepthFormat, int> BufferQueryResults;

	class GraphicsAdapter
	{
		struct Impl;

	public:
		GraphicsAdapter(std::string description, std::string vendor, GLFWmonitor* handle);
		~GraphicsAdapter();
		GraphicsAdapter(const GraphicsAdapter&);
		GraphicsAdapter(GraphicsAdapter&&);

		GraphicsAdapter& operator=(const GraphicsAdapter&);
		GraphicsAdapter& operator=(GraphicsAdapter&&);

		static const std::vector<GraphicsAdapter>& Adapters();
		static GraphicsAdapter* DefaultAdapter();
		static void FindAdapters();
		
		
		std::string Description() const;
		std::string DeviceName() const;
		bool IsDefaultAdapter() const;
		bool IsWideScreen() const;
		GLFWmonitor* MonitorHandle() const;
		bool IsProfileSupported(GraphicsProfile) const;
		DisplayMode CurrentDisplayMode() const;
		const DisplayModeCollection& SupportedDisplayModes() const;
		

		/* Not implementing unless there's a demonstrable need for them
		i32 DeviceID() const;
		i32 Revision() const;
		i32 SubSystemID() const;
		*/
		
		
		/*
		Not going to implement these quite yet,
		as I'm not sure they're entirely necessary (or make sense) in OpenGL
		
		bool QueryBackBufferFormat(GraphicsProfile, SurfaceFormat, DepthFormat, i32, BufferQueryResults&) const;
		bool QueryRenderTargetFormat(GraphicsProfile, SurfaceFormat, DepthFormat, i32, BufferQueryResults&) const;
		static bool UseNullDevice();
		static void UseNullDevice(bool);
		static bool UseReferenceDevice();
		static void UseReferenceDevice(bool);
		*/
	
	private:
		std::unique_ptr<Impl> _impl;

		static std::vector<GraphicsAdapter> _adapters;
		static GraphicsAdapter* _defaultAdapter;
		static bool _useNull, _useRef;

	};

	

}


#endif