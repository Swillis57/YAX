#ifndef _GRAPHICS_ADAPTER_H
#define _GRAPHICS_ADAPTER_H

#include <vector>
#include <string>
#include <tuple>
#include "../Utils.h" 
#include "DisplayMode.h"

namespace XNA
{
	enum class SurfaceFormat : int;
	enum class DepthFormat : int;
	enum class GraphicsProfile : int;

	class GraphicsAdapter
	{
	public:
		typedef std::vector<DisplayMode> DisplayModeCollection;
		typedef std::tuple<bool, SurfaceFormat, DepthFormat, int> BufferQueryResults;

		static const std::vector<GraphicsAdapter>& Adapters();
		static GraphicsAdapter& DefaultAdapter();
		
		static bool UseNullDevice();
		static void UseNullDevice(bool);
		static bool UseReferenceDevice();
		static void UseReferenceDevice(bool);
		
		GraphicsAdapter() = default;
		GraphicsAdapter(const GraphicsAdapter&) = default;
		GraphicsAdapter& operator=(const GraphicsAdapter&) = default;
		GraphicsAdapter(GraphicsAdapter&&) = delete;
		GraphicsAdapter& operator=(GraphicsAdapter&&) = delete;
		

		DisplayMode& CurrentDisplayMode() const;
		std::string Description() const;
		i32 DeviceID() const;
		std::string DeviceName() const;
		bool IsDefaultAdapter() const;
		bool IsWideScreen() const;
		i32 MonitorHandle() const;
		i32 Revision() const;
		i32 SubSystemID() const;
		const DisplayModeCollection& SupportedDisplayModes() const;
		
		bool IsProfileSupported(GraphicsProfile) const;
		BufferQueryResults QueryBackBufferFormat(GraphicsProfile, SurfaceFormat, DepthFormat, i32) const;
		BufferQueryResults QueryRenderTargetFormat(GraphicsProfile, SurfaceFormat, DepthFormat, i32) const;

	private:
		static std::vector<GraphicsAdapter> _adapters;
		static GraphicsAdapter _defaultAdapter;
		static bool _useNull, _useRef;

		DisplayMode _currDisplayMode;
		DisplayModeCollection _supportedModes;
		
		std::string _name, _desc;
		i32 _deviceID, _handle, _revision, _subSysID, _vendor;
		bool _isDefault, _isWideScreen;	 


	};

	

}


#endif