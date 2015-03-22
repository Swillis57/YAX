#ifndef _GRAPHICS_ADAPTER_H
#define _GRAPHICS_ADAPTER_H

#include <memory>
#include <vector>
#include <string>
#include "DisplayMode.h"
#include "../../YAX/include/Utils.h" 

struct GLFWmonitor;

namespace YAX
{
	enum class SurfaceFormat : int;
	enum class DepthFormat : int;
	enum class GraphicsProfile : int;

	typedef std::vector<DisplayMode> DisplayModeCollection;

	//GraphicsAdapter encapsulates all of the information needed
	//to identify monitors and the GPU they're connected to
	class GraphicsAdapter
	{	  
		//Using the pimpl idiom to cut down on header includes
		struct Impl;

	public:
		GraphicsAdapter(std::string name, std::string description, std::string vendor, GLFWmonitor* handle);
		~GraphicsAdapter();
		GraphicsAdapter(const GraphicsAdapter&);
		GraphicsAdapter(GraphicsAdapter&&);
		GraphicsAdapter& operator=(const GraphicsAdapter&);
		GraphicsAdapter& operator=(GraphicsAdapter&&);

		static const std::vector<GraphicsAdapter>& Adapters();
		static GraphicsAdapter DefaultAdapter();
		static void FindAdapters();
		
		
		std::string Description() const;
		std::string DeviceName() const;
		bool IsDefaultAdapter() const;
		bool IsWideScreen() const;
		GLFWmonitor* MonitorHandle() const;
		bool IsProfileSupported(GraphicsProfile) const;
		DisplayMode CurrentDisplayMode() const;
		const DisplayModeCollection& SupportedDisplayModes() const;
		
	
	private:
		std::unique_ptr<Impl> _impl;

		static std::vector<GraphicsAdapter> _adapters;
		static GraphicsAdapter& _defaultAdapter;
		static bool _useNull, _useRef;

	};

	

}


#endif