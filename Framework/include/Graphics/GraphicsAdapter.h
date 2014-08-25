#ifndef GRAPHICS_ADAPTER
#define GRAPHICS_ADAPTER

#include <vector>
#include <string>
#include <tuple>
#include "../Utils.h" 
#include "DisplayMode.h"

using std::string;

namespace XNA
{
    enum SurfaceFormat;
    enum DepthFormat;
    enum GraphicsProfile;

	class DisplayMode;

	class GraphicsAdapter
	{
	public:
		typedef std::vector<DisplayMode> DisplayModeCollection;
		typedef std::tuple<bool, SurfaceFormat, DepthFormat, int> BufferQueryResults;

		static const std::vector<GraphicsAdapter>& Adapters();
		const DisplayMode& CurrentDisplayMode();
		static GraphicsAdapter DefaultAdapter();
		string Description();
		i32 DeviceID();
		string DeviceName();
		bool IsDefaultAdapter();
		bool IsWideScreen();
		i32 MonitorHandle();
		i32 Revision();
		i32 SubSystemID();
		const DisplayModeCollection& SupportedDisplayModes();
		static bool UseNullDevice();
		static void UseNullDevice(bool);
		static bool UseReferenceDevice();
		static void UseReferenceDevice(bool);

		bool IsProfileSupported(GraphicsProfile);
		BufferQueryResults QueryBackBufferFormat(GraphicsProfile, SurfaceFormat, DepthFormat, int);
		BufferQueryResults QueryRenderTargetFormat(GraphicsProfile, SurfaceFormat, DepthFormat, int);

	private:
		std::vector<GraphicsAdapter> adapters;
		DisplayMode currDisplayMode;
		static GraphicsAdapter defaultAdapter;
		string desc;
		i32 deviceID;
		string name;
		bool isDefault;
		bool isWideScreen;
		i32 handle;
		i32 revision;
		i32 subSysID;
		DisplayModeCollection supportedModes;
		bool useNull;
		bool useRef;
		i32 vendor;



	};

	

}


#endif